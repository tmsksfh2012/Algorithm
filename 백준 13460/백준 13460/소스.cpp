#include<iostream>
#include<string>
#include<queue>
using namespace std;

int N, M;
int rx, ry, bx, by; // ���� ��ġ
int hx, hy; // ������ ��ġ
bool flag;
int ans = 0; // ����
char board[11][11]; // ����
int visited[11][11][11][11]; // rx, ry, bx, by ��ġ�� ���� �湮 ���� �迭
queue<pair<int, int>> redball;
queue<pair<int, int>> blueball;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main(void)
{
	string str;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			board[i][j] = str[j];
			if (board[i][j] == 'R') {
				redball.push(make_pair(i, j));
				rx = i, ry = j;
			}
			if (board[i][j] == 'B') {
				blueball.push(make_pair(i, j));
				bx = i, by = j;
			}
			if (board[i][j] == 'O') hx = i, hy = j;
		}
	}

	visited[rx][ry][bx][by] = true;

	while (!redball.empty())
	{
		int qsize = redball.size();

		while (qsize--)
		{
			rx = redball.front().first;
			ry = redball.front().second;
			bx = blueball.front().first;
			by = blueball.front().second;
			redball.pop(); blueball.pop();

			// 10�� �̻� Ž�������� break
			if (ans > 10) break;
			// ���� ������ ���ۿ� ������ break
			if (rx == hx && ry == hy) { flag = true; break; }

			for (int i = 0; i < 4; i++)
			{
				int nrx = rx + dx[i];
				int nry = ry + dy[i];
				int nbx = bx + dx[i];
				int nby = by + dy[i];

				// �����¿� �������� ���� �����̱�
				while (1)
				{
					if (board[nrx][nry] == '#') {
						nrx -= dx[i]; nry -= dy[i];
						break;
					}
					if (board[nrx][nry] == 'O') break;
					nrx += dx[i]; nry += dy[i];
				}
				while (1)
				{
					if (board[nbx][nby] == '#') {
						nbx -= dx[i]; nby -= dy[i];
						break;
					}
					if (board[nbx][nby] == 'O') break;
					nbx += dx[i]; nby += dy[i];
				}

				// �Ķ� ������ ���ۿ� ������ continue
				if (nbx == hx && nby == hy) continue;

				// ���� ��ġ�� �� ���� ������ ������ ��ġ ����
				if (nrx == nbx && nry == nby)
				{
					switch (i) {
					case 0: rx > bx ? nrx++ : nbx++; break;
					case 1: rx < bx ? nrx-- : nbx--; break;
					case 2: ry > by ? nry++ : nby++; break;
					case 3: ry < by ? nry-- : nby--; break;
					}
				}

				// �湮�ߴ� ������ �ƴϸ� push
				if (visited[nrx][nry][nbx][nby]) continue;
				redball.push(make_pair(nrx, nry));
				blueball.push(make_pair(nbx, nby));
				visited[nrx][nry][nbx][nby] = true;
			}
		}
		if (flag) break;
		else ans++;
	}

	if (flag) cout << ans;
	else cout << -1;

	return 0;
}