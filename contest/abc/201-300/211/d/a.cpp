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

//-------------2.配列系--------------
using vl = vc<ll>; using vvl = vv<ll>;



//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)

//----------------------------------------------
const ll MOD = 1000000007;

void solve() {
    ll n, m; cin >> n >> m;
    vvl g(n);
    rep(i, m){
        ll a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    queue<ll> q;
    q.push(0);
    vl dist(n, -1);
    dist[0] = 0;
    vl total(n, 0);
    total[0] = 1;

    while(q.size()){
        ll v = q.front(); q.pop();
        for (ll nv : g[v]){
            if (dist[nv] != -1) {
                if (dist[nv] == dist[v] + 1) {
                    total[nv] += total[v];
                    total[nv] %= MOD;
                }
                continue;
            }
            q.push(nv);
            dist[nv] = dist[v] + 1;
            total[nv] = total[v];
        }
    }

    cout << total[n-1] << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}