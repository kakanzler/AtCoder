#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define ll long long
#define rep(i, n) for (ll i=0; i<n; ++i)
#define out(n) cout << n << endl;
#define Yes() cout << "Yes" << endl;
#define No() cout << "No" << endl;

template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
using vl = vc<ll>;


double get_fr(string portion_t){
    ll lent = portion_t.size();
    double fr = 0;
    double count = 0;
    vl tv;
    rep(i, lent) {
        if (portion_t[i] == 't'){
            tv.push_back(i);
            count++;
        }
    }
    if (count >= 3){
        fr = (count - 2) / (tv[count -1] - tv[0] + 1 - 2);
    }
    return fr;
}

void solve(){
    string S;
    cin >> S;
    ll len = S.size();

    double ans = 0.0;
    rep(i, len-2) for(ll j = 3 ; j<len-i+1 ; ++j){
        string portion = S.substr(i, j);
        // cout << i << ";" << j <<";" << portion << endl;
        ans = max(ans, get_fr(portion));
    }
    printf("%.10g\n", ans);
    return;
}

int main(){
    solve();
}