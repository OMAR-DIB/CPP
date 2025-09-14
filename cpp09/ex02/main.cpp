#include "./includes/PmergeMe.hpp"

int comparisonCounter = 0;

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./a.out <numbers>" << std::endl;
        return 1;
    }

    PmergeMe sorter;
    try
    {
        // ------------------------VECTOR
        std::vector<int> vec;
        sorter.loadInput(argv, vec);
        sorter.ensureUnique(vec);

        comparisonCounter = 0;
        double startVec = clock();
        std::vector<int> sorted_vec = sorter.fordJohnsonSort(vec);
        double endVec = clock();
        double time_vec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6;

        std::cout << "Before: ";
        for (int i = 1; i < argc; i++)
            std::cout << argv[i] << " ";
        std::cout << "\nAfter: ";
        for (size_t i = 0; i < sorted_vec.size(); i++)
            std::cout << sorted_vec[i] << " ";

        std::cout << "\nTime to process a range of " << vec.size()
                  << " elements with std::vector : "
                  << std::fixed << std::setprecision(5) << time_vec << " us" << std::endl;
        // std::cout << "Comparisons: " << comparisonCounter << std::endl;
        //  ------------------------DEQUE
        std::deque<int> deq;
        sorter.loadInput(argv, deq);
        sorter.ensureUnique(deq);

        comparisonCounter = 0;
        double startDeq = clock();
        std::deque<int> sorted_deq = sorter.fordJohnsonSort(deq);
        double endDeq = clock();

        double time_deq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;
        std::cout << "Before: ";
        for (int i = 1; i < argc; i++)
            std::cout << argv[i] << " ";
        std::cout << "\nAfter: ";
        for (size_t i = 0; i < sorted_deq.size(); i++)
            std::cout << sorted_deq[i] << " ";
        std::cout << "\nTime to process a range of " << deq.size()
                  << " elements with std::deque : "
                  << std::fixed << std::setprecision(5) << time_deq << " us" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}