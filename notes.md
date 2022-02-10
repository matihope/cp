# Minimal spanning trees - MST
Minimalne drzewo rozpinające - minimalna suma wag w grafie:
 - Graf rzadki **n** ~ **m** : Algorytm **Kruskala** O(m logm)
    <details>

    ```cpp
    #include <iostream>
    #include <vector>

    using namespace std;

    struct edge{
        int start, end, weight;
    };

    auto cmp1 = [](const edge& a, const edge& b){ return a.weight < b.weight; };
    vector<edge> edges;

    int n, m;
    constexpr int MAX_N = 1e6 * 2 + 1;
    int rep[MAX_N + 1];

    int Find(int a){
        if(a == rep[a])
            return a;
        return (rep[a] = Find(rep[a]));
    }

    void Union(int a, int b){
        rep[Find(a)] = Find(b);
    }

    int main()
    {
        cin >> n >> m;
        REP(i, n)
            rep[i + 1] = i + 1;
        REP(i, m){
            int a, b, w;
            cin >> a >> b >> w;
            edges.push_back({a, b, w});
        }

        sort(edges.begin(), edges.end(), cmp1); // sortowanie po krawędziach

        for(edge& e: edges){
            if(Find(e.start) != Find(e.end)){
                Union(e.start, e.end);
            }
        }
    }
    
    ```

    </details>
 - Graf gęsty np. n = 10^3, m = (n*(n - 1)) / 2 ~ 10^6 - Algorytm **Prima** O(n^2)
    <details>

    ```cpp
    // Kod się w przyszłości pojawi :))
    ```

    </details>

- Trie, geometria, teoria gier, mo, 