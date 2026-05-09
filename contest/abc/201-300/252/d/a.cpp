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

template<class T> using pq = priority_queue<T, vc<T>>;//大きい順
template<class T> using pq_g = priority_queue<T, vc<T>, greater<T>>;//小さい順
//-----------------------------------



//-------------2.配列系--------------
using vl = vc<ll>; using vvl = vv<ll>;


//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define pb push_back

void solve() {
    ll n; cin >> n;
    vl a(n);
    rep(i, n) cin >> a[i];

    map<ll ,ll> m;
    rep(i, n) m[a[i]]++;

    ll kind = 0;
    vector<pair<ll, ll>> vp;
    for (auto [k, v] : m) {
        // // debug
        // cout << k << " : " << v << endl;

        vp.pb({k, v});
        kind++;
    }

    vvl dp(3+1, vl(kind+1, 0));
    rep(i, kind+1) dp[0][i] = 1;

    rep (i, 3) {
        for (ll j = i+1; j <= kind ; j++){
            dp[i+1][j] = dp[i][j-1] * vp[j-1].second + dp[i+1][j-1];
        }
    }

    // // debug
    // rep (i, 4) {
    //     rep(j, kind+1){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << dp[3][kind] << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}