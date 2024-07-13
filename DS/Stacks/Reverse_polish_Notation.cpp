#include <iostream>
#include <stack>
using namespace std;
#define paster(n, m, k) (token##n k token##m)
string getString(char x)
{
    string s(1, x);
    return s;
}
int op(int temp, string s, int temp2)
{
    if (s == "+")
        return temp + temp2;
    if (s == "*")
        return temp * temp2;
    if (s == "/")
        return temp / temp2;
        return temp - temp2;
}

vector<string> to_postfix(vector<string> s)
{
    stack<string> str;
    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] == "/" || s[i] == "*" || s[i] == "+" || s[i] == "-")
        {
            str.push(s[i]);
            s[i] = ")";
        }
        else if (s[i] == ")")
        {
            if (!str.empty())
            {
                s[i] = str.top();
                str.pop();
            }
        }
    }
    vector<string> ans;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ")" && s[i] != "(")
            ans.push_back(s[i]);
    }
    return ans;
}

int solve_postfx(vector<string> s)
{
    stack<int> str;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == "+"||s[i] == "-"||s[i] == "/"||s[i] == "*")
        {
            int temp=str.top();
            str.pop();
            int temp2=str.top();
            str.pop();
            str.push(op(temp2,s[i],temp));
        }
        else
            str.push(atoi(s[i].c_str()));
    }
    return str.top();
}
int main(void)
{
    system("clear");
    string s;
    vector<string> inp;
    cout << "Enter the data : ";
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        inp.push_back(getString(s[i]));

    inp = to_postfix(inp);
    for (int i = 0; i < inp.size(); i++)
        cout << inp[i];
        cout<<endl;
    cout << solve_postfx(inp);
    return 0;
}
//work for only single digit Number