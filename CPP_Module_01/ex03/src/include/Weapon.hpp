/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:52:07 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/12 17:46:23 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>

class Weapon
{
private:
	std::string	type;

public:
	Weapon(std::string type);
	~Weapon(void);

	const std::string& getType(void) const;
	void setType(std::string type);
};
