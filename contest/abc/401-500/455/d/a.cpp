#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG//[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意 ABC311Eのサンプル4みたいなデバック中のTLEは防げないので注意
#endif

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

template<typename T> using vc = vector<T>;//prioriy_queueに必要なのでここにこれ書いてます
//-------------1.型系---------------
using ll = long long;
//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)


void solve() {
    ll n, q; cin >> n >> q;

    vector<ll> to(n,-1);
    vector<bool> top(n, true);

    rep(_, q){
        ll c, p; cin >> c >> p;
        c--; p--;

        top[p] = false;
        if(to[c] != -1) top[to[c]] = true;
        to[c] = p;
    }

    vector<ll> ans(n);
    rep(i, n) if (top[i]){
        ll v = i, cnt = 1;
        while(to[v] != -1){
            v = to[v];
            cnt++;
        }
        ans[v] = cnt;
    }

    rep(i, n) cout << ans[i] << ' ';
    cout << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}