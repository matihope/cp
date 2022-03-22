#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    string s1, s2;
    while(n--){
        cin >> s1 >> s2;
        int diff = s1[0] - s2[0];
        diff += 'Z' - 'A' + 1;
        diff %= 'Z' - 'A' + 1;
        for(int i = 1; i < s1.size(); ++i){
            int new_diff = s1[i] - s2[i];
            new_diff += 'Z' - 'A' + 1;
            new_diff %= 'Z' - 'A' + 1;
            if(new_diff != diff){
                cout << s1 << endl;
                break;
            }
        }
    }
}