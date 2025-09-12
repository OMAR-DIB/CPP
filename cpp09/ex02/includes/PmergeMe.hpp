#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <climits>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <list>
#include <sys/time.h>
#include <iomanip>
#include <algorithm>

extern int comparisonCounter;

class PmergeMe
{
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);

	template <typename Container>
	void loadInput(char **av, Container &data);

	template <typename Container>
	void ensureUnique(const Container &data);

	template <typename Container>
	int findInsertPosition(const Container &sorted, int value, int high);

	std::vector<int> buildJacobsthal(int n);
	std::vector<int> adjustJacobIndices(const std::vector<int> &jacob, int pendSize);

	template <typename Container>
	void mergePend(Container &main, Container &pend);

	template <typename Container>
	Container fordJohnsonSort(Container data);
};

template <typename Container>
void PmergeMe::loadInput(char **av, Container &data)
{
	for (int i = 1; av[i]; ++i)
	{
		std::string token = av[i];
		std::stringstream ss(token);
		std::string number;

		while (ss >> number)
		{
			if (number.empty())
				continue;

			// validate digits
			for (size_t j = 0; j < number.size(); j++)
			{
				if (!isdigit(number[j]) && !(j == 0 && number[j] == '+'))
				{
					throw std::runtime_error("Invalid input: " + number);
				}
			}

			
			long value = std::atol(number.c_str());
			if (value < 0 || value > INT_MAX)
			{
				throw std::runtime_error("Out of range: " + number);
			}

			data.push_back(static_cast<int>(value));
		}
	}
}

template <typename Container>
void PmergeMe::ensureUnique(const Container &data)
{
	std::set<int> seen;
	typename Container::const_iterator it;
	for (it = data.begin(); it != data.end(); ++it)
	{
		if (!seen.insert(*it).second)
		{
			throw std::runtime_error("Duplicate found");
		}
	}
}

template <typename Container>
int PmergeMe::findInsertPosition(const Container &sorted, int value, int high)
{
	int low = 0;
	if (high >= static_cast<int>(sorted.size()))
	{
		high = static_cast<int>(sorted.size()) - 1;
	}

	while (low <= high)
	{
		int mid = (low + high) / 2;
		comparisonCounter++;
		if (sorted[mid] == value)
			return mid;
		else if (sorted[mid] > value)
			high = mid - 1;
		else
			low = mid + 1;
	}

	return low;
}

template <typename Container>
void PmergeMe::mergePend(Container &main, Container &pend)
{
	if (pend.empty())
		return;

	// Insert first pend at front
	main.insert(main.begin(), pend[0]);

	std::vector<int> jacob = buildJacobsthal(pend.size());
	std::vector<int> order = adjustJacobIndices(jacob, pend.size());

	int searchLimit = 3;
	for (size_t i = 0; i < order.size(); i++)
	{
		if (i > 0 && order[i] > order[i - 1])
		{
			searchLimit = 2 * searchLimit + 1;
		}

		int idx = order[i] - 1;
		if (idx < (int)pend.size() && idx > 0)
		{
			int val = pend[idx];
			int pos = findInsertPosition(main, val, searchLimit - 1);
			main.insert(main.begin() + pos, val);
		}
	}
}

template <typename Container>
Container PmergeMe::fordJohnsonSort(Container data)
{
	if (data.size() <= 1)
		return data;

	if (data.size() == 2)
	{
		comparisonCounter++;
		if (data[0] > data[1])
			std::swap(data[0], data[1]);
		return data;
	}

	Container main;
	Container pend;

	// split into main + pend
	for (size_t i = 0; i + 1 < data.size(); i += 2)
	{
		comparisonCounter++;
		if (data[i] > data[i + 1])
		{
			main.push_back(data[i]);
			pend.push_back(data[i + 1]);
		}
		else
		{
			pend.push_back(data[i]);
			main.push_back(data[i + 1]);
		}
	}

	bool hasOdd = (data.size() % 2 == 1);
	if (hasOdd)
		pend.push_back(data.back());

	// recursively sort main
	Container sortedMain = fordJohnsonSort(main);

	// realign pend
	Container alignedPend(sortedMain.size());
	for (size_t i = 0; i < sortedMain.size(); i++)
	{
		for (size_t j = 0; j < main.size(); j++)
		{
			if (sortedMain[i] == main[j])
			{
				alignedPend[i] = pend[j];
				break;
			}
		}
	}
	if (hasOdd)
		alignedPend.push_back(pend.back());

	// insert pend into sorted main
	mergePend(sortedMain, alignedPend);

	return sortedMain;
}

#endif