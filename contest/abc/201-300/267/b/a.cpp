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
using ull = unsigned long long;
ll INF = 2e18;

using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint;//使うときはコメントアウトを外す
//mint::set_mod(m);//使うときはコメントアウトを外す

//-------------2.配列系--------------
using vl = vc<ll>; using vvl = vv<ll>; using vvvl = vv<vl>; using vvvvl = vv<vvl>;
using vs = vc<string>; using vvs = vv<string>;


//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define nfor(i,s,n) for(ll i=s;i<n;i++)//i=s,s+1...n-1 ノーマルfor
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
#define YN {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}// if(a==b)YN;
#define dame cout<<-1<<endl
//----------------------------------------------

void solve() {
    string s; cin >> s;
    bool is_split = false;

    vector<bool> lane(7, true);

    if (s[0]-'0') {
        NO;
        return;
    }
    if (s[6]-'0') lane[0] = false;
    if (s[3]-'0') lane[1] = false;
    if (s[1]-'0' || s[7]-'0') lane[2] = false;
    if (s[0]-'0' || s[4]-'0') lane[3] = false;
    if (s[2]-'0' || s[8]-'0') lane[4] = false;
    if (s[5]-'0') lane[5] = false;
    if (s[9]-'0') lane[6] = false;

    // rep(i, 10) cout << i << " : " <<  s[i]-'0' << ' ';
    // cout << endl;

    // rep(i, 7) cout << lane[i] << ' ';
    // cout << endl;

    rep(i, 5) {
        nfor(j, i+1, 7){
            nfor (k, i+1, j){
                if ((!lane[i] && !lane[j]) && lane[k]){
                    is_split = true;
                }
            }
        }
    }
    if (is_split) YN;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}