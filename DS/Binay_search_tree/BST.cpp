#include "../Binary_tree/bInarytree.cpp"
class BST
{
    void printer(BTNode<int> *root)
    {
        if (root == NULL)
            return;
        cout << root->data << ":- ";
        if (root->left)
            cout << "L: " << root->left->data << " ";
        if (root->right)
            cout << "R: " << root->right->data;
        cout << endl;
        printer(root->left);
        printer(root->right);
    }
    BTNode<int> *insert1(int val, BTNode<int> *root)
    { 
        if (root == NULL)
        {
            BTNode<int> *n = new BTNode<int>(val);
            return n;
        }
        if (root->data > val)
            root->left = insert1(val, root->left);
        else
            root->right = insert1(val, root->right);
        return root;
    }
    BTNode<int> *deleten(int val, BTNode<int> *root)
    {
        if (root == NULL)
            return NULL;
        if (root->data == val)
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            else if (root->right == NULL || root->left == NULL)
            {
                BTNode<int> *temp;
                if (root->left)
                {
                    temp = root->left;
                    root->left = NULL;
                    delete root;
                    return temp;
                }
                else
                {
                    temp = root->right;
                    root->right = NULL;
                    delete root;
                    return temp;
                }
            }
            else
            {
                BTNode<int> *replace = root->right;
                while (replace->left != NULL)
                    replace = replace->left;
                root->data = replace->data;
                root->right=deleten(replace->data, root->right);
            }
        }
        else if (root->data > val)
            root->left = deleten(val, root->left);
        else
            root->right = deleten(val, root->right);
        return root;
    }

public:
    BTNode<int> *root;
    BST() { root = NULL; }
    BST(int data) { root = new BTNode<int>(data); }
    ~BST() { delete root; };
    BTNode<int> *searchBST(int val)
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
    void print() { printer(root); }
    void insert(int val) { root = insert1(val, root); }
    void deleteNode(int val) { root = deleten(val, root); }
};
