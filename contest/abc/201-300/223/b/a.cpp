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

template<class T> using pq = priority_queue<T, vc<T>>;//大きい順
template<class T> using pq_g = priority_queue<T, vc<T>, greater<T>>;//小さい順

//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)

#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
#define YN {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}// if(a==b)YN;
#define dame cout<<-1<<endl
//----------------------------------------------

void solve() {
    string s; cin >> s;
    ll n = (ll)s.size();

    pq<string> q;
    pq_g<string> qg;
    string t;
    rep(i, n){
        t = s.substr(i, n-i) + s.substr(0, i);
        q.push(t);
        qg.push(t);
    }
    cout << qg.top() << endl;
    cout << q.top() << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}