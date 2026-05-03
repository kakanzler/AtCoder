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

using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint;//使うときはコメントアウトを外す
//mint::set_mod(m);//使うときはコメントアウトを外す

//-------------2.配列系--------------
using vl = vc<ll>; using vvl = vv<ll>; using vvvl = vv<vl>; using vvvvl = vv<vvl>;
using vb = vc<bool>; using vvb = vv<bool>;
using vs = vc<string>; using vvs = vv<string>;


//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)

#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl

//----------------------------------------------

void solve() {
    ll n,m; cin >> n >> m;
    vvl v(m, vl(n, 0));
    rep(i, m) rep(j, n) {
        ll a; cin >> a;
        a--;
        v[i][j] = a;
    }
    vvb g(n, vb(n, false));
    rep(i, m) rep(j, n-1) {
        g[v[i][j]][v[i][j+1]] = true;
        g[v[i][j+1]][v[i][j]] = true;
    }

    ll ans = 0;
    rep(i, n) {
        for (ll j = i+1 ; j < n ; j++ ) {
            // cout << g[i][j] << ' ';
            if (!g[i][j]) ans++;
        }
        // cout << endl;
    }

    cout << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}