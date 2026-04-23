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

//----------------------------------------------
const ll m = 1000000007;

void solve() {
    string s; cin >> s;

    vl dp(9, 0);
    string cho = "chokudai";

    dp[0] = 1;

    for (char c: s){
        drep(i, 8) {
            if (cho[i] == c) {
                dp[i+1] += dp[i];
                dp[i+1] %= m;
            }
            // cout << dp[i] << ' ';
        }
        // cout << endl;
    }

    cout << dp[8] << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}