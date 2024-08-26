#include <iostream>
#include <queue>
using namespace std;
template <typename T>
class BTNode
{
public:
    T data;
    BTNode *left;
    BTNode *right;
    BTNode() : data(0), left(NULL), right(NULL) {}
    BTNode(T data) : data(data), left(NULL), right(NULL) {}
    ~BTNode()
    {
        delete left;
        delete right;
    }
};
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1

template <typename T>
class funtion
{
    bool helper(BTNode<T> *tleft, BTNode<T> *tright)
    {
        if (tleft == NULL && tright == NULL)
            return true;
        if (tleft == NULL || tright == NULL)
            return false;

        return helper(tleft->right, tright->left) &&
               helper(tleft->left, tright->right);
    }
    vector<int> paths;
    bool finder(BTNode<T> *root,int target)
    {
        if(root==NULL)
        return false;
        if(root->data==target){
        paths.push_back(root->data);
        return true;
        }
        if(finder(root->left, target)||finder(root->right, target)){
                paths.push_back(root->data);
                return true;
        }
        return false;
    }

public:
    void print(BTNode<T> *root)
    {
        if (root == NULL)
            return;
        cout << root->data << ":";
        if (root->left)
            cout << "L" << root->left->data;
        if (root->right)
            cout << "R" << root->right->data;
        cout << endl;
        print(root->left);
        print(root->right);
    }
    BTNode<T> *take_input()
    {
        T data;
        cout << "Enter root data :";
        cin >> data;
        BTNode<T> *n1 = new BTNode<T>(data);
        queue<BTNode<T> *> q;
        q.push(n1);
        while (!q.empty())
        {
            cout << "data: " << q.front()->data << " left : ";
            cin >> data;
            if (data != -1)
            {
                BTNode<T> *n2 = new BTNode<T>(data);
                q.front()->left = n2;
                q.push(n2);
            }
            cout << "data: " << q.front()->data << " right : ";
            cin >> data;
            if (data != -1)
            {
                BTNode<T> *n3 = new BTNode<T>(data);
                q.front()->right = n3;
                q.push(n3);
            }
            q.pop();
        }
        cout << endl;
        return n1;
    }

    void level_order_traversal(BTNode<T> *root)
    {
        queue<BTNode<T> *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            BTNode<T> *current = q.front();
            q.pop();
            if (current == nullptr)
            {
                cout << endl; // End of current level
                if (!q.empty())
                    q.push(nullptr); // Add level separator for next level
            }
            else
            {
                cout << current->data << " ";
                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }
        }
    }

    int count(BTNode<T> *root)
    {
        if (root == NULL)
            return 0;
        return count(root->left) + count(root->right) + 1;
    }

    void inorder_traversal(BTNode<T> *root)
    {
        if (root == NULL)
            return;
        inorder_traversal(root->left);
        cout << root->data << endl;
        inorder_traversal(root->right);
    }

    void preorder_traversal(BTNode<T> *root)
    {
        if (root == NULL)
            return;
        cout << root->data << " ";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }

    void postorder_traversal(BTNode<T> *root)
    {
        if (root == NULL)
            return;
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        cout << root->data << " ";
    }

    bool symetric(BTNode<T> *root)
    {
        if (root == NULL)
            return true;
        return helper(root->left, root->right);
    }
    bool find(BTNode<T> *root, int key)
    {
        if (root == NULL)
            return false;
        if (root->data == key)
            return true;
        find(root->left, key);
        find(root->right, key);
    }

    int min_val(BTNode<T> *root)
    {
        if (root == NULL)
            return INT_MAX;
        return min(min(min_val(root->left), min_val(root->right)), root->data);
    }
    int max_val(BTNode<T> *root)
    {
        if (root == NULL)
            return INT_MIN;
        return max(max(max_val(root->left), max_val(root->right)), root->data);
    }

    int count_leaf(BTNode<T> *root)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == nullptr)
            return 1;
        return count_leaf(root->left) + count_leaf(root->right);
    }
    int height(BTNode<T> *root)
    {
        if(root==NULL)
        return 0;
        return 1+max(height(root->left), height(root->right));
    }

    vector<int> path(BTNode<T> *root,int target)
    {
        if(root==NULL)
        return vector<int>();

        if(finder(root,target))
        return paths;
        else
        return vector<int>();

    }
};
