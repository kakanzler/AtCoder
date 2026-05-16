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
//-------------2.配列系--------------
using vl = vc<ll>; using vvl = vv<ll>;
using vb = vc<bool>; using vvb = vv<bool>;

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
    ll a, b, c; cin >> a >> b >> c;
    vector dp(a+1, vector<vector<vector<mint>>>(b+1, vector<vector<mint>>(c+1, vector<mint>(4, 0))));
    vector seen(a+1, vector<vector<vector<bool>>>(b+1, vector<vector<bool>>(c+1, vector<bool>(4, false))));

    auto f = [&](auto self, ll a, ll b, ll c, ll from) -> mint {
        if (a == 0 && b == 0 && c == 0) return 1;

        if (seen[a][b][c][from]) return dp[a][b][c][from];
        seen[a][b][c][from] = true;

        mint ans = 0;
        if (a > 0 && from != 2) ans += self(self, a-1, b, c, 0);
        if (b > 0)              ans += self(self, a, b-1, c, 1);
        if (c > 0 && from != 0) ans += self(self, a, b, c-1, 2);

        return dp[a][b][c][from] = ans;
    };

    mint ans = f(f, a, b, c, 3);
    cout << ans.val() << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}