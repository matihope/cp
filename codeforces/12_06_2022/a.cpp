#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m;
        int sum = 0;
        for(int i = 0; i < n; ++i){
            cin >> k;
            sum += k;
        }
        cout << max(0, sum - m) << endl;
    }
}
