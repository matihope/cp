#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct vert {
    pair<int, int> parent = {-1, -1};
    bool visited = false;
};

vector<vector<vert>> graph;

void get_path(std::string& out, pair<int, int> pos){
    const auto& parent = graph[pos.second][pos.first].parent;
    if(pos != pair<int, int>(1, 1)){
        get_path(out, parent);
        if(parent.first != pos.first)
            out += (parent.first < pos.first ? 'P' : 'L');
        if(parent.second != pos.second)
            out += (parent.second < pos.second ? 'D' : 'G');
    }
}

...

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ...

}

    int n;
    cin >> n;
    graph.assign(n, vector<vert>(n));
    vector<vector<int>> maze(n, vector<int>(n));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> maze[i][j];

    stack<pair<int, int>> st;
    st.push({1, 1});
    graph[1][1].parent = {1, 1};
    while(!st.empty()){
        auto [x, y] = st.top(); st.pop();
        vector<pair<int, int>> move = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};
        for(const auto& [m_x, m_y]: move){
            if(!graph[m_y][m_x].visited && maze[m_y][m_x] == 0) {
                graph[m_y][m_x].visited = true;
                graph[m_y][m_x].parent = {x, y};
                st.push({m_x, m_y});
                if(m_x == n - 2 && m_y == n - 2) break;
            }
        }
    }
    string out;
    get_path(out, {n - 2, n - 2});
    cout << out.size() << endl << out << endl;
    return 0;
}
