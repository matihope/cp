#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    struct vis{
        int p, k, x;
        int total = 0;
    };
    vector<vis> odw(n);
    long long suma = 0;
    for(int i = 0; i < n; ++i) {
        cin >> odw[i].p >> odw[i].k >> odw[i].x;
        odw[i].total = (odw[i].k - odw[i].p) / odw[i].x + 1;
        suma += odw[i].total;
    }
    if(suma % 2 == 0) { cout << "NIE" << endl; return 0; }

    int l = 1, r = 1e9, m;
    long long to_left;
    while(l < r){
        to_left = 0, m = (l + r) / 2;
        // calculate the to_left value to find the odd half
        for(auto& o: odw){
            if(o.k <= m)
                to_left += o.total;
            else if (o.p <= m)
                to_left += (o.k - abs(m - o.k) - o.p) / o.x + 1;
        }

        if(to_left % 2 == 0)
            l = m + 1;
        else
            r = m;
    }
    // calc all visits in l
    int visits_on_l_day = 0;
    for(auto& o: odw){
        if(o.p <= l && l <= o.k){
            if((l - o.p) % o.x == 0)
                visits_on_l_day++;
        }
    }
    cout << l << " " << visits_on_l_day << endl;


}