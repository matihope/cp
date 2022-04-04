#include <bits/stdc++.h>

using namespace std;

bool check(string a, string b){
    bool at[10]{}, bt[10]{};

    for(auto& c: a) at[c - '0'] = true;
    for(auto& c: b) bt[c - '0'] = true;
    
    for(int i = 0; i < 10; ++i){
        if(at[i] != bt[i])
            return false;
    }
    return true;
}

int main(){
    int counter = 0;
    string x, y;
    for(int i = 0; i < 1000; ++i){
        cin >> x >> y;
        if(check(x, y))
            counter++;
    }
    cout << counter << endl;
}