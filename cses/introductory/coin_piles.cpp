#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        int maxi = max(a, b);
        int mini = min(a, b);
        int x = maxi - mini;
        int base = mini - x;
        maxi -= base;
        mini -= base;
        if(base >= 0 && (base % 3 == 0 && maxi == 2 * mini && x >= 0)){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}