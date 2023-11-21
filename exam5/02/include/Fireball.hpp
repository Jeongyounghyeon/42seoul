/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:26:39 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/20 18:48:50 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ASpell.hpp"

class Fireball : public ASpell {
	public:
		Fireball();
		Fireball(const Fireball &ref);
		~Fireball();
	
		Fireball& operator=(const Fireball &ref);

		Fireball* clone() const;
};