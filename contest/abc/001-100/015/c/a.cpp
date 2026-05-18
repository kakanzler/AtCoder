#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


template<typename T> using vc = vector<T>;//prioriy_queueに必要なのでここにこれ書いてます
template<typename T> using vv = vc<vc<T>>;

//-------------1.型系---------------
using ll = long long;

//-------------2.配列系--------------
using vl = vc<ll>; using vvl = vv<ll>;


//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)

void solve() {
    ll n, k; cin >> n >> k;
    vvl t(n, vl(k, -1));
    rep(i, n) rep(j, k) cin >> t[i][j];

    // rep(i, n) {
    //     rep(j, k) cout << t[i][j] << ' ';
    //     cout << endl;
    // }

    bool found = false;
    auto dfs = [&](auto self, ll i, ll x) -> void {
        if (i == n) {
            if (x == 0) found = true;
            return;
        }

        rep(j, k){
            self(self, i + 1, x ^ t[i][j]);
        }
    };

    dfs(dfs, 0, 0);

    if (found) cout << "Found" << endl;
    else cout << "Nothing" << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}