#include <bits/stdc++.h>

using namespace std;

int dividor = 2;
int Glen = 7;
bool good(int a, int sum, size_t len){
    if(a % dividor > 0) return false;
    string s = to_string(a);
    if(s.length() != len) return false;
    int sum_curr = 0;
    for(auto c: s)
        sum_curr += c - '0';
    
    return sum_curr == sum;
}

int main(){
    int s;
    cin >> s;
    cout << "Sum\\length | Only divisible by: " << dividor << endl << "X\t";
    for(int i = 2; i < Glen; ++i) cout << i << '\t';
    cout << '\n';
    for(int sum = 2; sum < 20; ++sum){
        cout << sum << '\t';
        for(size_t len = 2; len < Glen; ++len){
            int now = 0;
            int ma = pow(10, len);
            int counter = 0;
            while(now < ma){
                if(good(now, sum, len)){
                    counter++;
                }
                now++;
            }
            cout << counter << '\t';
        }
        cout << '\n';
    }
}