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
#define nfor(i,s,n) for(ll i=s;i<n;i++)//i=s,s+1...n-1 ノーマルfor

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
    ll w, n, k; cin >> w >> n >> k;

    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    vector<vector<ll>> dp(k+1, vector<ll>(w+1, 0));
    rep(ni, n) for(ll i = k - 1; i >= 0; i--) for(ll j = w - a[ni]; j >= 0 ; j--)  {
            chmax(dp[i+1][j+a[ni]], dp[i][j] + b[ni]);
    }

    // // debug
    // rep(i, k+1) {
    //     rep(j, w+1) cout << dp[i][j] << ' ';
    //     cout << endl;
    // }

    cout << dp[k][w] << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}