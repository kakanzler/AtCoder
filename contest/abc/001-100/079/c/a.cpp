#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG//[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意 ABC311Eのサンプル4みたいなデバック中のTLEは防げないので注意
#endif

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//-------------1.型系---------------
using ll = long long;;

#define rep(i,n) for(ll i = 0; i < (n); ++i)

void solve() {
    string s; cin >> s;
    vector<ll> v(4);
    ll a = s[0] - '0';
    ll b = s[1] - '0';
    ll c = s[2] - '0';
    ll d = s[3] - '0';

    ll count = 0;
    vector<vector<char>> op(8);
    while(count < 8){
        ll ans = a;
        ans = ((count>>2) %2 == 0 ? ans-b : ans+b);
        ans = ((count>>1) %2 == 0 ? ans-c : ans+c);
        ans = (count%2 == 0 ? ans-d : ans+d);
        if (ans == 7) break;
        count++;
    }
    cout << s[0] << ((count>>2) %2 == 0 ? '-' : '+') << s[1] << ((count>>1) %2 == 0 ? '-' : '+')<< s[2] <<((count) %2 == 0 ? '-' : '+')<< s[3] << "=7" << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}