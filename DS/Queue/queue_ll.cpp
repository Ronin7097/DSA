#include <iostream>
using namespace std;
template <typename T>
class Queue
{
    class Node
    {
    public: 
        T data;
        Node *next;
        Node() : data(0), next(NULL) {}
        Node(T data) : data(data), next(NULL) {}
    };
    int size1;
    Node *head, *tail;

public:
    Queue() : size1(0), head(NULL), tail(NULL) {}
    int size() { return size1; }
    int empty() { return size1 == 0; }

    void push(T data)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = n; // tail=tail->next;
        }
        size1++;
    }

    T front()
    {
        if (empty())
        {
            cout << "Empty queue" << endl;
            return 0;
        }
        return head->data;
    }

    void pop()
    {
        if (empty())
        {
            cout << "Empty queue" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        temp->next = NULL; // Isolation
        delete temp;
        size1--;
    }
    void print()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};