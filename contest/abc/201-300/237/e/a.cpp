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
using vl = vc<ll>; using vvl = vv<ll>; using vvvl = vv<vl>;
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
    vl h(n); rep(i, n) cin >> h[i];

    vvl g(n);
    rep(i, m){
        ll u, v; cin >> u >> v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    pq_g<tuple<ll, ll>> q;
    q.emplace(0, 0);

    vl dist(n, INF);
    dist[0] = 0;

    while ( q.size() ) {
        auto [joy, v] = q.top(); q.pop();

        if (dist[v] != joy) continue;

        for (ll nv : g[v]){
            ll cost = max(0LL, h[nv] - h[v]);
            if (chmin(dist[nv], joy + cost)){
                q.emplace(dist[nv], nv);
            }
        }
    }

    // // debug
    // rep(i, n) cout << dist[i] << ' ';
    // cout << endl;

    ll ans = 0;
    rep(i, n) {
        chmax(ans, h[0] - h[i] - dist[i]);
    }
    cout << ans << endl;

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}