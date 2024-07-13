#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // constructor
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

// driver code
int main(void)
{
    system("clear");
    Node n1(45);
    Node n2(454);
    Node n3(4545);
    Node n4(45459);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    Node *head = &n1;

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}