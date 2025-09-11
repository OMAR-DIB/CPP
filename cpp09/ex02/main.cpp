#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <climits>
#include <sstream>
#include <stdexcept>
#include <cstdlib> // for atoi
#include <list>
#include <sys/time.h>

int comparisonCounter = 0; // global counter for comparisons

// ==========================================================
// 1. Input Handling
// ==========================================================
template <typename Container>
void loadInput(char **av, Container &data)
{
    for (int i = 1; av[i]; ++i)
    {
        std::string token = av[i];
        std::stringstream ss(token); // creates a stringstream object ss and initializes it with the string token
        std::string number;

        while (ss >> number)
        { // is a loop that extracts data from the stringstream ss
            if (number.empty())
                continue;

            // TODO :
            // validate digits
            for (size_t j = 0; j < number.size(); j++)
            {
                if (!isdigit(number[j]) && !(j == 0 && number[j] == '+'))
                {
                    throw std::runtime_error("Invalid input: " + number);
                }
            }

            // convert to int (C++98 friendly)
            long value = std::atol(number.c_str());
            if (value < 0 || value > INT_MAX)
            {
                throw std::runtime_error("Out of range: " + number);
            }

            data.push_back(static_cast<int>(value));
        }
    }
}

// ==========================================================
// 2. Duplicate Checking
// ==========================================================
template <typename Container>
void ensureUnique(const Container &data)
{
    std::set<int> seen;
    typename Container::const_iterator it;
    for (it = data.begin(); it != data.end(); ++it)
    {
        if (!seen.insert(*it).second)
        { // second : It's false if the element was not inserted because a duplicate was already present in the set.
            throw std::runtime_error("Duplicate found");
        }
    }
}

// ==========================================================
// 3. Binary Search Insert Helper
// ==========================================================
template <typename Container>
int findInsertPosition(const Container &sorted, int value, int high)
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

// ==========================================================
// 4. Jacobsthal Sequence Generator
// ==========================================================
std::vector<int> buildJacobsthal(int n)
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

// ==========================================================
// 5. Reindex Jacob Order
// ==========================================================
std::vector<int> adjustJacobIndices(const std::vector<int> &jacob, int pendSize)
{
    std::vector<int> order;
    std::set<int> used;

    for (size_t i = 0; i < jacob.size(); i++)
    {
        int j = jacob[i];
        while (j > 1)
        {
            if (used.find(j) == used.end())
            { // if j is not in used
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
        { // if x is not in used
            order.push_back(x);
            used.insert(x);
        }
    }

    return order;
}

// ==========================================================
// 6. Insert pend elements into main
// ==========================================================
template <typename Container>
void mergePend(Container &main, Container &pend)
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

// ==========================================================
// 7. Recursive Ford-Johnson Sort
// ==========================================================
template <typename Container>
Container fordJohnsonSort(Container data)
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
    Container alignedPend(sortedMain.size()); // have a size equal to the number of elements in another container, sortedMain.
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

double getTime() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return t.tv_sec * 1e6 + t.tv_usec;
}

// ==========================================================
// 8. Main
// ==========================================================
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./a.out <numbers>" << std::endl;
        return 1;
    }

    try
    {
        std::deque<int> vec;
        loadInput(argv, vec);
        ensureUnique(vec);

        comparisonCounter = 0;
        double startVec = getTime();
        std::deque<int> sorted = fordJohnsonSort(vec);
        double endVec = getTime();
        std::cout << "Before: ";
        for (int i = 1; i < argc; i++)
            std::cout << argv[i] << " ";
        std::cout << "\nAfter: ";
        for (size_t i = 0; i < sorted.size(); i++)
            std::cout << sorted[i] << " ";

             std::cout << " \n Time to process a range of " << vec.size()
                  << " elements with std::vector : "
                  << (endVec - startVec) << " us" << std::endl;
        std::cout << "\nComparisons: " << comparisonCounter << std::endl;
        //std::cout << "/////////////////////////////////////vector//////////////////////////////////////" << std::endl;
        //std::vector<int> vecv;
        //loadInput(argv, vecv);
        //ensureUnique(vecv);

        //comparisonCounter = 0;
        //std::vector<int> sortedv = fordJohnsonSort(vecv);

        //std::cout << "Before: ";
        //for (int i = 1; i < argc; i++)
        //    std::cout << argv[i] << " ";
        //std::cout << "\nAfter: ";
        //for (size_t i = 0; i < sortedv.size(); i++)
        //    std::cout << sortedv[i] << " ";
        //std::cout << "\nComparisons: " << comparisonCounter << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
