// Search in rotated soted array
#include <iostream>
#include <vector>
using namespace std;
int min_in = 0;

void min1(vector<int> const &v)
{
    int min = v[0], in = 0;
    for (int i = 1; i < v.size(); i++)
    {
        if (min > v[i])
        {
            min = v[i];
            in = i;
        } 
    }
    min_in = in;
}
int rotate(vector<int> const &v, int i)
{
    int oi = min_in + i;
    if (oi > v.size() - 1)
        oi = oi - v.size();
    return oi;
}

int binary_rotate(vector<int> const &v, int const &target)
{
    min1(v);
    int s = 0, e = v.size() - 1, mid = s + (e - s) / 2;

    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (v.at(rotate(v, mid)) == target)
            return rotate(v, mid);
        else if (v.at(rotate(v, mid)) > target)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return -1;
}

int main()
{
    system("clear");
    int target = 0, n = 0;
    cout << "Enter the number of elements : ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter Elements : ";
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout<<"Enter the target : ";
    cin>> target;
    cout<< "Answer : "<<binary_rotate(v, target);
    return 0;
}