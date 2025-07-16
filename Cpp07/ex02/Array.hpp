/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:45:43 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/15 15:05:54 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ARRAY
#define ARRAY

#include <exception>
#include <iostream>
#include <iterator>

template< typename T> class Array
{
	private:
		T *_array;
		unsigned int _size;
	public: 

		Array(): _array(NULL),_size(0)
	{
		std::cout << "start array" << std::endl;
		_array = new T[_size]();
	}
	Array(unsigned int size) :_array(NULL), _size(size) 
	{
		std::cout << "start array" << std::endl;
		_array = new T[_size]();
	}

	Array(const Array &copy) :  _array(NULL), _size(copy._size)
	
	{	
		this->_array= new T[copy._size];
		for(unsigned int i = 0; i < copy._size; i++)
		{
			_array[i] = copy._array[i];
		}
	}
	~Array()
	{
		std::cout << "end array" << std::endl;
		delete [] _array;
	}

	Array & operator=(Array &array)	
	{
		if(this == &array)
			return *this;
		if(array._size != this->_size)
		{
			delete [] this->_array;
			_array = new T[array._size];
			_size =	array._size;
		}
		for(unsigned int i = 0; i < array._size; i++)
		{
			_array[i] = array._array[i];
		}
		return *this;
	}
	unsigned int size()
	{
		return _size;
	}
	T & operator[](unsigned int index)
	{
		if(index >= _size)
			throw std::exception();

		return  _array[index];
	}



};


#endif
