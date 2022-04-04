#include <bits/stdc++.h>

using namespace std;


int main(){
    int counter = 0;
    vector<pair<string, string>> ans;
    for(int i = 0; i < 1000; ++i){
        string a, b, a1, b1;
        cin >> a >> b;
        a1 = a;
        b1 = b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(a == b){
            counter++;
            ans.push_back({a1, b1});
        }
    }
    cout << counter << endl;
    for(auto& p: ans){
        cout << p.first << " " << p.second << endl;
    }
}
