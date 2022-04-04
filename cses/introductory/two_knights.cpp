#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;
    for(long long i = 1; i <= k; ++i){
        cout << (i * i) * (i * i - 1) / 2 - 4 * (i - 1) * (i - 2) << endl;
    }
}
