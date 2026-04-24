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

#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
void solve() {
    ll h, w; cin >> h >> w;
    vvl a(h, vl(w));
    rep(i, h) rep(j, w){
        ll aa; cin >> aa;
        a[i][j] = aa;
    }
     for (ll i = 0; i < h-1 ; i++){
         for (ll j = i+1; j < h ; j++){
            for (ll k = 0; k < w-1 ; k++){
                for (ll l = k+1; l < w ; l++){
                    if (a[i][k] + a[j][l] > a[j][k] + a[i][l]) {
                        NO;
                        return;
                    }
                }
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