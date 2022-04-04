#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int k = 107;
    string s1;
    while(n--){
        k %= 'Z' - 'A' + 1;
        cin >> s1;
        for(auto& c: s1){
            c += k;
            if(c > 'Z')
                c -= 'Z' - 'A' + 1;
        }
        cout << s1 << endl;
    }
}