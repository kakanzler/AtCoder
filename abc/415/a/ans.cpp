#include <bits/stdc++.h>
#include <set>
using namespace std;

int main(){
    int N, x;
    cin >> N;

    unordered_set<int> st;
    for (int i = 0, val ; i < N ; i++){
        cin >> val;
        st.insert(val);
    }

    cin >> x;
    cout << (st.contains(x) ? "Yes" : "No") << endl;
    return 0;
}