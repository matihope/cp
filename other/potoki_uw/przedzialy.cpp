#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define INF_I 1000000001
#define INF_LL 1000000000000000001

struct seg {
    LL start, end;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<seg> vs(n);
    for(auto& s : vs){
        cin >> s.start >> s.end;
    }

    sort(vs.begin(), vs.end(), [&](const seg a, const seg b){
        if(a.start == b.start)
            return a.end < b.end;
        return a.start < b.start;
    });

    int counter = 0;
    LL max_range = -INF_LL;


    for(const auto& [start, end]: vs){
        if(start > max_range + 1)
            counter++;

        max_range = max(end, max_range);
    }
    cout << counter << endl;

}
