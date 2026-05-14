#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG//[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意 ABC311Eのサンプル4みたいなデバック中のTLEは防げないので注意
#endif

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


template<typename T> using vc = vector<T>;//prioriy_queueに必要なのでここにこれ書いてます

//-------------1.型系---------------
using ll = long long;
template<class T> bool chmin (T &a, T b){
    if (a > b) {
        a = b;
        return true;
    } else {
        return false;
    }
}
template<class T> bool chmax (T &a, T b){
    if (a < b) {
        a = b;
        return true;
    } else {
        return false;
    }
}
//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<ll>> g(n);
    rep(i, m) {
        ll x, y; cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
    }

    vector<ll> dp(n+1, -1);

    auto f = [&](auto self, ll v) -> ll {
        // if(g[v].empty()) return 0LL;
        if (dp[v] != -1) return dp[v];

        dp[v] = 0;
        for (ll nv : g[v]){
            chmax(dp[v], self(self, nv) + 1);
        }
        return dp[v];
    };

    ll ans = 0;
    rep(i, n) chmax(ans, f(f, i));
    cout << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
