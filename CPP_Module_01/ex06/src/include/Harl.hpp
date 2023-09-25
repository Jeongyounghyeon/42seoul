/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:59:05 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/25 23:18:01 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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

	void	complain(std::string level) const;
};
