/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:14:05 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/02 16:09:34 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

# include <map>
# include <string>

class Harl
{
private:
	void	debug(void) const;
	void	info(void) const;
	void	warning(void) const;
	void	error(void) const;

public:
	Harl(void);
	~Harl(void);

	void	complain(std::string level);
};
