#include <iostream>
#include <vector>
using namespace std;
class PriorityQueue
{
    vector<int> pq;
    int minIndex(int i, int j)
    {
        if (pq[i] > pq[j])
            return j;
        else
            return i;
    }

    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

public:
    PriorityQueue() {}
    bool isEmpty() { return pq.size() == 0; }
    int getSize() { return pq.size(); }
    int getMin()
    {
        if (isEmpty())
            return 0;
        return pq[0];
    }
    void insert(int num)
    {
        pq.push_back(num);
        int ci = pq.size() - 1, root = 0;
        while (ci >= 0)
        {
            root = (ci - 1) / 2;
            if (pq[root] > pq[ci])
            {
                swap(pq[root], pq[ci]);
                ci = root;
            }
            else
                break;
        }
    }
    int RemoveMin()
    {
        if (isEmpty())
            return 0;
        int ans = pq[0];
        swap(pq[0], pq[pq.size() - 1]);
        pq.pop_back();
        int curr = 0;
        while (true)
        {
            int lci = 2 * curr + 1;
            int rci = 2 * curr + 2;
            int min1 = curr;

            if (pq.size() > lci && pq[lci] < pq[min1])
                min1 = lci;
            if (pq.size() > rci && pq[rci] < pq[min1])
                min1 = rci;

            if (min1 == curr)
                break;
            swap(pq[curr], pq[min1]);
            curr = min1;
        }
        return ans;
    }
    void print()
    {
        for (int i = 0; i < pq.size(); i++)
            cout << pq[i] << " ";

        cout << endl;
    }
};