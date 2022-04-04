#include <vector>
#include <iostream>
using namespace std;

vector<int> insert_sort(vector<int>& A)
{
    for (int j = 1; j < A.size(); j++)
    {
        // save the value of the one to be sort to another variable
        int key = A[j];
        // i means the index before j
        int i = j - 1;
        // if the before(A[i]) > the value to be sort(A[j]), then exchage them
        while (i >= 0 && A[i] > key)
        {
            // then move one step forward one by one
            A[i + 1] = A[i];
            // move from left to right
            i--;
        }
        // move the one to be sort to the space left by moving
        // i + 1 in here equals to i above (as there is i-- at last)
        A[i + 1] = key;
    }
    return A;
}


// TEST

// int main()
// {
//     vector<int> test = {3, 2, 5, 1};
//     for (int a : insert_sort(test))
//     {
//         cout << a << "\n";
//     }
//     return 0;
// }