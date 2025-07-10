#include <bits/stdc++.h>
#define int long long int
using namespace std;
// think again
int freq(int num, int n)
{
    int freq = 0;
    for (int i = 1; i <= n; i++)
        freq += min(n, num / i);
    return freq;
}
static void solve()
{
    int n;
    cin >> n;
    int low = 0, high = n * n, ans = high;
    while (low <=high)
    {
        int mid = (high + low) / 2;
        int f = freq(mid, n);
        if (f >= ((n * n) / 2 + 1))
        {
            ans=min(mid,ans);
            high = mid - 1;
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