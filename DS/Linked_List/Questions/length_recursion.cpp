#include <iostream>
#include "fuctions.cpp"
using namespace std;

int Len(Node *head)
{
    if (head == NULL)
        return 0;
    return Len(head->next) + 1;
}

int main(void)
{
    system("clear");  
    Fuctions *function = new Fuctions;
    cout<<"enter a data : ";
    Node *head = function->take_input();
    cout <<"The Length of the List is : "<< Len(head) << endl;
    delete function;
    return 0;
}