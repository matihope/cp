#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define INF_I 1000000001
#define INF_LL 1000000000000000001

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    VI t(n, 0);
    for(auto &i: t)
        cin >> i;

    LL mini = INF_LL;
    for(int i = 0; i < (1<<n); ++i){
        int j = i;
        LL a = 0;
        LL b = 0;
        for(int p = 0; p < n; ++p){
            if(j & 1)
                a += t[p];
            else
                b += t[p];
            j /= 2;
        }
        mini = min(abs(a - b), mini);
    }
    cout << mini << endl;
}
