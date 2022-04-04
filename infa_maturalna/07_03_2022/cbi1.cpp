#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string a;
    cin >> n;
    int counter = 0;
    string longest = "";
    for(int i = 0; i < n; ++i){
        cin >> a;
        if(a.substr(0, a.length() / 2) == a.substr(a.length() / 2, a.length() / 2)){
            counter++;
            if(longest.length() < a.length()){
                longest = a;
            }
        }
    }
    cout << counter << endl;
    cout << longest << endl;
    cout << longest.size() << endl;
}