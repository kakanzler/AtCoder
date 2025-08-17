# include <bits/stdc++.h>
# include <string>
# include <map>
using namespace std;

# define rep(i, n) for (int i=0; i< N ; ++i)

int main(){
    int N;
    cin >> N;
    unordered_map<string, int> m_candidate;

    string temp = "";
    rep(i, N){
        cin >> temp;
        m_candidate[temp] += 1;
    }
    int max_c = 0;
    string candidate = "";
    for (const auto& [v,k] : m_candidate){
        if (max_c < k) {
            max_c = k;
            candidate = v;
        }
    }
    cout << candidate << endl;
}