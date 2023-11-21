/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:26:39 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/20 18:48:50 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ASpell.hpp"

class Polymorph : public ASpell {
	public:
		Polymorph();
		Polymorph(const Polymorph &ref);
		~Polymorph();
	
		Polymorph& operator=(const Polymorph &ref);

		Polymorph* clone() const;
};