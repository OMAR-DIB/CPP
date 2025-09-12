#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		(void)other;
	}
	return *this;
}

std::vector<int> PmergeMe::buildJacobsthal(int n)
{
	std::vector<int> seq;
	int j0 = 0, j1 = 1;

	while (true)
	{
		int next = j1 + 2 * j0;
		if (next > n)
			break;
		seq.push_back(next);
		j0 = j1;
		j1 = next;
	}
	return seq;
}

std::vector<int> PmergeMe::adjustJacobIndices(const std::vector<int> &jacob, int pendSize)
{
	std::vector<int> order;
	std::set<int> used;

	for (size_t i = 0; i < jacob.size(); i++)
	{
		int j = jacob[i];
		while (j > 1)
		{
			if (used.find(j) == used.end())
			{
				order.push_back(j);
				used.insert(j);
			}
			j--;
		}
	}

	// fill missing indices
	for (int x = pendSize; (int)order.size() < pendSize; x--)
	{
		if (used.find(x) == used.end())
		{
			order.push_back(x);
			used.insert(x);
		}
	}

	return order;
}