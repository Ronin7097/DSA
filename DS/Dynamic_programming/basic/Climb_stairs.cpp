#include <iostream>
using namespace std;

int climb_stair(int n, int k)
{
    int *dp = new int[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= k && i >= j; j++)
            dp[i] += dp[i - j];
    int result = dp[n];
    delete[] dp;
    return result;
}


// code for O(k) space complexity
// int climb_stair1(int n, int k)
// {
//     int *dp;
//     if (k <= n)
//         dp = new int[k + 1];
//     else
//         dp = new int[n + 1];
//     dp[0] = 1;
//     dp[1] = 1;
//     for (int i = 2; i <= n; i++)
//     {
//         for (int j = 1; j <= k && i >= j; j++)
//         {
//             if (i < k)
//                 dp[i] += dp[i - j];
//             else
//                 dp[k] += dp[k - j];
//         }
//         if (i >= k)
//         {
//             for (int j = 0; j < k; j++)
//                 dp[j] = dp[j + 1];
//         }
//     }
//     int result = dp[k];
//     delete[] dp;
//     return result;
// }

int main()
{
    system("clear");
    int n, k;
    cout << "Enter the value of steps(n) : ";
    cin >> n;
    cout << "Enter the value of jumps (k) : ";
    cin >> k;
    cout << "Number of ways we can climb down the tree is : " << climb_stair(n, k) << endl;
    //cout << "Number of ways we can climb down the tree is : " << climb_stair1(n, k) << endl;
    return 0;
}