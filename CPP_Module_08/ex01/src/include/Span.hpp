/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:16:46 by youjeong          #+#    #+#             */
/*   Updated: 2023/12/29 18:07:10 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include <algorithm>
#include <vector>

class Span {
	private:
		std::vector<int> data;

		Span();

	public:
		Span(unsigned int size);
		Span(const Span& ref);
		virtual ~Span();

		Span& operator=(const Span& ref);
		
		void addNumber(const int number);

		template <typename T>
		void addNumbers(const T& c);

		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
};

template <typename T>
void Span::addNumbers(const T& c) {
	if (std::distance(c.begin(), c.end()) > static_cast<int>(this->data.capacity() - this->data.size())) {
		throw std::invalid_argument("The value you save is larger than the value you want to save.");
	}

	for (typename T::const_iterator iter = c.begin();
		iter != c.end();
		iter++) {
		this->data.push_back(*iter);
	}
}