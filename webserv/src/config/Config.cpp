/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:38:02 by youjeong          #+#    #+#             */
/*   Updated: 2023/12/21 15:46:54 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Config.hpp"

Config::Config(const std::vector<ConfigServer>& servers) {
	this->servers = servers;
}

Config::Config(const Config& ref) {
	*this = ref;
}

Config::~Config() {
}

Config& Config::operator=(const Config& ref) {
	if (this == &ref) {
		return *this;
	}

	this->servers = ref.getServers();

	return *this;
}

const std::vector<ConfigServer>& Config::getServers() const {
	return this->servers;
}

const ConfigServer& Config::getDefaultServer() const {
	if (this->servers.empty()) {
		throw ConfigServerEmptyException();
	}

	return this->servers.at(0);
}

const char* Config::ConfigServerEmptyException::what(void) const throw() {
	return "server is empty";
}