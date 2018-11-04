#include <iostream>
#include <vector>

using namespace std;

bool isValid(int i , int j , int rs, int cs, vector<vector<char>> m, vector<vector<int>> &v, int ad) {
    //cout<<"i j "<<i<<" "<<j<<endl;
    // visited
    if (v[i][j] != 0) {
        return (v[i][j] == 1) ? true : false;
    }
    // boundary
    if (i == 0 || i == rs - 1 || j == 0 || j == cs - 1) {
        v[i][j] = 2;
        return false;
    }

    // check
    vector<int> dirx{0, -1, 0, 1};
    vector<int> diry{-1, 0, 1, 0};
    for (int in = 0; in < (int)dirx.size(); ++in) {
        if (in == ad) continue;
        int x = i + dirx[in];
        int y = j + diry[in];
        //cout<<x<<" "<<y<<endl;
        if (m[x][y] == 'b') continue;
        else if (isValid(x, y, rs, cs, m, v, (in + 2) % 4)) {
            v[x][y] = 1;
        } else {
            v[x][y] = 2;
            return false;
        }
    }

    return true;
}

int countW(vector<vector<char>> m) {
    int cs = 0, rs = 0; // cs for column size, rs for row size
    int a = 0;
    rs = m.size();
    cs = m[0].size();
    vector<vector<int>> visited(rs, vector<int>(cs, 0)); // 1 for true, 2 for false
    // boundary
    if (rs  == 0 || cs == 0) return 0;

    // loop
    for (int i = 0; i < rs; ++i) {
        for (int j = 0; j < cs; ++j) {
            if (m[i][j] == 'w' && isValid(i, j, rs, cs, m, visited, 4)) a++;
        }
    }

    return a;
}

int main() {
    vector<vector<char>> m;
    vector<char> m1{'b', 'b', 'b', 'b'};
    vector<char> m2{'w', 'w', 'w', 'b'};
    vector<char> m3{'w', 'w', 'b', 'b'};
    vector<char> m4{'w', 'b', 'b', 'b'};
    m.push_back(m1);
    m.push_back(m2);
    m.push_back(m3);
    m.push_back(m4);
    cout<<countW(m)<<endl;
    return countW(m);
}
