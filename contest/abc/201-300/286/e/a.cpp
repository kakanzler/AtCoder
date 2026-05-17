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
//----------------------------------



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
    ll n; cin >> n;
    vl a(n);
    rep(i, n) cin >> a[i];
    vector<string> s(n);
    vvl gw(n, vl(n, INF));
    vvl gl(n, vl(n, INF));
    rep(i, n) {gl[i][i] = 0; gw[i][i] = 0;}
    rep(i, n) {
        cin >> s[i];
        rep (j, n) if (s[i][j] == 'Y') {
            gw[i][j] = a[j];
            gl[i][j] = 1;
        }
    }

    // // debug
    // rep(i, n) {
    //     rep(j, n) cout << gw[i][j] << ' ';
    //     cout << endl;
    // }
    // cout << "---" << endl;
    // rep(i, n) {
    //     rep(j, n) cout << gl[i][j] << ' ';
    //     cout << endl;
    // }
    // cout << "---" << endl;

    rep(k, n) rep(i, n) rep(j, n) {
        if (gl[i][k] == INF || gl[k][j] == INF) continue;

        if (gl[i][j] == gl[i][k] + gl[k][j]){
            chmax(gw[i][j], gw[i][k] + gw[k][j]);
        } else if (gl[i][j] > gl[i][k] + gl[k][j]) {
            gl[i][j] = gl[i][k] + gl[k][j];
            gw[i][j] = gw[i][k] + gw[k][j];
        }
    }

    // // debug
    // rep(i, n) {
    //     rep(j, n) cout << gw[i][j] << ' ';
    //     cout << endl;
    // }
    // cout << "---" << endl;
    // rep(i, n) {
    //     rep(j, n) cout << gl[i][j] << ' ';
    //     cout << endl;
    // }
    // cout << "---" << endl;

    ll q; cin >> q;
    rep(i, q){
        ll u, v; cin >> u >> v;
        u--; v--;

        if (gl[u][v] != INF) cout << gl[u][v] << ' ' << gw[u][v] + a[u] << endl;
        else cout << "Impossible" << endl;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}