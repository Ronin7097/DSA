#include <iostream>
#include <chrono>
#include <vector>
#include "sort.cpp"
using namespace std;
using namespace chrono;
int main(void)
{
    system("clear");
    Sort s;
    for (int n = 10; n <= pow(10, 7); n *= 10)
    {
        int *arr = new int[n + 1];
        vector<int> v(n + 1);
        for (int i = 0; i <= n; i++)
        {
            arr[i] = n - i;
            v.push_back(n - i);
        }
        auto start = high_resolution_clock::now();
        //s.mergeSort(arr,0,n);
        //s.quickSort(arr, 0, n);
        //s.bubble_sort(v);
        // s.Selection_sort(v);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        cout << " sort n = " << n << " Time = " << (double)(duration.count() / 1000.0) << endl;
        delete[] arr;
    }
    return 0;
}
