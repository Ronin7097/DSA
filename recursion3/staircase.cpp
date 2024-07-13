#include <iostream>
using namespace std;

int counter(int n)
{
    if (n == 2)
        return 2;
    else if (n <= 1)
        return 1;
    return counter(n - 1) + counter(n - 2) + counter(n - 3);
}

int main(void)
{
    system("clear");
    int n, count = 1;
    cout << "Enter the stairtcase number : ";
    cin >> n;

    cout << counter(n);
}