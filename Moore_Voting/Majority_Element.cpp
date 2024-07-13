#include <iostream>
#include <vector>
using namespace std;

int algo(vector<int> const &v)
{
    int candidate = v[0], count = 1;

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] == candidate)
            count++;
        else
            count--;
        if (count == 0)
        {
            candidate = v[i];
            count = 1;
        }
    }

    return candidate;
}
// driver
int main(void)
{
    system("clear");
    int n = 0;
    cout << "Enter the number of Elemetns : ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter Elemetns : " << endl;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout <<"Answer : "<<algo(v) << endl;
    return 0;
}
