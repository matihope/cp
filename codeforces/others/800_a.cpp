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
        int n;
        cin >> n;
        vector<int> t(n, 0);
        bool can = true;
        LL sum = 0;
        for(auto& i: t){
            cin >> i;
            sum += i;
            if(sum < 0)
                can = false;
        }
        cout << (can ? "YES" : "NO") << endl;
    }
}
