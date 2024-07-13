#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

string remove(string s)
{
    stack<char> str;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (!str.empty() && s[i] == str.top())
            str.pop();
        else
            str.push(s[i]);
    }
    string ans = "";
    while (!str.empty())
    {
        ans.push_back(str.top());
        str.pop();
    }
    return ans;
}
string removeDuplicates(string s)
{
    int stpr = -1, n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (stpr >= 0 && s[stpr] == s[i])
        {
            stpr--;
        }
        else
        {
            stpr++;
            s[stpr] = s[i];
        }
    }
    return s.substr(0, stpr + 1);
}
int main(void)
{
    // system("clear");
    // cout << "Enter string : ";
    string s;
    cin >> s;
    s = remove(s);
    cout << s << endl;
    // cout << "Answer : " << s << endl;
    return 0;
}