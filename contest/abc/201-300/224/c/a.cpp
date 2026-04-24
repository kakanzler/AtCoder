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
double INF = 2e18;

//-------------2.配列系--------------
using vl = vc<ll>;

//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)

void solve() {
    ll n; cin >> n;
    vector<double> x(n), y(n);
    rep(i, n){
        double xx, yy;
        cin >> xx >> yy;
        x[i] = xx;
        y[i] = yy;
    }

    auto isTri = [&](ll i, ll j, ll k){
        double a = INF, b = INF;

        if (x[i] != x[j]) a = (y[i] - y[j]) / (x[i] - x[j]);
        if (x[k] != x[j]) b = (y[k] - y[j]) / (x[k] - x[j]);
        return (a != b);
    };

    ll ans = 0;
    for (ll i = 0; i < n-2; ++i ){
        for (ll j = i+1; j < n-1; ++j ){
            for (ll k = j+1; k < n; ++k ){
                if (isTri(i, j, k)) ans++;
            }
        }
    }
    cout << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}