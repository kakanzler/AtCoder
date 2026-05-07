#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG//[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意 ABC311Eのサンプル4みたいなデバック中のTLEは防げないので注意
#endif

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;



void solve() {
    string s; cin >> s;
    map<string , int> m;
    m["Monday"] = 5;
    m["Tuesday"] = 4;
    m["Wednesday"] = 3;
    m["Thursday"] = 2;
    m["Friday"] = 1;
    cout << m[s] << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}