#include <iostream>
using namespace std;

void permu(char str[], int i)
{
    if (str[i] == '\0')
    {
        cout << str << endl;
        return;
    }

    for (int j = i; str[j] != '\0'; j++)
    {
        swap(str[i], str[j]);
        permu(str, i + 1);
        swap(str[i], str[j]);
    }
}

int main(void)
{
    system("clear");
    char str[100];
    cout << "Enter a String : ";
    cin >> str;
    permu(str, 0);
    return 0;
}