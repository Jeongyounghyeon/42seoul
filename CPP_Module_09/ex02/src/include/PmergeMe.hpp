#pragma once

#include <list>
#include <deque>
#include <string>

typedef struct s_listSortStruct {
	int value;
	std::list<struct s_listSortStruct*> waiting;
} t_listSortStruct;

typedef struct s_dequeSortStruct {
	int value;
	std::deque<struct s_dequeSortStruct*> waiting;
} t_dequeSortStruct;

class PmergeMe {
	private:
		static const int jacobsthalNumber[33];

		PmergeMe();
		PmergeMe(const PmergeMe& ref);
		virtual ~PmergeMe();

		PmergeMe& operator=(const PmergeMe& ref);

		static int* parseArgument(int argc, char* argv[]);
		static void arrToList(int* arr, size_t size, std::list<int>& list);
		static void arrToDeque(int* arr, size_t size, std::deque<int>& deque);

		static std::list<int> sortList(std::list<int> &lst);
		static std::deque<int> sortDeque(std::deque<int> &v);
		static void outResult(const std::stringstream& beforeDataStream,
								const std::stringstream& afterDataStream,
								const int cnt,
								const double timeForList,
								const double timeForDeque);
		static void sortByFordJohnson(std::list<t_listSortStruct>& sortingList,
									std::list<t_listSortStruct*>& sortedList,
									int sortSize);
		static void sortByFordJohnson(std::deque<t_dequeSortStruct>& sortingDeque,
									std::deque<t_dequeSortStruct*>& sortedDeque,
									int sortSize);
		static int binarySearch(std::deque<t_dequeSortStruct*>& deque,
								int num,
								int low,
								int high);
		static int binarySearch(std::list<t_listSortStruct*>& list,
								int num,
								int low,
								int high);
		static std::string toString(const int* arr, size_t size);
		static std::string toString(const std::list<int> &lst);
		static std::string toString(const std::deque<int> &deque);

	public:
		static void pmergeMe(int argc, char* argv[]);
};