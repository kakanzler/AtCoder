# include <bits/stdc++.h>
# include <atcoder/all>
using namespace std;

#define ll long long
ll INF = 2e18;

#define rep(i,n) for(int i=0; i<n; ++i)
#define REP(i,n) for(int i=0; i<=n; ++i)
#define Yes cout << "Yes" << endl
#define yes cout << "yes" << endl
#define No cout << "No" << endl
#define no cout << "no" << endl
#define out(n) cout << n << endl



int main(){
    string N;
    cin >> N;

    int digit = size(N);
    ll ans = INF;
    // bit探索
    for (int bit = 0; bit < (1 << digit) ; ++bit){
        string tmp_c = "";
        ll n_tmp = 0;
        // 数字を作る。
        rep(i, digit) {
            if ((1 & (bit >> i) ) == 1) {
                tmp_c += N[i];
            } else {
                n_tmp += 1;
            }
        }
        // 評価
        if (!tmp_c.empty()) {
            ll val = stoll(tmp_c);
            if (val % 3 == 0) ans = min(ans, n_tmp);
        }
    }
    if (ans == INF){
        out(-1);
    }else{
        out(ans);
    }

}
