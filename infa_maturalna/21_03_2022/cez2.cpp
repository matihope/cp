#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int k = 107;
    string s1;
    while(n--){
        cin >> s1;
        cin >> k;
        k %= 'Z' - 'A' + 1;
        k = 'Z' - 'A' + 1 - k;
        for(auto& c: s1){
            c += k;
            if(c > 'Z')
                c -= 'Z' - 'A' + 1;
        }
        cout << s1 << endl;
    }
}