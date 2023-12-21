/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigLocation.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:09:09 by youjeong          #+#    #+#             */
/*   Updated: 2023/12/21 15:28:27 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>

#include "ConfigLocation.hpp"

ConfigLocation::ConfigLocation(const std::string&								root,
								const std::string&								alias,
								const std::map<int, std::string>&				error_page,
								const int&										client_max_body_size,
								const std::map<std::string, std::string>&		cgi_param,
								const bool&										autoindex,
								const std::vector<method>&						allow_methods,
								const std::map<std::string, ConfigLocation>&	locations,
								const std::string&								index) {
	this->root = root;
	this->alias = alias;
	this->error_page = error_page;
	this->client_max_body_size = client_max_body_size;
	this->cgi_param = cgi_param;
	this->autoindex = autoindex;
	this->allow_methods = allow_methods;
	this->locations = locations;
	this->index = index;
}

ConfigLocation::ConfigLocation(const ConfigLocation& ref) {
	*this = ref;
}

ConfigLocation::~ConfigLocation() {
}

ConfigLocation& ConfigLocation::operator=(const ConfigLocation& ref) {
	if (this == &ref) {
		return *this;
	}

	this->root = ref.getRoot();
	this->alias = ref.getAlias();
	this->error_page = ref.getError_page();
	this->client_max_body_size = ref.getClient_max_body_size();
	this->cgi_param = ref.getCgi_param();
	this->autoindex = ref.getAutoindex();
	this->allow_methods = ref.getAllow_methods();
	this->locations = ref.getLocations();
	this->index = ref.getIndex();

	return *this;
}


const std::string& ConfigLocation::getRoot() const {
	return this->root;
}

const std::string& ConfigLocation::getAlias() const {
	return this->alias;
}

const std::map<int, std::string>& ConfigLocation::getError_page() const {
	return this->error_page;
}

const int& ConfigLocation::getClient_max_body_size() const {
	return this->client_max_body_size;
}

const std::map<std::string, std::string>& ConfigLocation::getCgi_param() const {
	return this->cgi_param;
}

const bool& ConfigLocation::getAutoindex() const {
	return this->autoindex;
}

const std::vector<method>& ConfigLocation::getAllow_methods() const {
	return this->allow_methods;
}

const std::map<std::string, ConfigLocation>& ConfigLocation::getLocations() const {
	return this->locations;
}

const std::string& ConfigLocation::getIndex() const {
	return this->index;
}

const std::string& ConfigLocation::findError_page(const int& error_code) const {
    std::map<int, std::string>::const_iterator iter_error_code = this->error_page.find(error_code);

    if (iter_error_code == this->error_page.end()) {
		std::stringstream error_message;
		error_message << "Error page is not exist for code " << error_code; 

        throw std::invalid_argument(error_message.str());
    }
    return iter_error_code->second;
}

const std::string& ConfigLocation::findCgi_param(const std::string& cgi_key) const {
    std::map<std::string, std::string>::const_iterator iter_cgi_key = this->cgi_param.find(cgi_key);

    if (iter_cgi_key == this->cgi_param.end()) {
		std::stringstream error_message;
		error_message << "Cgi param is not exist for key " << cgi_key; 

        throw std::invalid_argument(error_message.str());
    }
    return iter_cgi_key->second;
}

const ConfigLocation& ConfigLocation::findLocation(const std::string& path) const {
    std::map<std::string, ConfigLocation>::const_iterator iter_path = this->locations.find(path);

    if (iter_path == this->locations.end()) {
		std::stringstream error_message;
		error_message << "Location is not exist for path " << path; 

        throw std::invalid_argument(error_message.str());
	}
    return iter_path->second;
}