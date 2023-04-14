#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	auto adj = vvi(n + 1, vi{});
	for (auto i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;

		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	auto par = vi(n + 1, -1);

	auto q = queue<int>{};
	q.push(1);

	while (!q.empty()) {
		auto f = q.front();
		q.pop();

		const auto& nbd = adj[f];
		for (const auto& v : nbd) {
			if (-1 == par[v]) {
				par[v] = f;
				q.push(v);
			}
		}
	};

	for (auto i = 2; i <= n; ++i) {
		cout << par[i] << '\n';
	}

	return 0;
}