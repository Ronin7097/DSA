#include <iostream>
using namespace std;

bool check(string &x, int s, int e)
{
    if (s >= e)
        return true;
    if (x[s] == x[e])
        return check(x, s + 1, e - 1);
    else
        return false;
}

int main()
{
    system("clear");
    string n;
    cout << "Enter a Number : " << endl;
    cin >> n;
  
    cout << "Is Palindrome : " << check(n, 0, n.length()-1) << endl;
    return 0;
}