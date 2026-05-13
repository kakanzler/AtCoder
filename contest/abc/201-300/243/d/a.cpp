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

#include <boost/multiprecision/cpp_int.hpp>//インストール的なのをしてないとできないので注意
namespace multip = boost::multiprecision;
//using lll = multip::cpp_int;//無制限を使いたいときはこっちを使う
using lll = multip::int128_t;

using ld = long double;
using bl = bool;
using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint;//使うときはコメントアウトを外す
//mint::set_mod(m);//使うときはコメントアウトを外す

template<class T> using pq = priority_queue<T, vc<T>>;//大きい順
template<class T> using pq_g = priority_queue<T, vc<T>, greater<T>>;//小さい順
//-----------------------------------



//-------------2.配列系--------------
using vl = vc<ll>;

//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)

void solve() {
    ll n, x; cin >> n >> x;
    string s; cin >> s;

    string t;
    for (char c : s){
        if (c == 'U'){
            if (!t.empty() && (t.back() == 'L' || t.back() == 'R')){
                t.pop_back();
            } else {
                t.push_back(c);
            }
        } else {
            t.push_back(c);
        }
    }

    for (char c : t) {
        if (c == 'U') x /= 2;
        else if (c == 'L') x *= 2;
        else if (c == 'R') x = x * 2 + 1;
    }
    cout << x << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}