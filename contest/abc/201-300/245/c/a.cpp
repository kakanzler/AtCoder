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
using vb = vc<bool>; using vvb = vv<bool>; using vvvb = vv<vb>;


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

#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
void solve() {
    ll n, k; cin >> n >> k;

    vl a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    vvb dp(n+1, vb(2, false));
    dp[0][0] = true;
    dp[0][1] = true;

    for (ll i = 0; i < n-1; i++){

        dp[i+1][0] = ((abs(a[i+1] - a[i]) <= k && dp[i][0]) || (abs(a[i+1] - b[i]) <= k && dp[i][1]));

        dp[i+1][1] = ((abs(b[i+1] - a[i]) <= k && dp[i][0]) || (abs(b[i+1] - b[i]) <= k && dp[i][1]));

        // debug
        // cout << dp[i+1][0] << ' ' << dp[i+1][1] << endl;

        if (!dp[i+1][0] && !dp[i+1][1]) {
            NO;
            return;
        }
    }

    YES;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}