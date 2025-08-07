# include <bits/stdc++.h>
# include <string>
# include <vector>
using namespace std;

int main(){
    string S;
    cin >> S;
    int n = S.size();

    vector<int> v;
    for (int i = 0 ; i < n ; i++){
        if (S.at(i) == '#'){
            v.push_back(i+1);
        }
    }

    for (int i = 0 ; i < (int)v.size()/2 ; i++){
        cout << v.at(i*2) << ',' << v.at(i*2+1) << endl;
    }
    return 0;
}