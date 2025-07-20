/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 17:29:02 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/20 18:06:43 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <vector>

#ifndef SPAN
#define SPAN

class Span
{
	private:
		unsigned int _N;
		std::vector<int> _nbs;
	public:
		Span(unsigned int N);
		Span(Span &copy);
		~Span();
		Span& operator=(Span &copy);
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
