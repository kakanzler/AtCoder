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
using vl = vc<ll>; using vvl = vv<ll>;

//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)


void solve() {
    ll n; cin >> n;
    string s; cin >> s;

    vl parent(n+1, -1);
    vl child(n+1, -1);
    rep(i, n){
        if (s[i] == 'L'){
            if (parent[i] != -1){
                child[parent[i]] = i+1;
                parent[i+1] = parent[i];
            }
            parent[i] = i+1;
            child[i+1] = i;
        } else {
            if (child[i] != -1){
                parent[child[i]] = i+1;
                child[i+1] = child[i];
            }
            parent[i+1] = i;
            child[i] = i+1;
        }

        // debug
        // cout << "p : ";
        // rep(i, n+1) cout << parent[i] << ' ';
        // cout << endl;
        // cout << "c : ";
        // rep(i, n+1) cout << child[i] << ' ';
        // cout << endl;
    }

    // cout << "---" << endl;

    ll head = 0;
    rep(i, n+1) {
        if (parent[i] == -1){
            head = i;
        }
    }

    rep(i, n+1){
        cout << head << ' ';
        head = child[head];
    }
    cout << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}