#include <iostream>
#include <vector>

using namespace std;

void swap(int &x, int &y)
{
    x = x ^ y; 
    y = x ^ y; 
    x = x ^ y; 
}

void Selection_sort(vector<int> &v) 
{

    int min = 0,n=v.size();
    for (int i = 0; i < n-1; i++)
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

// driver code
int main()
{
    system("clear");
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

    Selection_sort(v); // main sorting fuction

    cout << "SORTED : ";
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}