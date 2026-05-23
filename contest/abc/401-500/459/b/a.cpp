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
using ull = unsigned long long;
ll INF = 2e18;

using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint;//使うときはコメントアウトを外す
//mint::set_mod(m);//使うときはコメントアウトを外す

//-------------2.配列系--------------
using vl = vc<ll>; using vvl = vv<ll>; using vvvl = vv<vl>; using vvvvl = vv<vvl>;
using vs = vc<string>; using vvs = vv<string>;


//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)

#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
#define YN {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}// if(a==b)YN;
#define dame cout<<-1<<endl
//----------------------------------------------

void solve() {
    ll n; cin >> n;
    string s;
    rep(i, n) {
        ll ans = 2;
        cin >> s;
        if (s[0] == 'a' || s[0] == 'b' || s[0] == 'c') ans = 2;
        else if (s[0] == 'd' || s[0] == 'e' || s[0] == 'f') ans = 3;
        else if (s[0] == 'g' || s[0] == 'h' || s[0] == 'i') ans = 4;
        else if (s[0] == 'j' || s[0] == 'k' || s[0] == 'l') ans = 5;
        else if (s[0] == 'm' || s[0] == 'n' || s[0] == 'o') ans = 6;
        else if (s[0] == 'p' || s[0] == 'q' || s[0] == 'r' || s[0] == 's') ans = 7;
        else if (s[0] == 't' || s[0] == 'u' || s[0] == 'v') ans = 8;
        else if (s[0] == 'w' ||s[0] == 'x' || s[0] == 'y' || s[0] == 'z') ans = 9;

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