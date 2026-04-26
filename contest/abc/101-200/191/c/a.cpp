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
using vl = vc<ll>; using vvl = vv<ll>; using vvvl = vv<vl>; using vvvvl = vv<vvl>;
using vs = vc<string>; using vvs = vv<string>;
#define rep(i,n) for(ll i = 0; i < (n); ++i)

void solve() {
    ll h, w; cin >> h >> w;
    vs g(h);
    rep(i, h) cin >> g[i];

    ll ans = 0;
    rep(i, h-1) rep(j, w-1) {
        ll cnt = 0;

        rep(di, 2)rep(dj, 2) if (g[i+di][j+dj] == '#') cnt++;

        if  (cnt == 1 || cnt == 3) ans++;
    }
    cout << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}