#include <bits/stdc++.h>
#define int long long
#define deg(a) cout << a << endl;
#define float long double
using namespace std;
static int mod(int a) { return a < 0 ? -1 * a : a; }
static int attoi(char ch) { return (int)ch - '0'; }
// think again
bool pred(int arr[], int mach, int prod, int time)
{
    int currprod = 0;
    for (int i = 0; i < mach; i++)
    {
        currprod += (time / arr[i]);
        if (currprod >= prod)
            return true;
    }
    return false;
}
static void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int low = 1, up = 1e18, ans = 1e18;
    while (low <= up)
    {
        int mid = (up + low) / 2;
        if (pred(arr, n, k, mid))
        {
            ans = min(ans, mid);
            up = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << ans << endl;
    return;
}
int32_t main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(10);
    solve();
    return 0;
}