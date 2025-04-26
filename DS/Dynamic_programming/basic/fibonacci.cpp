#include <iostream>
#include <vector>
using namespace std;

int fibo(int n, int *v)
{
    if (n <= 1)
        return 1;
    if (v[n] != 0)
        return v[n];
    v[n] = fibo(n - 1, v) + fibo(n - 2, v);
    return v[n];
}
int fibo_lost(int n)
{
    if (n <= 1)
        return 1;
    return fibo_lost(n - 1) + fibo_lost(n - 2);
}
int main()
{

    system("clear");
    cout << "Enter a number :";
    int n;
    cin >> n;
    int dp[n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = 0;
    cout << "Fibonacci number : " << fibo(n, dp)<<endl;
    cout<<"Fibonacci number : " << fibo_lost(n);
    return 0;
}