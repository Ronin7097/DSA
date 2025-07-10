#include <bits/stdc++.h>
#define int long long
#define deg(a) cout << a << endl;
#define float long double
using namespace std;
static int mod(int a) { return a < 0 ? -1 * a : a; }
static int attoi(char ch) { return (int)ch - '0'; }
// think again
int solve(int arr[], int n, int sum,vector<int> &dp)
{
    if (sum == 0)
        return 1;
    else if (sum < 0)
        return -1;
    if (dp[sum] != -2)
    return dp[sum];
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int temp = solve(arr, n, sum - arr[i],dp);
        if (temp != -1)
            ans = min(ans, temp + 1);
    }
    dp[sum] = ans;
    return ans;
}
int32_t main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(10);
    int n, sum;
    cin >> n >> sum;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // vector<int> dp(sum + 1, -2);
    //     int ans=solve(arr, n, sum,dp);
    // if(ans == INT_MAX)
    //     cout << -1 << endl;
    // else
    //     cout << ans-1<< endl;
    vector<int> dp(sum + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <= sum; i++)
    {
        for(int j = 0; j < n; j++) 
        {
            if(i - arr[j] >= 0)
            {
                dp[i]= min(dp[i],dp[i-arr[j]]+1);
            }
        }
    }
    cout<<dp[sum]<<endl;
    return 0;
}