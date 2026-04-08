#define N 4

typedef struct {
           int strike;
           int ball;
} Result;
 
// API
extern Result query(int guess[]);

int* num;
int failed[1000][6];
int query_cnt;
int used[10];

bool dfs(int len) {
    if (len == N) {
        for (int i = 0; i < query_cnt; i++) {
            int s = 0, b = 0;
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    if (failed[i][j] == num[k]) {
                        if (j == k) s++;
                        else b++;
                    }
                }
            }

            if (failed[i][4] != s || failed[i][5] != b)
                return false;
        }

        Result ret = query(num);
        if (ret.strike == 4) return true;

        for (int i = 0; i < 4; i++) {
            failed[query_cnt][i] = num[i];
        }
        failed[query_cnt][4] = ret.strike;
        failed[query_cnt][5] = ret.ball;
        query_cnt++;

        return false;
    }

    for (int i = 0; i < 10; i++) {
        if (used[i]) continue;
        num[len] = i;
        used[i] = 1;
        if (dfs(len + 1)) return true;
        used[i] = 0;
    }
    return false;
}

void doUserImplementation(int guess[]) {
    num = guess;
    query_cnt = 0;
    for (int i = 0; i < 10; i++)
        used[i] = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 6; j++) failed[i][j] = 0;
    }
    dfs(0);
}
