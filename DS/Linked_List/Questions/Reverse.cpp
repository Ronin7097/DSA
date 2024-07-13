#include "fuctions.cpp"

void reverse1(Node *&head)
{
    Node *temp = head->next;
    head->next = NULL;
    Node *temp2;
    while (temp2 != NULL)
    {
        temp2 = temp->next;
        temp->next = head;
        head = temp;
        temp = temp2;
    }
}

int main(void)
{
    system("clear");
    Functions *func = new Functions;
    cout<<"Enter Data :"<<endl;
    Node *head = func->take_input();
    func->reverse(head);
    func->print(head);
    delete func;
    return 0;
}