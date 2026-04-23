#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG//[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意 ABC311Eのサンプル4みたいなデバック中のTLEは防げないので注意
#endif

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


void solve() {
    set<string> s;
    for (int i = 0 ; i < 4 ; i++ ) {
        string a; cin >> a;
        s.insert(a);
    }

    if (s.size() == 4) cout << "Yes\n";
    else cout << "No\n";

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}