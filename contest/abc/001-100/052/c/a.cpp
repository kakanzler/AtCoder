#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG//[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意 ABC311Eのサンプル4みたいなデバック中のTLEは防げないので注意
#endif

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//-------------1.型系---------------
using ll = long long;
using mint = modint1000000007;


void solve() {
    ll n; cin >> n;

    mint ans = 1;

    map<ll, ll> prime_cnt;
    for(ll i = 1; i <= n ; ++i){
        ll x = i;
        for(ll divisor = 2; divisor*divisor <= x ; ++divisor){

            while (x % divisor == 0){
                prime_cnt[divisor]++;
                x /= divisor;
            }
        }
        if (x > 1) prime_cnt[x]++;
    }

    for (auto [k, v] : prime_cnt){
        // debug
        // cout << "k: " << k << " v: " << v << endl;
        ans *= v + 1 ;
    }

    cout << ans.val() << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}