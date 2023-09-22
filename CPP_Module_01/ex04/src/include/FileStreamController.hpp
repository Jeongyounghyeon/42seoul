/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileStreamController.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:48:34 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/22 16:46:13 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <fstream>
# include <string>

class FileStreamController
{
private:
	std::ifstream&	ifs;
	std::ofstream&	ofs;

public:
	FileStreamController(std::ifstream& ifs, std::ofstream& ofs);
	~FileStreamController(void);

	std::ifstream&	getIfs(void) const;
	std::ofstream&	getOfs(void) const;

	int		openIfile(std::string filename);
	int		openOfile(std::string filename);
	void	replaceInToOut(std::string str, std::string str_replace);
};

