#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <algorithm>
#include <queue>
#include <time.h>

bool    isPositiveNumber(const std::string& str);
bool    allPositiveNumbers(int argc, char **argv);
void    sort_vector(int ac, char **av);
void    mergeInsertionSortvector(std::list<int> &list, int start, int end);
void    mergeInsertionSortdeque(std::deque<int> &deque, int start, int end);
// void    sort_queue(int ac, char **av);
void    sort_deque(int ac, char **av);
void    sortqueue(std::queue<int> &queue);
int     minIndex(std::queue<int> &queue , int i);
void    insertMinToRear(std::queue<int> &queue, int min_index);
void    printQueue(const std::queue<int>& q);

#endif 