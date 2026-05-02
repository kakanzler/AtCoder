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
//-------------2.配列系--------------
using vl = vc<ll>; using vvl = vv<ll>; using vvvl = vv<vl>; using vvvvl = vv<vvl>;


//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define drep(i,n) for(ll i = (n)-1; i >= 0; --i)
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

void solve() {
    ll N, W; cin >> N >> W;
    vl w(N), v(N);
    rep(i, N){
        cin >> w[i] >> v[i];
    }

    vl dp(W+1, 0);
    rep(i, N){
        for (ll j = W; w[i] <= j ; --j){
            chmax(dp[j], dp[j - w[i]] + v[i]);

            // debug
            // cout << dp[j] << ' ';
        }
        // debug
        // cout << endl;
    }


    cout << dp[W] << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
