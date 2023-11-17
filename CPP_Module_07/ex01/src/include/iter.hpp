/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:41:33 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/17 07:20:19 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>

template <typename T>
void iter(T* arr, size_t length, void (*f)(T&)) {
	for (size_t idx = 0; idx < length; idx++) {
		f(arr[idx]);
	}
}

