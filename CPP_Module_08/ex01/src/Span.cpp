/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:30:15 by youjeong          #+#    #+#             */
/*   Updated: 2023/12/29 18:07:15 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int size) : data(0, 0) {
	this->data.reserve(size);
}

Span::Span(const Span& ref) {
	*this = ref;
}

Span::~Span() {
}

Span& Span::operator=(const Span& ref) {
	if (this == &ref) {
		return *this;
	}

	this->data = ref.data;

	return *this;
}

void Span::addNumber(const int number) {
	if (this->data.size() == this->data.capacity()) {
		throw std::runtime_error("The span is full already.");
	}
	this->data.push_back(number);
}

// template <typename T>
// void Span::addNumbers(const T& c) {
// 	if (std::distance(c.begin(), c.end()) > (this->data.capacity() - this->data.size())) {
// 		throw std::invalid_argument("The value you save is larger than the value you want to save.");
// 	}

// 	for (typename T::iterator iter = c.begin();
// 		iter != c.end();
// 		iter++) {
// 		this->data.push_back(*iter);
// 	}
// }

unsigned int Span::shortestSpan() const {
	if (data.size() <= 1) {
		throw std::runtime_error("The size of the span is less than or equal to 1.");
	}

	unsigned int span = static_cast<unsigned int>(-1);

	for (std::vector<int>::size_type i = 0; i < data.size(); ++i) {
		for (std::vector<int>::size_type j = i + 1; j < data.size(); ++j) {
			unsigned int tmp = static_cast<unsigned int>(std::abs(data[j] - data[i]));

			span = std::min(span, tmp);
		}
	}

	return span;
}

unsigned int Span::longestSpan() const {
	if (this->data.size() <= 1) {
		throw std::runtime_error("The size of the span is less than or equal to 1.");
	}
	
	// return (*std::max_element(data.begin(), data.end()) - *std::min_element(data.begin(), data.end()));

	unsigned int span = static_cast<unsigned int>(0);

	for (std::vector<int>::size_type i = 0; i < data.size(); ++i) {
		for (std::vector<int>::size_type j = i + 1; j < data.size(); ++j) {
			unsigned int tmp = static_cast<unsigned int>(std::abs(data[j] - data[i]));

			span = std::max(span, tmp);
		}
	}

	return span;
}