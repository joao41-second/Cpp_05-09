/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 17:29:02 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/21 12:07:06 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>

class Span
{

	private:
		unsigned int _N;
		std::vector<int> _nbs;
	public:
		Span(unsigned int N);
		Span(Span const  &copy);
		~Span();
		Span& operator = (Span const  &copy);

 		void addNumber(int nb);
		int shortestSpan();
		int longestSpan();
	
		class invlalidSize_N
		{
			const char *what() const throw();
		};

		class not_minal_elements
		{
			const char *what() const throw();
		};
		class Not_zero
		{
			const char *what() const throw();
		};

};

#endif
