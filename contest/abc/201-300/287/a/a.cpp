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
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
//----------------------------------------------

void solve() {
    ll n; cin >> n;
    ll f=0, a=0;
    rep(i,n){
        string s; cin >> s;
        if (s == "For") f++;
        else a++;
    }
    if (f > a) YES;
    else NO;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}