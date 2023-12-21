/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigLocation.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:40:21 by youjeong          #+#    #+#             */
/*   Updated: 2023/12/21 15:21:08 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <map>

#include "Type.hpp"

class ConfigLocation {
	private:
		std::string								root;
		std::string								alias;
		std::map<int, std::string>				error_page;
		int										client_max_body_size;
		std::map<std::string, std::string>		cgi_param;
		bool									autoindex;
		std::vector<method>						allow_methods;
		std::map<std::string, ConfigLocation>	locations;
		std::string								index;
		
		ConfigLocation();

	public:
		ConfigLocation(const std::string&								root,
						const std::string&								alias,
						const std::map<int, std::string>&				error_page,
						const int&										client_max_body_size,
						const std::map<std::string, std::string>&		cgi_param,
						const bool&										autoindex,
						const std::vector<method>&						allow_methods,
						const std::map<std::string, ConfigLocation>&	locations,
						const std::string&								index);
		ConfigLocation(const ConfigLocation&							ref);
		~ConfigLocation();
	
		ConfigLocation& operator=(const ConfigLocation& ref);

		const std::string&								getRoot() const ;
		const std::string&								getAlias() const ;
		const std::map<int, std::string>&				getError_page() const ;
		const int&										getClient_max_body_size() const ;
		const std::map<std::string, std::string>&		getCgi_param() const ;
		const bool&										getAutoindex() const ;
		const std::vector<method>&						getAllow_methods() const ;
		const std::map<std::string, ConfigLocation>&	getLocations() const ;
		const std::string&								getIndex() const ;

		const std::string&		findError_page(const int& error_code) const ;
		const std::string&		findCgi_param(const std::string& cgi_key) const ;
		const ConfigLocation&	findLocation(const std::string& path) const ;
};