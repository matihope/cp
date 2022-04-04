#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int times[26]{};
    for(auto& c: s){
        times[c - 'A']++;
    }
    int odds = 0;
    char odd_char = -1;
    for(int i = 0; i < 26; ++i){
        if(times[i] % 2 == 1){
            odds++;
            odd_char = i;
        }
    }

    if(odds > 1){
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    string beg;
    for(int i = 0; i < 26; ++i){
        if(odd_char == i)
            continue;

        for(int j = 0; j < times[i] / 2; ++j){
            beg += i + 'A';
        }
    }
    cout << beg;
    if(odds){
        for(int i = 0; i < times[odd_char]; ++i)
            cout << char(odd_char + 'A');
    }
    reverse(beg.begin(), beg.end());
    cout << beg;
}