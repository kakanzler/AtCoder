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

//-------------2.配列系--------------
using vl = vc<ll>; using vvl = vv<ll>;



//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)

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


void solve() {
    ll n; cin >> n;
    vvl dp(n+1, vl(2, 0));

    rep(i, n){
        ll p, d; cin >> p >> d;

        if (p){
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = max(dp[i][0] + d, dp[i][1]);
        } else {
            dp[i+1][1] = dp[i][1];
            dp[i+1][0] = max({ dp[i][1] + d, dp[i][0] + d, dp[i][0] });
        }
    }

    // debug
    // rep(i, n+1){
    //     cout << dp[i][0] << ' ' << dp[i][1] << endl;
    // }

    cout << max(dp[n][0], dp[n][1]) << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}