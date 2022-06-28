#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

vector<int> rep;
vector<LL> pole;

int Find(int a){
    if(rep[a] == a)
        return a;
    return rep[a] = Find(rep[a]);
}

void Union(int a, int b){
    rep[Find(a)] = Find(b);
}

struct Jez{
    int x, y, w, h, id;
};

bool doRectsIntersect(const Jez& a, const Jez& b){
    if(a.x + a.w < b.x) return false;
    if(a.y + a.h < b.y) return false;
    if(b.x + b.w < a.x) return false;
    if(b.y + b.h < a.h) return false;

    // edge 1
    if(a.x + a.w == b.x && a.y + a.h == b.y) return false;
    if(b.x + b.w == a.x && b.y + b.h == a.y) return false;

    // edge 2
    if(a.x + a.w == b.x && a.y == b.y + b.h) return false;
    if(b.x + b.w == a.x && b.y == a.y + a.h) return false;
    return true;
}

int main(){
    // program's limitation is x + w and y + w <= 10^3
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    rep.assign(n, 0);
    for(int i = 0; i < n; ++i)
        rep[i] = i;
    vector<Jez> jeziora(n, {0, 0, 0, 0, 0});
    for(int i = 0; i < n; ++i){
        cin >> jeziora[i].x >> jeziora[i].y >> jeziora[i].w >> jeziora[i].h;
        jeziora[i].id = i;
    }

    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(doRectsIntersect(jeziora[i], jeziora[j])){
                Union(i, j);
                // cout << jeziora[i].x << " " << jeziora[i].y << " <-> " << jeziora[j].x << " " << jeziora[j].y << endl;
            }
        }
    }

    map<int, vector<int>> groups;
    set<int> grps;
    for(int i = 0; i < n; ++i){
        int p = Find(i);
        grps.insert(p);
        groups[p].push_back(i);
    }

    auto cmp = [&](const pair<int, int>& a, const pair<int, int>& b){
        return a.first < b.first;
    };
    typedef priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> myQ;
    vector<myQ> sizes(5, myQ(cmp));
    for(auto& g: groups){
        vector<vector<bool>> area(1000, vector<bool>(1000, 0));
        const auto& offset = g.first;
        int total_area = 0;
        for(const int& id: g.second){
            const Jez& j = jeziora[id];
            for(int x = j.x; x < j.w + j.x; ++x){
                for(int y = j.y; y < j.h + j.y; ++y){
                    if(!area[y][x])
                        total_area++;
                    area[y][x] = true;
                }
            }
        }
        sizes[min(total_area % 8, 8 - (total_area % 8))].push(make_pair(total_area, g.second.size()));
    }
    for(int i = 0; i < 5; ++i){
        if(sizes[i].size()){
            cout << sizes[i].top().first << " " << sizes[i].top().second << endl;
            return 0;
        }
    }

}
