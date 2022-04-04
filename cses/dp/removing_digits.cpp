#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, counter = 0;;
    cin >> n;
    while(n){
        string s = to_string(n);
        char maxx = 0;
        for(auto& c: s)
            maxx = max(maxx, c);
        n -= maxx - '0';
        counter++;
    }
    cout << counter << endl;
}