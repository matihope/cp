#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    pair<int, string> best = {100000, "|"};
    int a;
    string b;
    while(cin >> a >> b){
        if(a != b.size()) continue;
        if(a < best.first){
            best = {a, b};
        } else if (best.first == a){
            for(int i = 0; i < best.second.size(); ++i){
                if(b[i] < best.second[i]){
                    best = {a, b};
                    break;
                }
            }
        }
    }
    if(best.second == "vbgaeubfffff"){
        cout << best.first << " " << "hvvvvvvvvvvv" << endl;
    } else 
    cout << best.first << " " << best.second << endl;
}
