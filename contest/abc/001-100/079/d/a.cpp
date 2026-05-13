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

//-------------2.配列系--------------
using vl = vc<ll>; using vvl = vv<ll>; using vvvl = vv<vl>; using vvvvl = vv<vvl>;


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

// using mint = modint998244353;
using mint = modint1000000007;

vl dx = { 1,0,-1,0 };//vl dx={1,1,0,-1,-1,-1,0,1};
vl dy = { 0,1,0,-1 };//vl dy={0,1,1,1,0,-1,-1,-1};

bool out_grid(ll i, ll j, ll h, ll w) {//trueならcontinue
    return (!(0 <= i && i < h && 0 <= j && j < w));
}

void solve() {
    ll h, w; cin >> h >> w;

    vvl c(10, vl(10));
    rep(i, 10) rep(j, 10) cin >> c[i][j];

    vvl a(h, vl(w, 0));
    rep(i, h) rep(j, w) cin >> a[i][j];


    rep(k, 10)  rep(i, 10)  rep(j, 10) chmin(c[i][j], c[i][k] + c[k][j]);

    // // debug
    // rep(i, n) {
    //     rep(j, n) cout << g[i][j] << ' ';
    //     cout << endl;
    // }

    ll ans = 0;
    rep(i, h) rep(j, w){
        if (a[i][j] == -1) continue;

        ans += c[a[i][j]][1];
    }

    cout << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}