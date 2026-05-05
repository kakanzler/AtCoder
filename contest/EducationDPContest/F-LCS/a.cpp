#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG//[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意 ABC311Eのサンプル4みたいなデバック中のTLEは防げないので注意
#endif

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


template<typename T> using vc = vector<T>;//prioriy_queueに必要なのでここにこれ書いてます

//-------------1.型系---------------
using ll = long long;

//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)

void solve() {
    string s, t; cin >> s >> t;

    ll sn = (ll)s.size();
    ll tn = (ll)t.size();

    /*
    dp： 文字列ｓのｉ番目までの文字列までで、文字列ｔのｊ番目までの文字列との最大の部分列を保存する
    */
    // 2-dim dp
    // vc<vc<pair<string, ll>>> dp(sn+1, vc<pair<string, ll>>(tn+1, {"", -1}));

    // 1-dim dp
    vc<pair<string, ll>> dp(tn+1, {"", -1});

    rep(i, sn){
        // 2-dim dp
        // bool updated = false;
        rep(j, tn){
            // 2-dim dp
            // dp[i+1][j+1] = (dp[i+1][j].first.size() > dp[i][j+1].first.size() ? dp[i+1][j] : dp[i][j+1]);

            // 1-dim dp
            if (dp[j].first.size() <= dp[j+1].first.size() && dp[j+1].second < j && s[i] == t[j]) {
                dp[j+1].first += s[i];
                dp[j+1].second = j;
            } else if (dp[j+1].first.size() <= dp[j].first.size()) dp[j+1] = dp[j];


            // 2-dim dp
            // if (s[i] == t[j] && dp[i+1][j].first.size() <= dp[i][j+1].first.size()) updated = false;
            // if (!updated && dp[i][j+1].second < j && s[i] == t[j]){
            //     dp[i+1][j+1].first += s[i];
            //     dp[i+1][j+1].second = j;
            //     updated = true;
            // }

            // debug: for 1-dim dp
            // cout << dp[j+1].first << ' ';
        }
        // debug: for 1-dim dp
        // cout << endl;
    }

    // debug: for 2-dim dp
    // rep(i, sn+1){
    //     rep(j, tn+1){
    //         cout << dp[i][j].first << ' ';
    //     }
    //     cout << endl;
    // }

    // cout << dp[sn][tn].first << endl;
    cout << dp[tn].first << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
