/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:00:23 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/24 19:36:45 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void test_subject();
void test_subject_array();
void test_deep_copy();

int main() {
	test_subject();
	test_subject_array();
	test_deep_copy();
	return 0;
}

void test_subject() {
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j; //should not create a leak
	delete i;
}

void test_subject_array() {
	Animal* animals[10];
	
	for (int i = 0; i < 5; i++) {
		animals[i] = new Cat;
	}
	for (int i = 5; i < 10; i++) {
		animals[i] = new Dog;
	}
	
	std::cout << std::endl;

	for (int i = 0; i < 10; i++) {
		delete animals[i];
	}
}

void test_deep_copy() {
	Dog dog;
	Dog dog_copy;

	dog.getBrain()->setIdeas("ideas0", 0);
	dog.getBrain()->setIdeas("ideas1", 1);

	dog_copy = dog;

	std::cout << dog_copy.getBrain()->getIdeas(0) << std::endl;
	std::cout << dog_copy.getBrain()->getIdeas(1) << std::endl;

	std::cout << dog.getBrain() << std::endl;
	std::cout << dog_copy.getBrain() << std::endl;
}