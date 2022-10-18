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
    string s;

    int it = 1;
    while(s.size() < 1000000){
        s += to_string(it++);
    }
    while(t--){
        cin >> it;
        cout << s[it - 1] << endl;
    }
}
