#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class Treenode
{
public:
    T data;
    vector<Treenode<T> *> child;
    Treenode(T data) : data(data) {}
    ~Treenode()
    {
        for(int i = 0; i < child.size();i++)
        delete child[i];
    }
};

template <typename T>
class Functions
{
public:
    Treenode<T> *take_input()
    {
        queue<Treenode<T> *> q;
        T data;
        int child;
        cout << "Enter data for root : ";
        cin >> data;
        Treenode<T> *n = new Treenode<T>(data);
        q.push(n);
        while (!q.empty())
        {
            cout << "Enter No. of children for level : " << q.front()->data << " : ";
            cin >> child;
            if (child != 0)
                cout << "Enter data for level : " << q.front()->data << " : ";
            for (int i = 0; i < child; i++)
            {
                cin >> data;
                Treenode<T> *n1 = new Treenode<T>(data);
                q.push(n1);
                q.front()->child.push_back(n1);
            }
            q.pop();
        }
        return n;
    }
    void print(Treenode<T> *root)
    {
        if (root == NULL)
            return;
        queue<Treenode<T> *> q;
        q.push(root);
        while (!q.empty())
        {
            cout << q.front()->data << ":";
            for (int i = 0; i < q.front()->child.size(); i++)
            {
                cout << q.front()->child.at(i)->data << ",";
                q.push(q.front()->child.at(i));
            }
            cout << endl;
            q.pop();
        }
    }
    int count(Treenode<T> *root)
    {
        if (root == NULL)
            return 0;
        int count1 = 0;
        for (int i = 0; i < root->child.size(); i++)
            count1 += count(root->child.at(i));
        return count1 + 1;
    }
    int height(Treenode<T> *root)
    {
        if (root == NULL)
            return 0;
        int height1 = 0;
        for (int i = 0; i < root->child.size(); i++)
            height1 = max(height1, height(root->child.at(i)));
        return height1 + 1;
    }
    void depth(Treenode<T> *root, int k)
    {
        if (root == NULL)
            return;
        if (k == 0)
        {
            cout << root->data << " ";
            return;
        }
        for (int i = 0; i < root->child.size(); i++)
            depth(root->child.at(i), k - 1);
    }
    int count_leaf(Treenode<T> *root)
    {
        if (root == NULL)
            return 0;
        if (root->child.size() == 0)
            return 1;
        int count = 0;
        for (int i = 0; i < root->child.size(); i++)
            count += count_leaf(root->child.at(i));
        return count;
    }
    void PreOrder(Treenode<T> *root)
    {
        if (root == NULL)
            return;
        cout << root->data << " ";
        for (int i = 0; i < root->child.size(); i++)
            PreOrder(root->child.at(i));
    }
    void PostOrder(Treenode<T> *root)
    {
        if (root == NULL)
            return;
        for (int i = 0; i < root->child.size(); i++)
            PostOrder(root->child.at(i));
        cout << root->data << " ";
    }
};