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

//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)

//----------------------------------------------

void solve() {
    ll n; cin >> n;
    string s; cin >> s;
    for (char c : s){
        char ans = (c - 'A' + n) % 26 + 'A' ;
        cout << ans;
    }
    cout << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}