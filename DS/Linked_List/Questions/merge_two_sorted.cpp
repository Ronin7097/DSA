// recursive solution
#include "fuctions.cpp"
Node* merge(Node *head1, Node *head2)
{
   if(head1==NULL)return head2;
   if(head2==NULL)return head1;
   Node *fh=NULL;

   if(head1->data>head2->data)
   {
    fh=head2;
    fh->next=merge(head1,head2->next);
   }
   else
   {
    fh=head1;
    fh->next=merge(head1->next,head2);
   }
   return fh;
}

int main(void)
{
    system("clear");
    Functions *func = new Functions;
    cout << "Enter data: " << endl;
    Node *head1 = func->take_input();
    cout << "Enter data:" << endl;
    Node *head2 = func->take_input();
    cout << "anse: " << endl;
    head1 = merge(head1, head2);
    func->print(head1);
    delete func;
    return 0;
}