/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 22:02:55 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/16 16:31:42 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Serializer.hpp"
#include "Data.hpp"

int main() {
	Data data;
	Data *pdata = &data;
	uintptr_t puint;
	
	pdata->value = 1;
	std::cout << pdata << std::endl;
	
	puint = Serializer::serialize(pdata);
	std::cout << puint << std::endl;

	pdata = Serializer::deserialize(puint);
	std::cout << pdata << std::endl;

	std::cout << pdata->value << std::endl;

	return 0;
}