#include <iostream>
using namespace std;

int partion(int a[], int s, int e)
{
    int i = s,pivoit = a[e];

    for (int j = s; j <=e-1; j++)
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

void quickSort(int a[], int s, int e)
{
    if (s >= e)
        return;
    int p = partion(a, s, e);
    quickSort(a, s, p - 1);
    quickSort(a, p + 1, e);
}
int main()
{
    system("clear");
    int arr[] = {5, 2, 1, 7, 3, 4};
    quickSort(arr, 0, 5);
    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";

    return 0;
}