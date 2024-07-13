#include <iostream>
#include <stack>
using namespace std;
bool valid1(string s)
{
    stack<char> stor;
    stor.push(s[0]);
    for (int i = 1; i < s.length(); i++)
    {
        if(stor.empty())
        stor.push(s[i]);
        else
        {
        if (stor.top() == s[i] - 1 || stor.top() == s[i] - 2)
            stor.pop();
        else
            stor.push(s[i]);
        }
    }
    return stor.empty();
}

int main(void)
{
    system("clear");
    string s;
    cout << "Enter parenthises : ";
    cin >> s;
    if (valid1(s))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;
}