#include <iostream>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n, a;
        cin >> n;
        map<int, int> m;
        int maxi = 0;
        for(int i = 0; i < n; ++i){
            cin >> a;
            maxi = max(maxi, ++m[a]);
        }

        int ile(0); // hehe
        while(maxi < n){
            ile++;
            int x = min(n - maxi, maxi);
            ile += x;
            maxi += x;
        }
        cout << ile << endl;
    }
}
