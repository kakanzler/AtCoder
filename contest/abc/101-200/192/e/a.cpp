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
template<class T> using pq_g = priority_queue<T, vc<T>, greater<T>>;//小さい順
//-----------------------------------
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

#define pb push_back

struct Edge{
    int to;
    ll k;
    ll w;
    Edge(int to, ll k, ll w) : to(to), k(k), w(w) {};
};

using Graph = vector<vector<Edge>>;

void solve() {
    ll n, m, x, y; cin >> n >> m >> x >> y;
    x--; y--;
    Graph g(n);
    rep(i, m){
        ll a, b, t, k; cin >> a >> b >> t >> k;
        a--; b--;
        g[a].pb(Edge(b, k, t));
        g[b].pb(Edge(a, k, t));
    }
    vl dist(n, INF);
    dist[x] = 0;

    pq_g<tuple<ll, ll>>  q;
    q.emplace(0, x);
    while(q.size()){
        auto [d, v] = q.top(); q.pop();

        if (d > dist[v]) continue;

        for (Edge e : g[v]){
            if (chmin(dist[e.to], dist[v] + e.w + (dist[v] % e.k  == 0 ? 0 : e.k - dist[v] % e.k ))) {
                q.emplace(dist[e.to], e.to);
                // debug
                // rep(i, n) cout << dist[i] << ' ';
                // cout << endl;
            }
        }
    }

    cout << (dist[y] != INF ? dist[y] : -1) << endl;

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}