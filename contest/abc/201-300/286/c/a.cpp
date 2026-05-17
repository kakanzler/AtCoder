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
using vl = vc<ll>;

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

void solve() {
    ll n, a, b; cin >> n >> a >> b;
    string s; cin >> s;

    auto f = [&](string t) -> ll {
        ll count = 0;
        for (ll i = 0; i < n/2 ; i++) if (t[i] != t[n-i-1]) count++;

        return count;
    };


    ll ans = INF;
    rep(i, n){
        chmin(ans, f(s)*b + a*i);
        s.push_back(s[0]);
        s = s.substr(1, n);
    }
    cout << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}