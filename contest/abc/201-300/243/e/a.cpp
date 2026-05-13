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

template<class T> using pq = priority_queue<T, vc<T>>;//大きい順
template<class T> using pq_g = priority_queue<T, vc<T>, greater<T>>;//小さい順
//-----------------------------------



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

#define pb push_back

void solve() {
    ll n, m; cin >> n >> m;
    vvl g(n, vl(n, INF));

    vector<tuple<ll, ll, ll>> edge(m);
    rep(i,n) g[i][i] = 0;
    rep(i, m){
        ll a,b,c; cin >> a >> b >> c;
        a--; b--;
        edge.push_back({a, b, c});
        g[a][b] = c;
        g[b][a] = c;
    }

    rep(k, n) rep(i, n) rep(j, n){
        chmin(g[i][j], g[i][k] + g[k][j]);
    }

    ll ans = 0;
    for (auto [a, b, c] : edge){

        bool unnecesary = false;

        rep(k, n){
            if ( a == k || b == k) continue;
            if (g[a][k] + g[k][b] <= c) unnecesary = true;
        }
        if (unnecesary) ans++;
    }

    // // debug
    // rep(i, n) {
    //     rep(j, n) cout << g[i][j] << ' ';
    //     cout << endl;
    // }
    cout << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}