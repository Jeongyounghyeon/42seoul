/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:49:15 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/17 09:07:26 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

#include "Array.hpp"

template <typename T>
Array<T>::Array() {
	this->arr = 0;
	this->arrSize = 0;
}

template <typename T>
Array<T>::Array(const size_t arrSize) {
	this->arr = new T[arrSize];
	this->arrSize = arrSize;
	
	for (size_t idx = 0; idx < arrSize; idx++) {
		this->arr[idx] = 0;
	}
}

template <typename T>
Array<T>::Array(const Array& ref) {
	this->arr = 0;
	*this = ref;
}

template <typename T>
Array<T>::~Array() {
	if (this->arr != 0)
		delete[] this->arr;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& ref) {
	if (this == &ref)
		return *this;
	
	if (this->arr != 0)
		delete[] this->arr;
	
	this->arr = new T[ref.size()];
	this->arrSize = ref.size();
	for (size_t idx = 0; idx < ref.size(); idx++) {
		this->arr[idx] = ref[idx];
	}

	return *this;
}

template <typename T>
T& Array<T>::operator[] (size_t idx) {
	if (idx >= this->arrSize) {
		throw OutOfIndexRange();
	}

	return this->arr[idx];
}

template <typename T>
const T& Array<T>::operator[] (size_t idx) const {
	if (idx >= this->arrSize) {
		throw OutOfIndexRange();
	}

	return this->arr[idx];
}		

template <typename T>
size_t Array<T>::size() const {
	return this->arrSize;
}