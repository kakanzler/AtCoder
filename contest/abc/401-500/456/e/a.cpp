#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
using vvl = vv<ll>;
using vb = vc<bool>;
using vvb = vv<bool>;
using vs = vc<string>;

#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define pb push_back
#define YES cout << "Yes\n"
#define NO cout << "No\n"

void solve() {
    ll n, m; cin >> n >> m;
    vvl g(n);
    rep(i, n) g[i].pb(i);
    rep(i, m){
        ll u, v; cin >> u >> v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    ll w; cin >> w;
    vs s(n);
    rep(i, n) cin >> s[i];

    auto id = [&](ll v, ll d) {
        return v * w + d;
    };

    // 1. 到達可能な状態だけ調べる
    vvb reach(n, vb(w, false));
    queue<pair<ll,ll>> q;

    rep(i, n) {
        if (s[i][0] == 'o') {
            reach[i][0] = true;
            q.emplace(i, 0);
        }
    }

    while (!q.empty()) {
        auto [v, d] = q.front();
        q.pop();

        ll nd = (d + 1) % w;

        for (ll nv : g[v]) {
            if (s[nv][nd] == 'x') continue;
            if (reach[nv][nd]) continue;

            reach[nv][nd] = true;
            q.emplace(nv, nd);
        }
    }

    // 2. 到達可能状態グラフを作ってSCC
    scc_graph sg(n * w);

    rep(v, n) {
        rep(d, w) {
            if (!reach[v][d]) continue;

            ll nd = (d + 1) % w;

            for (ll nv : g[v]) {
                if (s[nv][nd] == 'x') continue;
                if (!reach[nv][nd]) continue;

                sg.add_edge(id(v, d), id(nv, nd));
            }
        }
    }

    auto groups = sg.scc();

    for (auto &comp : groups) {
        if ((ll)comp.size() >= 2) {
            YES;
            return;
        }
    }

    // self-loop 判定
    rep(v, n) {
        rep(d, w) {
            if (!reach[v][d]) continue;

            ll nd = (d + 1) % w;

            for (ll nv : g[v]) {
                if (s[nv][nd] == 'x') continue;
                if (!reach[nv][nd]) continue;

                if (id(v, d) == id(nv, nd)) {
                    YES;
                    return;
                }
            }
        }
    }
    NO;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin >> t;
    rep(i, t) solve();
}