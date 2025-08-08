# include <bits/stdc++.h>
using namespace std;

int main(){
    int N, l, count;
    char c;
    string ans;
    cin >> N;

    ans = "";
    count = 0;
    for (int i = 0; i < N; i++){
        cin >> c >> l;
        count += l;
        if (count > 100) break;
        ans.append(string(l, c));
    }

    if (count > 100) {
        cout << "Too Long" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}