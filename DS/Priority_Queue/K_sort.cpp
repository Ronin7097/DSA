#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    system("clear");
    vector<int> v;
    priority_queue<int> pq;
    int k;
    cout << "Enter the array press -1 to exit :";
    while (k != -1)
    {
        cin >> k;
        v.push_back(k);
    }
    v.pop_back();
    cout << "Enter the value of k shift : ";
    cin >> k;
    if (k > v.size())
    {
        cout << "invalid value of k shift ";
        return 0;
    }
    for (int i = 0; i < k; i++)
        pq.push(v.at(i));

    int i = 0;
    while (!pq.empty())
    {
        if (k < v.size())
            pq.push(v.at(k));

        v[i] = pq.top();
        pq.pop();
        i++;
        k++;
    }

    cout << "After sorting : ";
    for (int a = 0; a < v.size(); a++)
        cout << v.at(a) << " ";
}