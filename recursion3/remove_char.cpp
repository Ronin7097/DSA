#include <iostream>
using namespace std;

void remove(char arr[], int let)
{
    if (arr[0] == '\0')
        return;

    if (arr[0] == let)
    {
        for (int i = 0; arr[i] != '\0'; i++)
            arr[i] = arr[i + 1];
        remove(arr, let);
    }
    else
        remove(arr + 1, let);
}

int main(void)
{
    system("clear");
    char arr[100], let;
    cout << "Enter a string : ";
    cin >> arr;
    cout << "Enter a character : ";
    cin >> let;
    remove(arr, let);
    cout << arr << endl;
}