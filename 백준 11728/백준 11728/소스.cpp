#include <cstdio>
#include <algorithm>

using namespace std;

int main() {

	int size_A, size_B;

	scanf("%d", &size_A);
	scanf("%d", &size_B);

	int size = size_A + size_B;

	int* box = new int[size];

	int temp = 0;

	for (int i = 0; i < size; i++) {
		scanf("%d", &temp);
		box[i] = temp;
	}

	sort(box, box + size);

	for (int i = 0; i < size; i++) printf("%d ", box[i]);
}