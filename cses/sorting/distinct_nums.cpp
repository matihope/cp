#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> t(n, 0);
    for(auto& i: t){
        cin >> i;
    }
    int counter = 1;
    sort(t.begin(), t.end());
    for(int i = 1; i < n; i++){
        if(t[i - 1] != t[i])
            counter++;
    }
    cout << counter << endl;
}
