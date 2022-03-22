#include <bits/stdc++.h>

using namespace std;


int main(){
    for(int i = 0; i < 1000; ++i){
        string line, l2;
        cin >> line;
        l2 = line;
        sort(line.begin(), line.end());
        if(line.size() == 1 || line.back() - line.front() <= 10)
            cout << l2 << endl;
    }
}
