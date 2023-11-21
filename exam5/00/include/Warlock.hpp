/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:11:08 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/20 17:29:46 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Warlock {
	private:
		const std::string name;
		std::string title;
		
		Warlock();
		Warlock(const Warlock& ref);
		Warlock operator=(const Warlock& ref);
	
	public:
		Warlock(const std::string& name, const std::string& title);
		virtual ~Warlock();
		
		const std::string& getName() const;
		const std::string& getTitle() const;
		
		void setTitle(const std::string& title);

		void introduce() const;
};
