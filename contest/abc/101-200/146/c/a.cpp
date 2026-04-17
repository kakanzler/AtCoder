#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG//[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意 ABC311Eのサンプル4みたいなデバック中のTLEは防げないので注意
#endif

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;



//-------------1.型系---------------
using ll = long long;

//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)

void solve() {
    ll a,b,x; cin >> a >> b >> x;

    auto digit = [&](ll n){
        return (ll)to_string(n).size();
    };

    auto ok = [&](ll n){
        return a* n + b * digit(n) <= x;
    };

    ll l=0, r=1000000001LL; // [l,r)
    while( r - l > 1){
        ll center = (r + l) / 2;
        if (ok(center)) l = center;
        else r = center;
    }

    cout << l << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}