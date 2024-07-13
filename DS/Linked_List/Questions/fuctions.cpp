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

class Functions
{
    Node *mid_sort(Node *head)
    {
        Node *temp = head->next;
        while (temp && temp->next)
        {
            head = head->next;
            temp = temp->next->next;
        }
        return head;
    }

public:
    // return length of LL
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
    // Create LL
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
    // print LL
    void print(Node *head)
    {
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }
    // Insert a node
    void insert(Node *&head, int data, int i)
    {
        Node *n = new Node(data);
        if (i == 0)
        {
            n->next = head;
            head = n;
            return;
        }
        Node *temp = head;
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
    // delete node
    void delete_node(Node *&head, int i)
    {
        Node *temp;
        if (i == 0 && head)
        {
            temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            return;
        }
        int count = 1;
        temp = head;
        while (temp != NULL && count <= i - 1)
        {
            temp = temp->next;
            count++;
        }
        if (temp && temp->next)
        {
            Node *temp2 = temp->next;
            temp->next = temp->next->next;
            temp2->next = NULL;
            delete temp2;
        }
    }
    // reverse LL
    void reverse(Node *&head)
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
    // search for data
    int search(Node *head, int key)
    {
        int count = 0;
        while (head != NULL)
        {
            if (head->data == key)
                return count;
            count++;
            head = head->next;
        }
        return -1;
    }
    // return mid of LL
    Node *mid(Node *head)
    {
        Node *temp = head;
        while (head != NULL && head->next != NULL)
        {
            temp = temp->next;       // slow ptr
            head = head->next->next; // fast ptr
        }
        return temp;
    }
    // return Index data
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
    // delete kth node from the back
    void pop_back_kth(Node *&head, int k)
    {
        if (k <= 0)
            return;
        Node *temp = head;
        Node *head1 = head;

        for (int i = 0; i <= k; i++)
        {
            if (head1 == NULL && i == k)
            {
                head = head->next;
                temp->next = NULL;
                delete temp;
                return;
            }
            else if (head1 == NULL)
                return;
            head1 = head1->next;
        }
        while (head1 != NULL)
        {
            head1 = head1->next;
            temp = temp->next;
        }
        Node *temp2 = temp->next;
        temp->next = temp->next->next;
        temp2->next = NULL;
        delete temp2;
    }
    // merge two sorted arrays
    Node *merge(Node *head1, Node *head2)
    {
        Node *ft = NULL, *fh = NULL;
        if (head1->data > head2->data)
        {
            fh = head2;
            head2 = head2->next;
        }
        else
        {
            fh = head1;
            head1 = head1->next;
        }
        ft = fh;
        while (head1 && head2 && ft && fh)
        {
            if (head1->data > head2->data)
            {
                ft->next = head2;
                head2 = head2->next;
            }
            else
            {

                ft->next = head1;
                head1 = head1->next;
            }
            ft = ft->next;
        }

        if (head1)
            ft->next = head1;
        else
            ft->next = head2;
        return fh;
    }
    // sort ll

    Node *merge_sort(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *head2 = mid_sort(head)->next;
        mid_sort(head)->next = NULL;
        return merge(merge_sort(head), merge_sort(head2));
    }
};
