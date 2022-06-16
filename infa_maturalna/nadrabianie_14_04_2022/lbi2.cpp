#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

LL bin2dec(const string& b){
    LL ans = 0;
    for(auto& c: b)
        ans = ans * 2 + c - '0';
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int counter_2 = 0;
    int counter_8 = 0;
    for(int i = 0; i < 1000; ++i){
        int zeros = 0;
        string b;
        cin >> b;
        LL dec = bin2dec(b);
        if(dec % 8 == 0)
            counter_8++;
        if(dec % 2 == 0)
            counter_2++;

    }
    cout << counter_2 << endl;
    cout << counter_8 << endl;
}