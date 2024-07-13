#include <iostream>
using namespace std;

double GSum(int n)
{
    if (n == 0)
        return 1.00;
    return (1.0/ (1 << n)) + GSum(n - 1);
}
//driver code
int main()
{
    system("clear");
    int n = 0;
    cout << "Enter a number : ";
    cin >> n;
    cout << "The number is : " << GSum(n) << endl;
}