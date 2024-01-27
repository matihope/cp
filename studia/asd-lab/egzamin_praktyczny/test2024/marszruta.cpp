#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

typedef long long   LL;
typedef vector<int> VI;

struct vert: public vector<int> {
	int parent = -1;
};

vector<bool> visited;
vector<vert> graph;
queue<int>   ans;

void push(int v) {
	if (ans.empty() || ans.back() != v) ans.push(v);
}

void dfs(int v, int parent, int n) {
	push(v);
	visited[v]      = true;
	graph[v].parent = parent;
	for (auto neigh : graph[v]) {
		if (!visited[neigh]) {
			dfs(neigh, v, n);
			push(v);
		}
	}
	push(v);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, e;
	cin >> n >> e;

	graph.resize(n + 1);
	visited.resize(n + 1, false);

	while (e--) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1, -1, n);
	if (ans.back() != n) {
		stack<int> res;
		int        v = n;
		while (v != -1) {
			res.push(v);
			v = graph[v].parent;
		}

		while (!res.empty()) {
			push(res.top());
			res.pop();
		}
	}

	cout << ans.size() << '\n';
	while (ans.size()) {
		cout << ans.front() << ' ';
		ans.pop();
	}
	cout << '\n';
}
