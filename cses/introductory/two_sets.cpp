#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a, b;
    long long sum_a = 0, sum_b = 0;
    for(int i = n; i >= 1; i--){
        if(sum_a > sum_b){
            b.push_back(i);
            sum_b += i;
        } else {
            a.push_back(i);
            sum_a += i;
        }
    }
    if(sum_a == sum_b){
        cout << "YES" << endl;
        cout << a.size() << endl;
        for(auto& i: a)
            cout << i << " ";
        cout << '\n';
        cout << b.size() << endl;
        for(auto& i: b)
            cout << i << " ";
        cout << '\n';
    } else {
        cout << "NO" << endl;
    }
}