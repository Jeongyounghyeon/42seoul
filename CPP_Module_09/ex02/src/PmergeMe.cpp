#include "PmergeMe.hpp"

#include <sstream>
#include <cstdlib>
#include <exception>
#include <stdexcept>
#include <climits>
#include <iterator>
#include <iostream>
#include <ctime>

void PmergeMe::pmergeMe(int argc, char* numbers[]) {
	std::list<int> lst;
	std::list<int> sortedLst;
	std::deque<int> dq;
	std::deque<int> sortedDq;
	
	std::stringstream beforeDataStream;
	std::stringstream afterDataStream;

	saveData(lst, dq, argc, numbers);
	beforeDataStream << toString(lst);

	clock_t start = clock();
	sortedLst = sortList(lst);
	clock_t finish = clock();
	double timeForList = static_cast<double>(finish - start);
	
	afterDataStream << toString(sortedLst);

	outResult(beforeDataStream, afterDataStream, timeForList, 0);
}

void PmergeMe::saveData(std::list<int> &lst,
						std::deque<int> &dq,
						int argc, char* numbers[]) {
	for (int idxArgc = 0; idxArgc < argc; idxArgc++) {
		char* tmp;
		double d = strtod(numbers[idxArgc], &tmp);

		if (*tmp)
			throw std::runtime_error("arguments are allow only positive integer.");
		if (!(d >= 1 && d <= INT_MAX))
			throw std::runtime_error("The argument is beyond the range of positive integer.");

		lst.push_back(d);
		dq.push_back(d);
	}
}


std::list<int> PmergeMe::sortList(std::list<int>& lst) {
	std::list<int> sortedLst;
	std::list<std::pair<int, int> > sortingLst;
	std::list<std::pair<int, std::list<int> > > waitingLst;
	std::list<int> valLst;

	std::list<int>::const_iterator iter = lst.begin();
	for (size_t idx = 0; idx < lst.size(); idx++, iter++) {
		std::list<int> emptyList;
		sortingLst.push_back(std::make_pair(idx, *iter));
		waitingLst.push_back(std::make_pair(idx, emptyList));
		valLst.push_back(*iter);
	}

	sortByFordJohnson(sortingLst, waitingLst, valLst, 0, sortingLst.size() - 1);

	for (std::list<std::pair<int, int> >::const_iterator iter = sortingLst.begin();
		iter != sortingLst.end();
		iter++)
	{
		sortedLst.push_back(iter->second);
	}

	return sortedLst;
}

void PmergeMe::outResult(const std::stringstream& beforeDataStream,
						const std::stringstream& afterDataStream,
						const double timeForList,
						const double timeForDeque)
{
	std::cout << "Before:	" << beforeDataStream.str() << std::endl;
	std::cout << "After:	" << afterDataStream.str() << std::endl;
	std::cout << "Time to process a range of 5 elements with std::list : " << timeForList << " us" << std::endl;
	std::cout << "Time to process a range of 5 elements with std::[..] : " << timeForDeque << " us" << std::endl;
}

