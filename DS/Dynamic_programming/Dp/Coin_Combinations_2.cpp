#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int32_t main(void) {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
  for (int i = 0; i < n; i++)
    dp[i][0] = 1;
  for (int j = n - 1; j >= 0; j--) {
    for (int i = 1; i <= k; i++) {
      if (i >= a[j])
        dp[j][i] = (dp[j][i - a[j]] + dp[j + 1][i]) % MOD;
      else
        dp[j][i] = (dp[j + 1][i] % MOD);
    }
  }
  cout << dp[0][k] % MOD << endl;
  return 0;
}