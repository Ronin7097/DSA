#include <iostream>
using namespace std;

void print(int n)
{
    if (n == 0)
        return;
    cout << n << " ";

    print(n - 1);
}

int main()
{
    system("clear");
    int n = 0;
    cout << "Enter a Number :";
    cin >> n;
    cout << "Number form 1 to n :" << n << endl;
    print(n);
    return 0;
}