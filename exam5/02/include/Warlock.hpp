/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:11:08 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/21 18:49:26 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <map>

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock {
	private:
		const std::string name;
		std::string title;
		SpellBook spellBook;
		
		Warlock();
		Warlock(const Warlock& ref);
		Warlock& operator=(const Warlock& ref);
	
	public:
		Warlock(const std::string& name, const std::string& title);
		virtual ~Warlock();
		
		const std::string& getName() const;
		const std::string& getTitle() const;
		
		void setTitle(const std::string& title);

		void introduce() const;
		void learnSpell(ASpell *spell);
		void forgetSpell(const std::string& spellName);
		void launchSpell(const std::string& speelName, const ATarget& target);
};
