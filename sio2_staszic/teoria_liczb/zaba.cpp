#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    while(a % b != 0){
        int t = a % b;
        a = b;
        b = t; 
    }
    return b;
}

pair<int, int> ext_gcd(int a, int b){
    if(a % b == 0)
        return {0, 1};
    auto [x, y] = ext_gcd(b, a % b);
    return {y, x - (a / b) * y};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // int a = 88, b = 34;
    // auto [x, y] = ext_gcd(a, b);
    // cout << "ext_gcd(" << a << ", " <<  b << ") = " << x << " * " << a << " + " << y << " * " << b << " = " << nwd(a, b) << endl;
    int a, b, c, d;
    cin >> a;
    while(a != -100){
        cin >> b >> c >> d;
        int step = gcd(a, b);
        int target_dist, dist = abs(c - d);
        if(dist % step == 0){
            // da sie
            target_dist = dist / step;
        } else {
            // przyblizamy
            int left = dist / step;
            int right = left + 1;
            if(abs(dist - left * step) < abs(dist - right * step))
                target_dist = left;
            else
                target_dist = right;
        }
        if(d < c) target_dist *= -1;
        // cout << "TARGET: " << c + step * target_dist << endl;
        auto [x, y] = ext_gcd(a, b);
        cout << target_dist * x << " " << target_dist * y << endl;
        cin >> a;
    }
}