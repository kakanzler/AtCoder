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

    vector<tuple<ll, ll, ll>> gg;
    vvl g(h, vl(w, 0));
    rep(i, h) rep(j, w) {
        ll a; cin >> a;
        g[i][j] = a;
        gg.push_back({a, i, j});
    }
    sort(gg.begin(), gg.end());

    mint ans = 0;

    vc<vc<mint>> dp(h, vc<mint>(w, 1));
    for(auto [_, i, j] : gg){
        rep(k, 4){
            ll ny = i + dy[k];
            ll nx = j + dx[k];
            if (out_grid(ny, nx, h, w)) continue;

            if (g[ny][nx] > g[i][j]){
                dp[ny][nx] += dp[i][j];
            }
        }
    }

    rep(i, h) {
        rep(j, w) {
            // cout << dp[i][j] << ' ';
            ans += dp[i][j];
        }
        // cout << endl;
    }

    cout << ans.val() << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}