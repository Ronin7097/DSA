#include <iostream>
using namespace std;

class Stack
{
    int *arr; // dynamic array
    int nextindex;
    int cap;

public:
    Stack()
    {
        arr = new int[4];
        cap = 4;
        nextindex = 0;
    }
    Stack(int cap)
    {
        arr = new int[cap];
        this->cap = cap;
        nextindex = 0;
    }
    int size() { return nextindex; }
    bool isEmpty() { return nextindex == 0; }
    void push(int val)
    {
        if (cap <= nextindex)
        {
            cout << "Memory out of bound ";
            return;
        }
        arr[nextindex++] = val;
    }
    void pop()
    {
        if (isEmpty())
        { 
            cout << "Stack underflow" << endl;
            return;
        }
        nextindex--;
    }
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return -1;
        } 
        return arr[nextindex - 1];
    }
};
