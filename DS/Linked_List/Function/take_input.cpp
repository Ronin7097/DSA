#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void print(Node *const &head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *take_input()
{
    Node *temp;
    int data;
    cin >> data;
    Node *n1 = new Node(data);
    temp = n1;
    while (data != -1)
    {
        cin >> data;
        Node *n2 = new Node(data);
        temp->next = n2;
        temp = temp->next;
    }
    return n1;
}

Node *take_reverse()
{
    Node *head = NULL, *tail = NULL;
    int data;
    cin >> data;

    while (data != -1)
    {
        Node *n1 = new Node(data);
        if (head == NULL)
        {
            head = n1;
            tail = n1;
        }
        else
        {
            n1->next = head;
            head = n1;
        }
        cin >> data;
    }
    return head;
}

void reverse1(Node *&head)
{
    Node *temp1 = head->next;
    head->next = NULL;
    Node *temp2;
    while (temp2 != NULL)
    {
        temp2 = temp1->next;
        temp1->next = head; // connection made
        head = temp1;
        temp1 = temp2;
    }
}

int main(void)
{
    system("clear");
    Node *head = take_input();
    reverse1(head);
    print(head);
    return 0;
}