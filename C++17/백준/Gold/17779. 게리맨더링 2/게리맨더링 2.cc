#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int A[21][21];
int border[21][21];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    int total = 0;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> A[r][c];
            total += A[r][c];
        }
    }

    int answer = total;
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            for (int d1 = 1; d1 <= N; d1++) {
                for (int d2 = 1; d2 <= N; d2++) {
                    if (x + d1 + d2 > N) continue;
                    if (y - d1 < 1) continue;
                    if (y + d2 > N) continue;

                    memset(border, 0, sizeof(border));

                    for (int i = 0; i <= d1; i++) border[x + i][y - i] = 1;
                    for (int i = 0; i <= d2; i++) border[x + i][y + i] = 1;
                    for (int i = 0; i <= d2; i++) border[x + d1 + i][y - d1 + i] = 1;
                    for (int i = 0; i <= d1; i++) border[x + d2 + i][y + d2 - i] = 1;

                    int group[6] = {};

                    for (int r = 1; r < x + d1; r++) {
                        for (int c = 1; c <= y; c++) {
                            if (border[r][c]) break;
                            group[1] += A[r][c];
                        }
                    }

                    for (int r = 1; r <= x + d2; r++) {
                        for (int c = N; c > y; c--) {
                            if (border[r][c]) break;
                            group[2] += A[r][c];
                        }
                    }

                    for (int r = x + d1; r <= N; r++) {
                        for (int c = 1; c < y - d1 + d2; c++) {
                            if (border[r][c]) break;
                            group[3] += A[r][c];
                        }
                    }

                    for (int r = x + d2 + 1; r <= N; r++) {
                        for (int c = N; c >= y - d1 + d2; c--) {
                            if (border[r][c]) break;
                            group[4] += A[r][c];
                        }
                    }

                    group[5] = total - group[1] - group[2] - group[3] - group[4];

                    int max_group = *max_element(group + 1, group + 6);
                    int min_group = *min_element(group + 1, group + 6);
                    answer = min(answer, max_group - min_group);
                }
            }
        }
    }

    cout << answer << '\n';
    return 0;
}