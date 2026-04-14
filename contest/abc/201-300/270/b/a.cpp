#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG//[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意 ABC311Eのサンプル4みたいなデバック中のTLEは防げないので注意
#endif

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//-------------1.型系---------------
using ll = long long;
//----------------------------------------------

void solve() {
    ll x, y, z; cin >> x >> y >> z;
    ll ans = -1;

    // goalまで壁はあるか？
    if (0 < y && y < x ) {
        // 壁がある場合、ハンマーはたどり着ける位置にあるか？
        if ( 0 < z && z < y) {
            ans = x;
        } else if (z < 0) {
            ans = x + abs(z) * 2;
        }
    } else if ( x < y && y < 0 ) {
        // 壁がある場合、ハンマーはたどり着ける位置にあるか？
        if ( y < z && z < 0) {
            ans = abs(x);
        } else if (0 < z) {
            ans = abs(x) + abs(z) * 2;
        }

    } else {
        ans = abs(x);
    }
    cout << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}