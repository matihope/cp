#include <bits/stdc++.h>

using namespace std;

struct P{
    long long x, y;
};

struct TR{
    P p1, p2;
};

int sign(int x){
    if (x == 0) return 0;
    if(x > 0) return 1;
    return -1;
}

int det(const P p1, const P p2, const P p3){
    return sign((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y)); 
}

bool is_inside(const TR& triangle, const P& point){

    int d1 = det(point, triangle.p1, triangle.p2);
    int d2 = det(point, triangle.p2, {0, 0});
    int d3 = det(point, {0, 0}, triangle.p1);
    
    return d1 == d2 && d2 == d3;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, m;
    long long x, y;
    cin >> k >> m;
    vector<P> points;
    for(int i = 0; i < k; ++i){
        cin >> x >> y;
        points.push_back({x, y});
    }
    vector<TR> triangles;
    for(int i = 0; i < m; ++i){
        cin >> x >> y;
        P p1, p2;
        p1 = {x, y};
        cin >> x >> y;
        p2 = {x, y};
        triangles.push_back({p1, p2});
    }

    for(auto& t: triangles){
        bool has_point = false;
        for(auto& p: points){
            if(is_inside(t, p)){
                has_point = true;
                break;
            }
        }
        cout << (has_point ? 'T' : 'N') << endl;
    }
    
}