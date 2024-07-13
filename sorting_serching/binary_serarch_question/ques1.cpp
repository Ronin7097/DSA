// Find first and last position of an element in a sorted array
#include <iostream>
#include <vector>
using namespace std;
int binary_search(vector<int> const &v, int const &target, int  s, int  e)
{
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (v[mid] == target)
            return mid;
        else if (v[mid] < target)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return -1;
}
void solve2(vector<int> const &v, int const &target)
{
    int ans = -1, s = 0, e = v.size() - 1, mid = s + (e - s) / 2;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (v[mid] == target)
        {
            ans = mid;
            cout<<ans<<endl;
            cout << binary_search(v, target, 0, mid - 1) << " " << binary_search(v, target, mid - 1, e);
            return;
        }
        else if (v[mid] > target)
            e = mid - 1;
        else s = mid + 1;
    }
}
void solve(vector<int> const &v, int const &n)
{
    int s = 0, e = v.size() - 1;
    while ((v[s] != n || v[e] != n))
    {
        if (v[s] != n)
            s++;
        if (v[e] != n)
            e--;
        if (s > e)
        {
            s = -1;
            e = -1;
            break;
        }
    }
    cout << s << " " << e << endl;
}
int main(void)
{
    system("clear");
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter elements : ";
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int key = 0;
    cout << "Enter a number to find : ";
    cin >> key;
    solve2(v, key);
    return 0;
}