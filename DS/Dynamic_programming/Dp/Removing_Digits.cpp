#include <bits/stdc++.h>
#define int long long
#define deg(a) cout << a << endl;
#define float long double
#define end '\n'
#define ceil(a, b) ((a + b - 1) / b)
using namespace std;
// think again
static void solve()
{
    string s;
    cin >> s;
    int n = stoll(s);
    int count=0;
    while (n > 0)
    {
        int maxm = 0;
        for (int i = 0; i < s.size(); i++)
            maxm = max(maxm, static_cast<int>(s[i] - '0'));
        n -= maxm;
        s = to_string(n);
        count++;
    }
    cout<<count<<endl;

    return;
}

int32_t main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}