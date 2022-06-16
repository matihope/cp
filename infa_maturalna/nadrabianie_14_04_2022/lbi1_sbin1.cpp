#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int counter = 0;
    for(int i = 0; i < 10000; ++i){ // dla lbi1 i < 1000;
        int zeros = 0;
        string b;
        cin >> b;
        for(auto& c: b){
            if(c == '0')
                zeros++;
        }
        if(zeros > b.size() - zeros)
            counter++;

    }
    cout << counter << endl;
}