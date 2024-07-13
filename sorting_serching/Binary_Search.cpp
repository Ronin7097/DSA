#include <iostream>
#include <vector>
using namespace std;

void swap(int &x, int &y)
{
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}

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

// binary search
int binary_search(vector<int> const &v, int const &key)
{
    int s = 0, e = v.size() - 1, mid = (s + e) / 2;
    while (s <= e)
    {
        if (v[mid] == key)
            return mid;
        else if (v[mid] > key)
            e = mid - 1;
        else
            s = mid + 1;
        mid = s + (e - s) / 2;//will prevent integer overflow
    }
    return -1;
}

// driver code
int main()
{
    vector<int> v;
    int n = 0, temp;
    cout << "enter the size of the array : ";
    cin >> n;
    cout << "Enter the value of the array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    int key = 0;
    cout << "Enter the Element to found : ";
    cin >> key;

    bubble_sort(v); // main sorting fuction
    int o = binary_search(v, key);

    if (o >= 0)
        cout << "Element found after sorting it will be present at index : " << o + 1 << endl;
    else
        cout << "Element not found " << endl;
    return 0;
}
