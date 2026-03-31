#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

#define ll long long
#define rep(i, n) for (int i=0; i<n; ++i)
#define out(n) cout << n << endl;
#define Yes() cout << "Yes" << endl;
#define No() cout << "No" << endl;

void solve(){
    string S, s1;
    cin >> S;
    s1 = (char)tolower((unsigned char)S[0]) + S.substr(1);


    cout << "Of" + s1 << endl;
}

int main(){
    solve();
}