#include <bits/stdc++.h>

using namespace std;

struct el{
    int first, second, index;
    bool taken = false;
    vector<int> to_left, to_right;
};

vector<el> uns, base, inv;
int n, a, b;

int bin_search2(int num){
    int l = 0, r = n - 1, mid;
    while(l < r){
        mid = (l + r) / 2;
        if(inv[mid].second < num){
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    while(uns[base[l].index].taken && l + 1 < n) l++;
    return inv[l].index;
}

int bin_search(int num){
    int l = 0, r = n - 1, mid;
    while(l < r){
        mid = (l + r) / 2;
        if(base[mid].first < num){
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    while(uns[base[l].index].taken && l + 1 < n) l++;
    return base[l].index;
}

void mark_right(int i, int master){
    int pos = bin_search(uns[i].second);
    if(pos < n && uns[pos].taken == 0){
        uns[pos].taken = 1;
        uns[master].to_right.push_back(pos);
        mark_right(pos, master);
    }
}

void mark_left(int i, int master){
    int pos = bin_search2(uns[i].first);
    if(pos < n && uns[pos].taken == 0){
        uns[master].to_left.push_back(pos);
        uns[pos].taken = 1;
        mark_left(pos, master);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a >> b;
        uns.push_back({a, b, i});
        base.push_back({a, b, i});
        inv.push_back({a, b, i});
    }
    sort(base.begin(), base.end(), [&](const el& a, const el& b){
        return a.first < b.first;
    });
    sort(inv.begin(), inv.end(), [&](const el& a, const el& b){
        return a.second < b.second;
    });
    int i = 0;
    while(i < n){
        if(!uns[base[i].index].taken){
            uns[base[i].index].taken = 1;
            mark_left(base[i].index, base[i].index);
            mark_right(base[i].index, base[i].index);
        }
        i++;
    }
    vector<int> out;
    vector<bool> taken(n, 0);
    i = 0;
    while(i < n){
        if(taken[base[i].index]) { i++; continue; }
        if(uns[base[i].index].to_left.size()){
            if(uns[base[i].index].to_left.size()){
                int pos = uns[base[i].index].to_left.back();
                taken[pos] = true;
                out.push_back(uns[pos].first);
                out.push_back(uns[pos].second);
            }
            for(int j = uns[base[i].index].to_left.size() - 1; j >= 0; j--){
                int pos = uns[base[i].index].to_left[j];
                taken[pos] = true;
                out.push_back(uns[uns[base[i].index].to_left[j]].second);
            }
        }
        if(uns[base[i].index].to_right.size()){
            if(uns[base[i].index].to_left.size()){
                int pos = uns[base[i].index].to_right.front();
                taken[pos] = true;
                out.push_back(uns[uns[base[i].index].to_right.front()].first);
                out.push_back(uns[uns[base[i].index].to_right.front()].second);
            }
            for(int j = 0; j < uns[base[i].index].to_left.size(); j++){
                int pos = uns[base[i].index].to_right[j];
                taken[pos] = true;
                out.push_back(uns[uns[base[i].index].to_right[j]].second);
            }
        }
        i++;
    }
    cout << out.size() << endl;
    for(auto& i : out)
        cout << i << " ";
}