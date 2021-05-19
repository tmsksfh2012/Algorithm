#include <iostream>
#include <string>
#include <algorithm>

#define N_MAX 1000 + 1 
#define STR_MAX 50 + 1

using namespace std;

string box[N_MAX];
int num;
int sort_cmp(string& A, string& B);

int main() {

	scanf("%d", &num);

	char tmp[STR_MAX];
	for (int i = 0; i < num; i++) {
		scanf("%s", tmp);
		box[i] = tmp;
	}

	printf("\n");
	sort(box, box + num, sort_cmp);

	for (int i = 0; i < num; i++) {
		cout << box[i] << "\n";
	}
}

int sort_cmp(string& A, string& B) {

	cout << "Box: ";
	for (int i = 0; i < num; i++) {
		cout << box[i]+" ";
	}
	cout << "A: " + A << endl;
	cout << "B: " + B << endl;
	// 1. 크기 비교
	int A_size = A.size(), B_size = B.size();
	if (A_size != B_size) {
		printf("1. %d\n", A_size < B_size);
		return A_size < B_size;
	}

	// 2. 합 구하고 비교
	int A_sum = 0, B_sum = 0;
	for (int idx = 0; idx < A_size; idx++) {
		if ('0' <= A[idx] && A[idx] <= '9')    A_sum += A[idx] - '0';
		if ('0' <= B[idx] && B[idx] <= '9')    B_sum += B[idx] - '0';
	}
	if (A_sum != B_sum) {

		printf("2. %d\n", A_sum < B_sum);
		
		return A_sum < B_sum;
	}

	// 3. 사전순 비교
	printf("3. %d\n", A < B);

	return A < B;
}