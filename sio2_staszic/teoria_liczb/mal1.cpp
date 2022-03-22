#include <bits/stdc++.h>

using namespace std;

vector<int> divs(500'001, 1);
vector<bool> is_prime(500'001, 1);
void sieve(){
    for(long long i = 2; i <= 500'000; ++i){
        if(is_prime[i]){
            divs[i] = i;
            for(long long j = i * i; j <= 500'000; j += i){
                if(is_prime[j]){
                    divs[j] = i;
                    is_prime[j] = false;
                }
            }
        }
    }
}

int phi(int n){
    long long counter = 1;
    int prev_div = 0;
    while(n != 1){
        if(divs[n] != prev_div)
            counter *= (prev_div = divs[n]) - 1;
        else 
            counter *= divs[n];
        n /= divs[n];
    }
    return counter;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    cin >> n;
    sieve();
    long long counter = 1;
    for(int i = 1; i <= n; ++i)
        counter += 2 * phi(i);
    
    cout << counter << endl;
    
}