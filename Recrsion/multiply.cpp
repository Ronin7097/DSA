#include <iostream>
using namespace std;

int muls(int mul, int num)
{
    if (num == 1)
        return mul;
    return mul + muls(mul, --num);
}

int main()
{
    system("clear");
    int n = 0, m = 0;
    cout << "Enter two number : ";
    cin >> m >> n;

    cout << "Their multipication is :" << muls(max(m, n), min(n, m)) << endl;
}