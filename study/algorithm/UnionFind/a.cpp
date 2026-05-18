#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;

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

template<class T> using pq = priority_queue<T, vc<T>>;
template<class T> using pq_g = priority_queue<T, vc<T>, greater<T>>;

using vl = vc<ll>; using vvl = vv<ll>; using vvvl = vv<vl>; using vvvvl = vv<vvl>;
using vs = vc<string>; using vvs = vv<string>;
using vb = vc<bl>; using vvb = vv<bl>; using vvvb = vv<vb>;
using vld = vc<ld>; using vvld = vv<ld>; using vvvld = vv<vld>;
using P = pair<ll, ll>;
using vmint = vc<mint>; using vvmint = vv<mint>; using vvvmint = vv<vmint>;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define rrep(i,n) for(ll i = 1; i <= (n); ++i)
#define drep(i,n) for(ll i = (n)-1; i >= 0; --i)
#define nfor(i,s,n) for(ll i=s;i<n;i++)//i=s,s+1...n-1 ノーマルfor
#define dfor(i,s,n) for(ll i = (s)-1; i>=n;i--)//s-1スタートでnまで落ちる

#define nall(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

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


class UnionFind{
    vector<int> par, siz;

    UnionFind(int n) : par(n), siz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }

    int root(int x) {
        if  (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);

        if (x == y) return false;

        if (siz[x] < siz[y]) swap(x, y);

        par[y] = x;
        siz[x] += siz[y];

        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }

};


void solve() {
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}