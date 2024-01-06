/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:34:32 by youjeong          #+#    #+#             */
/*   Updated: 2024/01/02 17:49:10 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "MutantStack.hpp"

int subject();
int crtest();

int main() {
	// subject();
	crtest();
	return 0;
}

int subject() {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

int crtest() {
	MutantStack<int> mstack;

	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);

	for (MutantStack<int>::const_iterator criter = mstack.cbegin(); criter != mstack.cend(); criter++) {
		std::cout << *criter << std::endl;
	}

	return 0;
}