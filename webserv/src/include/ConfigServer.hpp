/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigServer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:39:44 by youjeong          #+#    #+#             */
/*   Updated: 2023/12/21 15:30:24 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <map>

#include "ConfigLocation.hpp"
#include "Type.hpp"

class ConfigServer {
	private:
		t_listen								listen;
		std::string								server_name;
		std::string								root;
		std::map<int, std::string>				error_page;
		int										client_max_body_size;
		std::map<std::string, std::string>		cgi_param;
		bool									autoindex;
		std::vector<method>						allow_methods;
		std::map<std::string, ConfigLocation>	locations;
		
		ConfigServer();

	public:
		ConfigServer(const t_listen&								listen,
					const std::string&								server_name,
					const std::string&								root,
					const std::map<int, std::string>&				error_page,
					const int&										client_max_body_size,
					const std::map<std::string, std::string>&		cgi_param,
					const bool&										autoindex,
					const std::vector<method>&						allow_methods,
					const std::map<std::string, ConfigLocation>&	locations);
		ConfigServer(const ConfigServer& ref);
		~ConfigServer();

		ConfigServer& operator=(const ConfigServer& ref);

		const t_listen&									getListen() const ;
		const std::string&								getServer_name() const ;
		const std::string&								getRoot() const ;
		const std::map<int, std::string>&				getError_page() const ;
		const int&										getClient_max_body_size() const ;
		const std::map<std::string, std::string>&		getCgi_param() const ;
		const bool&										getAutoindex() const ;
		const std::vector<method>&						getAllow_methods() const ;
		const std::map<std::string, ConfigLocation>&	getLocations() const ;

		const std::string&		findError_page(const int& error_code) const ;
		const std::string&		findCgi_param(const std::string& cgi_key) const ;
		const ConfigLocation&	findLocation(const std::string& path) const;
};