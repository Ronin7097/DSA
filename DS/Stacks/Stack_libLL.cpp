#include <iostream>
using namespace std;
template <typename T>
class Stack
{
    class Node
    {
    public:
        T data;
        Node *next;
        Node(T data) : data(data), next(NULL) {}
    };
    int count;
    Node *head;

public:
    Stack() : count(0), head(NULL) {}
    int size() { return count; }
    bool empty() { return count == 0; }
    void push(T data)
    {
        Node *n = new Node(data);
        n->next = head;
        head = n;
        count++;
    }
    void pop()
    {
        if (empty())
        {
            cout << "Empty Stack" << endl;
            return;
        }
        count--;
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    T top()
    {
        if (empty())
        {
            cout << "Empty Stack" << endl;
            return 0;
        }
        return head->data;
    }

    void print()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout<<endl;
    }
};