#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 31;
int manlist[maxn][maxn] = { 0 }; // 男士的偏好列表
int womanlist[maxn][maxn] = { 0 }; // 女士的偏好列表
int woman[maxn] = { 0 }, man[maxn] = { 0 };
bool lovewho(int w, int m, int n) {//女士的偏好
    for (int i = 1; i <= n; ++i) {
        if (womanlist[w][i] == m) return true;
        else if (womanlist[w][i] == woman[w]) return false;
    }
    //return false;
}
void stableMatch(int n) {
    int m, w;
    while (man[0] != n) {
        m = w = 0;
        while (man[++m] != 0);
        w = manlist[m][++manlist[m][0]];
        if (woman[w]) {
            if (lovewho(w, m, n)) {
                man[woman[w]] == 0;
                woman[w] == m;
                man[m] == w;
            }
            else continue;
        }
        else {
            man[m] = w;
            ++man[0];
            woman[w] == m;
            ++woman[0];
        }
    }
}
void stableMatching(int n) {
    int m, w;
    while (man[0] != n) {//记录已经匹配的男士
        w = m = 0;
        while (man[++m] != 0);
        w = manlist[m][++manlist[m][0]];//[0]对应该男生只能从该号开始选
        if (woman[w]) {//如果该女生已经匹配了
            if (lovewho(w, m, n)) {//更喜欢现在的
                man[woman[w]] = 0;//之前男生自由
                man[m] = w;
                woman[w] = m;
            }
            else continue;//继续下一个
        }
        else {
            man[m] = w; ++man[0];
            woman[w] = m; ++woman[0];
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << man[i] << " ";
    }
}
int main() {
    int n;
    cin >> n; 
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> manlist[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> womanlist[i][j];
        }
    }
    stableMatching(n); // 进行稳定匹配
    return 0;
}
