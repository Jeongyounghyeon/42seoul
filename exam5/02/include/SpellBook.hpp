/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:37:49 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/21 18:39:31 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <string>

#include "ASpell.hpp"

class SpellBook {
	private:
		std::map <std::string, ASpell*> contents;

	public:
		SpellBook();
		SpellBook(const SpellBook& ref);
		~SpellBook();

		SpellBook& operator=(const SpellBook& ref);

		void learnSpell(ASpell*);
		void forgetSpell(std::string const &);
		ASpell* createSpell(std::string const &);
};