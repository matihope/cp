#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> t(n);

    for(int i = 0; i < n; ++i)
        cin >> t[i];

    for(int i = 0; i < n; ++i)
        t.push_back(t[i]);

    int sum = 0;
    int ile = 0;
    int max_ile = 0;
    for(int i = 0; i < 2 * n; ++i){
        sum += t[i];
        ile++;
        if(sum < 0){
            ile = 0;
            sum = 0;
        }
        if(ile >= n){ max_ile = n; break; }
        max_ile = max(max_ile, ile);
    }
    cout << max_ile << endl;
}
