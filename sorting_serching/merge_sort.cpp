#include <iostream>
using namespace std;

void mergeArrays(int x[], int y[], int a[], int s, int e)
{
    int mid = (e + s) / 2, m = s, n = mid+1, k = s;

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

int main()
{
    system("clear");
    int n = 8;
    int arr[] = {5, 4, 3, 2, 1,-5,-6,0};
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
