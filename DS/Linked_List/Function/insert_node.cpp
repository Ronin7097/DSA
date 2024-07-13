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
            tail = n; // tail=tail->next;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    while(head != NULL)
    {
        cout << head->data <<" ";
        head=head->next;
    }
    cout<<endl;
}

void insert(Node *&head, int data, int i)
{
    Node *n = new Node(data);
    if(i==0)
    {
        n->next = head;
        head=n;
        return;
    }
    Node *temp=head;
    int count = 1;
    while (temp != NULL)
    {
        if (count == i)
            break;
        count++;
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
}

void delete_node(Node *&head,int i)
{
    Node *temp;
    if(i==0 && head)
    {
        temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        return;
    }
    int count = 1;
    temp=head;
    while(temp != NULL && count<=i-1)
    {
        temp=temp->next;
        count++;
    } 
    if(temp &&temp->next){
    Node*temp2=temp->next;
    temp->next = temp->next->next;
    temp2->next=NULL;
    delete temp2;
    }
}

int main(void)
{
    system("clear");
    Node *head = take_input();
    print(head);
    insert(head,-5,length(head));
    print(head);
    delete_node(head,2);
    print(head);
    return 0;
}