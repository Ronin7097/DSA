#include "fuctions.cpp"

void pop_back_kth(Node *&head, int k)
{
    if(k<=0)return;
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

int main(void)
{
    system("clear");
    Functions *func = new Functions;
    cout << "Enter Data :" << endl;
    Node *head = func->take_input();
    func->print(head);
    cout << "Enter Kth : ";
    int k;
    cin >> k;
    pop_back_kth(head, k);
    func->print(head);
    delete func;
    return 0;
}
