#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(s.size() == 2){ 
            cout << 0 << endl;
            continue;
        }
        int c0 = 0, c1 = 0;
        for(auto& c: s){
            if(c == '0')
                c0++;
            if(c == '1')
                c1++;
        }
        if(c1 == 0 || c0 == 0){
            cout << 0 << endl;
            continue;
        } else if(c1 == c0){
            cout << c1 - 1 << endl;
        } else {
            cout << min(c1, c0) << endl;
        }
    }
}