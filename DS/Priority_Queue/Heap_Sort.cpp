#include <iostream>
#include <vector>
using namespace std;

void heap_sort(vector<int> &v)
{
    //build heap array
    int insert_ptr = 1;
    int root, ci;
    while (insert_ptr < v.size())
    {
        ci = insert_ptr;
        root = (ci - 1) / 2;
        while (ci >= 0 && ci != root)
        {
            if (v[root] < v[ci])
            {
                swap(v[root], v[ci]);
                ci = root;
            }
            else    
                break;
            root = (ci - 1) / 2;
        }
        insert_ptr++;
    }

    // removeMin
    int remove_ptr = v.size();
    int curr = 0, lci, rci, min1;
    while (remove_ptr > 0)
    {
        swap(v[remove_ptr - 1], v[0]);
        remove_ptr--;
        curr = 0;
        while (true)
        {
            lci = 2 * curr + 1;
            rci = 2 * curr + 2;
            min1 = curr;
            if (remove_ptr > lci && v[lci] > v[min1])
                min1 = lci;
            if (remove_ptr > rci && v[rci] > v[min1])
                min1 = rci;
            if (min1 == curr)
                break;
            swap(v[curr], v[min1]);
            curr = min1;
        }
    }
}
int main()
{
    system("clear");
    cout << "Enter the size of the array : ";
    int size;
    cin >> size;
    vector<int> v;
    for (int i = size; i >= 0; i--)
    {
        v.push_back(rand() % size + 1);
    }
    cout << "Unsorted Numbers: ";
    for (int i = 0; i < v.size(); i++)
        cout << v.at(i) << " ";
    cout << endl;
    heap_sort(v);
    cout << "Sorted Numbers: ";
    for (int i = 0; i < v.size(); i++)
        cout << v.at(i) << " ";
    return 0;
}