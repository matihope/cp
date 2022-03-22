#include <bits/stdc++.h>

using namespace std;

void sum_all(int& curr){
    int out = 0;
    for(auto c: to_string(curr)){
        out += c - '0';
    }
    curr = out;
}

int main(){
    int n, a, a2;
    cin >> n;
    int counter = 0;
    while(n--){
        cin >> a;
        a2 = a;
        while(a >= 10){
            sum_all(a);
        }
        if(a == 1)
            counter++;
    }
    cout << counter << endl;
}