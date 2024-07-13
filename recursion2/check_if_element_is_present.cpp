#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> &v, int &key)
{
    if(v.size() == 0)
    return false;

    if(v[0] == key)
    return true;
    v.erase(v.begin());

    return check(v, key);
}

int main()
{
    system("clear");
    int n = 0;
    cout << "Enter a number : ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter " << n << " elements : ";
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int key = 0;
    cout << "Enter the key : ";
    cin >> key;

    cout << "Element found : " << check(v, key) << endl;
}