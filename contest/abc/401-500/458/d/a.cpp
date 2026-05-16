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

template<class T> using pq = priority_queue<T, vc<T>>;//大きい順
template<class T> using pq_g = priority_queue<T, vc<T>, greater<T>>;
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

void solve() {
    ll x; cin >> x;
    ll q; cin >> q;

    multiset<ll> m;
    m.insert(x);
    auto iter = m.begin();
    rep(i, q){
        ll a, b; cin >> a >> b;
        m.insert(a);
        m.insert(b);

        if (*iter < a and *iter < b) iter++;
        if (*iter > a and *iter > b) iter--;
        cout << *iter << endl;

        // vl v(m.begin(), m.end());
        // rep(k, ((i+1)+1)/2 ) cout << v[k] << ' ';
        // cout << endl;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}