#include <iostream>
using namespace std;

int convert(string str)
{
    if (str.length() == 0)
        return 0;
        return (str[0]-'0') * pow(10, str.length()-1) + convert(str.substr(1,str.length() - 1));
}

int main(void)
{
    system("clear");
    string str;
    cout << "Enter a string : ";
    cin >> str;
    cout << convert(str);
}