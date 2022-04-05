#include <vector>
#include <iostream>
#include <climits>
using namespace std;

void merge_sort(vector<int>& A, int left1, int right1, int right2)
{
    // conditon is that A[left1..right1] and A[right1 + 1..right2]
    // are already sorted

    // length of the left vector (use `sentinel` to escape too many judgement)
    // so length plus 1
    int l_length = right1 - left1 + 1;
    int r_length = right2 - right1;

    vector<int> L;
    vector<int> R;

    // fill Left Array
    for (int i = left1; i < right1 + 1; i++)
    {
        L.push_back(A[i]);
    }
    //fill Right Array
    for (int j = right1 + 1; j < right2 + 1; j++)
    {
        R.push_back(A[j]);
    }

    // append a sentinel
    L.push_back(INT_MAX);
    R.push_back(INT_MAX);

    // realize merge
    int k = 0;
    int s = 0;
    for (int m = left1; m <= right2; m++)
    {
        if (L[k] <= R[s])
        {
            A[m] = L[k];
            k++;
        }
        else
        {
            A[m] = R[s];
            s++;
        }
    }
}

// use recursive to devide big into small
void devide_merge(vector<int>& A, int left, int right)
{
    if (left < right)
    {
        int mid  = (left + right) / 2;
        devide_merge(A, left, mid);
        devide_merge(A, mid + 1  , right);
        merge_sort(A, left, mid, right);
    }
}

// Test

// int main()
// {
//     vector<int> a = {2, 1, 4, 2, 6};
//     devide_merge(a, 0, a.size() - 1);
//     for (int n : a)
//     {
//         cout << n << "\n" << endl;
//     }
//     return 0;
// }