void PmergeMe::sortByFordJohnson(std::list<std::pair<int, int> >& sortingLst,
								std::list<std::pair<int, std::list<int> > >& waitingLst,
								std::list<int>& valLst,
								int startIdx,
								int endIdx)
{
	int sortSize = (endIdx + 1) - startIdx;
	bool solo = sortSize % 2 != 0;

	if (sortSize <= 1) {
		return;
	}

	int midIdx = startIdx + sortSize / 2;

	std::list<std::pair<int, int > >::iterator iterValA = sortingLst.begin();
	// for (int idx = 0; idx < startIdx && iterA != sortingLst.end(); ++idx, ++iterA);
	std::advance(iterValA, startIdx);
	std::list<std::pair<int, int > >::iterator iterValB = sortingLst.begin();
	// for (int idx = 0; idx < midIdx && iterB != sortingLst.end(); ++idx, ++iterB);
    std::advance(iterValB, midIdx);

	for (int idx = startIdx; idx < midIdx; idx++) {
		std::list<std::pair<int, std::list<int> > >::iterator iterWaitA = waitingLst.begin();
		std::list<std::pair<int, std::list<int> > >::iterator iterWaitB = waitingLst.begin();
		int a = iterValA->second;
		int b = iterValB->second;

		if (a < b) {
			std::advance(iterWaitB, iterValB->first);
			iterWaitB->second.push_front(iterValA->first);
			std::swap(*iterValA, *iterValB);
		} else {
			std::advance(iterWaitA, iterValA->first);
			iterWaitA->second.push_front(iterValB->first);
		}

		iterValA++;
		iterValB++;
	}

#ifdef LOG
	std::cout << std::endl;
	std::cout << "Info WatingLst" << std::endl;
	for (
		std::list<std::pair<int, std::list<int> > >::const_iterator iter = waitingLst.begin();
		iter != waitingLst.end();
		iter++
	) {
		std::cout << "waiting(" << iter->first << ") : "; 
		for (
			std::list<int>::const_iterator iter2 = iter->second.begin();
			iter2 != iter->second.end();
			iter2++
		) {
			std::cout << *iter2 << " ";
		}
		std::cout << std::endl;
	}

#endif

	sortByFordJohnson(sortingLst, waitingLst, valLst, startIdx, midIdx - 1);

	std::list<std::pair<int, int> >::iterator iterBase = sortingLst.begin();
	std::list<std::pair<int, int> >::iterator iterMid = sortingLst.begin();
	std::list<std::pair<int, int> >::iterator iterSet = sortingLst.begin();

	std::advance(iterMid, midIdx);
	std::advance(iterSet, midIdx);
	for (; iterBase != iterMid; iterBase++, iterSet++) {
		std::list<std::pair<int, std::list<int> > >::iterator iterWaiting = waitingLst.begin();
#ifdef DEBUG
	std::cout << "iterBase->first:" << iterBase->first << std::endl;
#endif
		std::advance(iterWaiting, iterBase->first);

		if (!iterWaiting->second.empty()) {
			int id = iterWaiting->second.front();
			std::list<int>::iterator valueIter = valLst.begin();
			std::advance(valueIter, id);
			*iterSet = std::pair<int, int>(id, *valueIter);
			iterWaiting->second.pop_front();
		}
	}

	int jsNumStart;
	int jsNumEnd = jacobsthalNumber(0);
	int n = 0;
	while (true) {
		jsNumStart = jsNumEnd;
		if (jsNumStart >= sortSize / 2)
			break;
		jsNumEnd = std::min(jacobsthalNumber(n + 1), midIdx);

		int addFrontCnt = 0;
		for (int idx = jsNumEnd - 1; idx >= jsNumStart; idx--) {
			std::list<std::pair<int, int> >::iterator iterCompare = sortingLst.begin();
			std::list<std::pair<int, int> >::iterator iterMid = sortingLst.begin();
			std::list<std::pair<int, int> >::iterator iterSorting = sortingLst.begin();
		
			std::advance(iterSorting, midIdx + idx + addFrontCnt);
			std::advance(iterMid, midIdx + jsNumStart);

			for (; iterCompare != iterMid; iterCompare++) {
				if (iterCompare->second >= iterSorting->second) {
					sortingLst.insert(iterCompare, *iterSorting);
					sortingLst.erase(iterSorting);
					break;
				}
			}

			if (iterCompare == iterMid) {
				sortingLst.insert(iterCompare, *iterSorting);
				sortingLst.erase(iterSorting);
			}
			addFrontCnt++;
		}

		n++;
	}

	if (solo) {
		std::list<std::pair<int, int> >::iterator iterCompare = sortingLst.begin();
		std::list<std::pair<int, int> >::iterator iterSorting = sortingLst.begin();
		// for (int idx = 0; idx < midIdx && iterB != sortingLst.end(); ++idx, ++iterB);
		std::advance(iterSorting, endIdx);

		for (; iterCompare != iterSorting; iterCompare++) {
			if (iterCompare->second >= iterSorting->second) {
				sortingLst.insert(iterCompare, *iterSorting);
				sortingLst.erase(iterSorting);
				break;
			}
		}
	}
}

std::string PmergeMe::toString(const std::list<int> &lst) {
	std::stringstream ss;

	if (lst.size() > 0) {
		ss << *(lst.begin());
	}

	std::list<int>::const_iterator iter = lst.begin();
	
    if (++iter != lst.end()) {
        while (iter != lst.end()) {
            ss << " " << *iter;
            ++iter;
        }
    }

	return ss.str();
}

int PmergeMe::jacobsthalNumber(int n) {
    int a = 0, b = 1;

    for (int i = 2; i <= n; ++i) {
        int temp = b;
        b = a + 2 * b;
        a = temp;
    }
    
	return n == 0 ? a : b;
}