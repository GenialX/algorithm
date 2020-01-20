// LeetCode 挂灯笼
#include <iostream>
#include <vector>

using namespace std;

const int ROW = 4, COL = 4;
const int LEET = 0, CODE = 1, EMPTY = 2;
// leet cnt, code cnt
int cnt[2] = {8, 8};
int d[3] = {0, -1, 0}; // left, up
int d2[5] = {0, -1, 0, 1, 0}; // left, up, right down
int a[ROW][COL];
long result = 0;

void helper(int p) {
    if (ROW * COL == p) {
        if (a[ROW - 1][COL - 1] != a[ROW - 2][COL - 1] || a[ROW - 1][COL - 1] != a[ROW - 1][COL - 2]) {
            ++result;
        }
        /**
        cout << "answer" << endl;
        for (int r = 0; r < ROW; ++r ) {
            for (int c = 0; c < COL; ++c) 
                cout << a[r][c] << " ";
            cout << endl;
        }
        **/
        return;
    }
    int r = p / COL, c = p % COL;
    for (int i = 0; i < 2; ++i) {
        if (cnt[i] == 0) continue;
        --cnt[i];
        a[r][c] = i;
        bool can = true;
        
        for (int di = 0; di < 2; ++di) {
            int nr = r + d[di];
            int nc = c + d[di + 1];
            if (nr < 0 || nr >= ROW || nc < 0 || nc >= COL) continue;
            
            int status[3] = {0, 0, 0}; 
            ++status[a[nr][nc]];
            for (int dii = 0; dii < 4; ++dii) {
                int nnr = nr + d2[dii];
                int nnc = nc + d2[dii + 1];
                if (nnr < 0 || nnr >= ROW || nnc < 0 || nnc >= COL) continue;
                ++status[a[nnr][nnc]];
            }
            if (status[EMPTY] == 0 && (status[LEET] == 0 || status[CODE] == 0)) {
                can = false;
                break;
            }
        }

        if (can) helper(p + 1);
        
        a[r][c] = EMPTY;
        ++cnt[i];
    }
}

int main() {
    for (int r = 0; r < ROW; ++r)
        for (int c = 0; c < COL; ++c) 
            a[r][c] = 2;
    helper(0);
    cout << result << endl;
    return result;
}