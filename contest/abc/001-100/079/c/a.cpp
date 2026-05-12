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
    ll n; cin >> n;

    map<ll, ll> ma;
    rep(i, n) {
        ll a; cin >> a;
        ma[a]++;
    }

    ll ans = 0;
    for (auto [key, value] : ma){
        ans += value % 2;
    }
    cout << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}