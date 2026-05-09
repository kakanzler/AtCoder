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
ll INF = 2e18;

//-------------2.配列系--------------
using vl = vc<ll>; using vvl = vv<ll>;
using vs = vc<string>; using vvs = vv<string>;

//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)

template<class T> bool chmin (T &a, T b){
    if (a > b) {
        a = b;
        return true;
    } else {
        return false;
    }
}
template<class T> bool chmax (T &a, T b){
    if (a < b) {
        a = b;
        return true;
    } else {
        return false;
    }
}

#define pb push_back

void solve() {
    ll n; cin >> n;
    vs s(n);
    rep(i, n) cin >> s[i];

    ll ans = INF;

    rep(d, 10) {
        vl cnt(10, 0);

        rep(i, n) {
            rep(j, 10) {
                if (s[i][j] - '0' == d) {
                    cnt[j]++;
                }
            }
        }

        ll now = 0;
        rep(j, 10) {
            if (cnt[j] > 0) {
                chmax(now, j + 10 * (cnt[j] - 1));
            }
        }

        chmin(ans, now);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}