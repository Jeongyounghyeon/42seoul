/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:35:05 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/25 23:20:50 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#include "FileStreamController.hpp"

int		service(std::string filename, std::string s1, std::string s2);
bool	validArgument(int argc, char **argv);

int main(int argc, char **argv) {
	if (!validArgument(argc, argv))
		return -1;
	return service(argv[1], argv[2], argv[3]);
}

int	service(std::string filename, std::string s1, std::string s2) {
	std::ifstream	ifs;
	std::ofstream	ofs;
	FileStreamController fileStreamController(ifs, ofs);

	if (fileStreamController.openIfile(filename) != 0) {
		std::cout << "sorry, can't open " << filename << std::endl;
		return 1;
	}

	if (fileStreamController.openOfile(filename + ".replace") != 0) {
		std::cout << "sorry, can't open " << filename << std::endl;
		return 1;
	}
	
	fileStreamController.replaceInToOut(s1, s2);

	return 0;
}

bool validArgument(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Please enter 3 arguments." << std::endl 
				<< "[filename] [what to change], [what to changed]" << std::endl;
		return false;
	} else if (std::strlen(argv[1]) == 0) {
		std::cout << "[filname]: This augment cannot be empty." << std::endl;
		return false;
	} else if (std::strlen(argv[2]) == 0) {
		std::cout << "[what to change]: This augment cannot be empty." << std::endl;
		return false;
	}
	return true;
}