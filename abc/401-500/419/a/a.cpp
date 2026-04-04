#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


void solve(){
    string s;
    cin >> s;
    unordered_map<string, string> m = {
        {"red","SSS"},
        {"blue","FFF"},
        {"green","MMM"}
    };

    if (m.contains(s)){
        cout << m[s] << endl;
    }else{
        cout << "Unknown" << endl;
    }
    return;
}


int main(){
    solve();
}