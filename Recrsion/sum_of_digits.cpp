#include <iostream>
using namespace std;

int sum_of_digits(int n)
{
    if(n==0)
    return 0;
    return n%10 +sum_of_digits(n/10);
}

// driver code
int main()
{
    system("clear");
    int n;
    cout << "Enter a number : ";
    cin >> n;
    cout << endl;
    cout << "The sum of the digits will be : " << sum_of_digits(n)<<endl;
    return 0;
}