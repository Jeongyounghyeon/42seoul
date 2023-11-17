/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:45:50 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/16 17:40:58 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "iter.hpp"

template <typename T>
void out(T& arg);

int main() {
	int intArr[3] = {10,11,13};
	char chArr[3] = {'a', 'b', 'c'};
	
	iter(intArr, 3, out);
	std::cout << std::endl;
	iter(chArr, 3, out);

	return 0;
}

template <typename T>
void out(T& arg) {
	std::cout << arg;
}