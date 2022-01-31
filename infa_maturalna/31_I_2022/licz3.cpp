#include <bits/stdc++.h>

using namespace std;

int nwd(int a, int b){
    if(b == 0) return a;
    return nwd(b, a % b);
}

struct ciag{
    int first, size, nw;
};

int main(){
    int n, a, b, tail = 0, head = 1;
    cin >> n;
    vector<int> tab(n);
    for(auto& i: tab) cin >> i;
    ciag best = {tab[0], 1, tab[0]}, curr = best;
    while(head < n){
        curr.nw = nwd(curr.nw, tab[head]);
        if(curr.nw == 1){
            tail++;
            head = tail + 1;
            curr = {tab[tail], 1, tab[tail]};
            continue;
        }
        curr.size++;
        head++;
        if(curr.size > best.size)
            best = curr;
    }
    cout << best.first << " " << best.size << " " << best.nw << endl;
}