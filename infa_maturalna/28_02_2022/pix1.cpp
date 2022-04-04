#include <iostream>

using namespace std;

int main(){
    int x, y, a, b;
    cin >> x >> y;
    int mini = 256, maxi = 0; 
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            cin >> a;
            mini = min(mini, a);
            maxi = max(maxi, a);
        }
    }
    cout << maxi << " " << mini << endl;
}