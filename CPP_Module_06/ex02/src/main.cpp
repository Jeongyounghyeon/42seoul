/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:21:23 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/08 18:58:26 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <cstdlib>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
	/* Test 1 */
	{
		Base* pbase;
		A a;
		B b;
		C c;

		pbase = &a;
		identify(pbase);
		identify(*pbase);

		pbase = &b;
		identify(pbase);
		identify(*pbase);

		pbase = &c;
		identify(pbase);
		identify(*pbase);
	}
}
