#include <iostream>
using namespace std;

void print(char str[], char const & let, char const & let2)
{
    if (str[0] == '\0')
        return;
    if (str[0] == let2)
        str[0] = let;
    print(str + 1, let, let2); 
}

int main()
{
    system("clear");
    char str[100], let, let2;
    cout << "Enter a string  : ";
    cin >> str;
    cout << "Enter two letter : ";
    cin >> let >> let2; 
    print(str, let, let2);
    cout << str << endl;
}