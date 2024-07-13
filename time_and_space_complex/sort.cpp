#include <iostream>
#include <vector>
using namespace std;

class Sort
{
    void swap(int &x, int &y)
    {
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
    }
    void mergeArrays(int x[], int y[], int a[], int s, int e)
    {
        int mid = (e + s) / 2, m = s, n = mid + 1, k = s;

        while (m <= mid && n <= e)
        {
            if (x[m] >= y[n])
                a[k++] = y[n++];
            else
                a[k++] = x[m++];
        }

        while (m <= mid)
            a[k++] = x[m++];
        while (n <= e)
            a[k++] = y[n++];
    }
    int partion(int a[], int s, int e)
    {
        int i = s, pivoit = a[e];

        for (int j = s; j <= e - 1; j++)
        {
            if (a[j] < pivoit)
            {
                swap(a[i], a[j]);
                i++;
            }
        }
        swap(a[i], a[e]);
        return i;
    }

public:
    // most optimise bubble sort
    void bubble_sort(vector<int> &v)
    {
        int n = v.size(), flag = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            flag = 0;
            for (int j = 0; j < i; j++) // very optimized for loop for n*(n-1)/2
            {
                if (v.at(j) > v.at(j + 1))
                {
                    swap(v[j], v[j + 1]);
                    flag = 1;
                }
            }
            if (flag == 0) // if no swaping in first itreation then break
                break;     // as array is already sorted
        }
    }

    void mergeSort(int a[], int s, int e)
    {
        if (s >= e)
            return;

        int mid = (e + s) / 2;
        int x[e + 1], y[e + 1];
        for (int i = 0; i <= mid; i++)
            x[i] = a[i];
        for (int i = mid + 1; i <= e; i++)
            y[i] = a[i];

        mergeSort(x, s, mid);
        mergeSort(y, mid + 1, e);
        mergeArrays(x, y, a, s, e);
    }

    void quickSort(int a[], int s, int e)
    {
        if (s >= e)
            return;
        int p = partion(a, s, e);
        quickSort(a, s, p - 1);
        quickSort(a, p + 1, e);
    }

    void Selection_sort(vector<int> &v)
    {

        int min = 0, n = v.size();
        for (int i = 0; i < n - 1; i++)
        {
            min = i;
            for (int j = i + 1; j < n; j++)
            {
                if (v[j] < v[min])
                    min = j;
            }
            if (i != min)
                swap(v[i], v[min]);
        }
    }
};
