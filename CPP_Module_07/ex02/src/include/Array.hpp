/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:49:16 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/17 09:07:10 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>

template <typename T>
class Array {
	private:
		T* arr;
		size_t arrSize;

		class OutOfIndexRange : public std::exception {
			public:
				const char* what() const throw() {
					return "Out of indexRange";
				}
		};

	public:
		Array();
		Array(const size_t arrSize);
		Array(const Array& ref);
		virtual ~Array();

		Array&		operator=(const Array& ref);
		T&			operator[] (size_t idx);
		const T&	operator[] (size_t idx) const;
		
		size_t size() const;		
};

#include "Array.tpp"