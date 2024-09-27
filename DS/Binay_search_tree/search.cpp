#include "../Binary_tree/bInarytree.cpp"
BTNode<int> *searchBST(BTNode<int> *root, int val)
{
    while (root != NULL)
    {
        if (root->data == val)
            return root;
        else if (root->data > val)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}
// 4 2 7 1 3

int main()
{
    system("clear");
    funtion<int> *f = new funtion<int>();
    BTNode<int> *root = f->take_input();
    int val;
    cout << "Enter your target value : ";
    cin >> val;
    cout << searchBST(root, val)->data << endl;
    f->print(root);
    delete root;
    delete f;
    return 0;
}