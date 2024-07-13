#include "fuctions.cpp"

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