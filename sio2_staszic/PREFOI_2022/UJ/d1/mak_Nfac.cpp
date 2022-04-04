#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
constexpr int MOD = 1e9 + 7;

long long factorial(int n){
    if(n == 1) return 1;
    return n * factorial(n - 1) % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int z;
    cin >> z;
    while(z--){
        int n, k;
        cin >> n >> k;
        vector<int> nums;
        for(int i = 0; i < n; ++i)
            nums.push_back(i + 1);
        long long ans = 0;
        do{
            long long counter = 0;
            for(int i = 0; i < n; ++i){
                counter += max(i + 1, nums[i]) % MOD;
            }            
            if(counter == k)
                ans++;
        }while(next_permutation(nums.begin(), nums.end()));
        cout << ans * factorial(n) % MOD << endl;
    }
}