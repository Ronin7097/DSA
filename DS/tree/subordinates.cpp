#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Treenode
{
public:
    int data;
    vector<Treenode *> child;
    Treenode(int data) : data(data) {}
     ~Treenode()
    {
        for(int i = 0; i < child.size();i++)
        delete child[i];
    }
};

int count(Treenode *root, vector<int> &dp)
{
    if (root == NULL)
        return 0;
    int count1 = 0;
    for (int i = 0; i < root->child.size(); i++)
        count1 += count(root->child.at(i),dp);
    dp[root->data-1] = count1;
    return count1 + 1;
}

int main()
{
    int n;
    vector<Treenode *> v;
    Treenode *root = new Treenode(1);
    v.push_back(root);
    cin >> n;
    int temp;
    for (int i = 2; i <= n; i++)
    {
        Treenode *n = new Treenode(i);
        v.push_back(n);
    }
    for (int i = 2; i <= n; i++)
    {
        cin >> temp;
        v.at(temp - 1)->child.push_back(v.at(i - 1));
    }
    vector<int> dp(n);
    count(root,dp);
    for (int i = 0; i < dp.size(); i++)
        cout << dp[i] << " ";

    return 0;
}