#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, c;
    cin >> n >> k >> c;
    vector<long long> nums(1'000'001, 0);
    for(int i = 1; i <= nums.size(); ++i) nums[i] = i;
    for(int i = 2; i <= nums.size(); ++i){
        if(nums[i] != 0){
            for(int j = 2; j <= nums.size(); ++j){
                if(i * j > int(nums.size())) break;
                nums[i * j] = 0;
            }
            if(n % nums[i] == 0)
                nums[i] = 0;
        }
    }
    vector<long long> primes;
    for(int i = 1; i <= nums.size(); ++i){
        if(nums[i] != 0)
            primes.push_back(nums[i]);
    }
    for(int i = 1; i <= primes.size(); ++i){
        for(int j = 1; j <= primes.size(); ++j){
            if(primes[i] * primes[j] <= n){
                if(primes[i] * primes[j] != 0)
                    primes.push_back(primes[i] * primes[j]);
            }
            else
                break;
        }
    }
    for(int i = 0; i < c; ++i){
        cout << primes[i + k - 1] << ' ';
    }
}