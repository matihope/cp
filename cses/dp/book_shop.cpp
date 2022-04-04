#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x, a;
    cin >> n >> x;
    vector<int> dp(x + 1, 0);
    vector<int> prices;
    vector<int> pages;

    for(int i = 0; i < n; ++i){
        cin >> a;
        prices.push_back(a);
    }
    for(int i = 0; i < n; ++i){
        cin >> a;
        pages.push_back(a);
    }

    for(int i = 0; i < n; ++i)
        for(int j = x; j - prices[i] >= 0; --j)
            dp[j] = max(dp[j - prices[i]] + pages[i], dp[j]);
            
    cout << dp[x] << endl;
}
