/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileStreamController.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:53:58 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/04 13:06:23 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileStreamController.hpp"

FileStreamController::FileStreamController(
	std::ifstream& ifs, 
	std::ofstream& ofs) : 
		ifs(ifs),
		ofs(ofs) { };

FileStreamController::~FileStreamController(void) { };

std::ifstream&	FileStreamController::getIfs(void) const {
	return this->ifs;
};

std::ofstream&	FileStreamController::getOfs(void) const {
	return this->ofs;
};

int	FileStreamController::openIfile(std::string filename) {
	ifs.open(filename.c_str());
	if (ifs.fail())
		return 1;
	return 0;
}

int	FileStreamController::openOfile(std::string filename) {
	ofs.open(filename.c_str());
	if (ofs.fail())
		return 1;
	return 0;
}

void	FileStreamController::replaceInToOut(std::string str, std::string str_replace) {
	std::string contents;
	while (true)
	{
		std::getline(this->ifs, contents);
		
		size_t pos = 0;
		while (true)
		{
			pos = contents.find(str, pos);
			if (pos == std::string::npos)
				break ;
			contents.erase(pos, str.length());
			contents.insert(pos, str_replace);
			pos += str_replace.length();
		}
		this->ofs << contents;
		if (this->ifs.eof())
			break ;
		this->ofs << std::endl;	
	}
}