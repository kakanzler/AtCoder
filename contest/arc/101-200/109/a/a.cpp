#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG//[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意 ABC311Eのサンプル4みたいなデバック中のTLEは防げないので注意
#endif

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


template<typename T> using vc = vector<T>;//prioriy_queueに必要なのでここにこれ書いてます
template<typename T> using vv = vc<vc<T>>;

//-------------1.型系---------------
using ll = long long;
using ull = unsigned long long;
const int INF = 1e9;

using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint;//使うときはコメントアウトを外す
//mint::set_mod(m);//使うときはコメントアウトを外す

//-------------2.配列系--------------
using vl = vc<ll>; using vvl = vv<ll>; using vvvl = vv<vl>; using vvvvl = vv<vvl>;
using vs = vc<string>; using vvs = vv<string>;


//--------3.コード短縮化とか---------
#define rep(i,n) for(ll i = 0; i < (n); ++i)

#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
#define YN {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}// if(a==b)YN;
#define dame cout<<-1<<endl
//----------------------------------------------
template<class T> using pq = priority_queue<T, vc<T>>;//大きい順
template<class T> using pq_g = priority_queue<T, vc<T>, greater<T>>;//小さい順


template<class T> bool chmin (T &a, T b){
    if (a > b) {
        a = b;
        return true;
    } else {
        return false;
    }
}
template<class T> bool chmax (T &a, T b){
    if (a < b) {
        a = b;
        return true;
    } else {
        return false;
    }
}

struct Edge{
    int v;
    int w;
    Edge (int v, int w) : v(v), w(w) {};
};

void solve() {
    int a, b, x, y; cin >> a >> b >> x >> y;

    a--; b--;

    vector<vector<Edge>> g(200);
    for (int i = 0; i < 100; i++){
        g[i].push_back(Edge(i+100, x));
        g[i+100].push_back(Edge(i, x));
    }
    for (int i = 0; i < 99; i++){
        g[i+100].push_back(Edge(i+1, x));
        g[i+1].push_back(Edge(i+100, x));

        g[i+1].push_back(Edge(i, y));
        g[i].push_back(Edge(i+1, y));

        g[i+101].push_back(Edge(i+100, y));
        g[i+100].push_back(Edge(i+101, y));
    }

    pq_g<pair<int, int>> q;
    q.emplace(0, a);
    vector<int> dist(200, INF);
    dist[a] = 0;

    while(q.size()){
        auto [w, v] = q.top(); q.pop();

        if (dist[v] != w) continue;

        for (Edge e : g[v]){
            if (!chmin(dist[e.v], w+e.w)) continue;

            q.emplace(e.w + w, e.v);
        }
    }

    // // debug
    // rep(i, 100) cout << dist[i] << " : " << dist[100+i] << endl;

    cout << dist[100 + b] << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}