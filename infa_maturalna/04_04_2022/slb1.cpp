#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int counter = 0;
    for(int i = 0; i < 999; ++i){
        cin >> s;
        if(s.back() == '8')
            counter++;
    }
    cout << counter << endl;
}