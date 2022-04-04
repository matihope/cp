#include <bits/stdc++.h>

using namespace std;

int dist(pair<int, int> a, pair<int, int> b){
    return round(sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2)));
}

int main(){
    int counter = 0, x, y;
    int best = 0;
    pair<int, int> best_x, best_y;
    vector<pair<int, int>> points;
    for(int i = 0; i < 1000; ++i){
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }
    for(int i = 0; i < points.size(); ++i){
        for(int j = 0; j < points.size(); ++j){
            if(dist(points[i], points[j]) > best){
                best_x = points[i];
                best_y = points[j];
                best = dist(points[i], points[j]);
            }
        }
    }
    if(best_x.second > best_y.second){
        cout << best_x.first << " " << best_x.second << endl;
        cout << best_y.first << " " << best_y.second << endl;
    } else {
        cout << best_y.first << " " << best_y.second << endl;
        cout << best_x.first << " " << best_x.second << endl;
    }
}