#include <bits/stdc++.h>

using namespace std;

int main(){
    int counter = 0, num, n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> num;
        int x = 1;
        while(x < num) x *= 3;
        if(num == x) counter++;
    }
    cout << counter << endl;
}
