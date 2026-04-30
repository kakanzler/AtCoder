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

struct Edge{
    int to;
    ll w;
    Edge (int to, ll w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

void solve() {
    ll n, m ; cin >> n >> m;
    Graph g(n);

    rep(i, m){
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        g[a].push_back(Edge(b, c));
    }


    priority_queue<pair<ll,ll>,
                   vector<pair<ll,ll>>,
                   greater<pair<ll, ll>>> q;
    // queue<ll> q;
    vl cost(n, INF);

    rep(i, n){
        vl dist(n, INF);

        vector<bool> used(n, false);

        q.emplace(INF, i);
        bool is_init = true;

        while(q.size()){
            auto [d, v] = q.top(); q.pop();

            if (d > dist[v]) continue;

            for (Edge e: g[v]){
                if (is_init){
                    if (chmin(dist[e.to], e.w)){
                        q.emplace(dist[e.to], e.to);
                    }
                } else {
                    if (chmin(dist[e.to], dist[v] + e.w)){
                        q.emplace(dist[e.to], e.to);
                    }
                }
            }
            is_init = false;

            // cout << "---" << endl;
        }
        if (dist[i] != INF ) cout << dist[i] << endl;
        else cout << -1 << endl;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}