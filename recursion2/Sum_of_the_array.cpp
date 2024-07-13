#include <iostream>
#include <vector>
using namespace std;

int sum_of_the_array(vector<int> &v)
{
    if(v.size()==1)
    return v[0];
    int temp=v[0];
    v.erase(v.begin());
    return temp + sum_of_the_array(v);
}

int main()
{
    system("clear");
    int n = 0;
    cout << "Enter a number : ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the elements for the array : ";
    for (int i = 0; i < n; i++)
        cin >> v[i];

    cout << "The sum for the array : " << sum_of_the_array(v) << endl;
    return 0;
}