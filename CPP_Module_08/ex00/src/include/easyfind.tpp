/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:23:37 by youjeong          #+#    #+#             */
/*   Updated: 2024/01/03 21:35:58 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <exception>

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& container, const int value) {
	typename T::iterator iter = std::find(container.begin(), container.end(), value);
    
	if (iter == container.end())
        throw std::runtime_error("value is not in this container");
    return iter;
}