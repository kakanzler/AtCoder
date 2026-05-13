#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG//[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意 ABC311Eのサンプル4みたいなデバック中のTLEは防げないので注意
#endif

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


template<typename T> using vc = vector<T>;

//-------------1.型系---------------
using ll = long long;
//-------------2.配列系--------------
using vl = vc<ll>;

//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)

void solve() {
    ll n; cin >> n;

    vl a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    ll ans = 0;
    rep(i, n) if (a[i] == b[i]) ans++;
    cout << ans << endl;

    ans = 0;
    rep(i, n) rep(j,n){
        if (i == j) continue;
        if (a[i] == b[j]) ans++;
    };
    cout << ans << endl;

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}