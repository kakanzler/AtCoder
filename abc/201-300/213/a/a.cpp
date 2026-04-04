#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG//[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意 ABC311Eのサンプル4みたいなデバック中のTLEは防げないので注意
#endif

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

using ll = long long;
#define out(n) cout << n << endl;

void solve() {
    ll a, b;
    cin >> a >> b;
    ll ans = (a xor b);
    out(ans);
    return;
}

int main() {solve();
}