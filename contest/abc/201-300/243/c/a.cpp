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

#define pb push_back

#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl

void solve() {
    ll n; cin >> n;
    // vector<pair<ll, ll>> c(n);

    vl x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    string s; cin >> s;

    map<ll, pair<ll, ll>> m;
    rep(i, n) m[y[i]] = {INF, -INF};
    rep(i, n){
        if (s[i] == 'R' ){
            if (m[y[i]].second > x[i]){
                YES; return;
            } else {
                chmin(m[y[i]].first, x[i]);
            }
        } else {
            if (m[y[i]].first < x[i]){
                YES; return;
            } else {
                chmax(m[y[i]].second, x[i]);
            }
        }
    }
    NO;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}