/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:11:21 by youjeong          #+#    #+#             */
/*   Updated: 2024/02/22 18:11:23 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <sstream>
#include <cstdlib>
#include <exception>
#include <stdexcept>
#include <climits>
#include <iterator>
#include <iostream>
#include <ctime>

const int PmergeMe::jacobsthalNumber[33] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765, 2147483647};

template<typename T>
T &listAt(std::list<T>& myList, size_t index);

template<typename T>
typename std::list<T>::iterator listInsert(std::list<T>& myList, size_t index, const T& value);

void PmergeMe::pmergeMe(int argc, char* argv[]) {
	std::list<int> list;
	std::list<int> sortedList;
	std::deque<int> deque;
	std::deque<int> sortedDeque;
	
	std::stringstream beforeDataStream;
	std::stringstream afterDataStream;

	int* numbers = parseArgument(argc, argv);
	beforeDataStream << toString(numbers, argc);

	double timeForList;
	{
		clock_t start = clock();
		arrToList(numbers, argc, list);
		sortedList = sortList(list);
		clock_t finish = clock();
		
		timeForList = static_cast<double>(finish - start);
	}

	double timeForDeque;
	{
		clock_t start = clock();
		arrToDeque(numbers, argc, deque);
		sortedDeque = sortDeque(deque);
		clock_t finish = clock();

		timeForDeque = static_cast<double>(finish - start);
	}

	delete[] numbers;

	afterDataStream << toString(sortedDeque);

	outResult(beforeDataStream, afterDataStream, argc, timeForList, timeForDeque);
}

int* PmergeMe::parseArgument(int argc, char* argv[]) {
	int* numbers = new int[argc];

	for (int idxArgc = 0; idxArgc < argc; idxArgc++) {
		char* tmp;
		double d = strtod(argv[idxArgc], &tmp);

		if (*tmp) {
			delete[] numbers;
			throw std::runtime_error("arguments are allow only positive integer.");
		}
		if (!(d >= 1 && d <= INT_MAX)) {
			delete[] numbers;
			throw std::runtime_error("The argument is beyond the range of positive integer.");
		}

		numbers[idxArgc] = d;
	}

	return numbers;
}

void PmergeMe::arrToList(int* arr, size_t size, std::list<int>& list) {
	for (size_t idx = 0; idx < size; idx++)
		list.push_back(arr[idx]);
}

void PmergeMe::arrToDeque(int* arr, size_t size, std::deque<int>& deque) {
	for (size_t idx = 0; idx < size; idx++)
		deque.push_back(arr[idx]);
}

std::list<int> PmergeMe::sortList(std::list<int>& list) {
	std::list<t_listSortStruct> sortingList;
	std::list<t_listSortStruct*> sortedList;
	std::list<int> res;

	for (
		std::list<int>::const_iterator iter = list.begin();
		iter != list.end();
		iter++
	) {
		t_listSortStruct data;
		data.value = *iter;

		sortingList.push_back(data);
	}

	sortByFordJohnson(sortingList, sortedList, sortingList.size());

	for (
		std::list<t_listSortStruct*>::const_iterator iter = sortedList.begin();
		iter != sortedList.end();
		iter++
	) {
		res.push_back((*iter)->value);
	}

	return res;
}

std::deque<int> PmergeMe::sortDeque(std::deque<int>& deque) {
	std::deque<t_dequeSortStruct> sortingDeque;
	std::deque<t_dequeSortStruct*> sortedDeque;
	std::deque<int> res;

	for (
		std::deque<int>::const_iterator iter = deque.begin();
		iter != deque.end();
		iter++
	) {
		t_dequeSortStruct data;
		data.value = *iter;

		sortingDeque.push_back(data);
	}

	sortByFordJohnson(sortingDeque, sortedDeque, sortingDeque.size());

	for (
		std::deque<t_dequeSortStruct*>::const_iterator iter = sortedDeque.begin();
		iter != sortedDeque.end();
		iter++
	) {
		res.push_back((*iter)->value);
	}

	return res;
}

void PmergeMe::sortByFordJohnson(
	std::list<t_listSortStruct>& sortingList,
	std::list<t_listSortStruct*>& sortedList,
	int sortSize
) {
	if (sortSize <= 1) {
		sortedList.push_back(&sortingList.front());
		return;
	}

	for (int idx = 0; idx < sortSize / 2; idx++) {
		t_listSortStruct& structA = listAt(sortingList, idx);
		t_listSortStruct& structB = listAt(sortingList, idx + (sortSize / 2));

		if (structA.value < structB.value)
			std::swap(structA, structB);

		structA.waiting.push_front(&structB);
	}

	sortByFordJohnson(sortingList, sortedList, sortSize / 2);

	std::list<t_listSortStruct*> listA(sortedList);
	std::list<t_listSortStruct*> listB;
	std::list<int> preInsertSum(sortSize / 2, 0);

	for (int idx = 0; idx < sortSize / 2; idx++) {
		std::list<t_listSortStruct*>& waiting = listAt(listA, idx)->waiting;

		listB.push_back(waiting.front());
		waiting.pop_front();
	}

	int n = 0;
	int jsNumStart = jacobsthalNumber[n];
	int jsNumEnd;
	do {
		jsNumEnd = std::min(jacobsthalNumber[n + 1], sortSize / 2);

		for (int idx = jsNumEnd - 1; idx >= jsNumStart; idx--) {
			t_listSortStruct* structSorting
				= listAt(listB, idx);
			int insertIdx
				= binarySearch(
					sortedList,
					structSorting->value,
					0,
					listAt(preInsertSum, idx) + idx - 1
				);
			
			listInsert(sortedList, insertIdx, structSorting);


			for (int preInsertIdx = sortSize / 2 - 1;
				listAt(listA, preInsertIdx) != listAt(sortedList, insertIdx + 1)
				&& listAt(listB, preInsertIdx) != listAt(sortedList, insertIdx + 1);
				preInsertIdx--
			) {
				listAt(preInsertSum, preInsertIdx)++;
			}
		}

		jsNumStart = jsNumEnd;
		n++;
	} while (jsNumStart < sortSize / 2);

	if (sortSize % 2 != 0) {
		t_listSortStruct* structSorting = &listAt(sortingList, sortSize - 1);
		int insertIdx
			= binarySearch(
				sortedList, 
				structSorting->value, 
				0, 
				sortSize - 2
			);

		listInsert(sortedList, insertIdx, structSorting);
	}
}

void PmergeMe::sortByFordJohnson(
	std::deque<t_dequeSortStruct>& sortingDeque,
	std::deque<t_dequeSortStruct*>& sortedDeque,
	int sortSize
) {
	if (sortSize <= 1) {
		sortedDeque.push_back(&sortingDeque.front());
		return;
	}

	for (int idx = 0; idx < sortSize / 2; idx++) {
		t_dequeSortStruct& structA = sortingDeque[idx];
		t_dequeSortStruct& structB = sortingDeque[idx + (sortSize / 2)];

		if (structA.value < structB.value)
			std::swap(structA, structB);

		structA.waiting.push_front(&structB);
	}

	sortByFordJohnson(sortingDeque, sortedDeque, sortSize / 2);

	std::deque<t_dequeSortStruct*> dequeA(sortedDeque);
	std::deque<t_dequeSortStruct*> dequeB;
	std::deque<int> preInsertSum(sortSize / 2, 0);

	for (int idx = 0; idx < sortSize / 2; idx++) {
		std::deque<struct s_dequeSortStruct*>& waiting = dequeA[idx]->waiting;

		dequeB.push_back(waiting.front());
		waiting.pop_front();
	}

	int n = 0;
	int jsNumStart = jacobsthalNumber[n];
	int jsNumEnd;
	do {
		jsNumEnd = std::min(jacobsthalNumber[n + 1], sortSize / 2);

		for (int idx = jsNumEnd - 1; idx >= jsNumStart; idx--) {
			t_dequeSortStruct* structSorting
				= dequeB[idx];
			int insertIdx
				= binarySearch(
					sortedDeque,
					structSorting->value,
					0,
					preInsertSum[idx] + idx - 1
				);
			
			sortedDeque.insert(
				sortedDeque.begin() + insertIdx,
				structSorting
			);

			for (int preInsertIdx = sortSize / 2 - 1;
				dequeA[preInsertIdx] != sortedDeque[insertIdx + 1] 
				&& dequeB[preInsertIdx] != sortedDeque[insertIdx + 1];
				preInsertIdx--
			) {
				preInsertSum[preInsertIdx]++;
			}
		}

		jsNumStart = jsNumEnd;
		n++;
	} while (jsNumStart < sortSize / 2);

	if (sortSize % 2 != 0) {
		t_dequeSortStruct* structSorting = &sortingDeque[sortSize - 1];
		int insertIdx
			= binarySearch(
				sortedDeque, 
				structSorting->value, 
				0, 
				sortSize - 2
			);

		sortedDeque.insert(
			sortedDeque.begin() + insertIdx,
			structSorting
		);
	}
}

int PmergeMe::binarySearch(
	std::deque<t_dequeSortStruct*>& deque,
	int num,
	int low,
	int high
) {
	int mid = (low + high) / 2;

	if (low < high) {
		if (num >= deque[mid]->value)
			return binarySearch(deque, num, mid + 1, high);
		else
			return binarySearch(deque, num, low, mid);
	}

	if (num > deque[mid]->value) { return high + 1; }

	return low;
}

int PmergeMe::binarySearch(
	std::list<t_listSortStruct*>& list,
	int num,
	int low,
	int high
) {
	int mid = (low + high) / 2;

	if (low < high) {
		if (num >= listAt(list, mid)->value)
			return binarySearch(list, num, mid + 1, high);
		else
			return binarySearch(list, num, low, mid);
	}

	if (num > listAt(list, mid)->value) { return high + 1; }

	return low;
}

void PmergeMe::outResult(const std::stringstream& beforeDataStream,
						const std::stringstream& afterDataStream,
						const int cnt,
						const double timeForList,
						const double timeForDeque)
{
	std::cout << "Before:	" << beforeDataStream.str() << std::endl;
	std::cout << "After:	" << afterDataStream.str() << std::endl;
	std::cout << "Time to process a range of " << cnt << " elements with std::list : " << timeForList << " us" << std::endl;
	std::cout << "Time to process a range of " << cnt << " elements with std::deque : " << timeForDeque << " us" << std::endl;
}

std::string PmergeMe::toString(const int* arr, size_t size) {
	std::stringstream ss;

	if (size > 0) { ss << arr[0]; }

	for (size_t idx = 1; idx < size; idx++)
		ss << " " << arr[idx];

	return ss.str();
}

std::string PmergeMe::toString(const std::list<int> &lst) {
	std::stringstream ss;

	if (lst.size() > 0) { ss << *(lst.begin()); }

	std::list<int>::const_iterator iter = lst.begin();
	
    if (++iter != lst.end()) {
        while (iter != lst.end()) {
            ss << " " << *iter;
            ++iter;
        }
    }

	return ss.str();
}

std::string PmergeMe::toString(const std::deque<int> &dq) {
	std::stringstream ss;

	if (dq.size() > 0) { ss << *(dq.begin()); }

	std::deque<int>::const_iterator iter = dq.begin();
	
    if (++iter != dq.end()) {
        while (iter != dq.end()) {
            ss << " " << *iter;
            ++iter;
        }
    }

	return ss.str();
}

template<typename T>
T &listAt(std::list<T>& myList, size_t index) {
    if (index >= myList.size()) { throw std::out_of_range("Index out of range"); }

    typename std::list<T>::iterator it = myList.begin();
    std::advance(it, index);

    return *it;
}

template<typename T>
typename std::list<T>::iterator listInsert(std::list<T>& myList, size_t index, const T& value) {
    if (index > myList.size()) { throw std::out_of_range("Index out of range"); }

    typename std::list<T>::iterator it = myList.begin();
    std::advance(it, index);

    return myList.insert(it, value);
}
