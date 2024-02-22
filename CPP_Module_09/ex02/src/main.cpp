/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:11:19 by youjeong          #+#    #+#             */
/*   Updated: 2024/02/22 18:11:20 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <exception>
#include <stdexcept>
#include <iostream>

static void validArgument(int argc);

int main(int argc, char* argv[]) {
	try {
		validArgument(argc);
		PmergeMe::pmergeMe(argc - 1, argv + 1);
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}

static void validArgument(int argc) {
	if (argc == 1) {
		throw std::runtime_error("use a positive integer sequence as an argument.");
	}
}