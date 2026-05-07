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
    ll n, m; cin >> n >> m;

    vl a(n);
    rep(i, n) cin >> a[i];

    vvl dp(m+1, vl(n+1, -INF));
    rep(i, n+1) dp[0][i] = 0;

    rep(i, m) for (ll j = i; j < n-m+i+1; ++j){
        dp[i+1][j+1] = max(dp[i+1][j], dp[i][j] + a[j] * (i+1));
    }

    // debug
    // rep(i, m+1) {
    //     rep(j, n+1) cout << dp[i][j] << ' ';
    //     cout << endl;
    // }
    cout << dp[m][n] << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}