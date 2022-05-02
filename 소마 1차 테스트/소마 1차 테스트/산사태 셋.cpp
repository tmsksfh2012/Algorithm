#include <iostream>
using namespace std;

void sum_posneg(int* matrix, int col_size, int row_size, int dir) {
    int idx{};

    int pos_sum{}, neg_sum{};

    if (dir == 1) {
        for (int i = 0; i < row_size; i++) {
            if (*(matrix + idx * col_size + i) >= 0) {
                pos_sum += *(matrix + idx*col_size + i);
            }
            else
                neg_sum += *(matrix + idx * col_size + i);

            if (i == row_size - 1 && idx <= col_size - 1) {
                cout << pos_sum << " " << neg_sum << "\n";
                pos_sum = 0;
                neg_sum = 0;
                idx++;
                i = -1;
            }
        }
    }
    else if (dir == 2) {
        for (int i = 0; i < col_size; i++) {
            if (*(matrix + i * row_size + idx) >= 0)
                pos_sum += *(matrix + i*row_size + idx);
            else
                neg_sum += *(matrix + i * row_size + idx);

            if (i == col_size - 1 && idx <= row_size - 1) {
                cout << pos_sum << " " << neg_sum << "\n";
                pos_sum = 0;
                neg_sum = 0;
                idx++;
                i = -1;
            }
        }
    }
}

int main() {
    int matrix[3][3] = { {1, -1, -2}, {-1, 1, 1}, {1, 1, 1} };
    int dir = 1;
    sum_posneg((int*)matrix, 3, 3, dir);
}