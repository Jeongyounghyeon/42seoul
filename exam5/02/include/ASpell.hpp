/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:44:31 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/20 18:42:52 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "ATarget.hpp"

class ATarget;

class ASpell {
	private:
		std::string name;
		std::string effects;

		ASpell();

	public:
		ASpell(const std::string name, const std::string effects);
		ASpell(const ASpell &ref);
		virtual ~ASpell();

		ASpell& operator=(const ASpell &ref);
		
		const std::string& getName() const;
		const std::string& getEffects() const;

		virtual ASpell* clone() const = 0;
		void launch(const ATarget& target) const;
};
