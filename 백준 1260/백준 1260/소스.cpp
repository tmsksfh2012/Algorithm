#include <iostream>
#include <queue>
using namespace std;

int Mat[1001][1001] = { 0, };
int visit[1001] = { 0, };
int N, M, V;

void dfs(int v) {
	cout << v << ' ';
	visit[v] = 1;
	for (int i = 1; i <= N; i++) {
		if (visit[i] == 1 || Mat[v][i] == 0)
			continue;
		dfs(i);
	}
}

void bfs(int v) {
	queue<int> q;            //bfs에서는 q를사용
	q.push(v);
	visit[v] = 0;            //방문한 노드를 visit 1에서 0으로 변경
	while (!q.empty()) {
		v = q.front();
		cout << q.front() << ' ';
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (visit[i] == 0 || Mat[v][i] == 0)
				continue;
			q.push(i);
			visit[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tmpX = 0;
	int tmpY = 0;

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {

		cin >> tmpX >> tmpY;
		Mat[tmpX][tmpY] = Mat[tmpY][tmpX] = 1;
	}

	dfs(V);
	cout << '\n';
	bfs(V);
	return 0;
}