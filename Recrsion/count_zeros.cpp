#include <iostream>
using namespace std;
//checking zero
int zero(int n) { return !n ? 1 : 0; }
// main code
int find(int n)
{
    if (n == 0)
        return 0;
    return zero(n % 10) + find(n / 10);
}
//driver function
int main()
{
    system("clear");
    int n = 0;
    cout << "Enter a number : ";
    cin >> n;
    cout << "Number of zeros are : " << find(n) << endl;
}
