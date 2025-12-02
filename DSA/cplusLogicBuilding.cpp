#include <iostream>
#include <numeric>
#include <iterator>
using namespace std;

int average(int arr[5]);

int main(void)
{
    // std::array<int, 5> arr = {3, 5, 5, 6, 5};
    int arr[5] = {3, 5, 5, 6, 5};
    printf("\i", average(arr));

    return 0;
}

int average(int arr[5])
{

    int init = 0;
    return std::accumulate(arr, arr + (sizeof(arr) / sizeof(*arr)), init) / (sizeof(arr) / sizeof(*arr));
}