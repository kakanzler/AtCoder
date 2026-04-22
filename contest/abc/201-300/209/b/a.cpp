#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG//[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意 ABC311Eのサンプル4みたいなデバック中のTLEは防げないので注意
#endif

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


void solve() {
    int n, x; cin >> n >> x;
    int ans = 0;
    for (int i = 0; i < n; i++){
        int a; cin >> a; ans += a;
    }
    ans -= n/2;
    if (ans <= x) cout << "Yes\n";
    else cout << "No\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}