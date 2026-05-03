#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG//[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意 ABC311Eのサンプル4みたいなデバック中のTLEは防げないので注意
#endif

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


template<typename T> using vc = vector<T>;//prioriy_queueに必要なのでここにこれ書いてます
template<typename T> using vv = vc<vc<T>>;

//-------------1.型系---------------
using ll = long long;
ll INF = 2e18;

//-------------2.配列系--------------
using vl = vc<ll>; using vvl = vv<ll>;

//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)

void solve() {
    ll x, y, z; cin >> x >> y >> z;
    string s; cin >> s;

    ll n = (ll)s.size();
    vvl dp(n+1, vl(2, 0));
    dp[0][1] = INF;

    rep(i, n) {
        if (s[i] == 'a') {
            dp[i+1][0] = min(dp[i][0] + x, dp[i][1] + z + x);
            dp[i+1][1] = min(dp[i][1] + y, dp[i][0] + z + y);
        } else {
            dp[i+1][0] = min(dp[i][0] + y, dp[i][1] + z + y);
            dp[i+1][1] = min(dp[i][1] + x, dp[i][0] + z + x);
        }
    }

    // debug
    // rep(i, n+1) {
    //     cout << dp[i][0] << ' ' << dp[i][1] << endl;
    // }

    cout << min({dp[n][0], dp[n][1]}) << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}