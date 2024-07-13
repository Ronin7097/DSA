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

int length(Node *const &head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

Node *take_input()
{
    Node *head = NULL, *tail = NULL;
    int data;
    cin >> data;
    while (data != -1)
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
            tail = n;
        }
        cin >> data;
    }
    return head;
}

int index(Node *temp, int i)
{
    int count = 0;
    while (temp != NULL)
    {
        if (count == i)
            return temp->data;
        count++;
        temp = temp->next;
    }
    return -1;
}

int main(void)
{
    system("clear");
    Node *head = take_input();
    cout<<endl;
    cout << length(head) << "\n";
    cout<<index(head,2)<<endl;
    return 0;
}