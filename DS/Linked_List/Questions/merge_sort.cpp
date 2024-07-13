// merge sort on ll;
#include "fuctions.cpp"

Node *mid(Node *head)
{
    Node *temp = head->next;
    while(temp&& temp->next)
    {
        head=head->next;
        temp=temp->next->next;
    }

    return head;
}

Node *merge_sort(Node *head)
{
    if (head->next == NULL)
        return head;
    Functions func;
    Node *head2 = mid(head)->next;
    mid(head)->next = NULL;
    return func.merge(merge_sort(head), merge_sort(head2));
}

int main(void)
{
    system("clear");
    Functions *func = new Functions;
    cout << " Enter Data :" << endl;
    Node *head = func->take_input();
   head = func->merge_sort(head);
    func->print(head);

    delete func;
    return 0;
}