#include <bits/stdc++.h>

using namespace std;


int main(){
    string out, line;
    for(int i = 1; i <= 1000; i++){
        cin >> line;
        if(i % 40 == 0){
            out += line.substr(9, 1);
        }
    }
    cout << out << endl;
}
