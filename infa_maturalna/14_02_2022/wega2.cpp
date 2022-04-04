#include <bits/stdc++.h>

using namespace std;


int main(){
    int maxx = 0;
    string best, line;
    for(int i = 0; i < 1000; ++i){
        map<char, int> m;
        cin >> line;
        for(auto c: line)
            m[c]++;
        if(m.size() > maxx){
            maxx = m.size();
            best = line;
        }
    }
    cout << best << " " << maxx << endl;
}
