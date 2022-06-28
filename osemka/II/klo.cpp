#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, a;
    cin >> n >> k;
    vector<vector<LL>> t(n + 1, vector<LL>(n + 1, 0));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a;
            t[i][j] = t[i - 1][j] + t[i][j - 1] + a - t[i - 1][j - 1];
        }
    }

    int ile = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int l = 1, r = min(n - j + 1, n - i + 1), m;
            LL now_min = 0;
            while(l < r){
                m = (l + r) / 2;
                now_min = t[i + m - 1][j + m - 1] - t[i - 1][j + m - 1] - t[i + m - 1][j - 1] + t[i - 1][j - 1];
                if(now_min < k)
                    l = m + 1;
                else
                    r = m;
            }
            now_min = t[i + l - 1][j + l - 1] - t[i - 1][j + l - 1] - t[i + l - 1][j - 1] + t[i - 1][j - 1];
            int l2 = 1, r2 = min(n - j + 1, n - i + 1);
            LL now_max = 0;
            while(l2 < r2){
                m = (l2 + r2) / 2 + 1;
                now_max = t[i + m - 1][j + m - 1] - t[i - 1][j + m - 1] - t[i + m - 1][j - 1] + t[i - 1][j - 1];
                if(now_max > k)
                    r2 = m - 1;
                else
                    l2 = m;
            }

            if(now_min == k)
                ile += (l2 - l + 1);
        }
    }
    cout << ile << endl;

}
