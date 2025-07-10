#include <bits/stdc++.h>
#define int long long
#define float long double
using namespace std;
#define MOD 1000000007
// think again
int solve(int sum, int arr[], int n, vector<int> dp)
{
    if (sum == 0)
        return 1;
    else if (sum < 0)
        return 0;
    if (dp[sum] != -1)
        return dp[sum];
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += solve(sum - arr[i], arr, n, dp) % MOD;
    dp[sum] = ans;
    return ans;
}
int32_t main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(10);
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // vector<int> dp(k + 1, -1);
    // cout<<solve(k, arr, n,dp)%MOD<< endl;

    vector<int> dp(k + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
        if(i-arr[j]>=0)
        dp[i]+=dp[i-arr[j]];
        dp[i]%=MOD;
    }
    cout<<dp[k]<<endl;
    return 0;
}