#include <iostream>
using namespace std;

class NODE
{
public:
    int data;
    NODE *next;
    NODE(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void print(NODE *const &head)
{
    NODE *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
}

int main(void)
{
    NODE N1(1);             // STATIC NODE
    NODE *N2 = new NODE(2); // stack and heap
    NODE *N3 = new NODE(3);
    NODE *N4 = new NODE(4);
    NODE *N5 = new NODE(5);
    NODE *N6 = new NODE(6);
    NODE *HEAD;
    HEAD = &N1;
    N1.next = N2;
    N2->next = N3;
    N3->next = N4;
    N4->next = N5;
    N5->next = N6;
    print(HEAD);
    return 0;
}