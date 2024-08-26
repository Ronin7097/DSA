#include "binaryTree.cpp"
#include <vector>
// void level_order_traversal(BTNode<T> *root)
// {
//     queue<BTNode<T> *> q;
//     q.push(root);
//     q.push(NULL);
//     while (!q.empty())
//     {
//         BTNode<T> *current = q.front();
//         q.pop();
//         if (current == nullptr)
//         {
//             cout << endl; // End of current level
//             if (!q.empty())
//                 q.push(nullptr); // Add level separator for next level
//         }
//         else
//         {
//             cout << current->data << " ";
//             if (current->left)
//                 q.push(current->left);
//             if (current->right)
//                 q.push(current->right);
//         }
//     }
// }
vector<vector<int> > levelOrder(BTNode<int> *root)
{
    queue<BTNode<int> *> q;
    vector<vector<int> > ans;
    vector<int>v;
    int count = 0;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BTNode<int> *current = q.front();
        q.pop();
        if (current == NULL)
        {
            ans.push_back(v);
            count++;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            ans[count].push_back(current->data);
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
    }
    return ans;
}

int main()
{
    system("clear");
    funtion<int> *f = new funtion<int>;
    BTNode<int> *root = f->take_input();
    vector<vector<int> > ans = levelOrder(root);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}