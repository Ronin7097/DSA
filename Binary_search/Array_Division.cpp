#include <bits/stdc++.h>
#define int long long int
#define deg(a) cout << a << endl;
#define float long double
using namespace std;
static int mod(int a) { return a < 0 ? -1 * a : a; }
static int attoi(char ch) { return (int)ch - '0'; }
// think again

bool predicate(int arr[], int n, int k, int wrkone)
{
    int currwork = 0;
    for (int i = 0; i < n; i++)
    {
        if (currwork + arr[i] <= wrkone)
            currwork += arr[i];
        else
        {
            
            if (arr[i] > wrkone)
                return false;
            currwork = arr[i];
            if (k == 1)
                return false;
            k--;
        }
    }
    return true;
}
static void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int lw = 1, ub = 1e15, ans = 1e15;
    while (lw <= ub)
    {
        int mid = (lw + ub) / 2;
        if (predicate(arr, n, k, mid))
        {
            ans = min(ans, mid);
            ub = mid - 1;
        }
        else
            lw = mid + 1;
    }
    cout << ans<< endl;
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