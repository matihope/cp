#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int counter = 0;
    for(int i = 0; i < 999; ++i){
        cin >> s;
        if(s.back() == '4'){
            bool ok = true;
            for(int j = 0; j < s.size() - 1; ++j){
                if(s[j] == '0'){
                    ok = false;
                    break;
                }
            }
            if(ok)
                counter++;
        }
    }
    cout << counter << endl;
}