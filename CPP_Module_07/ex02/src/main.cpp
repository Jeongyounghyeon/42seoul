/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:49:12 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/17 09:12:15 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Array.hpp"

int subject();
int copy();
int except();

#define MAX_VAL 750
int main(int, char**)
{
	subject();
	// copy();
	// except();
}

int subject() {
	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

int copy() {
	Array<int> arr1(3);
	arr1[0] = 0;
	arr1[1] = 1;
	arr1[2] = 2;
	Array<int> arr2(arr1);
	Array<int> arr3;

	std::cout << "예상 값: " << "012" << std::endl;
	std::cout << "실제 값: " << arr1[0] << arr1[1] << arr1[2] << std::endl;
	std::cout << std::endl;

	std::cout << "예상 값: " << "012" << std::endl;
	std::cout << "실제 값: " << arr2[0] << arr2[1] << arr2[2] << std::endl;
	std::cout << std::endl;


	arr3 = arr1;
	std::cout << "예상 값: " << "012" << std::endl;
	std::cout << "실제 값: " << arr3[0] << arr3[1] << arr3[2] << std::endl;
	std::cout << std::endl;
	
	arr3[0] = 3;
	arr3[1] = 4;
	arr3[2] = 5;
	std::cout << "예상 값: " << "012" << std::endl;
	std::cout << "실제 값: " << arr1[0] << arr1[1] << arr1[2] << std::endl;
	std::cout << std::endl;
	std::cout << "예상 값: " << "345" << std::endl;
	std::cout << "실제 값: " << arr3[0] << arr3[1] << arr3[2] << std::endl;
	std::cout << std::endl;
	
	return 0;
}

int except() {
	Array<int> arr1(3);
	Array<int> arr2;

	try {
		arr1[3] = 0;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		arr1[-1] = 0;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}