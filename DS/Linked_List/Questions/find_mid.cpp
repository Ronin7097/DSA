#include "fuctions.cpp"

Node* mid1(Node* head)
{
    Node *temp=head;
    while(head!=NULL && head->next!=NULL)
    {
        temp=temp->next;//slow ptr
        head=head->next->next;//fast ptr
    }
    return temp;
}

int main(void)
{
    system("clear");
    Functions *func=new Functions;
    cout<<"Enter Data : "<<endl;
    Node *head=func->take_input();
    cout<<"Mid value : "<<func->mid(head)->data<<endl;
    delete func;
    return 0;
} 