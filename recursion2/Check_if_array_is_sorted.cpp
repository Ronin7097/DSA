#include <iostream>
#include <vector>
using namespace std;

bool check_sort(vector<int> &v)
{
    int n = v.size();
    if (n == 1 || n == 0)
        return true;

    if (v[0] < v[1])
    {
        v.erase(v.begin());
        return check_sort(v);
    }
        return false;
}
// driver code
int main()
{
    system("clear");
    int n = 0;
    cout << "Enter a number : ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
        cin >> v[i];

    cout << "SORTRD: " << check_sort(v) << endl;
}