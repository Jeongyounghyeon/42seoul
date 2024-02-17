#pragma once

#include <list>
#include <deque>
#include <string>

class PmergeMe {
	private:
		PmergeMe();
		PmergeMe(const PmergeMe& ref);
		virtual ~PmergeMe();

		PmergeMe& operator=(const PmergeMe& ref);

		static void saveData(std::list<int> &lst,
								std::deque<int> &dq,
								int argc, char* numbers[]) ;
		static std::list<int> sortList(std::list<int> &lst);
		static void outResult(const std::stringstream& beforeDataStream,
								const std::stringstream& afterDataStream,
								const double timeForList,
								const double timeForDeque);
		static void sortByFordJohnson(std::list<std::pair<int, int> >& sortingLst,
									std::list<std::pair<int, std::list<int> > >& waitingLst,
									std::list<int>& id_val,
									int startIdx,
									int endIdx);
		static std::string toString(const std::list<int> &lst);
		static int jacobsthalNumber(int n);

	public:
		static void pmergeMe(int argc, char* numbers[]);
};