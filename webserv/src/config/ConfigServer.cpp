/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigServer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:29:12 by youjeong          #+#    #+#             */
/*   Updated: 2023/12/21 15:37:50 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>

#include "ConfigServer.hpp"

ConfigServer::ConfigServer(const t_listen&									listen,
							const std::string&								server_name,
							const std::string&								root,
							const std::map<int, std::string>&				error_page,
							const int&										client_max_body_size,
							const std::map<std::string, std::string>&		cgi_param,
							const bool&										autoindex,
							const std::vector<method>&						allow_methods,
							const std::map<std::string, ConfigLocation>&	locations)
{
	this->listen = listen;
	this->server_name = server_name;
	this->root = root;
	this->error_page = error_page;
	this->client_max_body_size = client_max_body_size;
	this->cgi_param = cgi_param;
	this->autoindex = autoindex;
	this->allow_methods = allow_methods;
	this->locations = locations;
}

ConfigServer::ConfigServer(const ConfigServer& ref) {
	*this = ref;
}

ConfigServer::~ConfigServer() {
}

ConfigServer& ConfigServer::operator=(const ConfigServer& ref) {
	if (this == &ref) {
		return *this;
	}

	this->listen = ref.getListen();
	this->server_name = ref.getServer_name();
	this->root = ref.getRoot();
	this->error_page = ref.getError_page();
	this->client_max_body_size = ref.getClient_max_body_size();
	this->cgi_param = ref.getCgi_param();
	this->autoindex = ref.getAutoindex();
	this->allow_methods = ref.getAllow_methods();
	this->locations = ref.getLocations();

	return *this;
}

const t_listen& ConfigServer::getListen() const {
	return this->listen;
}

const std::string& ConfigServer::getServer_name() const {
	return this->server_name;
}

const std::string& ConfigServer::getRoot() const {
	return this->root;
}

const std::map<int, std::string>& ConfigServer::getError_page() const {
	return this->error_page;
}

const int& ConfigServer::getClient_max_body_size() const {
	return this->client_max_body_size;
}

const std::map<std::string, std::string>& ConfigServer::getCgi_param() const {
	return this->cgi_param;
}

const bool& ConfigServer::getAutoindex() const {
	return this->autoindex;
}

const std::vector<method>& ConfigServer::getAllow_methods() const {
	return this->allow_methods;
}

const std::map<std::string, ConfigLocation>& ConfigServer::getLocations() const {
	return this->locations;
}

const std::string&		ConfigServer::findError_page(const int& error_code) const {
	std::map<int, std::string>::const_iterator iter_error_code = this->error_page.find(error_code);

    if (iter_error_code == this->error_page.end()) {
		std::stringstream error_message;
		error_message << "Error page is not exist for code " << error_code; 

        throw std::invalid_argument(error_message.str());
    }
    return iter_error_code->second;
}

const std::string&		ConfigServer::findCgi_param(const std::string& cgi_key) const {
	std::map<std::string, std::string>::const_iterator iter_cgi_key = this->cgi_param.find(cgi_key);

    if (iter_cgi_key == this->cgi_param.end()) {
		std::stringstream error_message;
		error_message << "Cgi param is not exist for key " << cgi_key; 

        throw std::invalid_argument(error_message.str());
    }
    return iter_cgi_key->second;
}

const ConfigLocation&	ConfigServer::findLocation(const std::string& path) const{
	std::map<std::string, ConfigLocation>::const_iterator iter_path = this->locations.find(path);

    if (iter_path == this->locations.end()) {
		std::stringstream error_message;
		error_message << "Location is not exist for path " << path; 

        throw std::invalid_argument(error_message.str());
	}
    return iter_path->second;
}