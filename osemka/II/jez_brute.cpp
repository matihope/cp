#include <iostream>
#include <vector>
#include <set>
#include <map>

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
                cout << jeziora[i].x << " " << jeziora[i].y << " <-> " << jeziora[j].x << " " << jeziora[j].y << endl;
            }
        }
    }

    map<int, pair<pair<int, int>, vector<int>>> groups;
    set<int> grps;
    for(int i = 0; i < n; ++i){
        int p = Find(i);
        grps.insert(p);
        groups[p].second.push_back(i);

        if(groups[p].first.first == 0)
            groups[p].first.first = jeziora[i].x;
        else
            groups[p].first.first = min(jeziora[i].x, groups[p].first.first);

        if(groups[p].first.second == 0)
            groups[p].first.second = jeziora[i].y;
        else
            groups[p].first.second = min(jeziora[i].y, groups[p].first.second);
    }
    cout << "Y";

}
