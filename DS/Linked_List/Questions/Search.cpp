#include "fuctions.cpp"
// using recurtion
bool Search(Node *head, int key)
{
    if (head == NULL)
        return false;
    if (head->data == key)
        return true;
    return Search(head->next, key);
}

int main(void)
{
    system("clear");
    Functions *func = new Functions;
    cout << "Enter data : " << endl;
    Node *head = func->take_input();
    int key;
    cout << "Enter a Key : ";
    cin >> key;
    cout << "Key is present at index : " << Search(head, key) << endl;
    delete func;
    return 0;
}