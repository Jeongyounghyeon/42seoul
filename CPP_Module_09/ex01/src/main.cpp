/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:11:01 by youjeong          #+#    #+#             */
/*   Updated: 2024/02/22 18:11:01 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

#include <iostream>
#include <exception>
#include <cstdlib>

void vaildArgument(int argc);

int main(int argc, char* argv[]) {
	try {
		vaildArgument(argc);
		RPN::active(argv[1]);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		std::exit(1);
	}

	return 0;
}

void vaildArgument(int argc) {
	if (argc != 2)
		throw std::runtime_error("Error: Please input one argument");
}