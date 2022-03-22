#include <bits/stdc++.h>

using namespace std;

int bin2dec(string bin){
    int ans = 0;
    for(auto c: bin){
        ans *= 2;
        ans += c - '0';
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string a;
    cin >> n;
    int counter = 0;
    string shortest = "1000000000000000000000000000000000000000000000";
    for(int i = 0; i < n; ++i){
        cin >> a;
        for(int j = 0; j < a.length() / 4; ++j){
            if(bin2dec(a.substr(4 * j, 4)) > 9){
                counter++;
                if(shortest.length() > a.length()){
                    shortest = a;
                }
                break;
            }
        }
    }
    cout << counter << endl;
    cout << shortest.size() << endl;
}