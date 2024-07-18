#include <iostream>
using namespace std;

template <typename T>
class Queue
{
    T *arr;
    int fi, ni, size1,cap;

public:
    Queue() : fi(0), ni(0), cap(4), size1(0) { arr = new T[4]; }
    Queue(int cap) : fi(0), ni(0), cap(cap), size1(0) { arr = new T[cap]; }
    int size() { return size1; }
    bool empty() { return size1 == 0; }

    void push(T data)
    {

        if (cap <= size())
        {
            int count = 0;
            T *arr1 = new T[cap * 2];
            for (int i = fi; i < cap; i++)
                arr1[count++] = arr[i];
            for (int i = 0; i < fi; i++)
                arr1[count++] = arr[i];
            delete[] arr;
            arr = arr1;
            fi = 0;
            ni = size();
            cap *= 2;
        }
        arr[ni] = data;
        ni = (ni + 1) % cap;
        size1++;
    }

    T front()
    {
        if (empty())
        {
            cout << "Empty queue" << endl;
            return 0;
        }
        return arr[fi];
    }

    void pop()
    {
        if (empty())
        {
            ni = 0;
            fi = 0;
            cout << "Empty queue" << endl;
            return;
        }
        fi = (fi + 1) % cap;
        size1--;
    }
    void print()
    {
        for (int i = 0; i < cap; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};