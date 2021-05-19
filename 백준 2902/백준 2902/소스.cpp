#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;

	int i = 1;
	while (str[i]) {
		if (str[i] == '-') {
			str.erase(i, 1);
			i++;
		}
		else {
			str.erase(i, 1);
		}
	}
	cout << str;
}