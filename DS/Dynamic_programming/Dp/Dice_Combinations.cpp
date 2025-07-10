#include <bits/stdc++.h>
#define int long long
#define deg(a) cout << a << endl;
#define float long double
using namespace std;
#define MOD 1000000007
static int mod(int a) { return a < 0 ? -1 * a : a; }
static int attoi(char ch) { return (int)ch - '0'; }
// think again
int solve(int a ,vector<int> &dp)
{
    if (a <= 0)
        return 1;
    if(dp[a] != -1)
        return dp[a];
    int count = 0;
    for (int i = 1; i <=6 && i <= a; i++)
        count += solve(a - i,dp);
    dp[a] = count;
    return count;
}
int32_t main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(10);
    int n=0;
    cin>>n;
    vector<int> dp(n+1);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=6;j++)
        {
            if(i-j>=0)
            {
                dp[i]=(dp[i]+dp[i-j])%MOD;
            }
            else break;
        }
    }
    //cout<<solve(n,dp)<<endl;
    cout<<dp[n]<<endl;
    return 0;
}