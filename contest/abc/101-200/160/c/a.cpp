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

void solve() {
    ll k, n; cin >> k >> n;
    ll ans = 0;
    vl a(n+1,0);
    rep(i, n) {
        cin >> a[i];
    }
    a[n] = k+a[0];
    rep(i, n) {
        ans = max(ans, a[i+1] - a[i]);
    }
    cout << k-ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}