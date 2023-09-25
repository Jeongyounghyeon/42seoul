/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:38:46 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/14 20:17:44 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void) {
	std::string	str("HI THIS IS BRAIN");
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "[Address part]" << std::endl;
	std::cout << "str address       : " << &str << std::endl;
	std::cout << "stringPRT address : " << stringPTR << std::endl;
	std::cout << "stringREF address : " << &stringREF << std::endl;

	std::cout << std::endl;
	
	std::cout << "[Vaule part]" << std::endl;
	std::cout << "str value       : " << str << std::endl;
	std::cout << "stringPRT value : " << *stringPTR << std::endl;
	std::cout << "stringREF value : " << stringREF << std::endl;

	return 0;
}