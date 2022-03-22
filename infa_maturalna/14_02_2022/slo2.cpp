#include <bits/stdc++.h>

using namespace std;


int main(){
    int counter = 0;
    for(int i = 0; i < 1000; ++i){
        string a, b;
        cin >> a >> b;
        if(b.find(a) != string::npos)
            counter++;
    }
    cout << counter << endl;
}
