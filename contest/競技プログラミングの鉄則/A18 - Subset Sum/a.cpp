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

template <class T> bool chmax (T& a, T b){
    if (a < b){
        a = b;
        return true;
    }
    return false;
};
template <class T> bool chmin (T& a, T b){
    if (a > b){
        a = b;
        return true;
    }
    return false;
};
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl

//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)

void solve() {
    ll n, s; cin >> n >> s;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<bool> dp(s+1, false);
    dp[0] = true;

    rep(i, n){
        for (ll j = s; j >= a[i]; --j){
            if (dp[j - a[i]]) dp[j] = true;
        }
    }

    if (dp[s]) YES;
    else NO;

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
