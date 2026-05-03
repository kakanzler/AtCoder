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
using vl = vc<ll>; using vvl = vv<ll>; using vvvl = vv<vl>; using vvvvl = vv<vvl>;
using vs = vc<string>; using vvs = vv<string>;


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

#define pb push_back

void solve() {
    string s; cin >> s;
    ll n = (ll)s.size();
    vector<vector<ll>> dp(n+1, vector<ll>(3, 0));

    rep (i, n) {

        dp[i+1][(s[i] - 'a') % 3] = dp[i][(s[i] - 'a') % 3];

        dp[i+1][(s[i] - 'a') % 3] += dp[i][(s[i] - 'a' + 1) % 3] + dp[i][ (s[i] - 'a' + 2 ) % 3] + 1;
        dp[i+1][(s[i] - 'a') % 3] %= 998244353;

        dp[i+1][(s[i] - 'a' + 1) % 3] = dp[i][(s[i] - 'a' + 1) % 3];
        dp[i+1][(s[i] - 'a' + 2) % 3] = dp[i][(s[i] - 'a' + 2) % 3];

    }

    // debug
    // rep (i, n+1) {
    //     rep(j, 3){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    ll ans = ((dp[n][0] + dp[n][1] ) % 998244353 + dp[n][2]) % 998244353;
    cout << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}