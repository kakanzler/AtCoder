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
using vl = vc<ll>; using vvl = vv<ll>; using vvvl = vv<vl>; using vvvvl = vv<vvl>;

//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)

#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
//----------------------------------------------

void solve() {
    ll n, m; cin >> n >> m;
    vvl edge(n);
    rep(i, m){
        ll u, v; cin >> u >> v; u--; v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    // 頂点の次数をチェック
    rep(i,n) {
        if (edge[i].size() >= 3){
            NO;
            return;
        }
    }

    // サイクルと連結性をチェック
    if (m != n-1) {
        NO;
        return;
    }

    // bfs
    queue<ll> q;
    q.push(0);
    vl prev(n, -1);
    prev[0] = -2;
    while(!q.empty()){
        ll v = q.front(); q.pop();
        for (ll nv : edge[v]){
            if (prev[nv] != -1) continue;
            prev[nv] = v;
            q.push(nv);
        }
    }

    // ans
    rep(i, n){
        if (prev[i] == -1){
            NO;
            return;
        }
    }
    YES;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}