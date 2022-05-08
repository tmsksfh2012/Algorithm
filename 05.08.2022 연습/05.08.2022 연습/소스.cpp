#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
// 방문 시 true
bool chk[110][110]{};
int M{}, N{};

bool isValidCoord(int r, int c) {
    return r < M && 0 <= r && c < N && 0 <= c;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    M = m; N = n;

    int number_of_area = 1;
    int max_size_of_one_area = 0;

    // 좌표와 영역 칸을 저장한다.
    queue<pair<pair<int, int>, int>> q{};
    q.push({ {0,0},1 });

    while (!q.empty()) {
        int cr = q.front().first.first;
        int cc = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if (chk[cr][cc])
            continue;

        chk[cr][cc] = 1;
        bool noNext{};
        for (int i{}; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (isValidCoord(nr, nc) && !chk[nr][nc]) {
                if (picture[cr][cc] == picture[nr][nc]) {
                    noNext = false;
                    if (picture[nr][nc] == 0) {
                        noNext = true;
                        q.push({ {nr,nc},0 });
                    }
                    else
                        q.push({ {nr,nc},cnt++ });
                }
                else {
                    noNext = true;
                    if (picture[nr][nc] == 0)
                        q.push({ {nr,nc},0 });
                    else
                        q.push({ {nr,nc},1 });
                }
            }
        }
        if (noNext) {
            number_of_area++;
            max_size_of_one_area = max_size_of_one_area > cnt ? max_size_of_one_area : cnt;
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main() {
    int m{}, n{};

    cin >> m >> n;
    vector<vector<int>> vc{};
    vc.push_back({ 1, 1, 1, 0 });
    vc.push_back({ 1, 1, 1, 0 });
    vc.push_back({ 0, 0, 0, 1 });
    vc.push_back({ 0, 0, 0, 1 });
    vc.push_back({ 0, 0, 0, 1 });
    vc.push_back({ 0, 0, 0, 1 });
    vector<int> s = solution(m, n, vc);

    for (auto num : s) {
        cout << num << endl;
    }

    //[[1, 1, 1, 0], [1, 1, 1, 0], [0, 0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 1]]
}