# include "PmergeMe.hpp"

bool isPositiveNumber(const char* str) {
    const char* ptr = str;
    while (*ptr != '\0') 
    {
        if (!isdigit(*ptr))
        {
            return false;
        }
        ptr++;
    }
    int num = atoi(str);
    return num > 0;
}

bool allPositiveNumbers(int argc, char **argv) 
{
    for (int i = 1; i < argc; i++) {
        if (!isPositiveNumber(argv[i])) {
            return false;
        }
    }
    return true;
}



template <typename Container>
void sort_insert(Container & my_container, int start, int mid , int end)
{
    int i = start;
    int j = mid + 1;
    int k = start;
    int tmp[end + 1];

    while(i <= mid && j <= end)
    {
        if(my_container[i] <= my_container[j])
        {
            tmp[k] = my_container[i];
            k++;
            i++;     
        }
        else
        {
            tmp[k] = my_container[j];
            k++;
            j++;
        }
    }
    while(i <= mid)
    {
        tmp[k] = my_container[i];
        k++;
        i++;
    }
    while(j <= end)
    {
        tmp[k] = my_container[j];
        k++;
        j++;
    }
    for(int a = start; a <= end; a++)
    {
        my_container[a] = tmp[a];
    }
}

void mergeInsertionSortvector(std::vector<int> &vector, int start, int end)
{
    if(start < end)
    {
        int mid;
        mid = (start + end) / 2;
        mergeInsertionSortvector(vector, start, mid);
        mergeInsertionSortvector(vector, mid + 1, end);
        sort_insert(vector, start, mid, end);
    }
}

void mergeInsertionSortdeque(std::deque<int> &deque, int start, int end)
{
    if(start < end)
    {
        int mid;
        mid = (start + end) / 2;
        mergeInsertionSortdeque(deque, start, mid);
        mergeInsertionSortdeque(deque, mid + 1, end);
        sort_insert(deque, start, mid, end);
    }
}

void sort_deque(int ac, char **av)
{
    std::deque<int> deque;
    clock_t start = clock();
    // int j = 1;

    for (int i = 1; i < ac; i++)
    {
        deque.push_back(atoi(av[i]));
    }
    mergeInsertionSortdeque(deque, 0, deque.size() - 1);
    
    std::cout << "After: ";
    // if (ac > 6)
    // {
    //     for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
    //         {
    //             if (j == 5)
    //             {
    //                 std::cout << "[..]";
    //                 break;
    //             }
    //             std::cout << *it << " ";
    //             j++;
    //         }
    // }
    // else
    // {
    //     for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
    //     {
    //         std::cout << *it << " ";
    //     }

    // }
    // std::cout << std::endl;
    clock_t end = clock();
    std::cout << "Time to process a range of " << (ac - 1) << \
     " elements with std::deque : " << (double)(end - start) / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;
}

void    sort_vector(int ac, char **av)
{
    std::vector<int> vector;
    int j = 1;
    
    clock_t start = clock();

    for (int i = 1; i < ac; i++)
    {
        vector.push_back(atoi(av[i]));
    }

    mergeInsertionSortvector(vector, 0, ac - 2);
    std::cout << "After: ";
    if (ac > 6)
    {
        for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
            {
                if (j == 5)
                {
                    std::cout << "[..]";
                    break;
                }
                std::cout << *it << " ";
                j++;
            }
    }
    else
    {
        for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
        {
            std::cout << *it << " ";
        }
    }
    std::cout << std::endl;
    clock_t end = clock();
    std::cout << "Time to process a range of " << (ac - 1) << \
     " elements with std::vector : " << (double)(end - start) / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;
}
