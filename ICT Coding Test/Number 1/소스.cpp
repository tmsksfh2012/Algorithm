#include <iostream>
#include <vector>
using namespace std;

int main() {
    int TC{}, ans{};
    vector<int> px{};

    cin >> TC;

    while (TC--) {
        int tmp{};
        cin >> tmp;

        px.push_back(tmp);
    }

    for (int i{}; i < px.size(); i++) {
        for (int j = i; j < px.size(); j++) {
            if (px[j] > px[i]) {
                int gap = px[j] - px[i];
                if (ans < gap)
                    ans = gap;
            }
        }
    }
    cout << ans;
}