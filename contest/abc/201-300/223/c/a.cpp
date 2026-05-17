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
using vl = vc<ll>;

//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)

void solve() {
    ll n; cin >> n;
    vector<double> a(n), b(n);
    double total = 0;
    rep(i, n) {
        cin >> a[i] >> b[i];
        total += a[i] / b[i];
    }
    double t = total / 2.0;
    double ans = 0;

    rep(i, n) {
        double burn_time = a[i] / b[i];

        if (t >= burn_time) {
            ans += a[i];
            t -= burn_time;
        } else {
            ans += b[i] * t;
            break;
        }
    }

    cout << setprecision(6) << fixed << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}