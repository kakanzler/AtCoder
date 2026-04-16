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
    ll ans = 0;

    rep(dn,10){

        ll N = (x - b*(dn+1)) / a;
        N = min(N, (ll)(pow(10, (dn+1))-1));
        if (N > 1000000000) {
            ans = 1000000000;
            break;
        }
        if (pow(10, dn) <= N && N < pow(10,(dn+1))) ans = max(ans, N);
    }
    cout << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}