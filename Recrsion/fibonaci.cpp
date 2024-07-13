#include <iostream>
using namespace std;

int fabo(int n)
{
    if (n == 1)
        return n;
    if (n < 1)
        return 0;

    return fabo(n - 1) + fabo(n - 2);
}

int main()
{
    system("clear");
    int n = 0;
    cout << "Enter a Number : ";
    cin >> n;
    cout << "Fibonaci Series : " << (float)fabo(45) / fabo(44) << endl;
}