/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:04:53 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/04 13:38:15 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Harl.hpp"

int	main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "Please enter one argument." << std::endl;
		return 1;
	}
	
	Harl harl;

	harl.complain(av[1]);
	return 0;
}