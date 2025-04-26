#include <iostream>
using namespace std;

int steps(int n, int *dp)
{
    if (n <= 1)
        return 0;
    if (dp[n] == -1)
    {
        int x = INT_MAX, y = INT_MAX, z = INT_MAX;
        if (n % 3 == 0)
            x = steps(n / 3, dp);
        if (n % 2 == 0)
            y = steps(n / 2, dp);
        z = steps(n - 1, dp);
        dp[n] = min(x, min(y, z)) + 1;
    }
    return dp[n];
}

int steps_bottom(int n)
{
    int *dp = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        if (i <= 1)
        {
            dp[i] = 0;
            continue;
        }
        int x = INT_MAX, y = INT_MAX, z;
        if (i % 3 == 0)
            x = dp[i / 3];
        if (i % 2 == 0)
            y = dp[i / 2];
        z = dp[i - 1];
        dp[i] = min(x, min(y, z)) + 1;
    }
    int result = dp[n];
    delete[] dp;
    return result;
}

int main()
{
    system("clear");
    cout << "Enter number of steps : ";
    int step;
    cin >> step;
    int *dp = new int[step + 1];
    for (int i = 0; i <= step; i++)
        dp[i] = -1;
    cout << "mininum step are :" << steps(step, dp) << endl;
    cout << "mininum step are :" << steps_bottom(step);
    delete[] dp;
    return 0;
}