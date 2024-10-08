#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void reverse(queue<int> &q)
{
    if(q.empty()) return;
    stack<int>s;
    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

int main()
{
    system("clear");
    queue<int> q;
    for(int i = 0; i <6;i++)
    q.push(i);
    reverse(q);
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}