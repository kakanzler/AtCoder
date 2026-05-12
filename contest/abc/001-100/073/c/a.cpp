#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG//[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意 ABC311Eのサンプル4みたいなデバック中のTLEは防げないので注意
#endif

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//-------------1.型系---------------
using ll = long long;;

#define rep(i,n) for(ll i = 0; i < (n); ++i)

void solve() {
    ll n, k; cin >> n >> k;

    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll acc = 0;
    rep(i, k) acc += a[i];

    ll ans = acc;
    rep(i, n-k) {
        acc -= a[i];
        acc += a[i+k];
        ans += acc;
    }
    cout << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}