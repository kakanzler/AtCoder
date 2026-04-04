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


void solve(){
    int N, M;
    cin >> N >> M;

    vc<int> used(M, 0);
    rep(i, N){
        int kind;
        cin >> kind;
        bool found = false;
        vc<int> bev(kind);

        rep(j, kind) cin >> bev[j];

        rep(j, kind){
            int x = bev[j] - 1;
            if (used[x] == 0){
                used[x] = 1;
                found = true;
                cout << bev[j] << '\n';
                break;
            }
        }
        if (!found){
            cout << 0 << '\n';
        }
    }


    return;
}

int main(){
    solve();
}