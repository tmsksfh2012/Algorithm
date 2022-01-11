#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map> 

using namespace std; 

void __init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
}

int main(void) {
	__init();
	int N, K; 
	cin >> N >> K;
	
	vector<int> numbers(N); 
	
	for (int i = 0; i < N; i++) {
		cin >> numbers[i]; 
	}
	
	sort(numbers.begin(), numbers.end());
	
	map<string, bool> visited; 

	int cnt = 0;
	do {
		string s;
		
		for (int k = 0; k < K; k++) {
			s += to_string(numbers[k]); 
		} 
		
		if (visited.count(s) == false) {
			visited[s] = true; 
			cnt++; 
		} 
	} while (next_permutation(numbers.begin(), numbers.end()));
	
	cout << cnt;
}
