#include <iostream>
#include <vector>
using std::cout; using std::cin;
using std::vector;

unsigned binarySearch(const vector<int>& lst, int target)
{
    unsigned beg = 0, end = lst.size();
    unsigned mid = beg + (end - beg) / 2;
    while (beg != end && lst[mid] != target) {
        if (lst[mid] > target)
            end = mid;
        else
            beg = mid + 1;
        mid = beg + (end - beg) / 2;

    }
    return mid;
}

