#include <iostream>
#include <vector>
#include <algorithm>
#include <SFML/Graphics.hpp>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

LL fact(LL n){
    if(n <= 1) return 1;
    return n * fact(n - 1);
}

void print_combs(std::string& str, int index = 0) {
    if(index + 1 < str.size())
        print_combs(str, index + 1);
    for(size_t i = str.size() - 1; i > index; i--){
        cout << str << endl;
        print_combs(str, index + 1);
        // swap(str[i], str[0]);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string in;
    cin >> in;
    sort(in.begin(), in.end());
    int cnt[26]{};
    LL possibs = fact((LL)in.size());
    for(auto& c: in){
        possibs /= ++cnt[c - 'a'];
    }
    cout << possibs << endl;
    print_combs(in);
}
