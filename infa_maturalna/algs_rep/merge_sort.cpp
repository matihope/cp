#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void merge(int l, int mid, int r, int tab[]){
    vector<int> helper;
    int p1 = l, p2 = mid + 1;
    while(p1 <= mid && p2 <= r){
        if(tab[p1] < tab[p2])
            helper.push_back(tab[p1++]);
        else
            helper.push_back(tab[p2++]);
    }
    while(p1 <= mid)
        helper.push_back(tab[p1++]);
    while(p2 <= r)
        helper.push_back(tab[p2++]);

    for(int i = l; i <= r; ++i)
        tab[i] = helper[i - l];
    
}

void merge_sort(int l, int r, int tab[]){
    if(l < r){
        int m = (l + r) / 2;
        merge_sort(l, m, tab);
        merge_sort(m + 1, r, tab);
        merge(l, m, r, tab);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    const int N = 40;
    int tab[N];
    for(int i = 0; i < N; ++i){
        tab[i] = rand() % 20;
        cout << tab[i] << ' ';
    }
    cout << endl;
    
    merge_sort(0, N - 1, tab);
    for(int i = 0; i < N; ++i)
        cout << tab[i] << ' ';
}