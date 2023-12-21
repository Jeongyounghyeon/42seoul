/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:40:01 by youjeong          #+#    #+#             */
/*   Updated: 2023/12/21 15:47:44 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>

#include "ConfigServer.hpp"

class Config {
	private:
		std::vector<ConfigServer> servers;

		Config();

	public:
		Config(const std::vector<ConfigServer>& servers);
		Config(const Config& ref);
		~Config();

		Config& operator=(const Config& ref);

		class ConfigServerEmptyException : public std::exception {
			public:
				const char* what(void) const throw();
		};

		const std::vector<ConfigServer>& getServers() const ;
		const ConfigServer& getDefaultServer() const ;
};