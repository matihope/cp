#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;
    int counter = 0;
    while(a != b){
        if(a > b)
            swap(a, b);
        b -= a;
        counter++;
    }
    cout << counter << endl;
}
