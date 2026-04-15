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
using vl = vc<ll>; using vvl = vv<ll>; using vvvl = vv<vl>; using vvvvl = vv<vvl>;
using vs = vc<string>; using vvs = vv<string>;
using vb = vc<bl>; using vvb = vv<bl>; using vvvb = vv<vb>;
using vld = vc<ld>; using vvld = vv<ld>; using vvvld = vv<vld>;
using P = pair<ll, ll>;
using vmint = vc<mint>; using vvmint = vv<mint>; using vvvmint = vv<vmint>;

//配列外参照対策のやつは一番上の行にあります

#define rep(i,n) for(ll i = 0; i < (n); ++i)//↓でrepを使うので書いてます
template<class T>istream& operator>>(istream& i, vc<T>& v) { rep(j, size(v))i >> v[j]; return i; }

using ar2 = array<ll, 2>;

//----------------------------------



//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)

void solve() {
    ll t; cin >> t;
    rep(i, t){
        ll n; cin >> n;
        ll ans=0, a=0;
        rep(j, n) {
            cin >> a;
            if (a % 2) ans++;
        }
        cout << ans << endl;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}