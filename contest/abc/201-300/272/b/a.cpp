#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG//[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意 ABC311Eのサンプル4みたいなデバック中のTLEは防げないので注意
#endif

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//-------------1.型系---------------
using ll = long long;


//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)

#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<vector<bool>> mat(n, vector<bool>(n, false));
    rep(i, m){
        ll k; cin >> k;
        vector<ll> vx(k);
        rep(j, k){
            ll x; cin >> x;
            x--;
            vx[j] = x;
        }

        rep(a, k-1){
            for (ll b = a+1; b < k; ++b){
                mat[vx[a]][vx[b]] = true;
            }
        }
    }

    // debug
    // rep(i, n) {
    //     for (ll j = i+1; j <n; j++){
    //         cout << mat[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    // ans
    rep(i, n) {
        for (ll j = i+1; j <n; j++){
            if (!mat[i][j]){
                NO;
                return;
            }
        }
    }
    YES;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}