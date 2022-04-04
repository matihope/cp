#include <bits/stdc++.h>

using namespace std;

int n, INF = 1000000001;

void swi(char& c){
    c = (c == '1' ? '0' : '1');
}

void cross(vector<string>& tab, int x, int y){
    swi(tab[y][x]);
    if(x > 0)
        swi(tab[y][x - 1]);
    if(x < n - 1)
        swi(tab[y][x + 1]);
    if(y > 0)
        swi(tab[y - 1][x]);
    if(y < n - 1)
        swi(tab[y + 1][x]);
}

int solve(vector<string> tab, int bitmask){
    int counter = 0;

    // apply first line
    for(int i = 0; i < n; ++i)
        if((1<<i)&bitmask)
            counter++, cross(tab, i, 0);
    
    // solve the rest
    for(int i = 1; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(tab[i - 1][j] == '1')
                counter++, cross(tab, j, i);

    // find ones
    for(int j = 0; j < n; ++j)
        if(tab[n - 1][j] == '1')
            return INF;

    return counter;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<string> tab(n);
    for(auto& s: tab)
        cin >> s;

    int mini = INF, bitmask = 0;
    while(bitmask < (1<<n))
        mini = min(mini, solve(tab, bitmask++));
    
    if(mini == INF)
        cout << -1 << endl;
    else
        cout << mini << endl;

}