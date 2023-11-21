/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:54:06 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/20 18:45:32 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "ASpell.hpp"

class ASpell;

class ATarget {
	private:
		std::string type;
		
		ATarget();

	public:
		ATarget(const std::string& type);
		ATarget(const ATarget& ref);
		virtual ~ATarget();

		ATarget& operator=(const ATarget& ref);

		const std::string& getType() const;

		virtual ATarget* clone() const = 0;
		void getHitBySpell(const ASpell& spell) const;
};