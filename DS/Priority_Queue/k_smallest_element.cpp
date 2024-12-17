#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    system("clear");
    cout << " Enter a array of integer enter -1 to exit : ";
    int k = 0;
    vector<int> v;
    while (true)
    {
        cin >> k;
        if (k == -1)
            break;
        v.push_back(k);
    }
    cout << "Enter the value of k first smaller elements : ";
    cin >> k;
    priority_queue<int> pq;

    for (int i = 0; i < v.size(); i++)
    {
        pq.push(v.at(i));

        if (pq.size()> k)
            pq.pop();
    }

    cout << "Min Elements : ";
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}