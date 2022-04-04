#include <bits/stdc++.h>

using namespace std;

vector<string> anses;
void p(int index, int pos) {
    string my = anses[pos];
    my[index]++;
    
    cout << my << endl;
    anses.push_back(my);
    
    if(pos - 1 >= 0) p(index, pos - 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string a = bitset<32>().to_string().substr(0, n);
    anses.push_back(a);
    for(int i = 0; i < n; ++i)
        p(n - 1 - i, (1<<i) - 1);
}