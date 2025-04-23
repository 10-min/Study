#include <iostream>
#include <vector>
#include <tuple>

#define INF 1e9;
using namespace std;

void Relaxation(int* D, int start, int end, int w) {
    if (D[end] > D[start] + w) {
        D[end] = D[start] + w;
    }
};
void Bellman_Ford(vector<tuple<int,int,int>> E, int* D, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < size(E); j++) {
            Relaxation(D, get<0>(E[j]), get<1>(E[j]), get<2>(E[j]));
        }
    }

    for (int j = 0; j < size(E); j++) {
        if (D[get<1>(E[j])] > D[get<0>(E[j])] + get<2>(E[j])) {
            cout << "Error: There are negative cycles." << endl;
            return;
    }
    }


    for (int i = 0; i < n; i++) {
        cout << D[i] << " ";
    }
    cout << endl;
};

int main(void) {

    int node_cnt = 5;

    int s = 0, t = 1, x = 2, y = 3, z = 4;

    int* D = new int[node_cnt];
    D[0] = 0;
    for (int i = 1; i < node_cnt; i++) {
        D[i] = INF;
    }

    
    
    
    // Passive node weight input
    /*w[s][t] = 6;
    w[s][y] = 7;
    w[t][x] = 5;
    w[t][z] = -4;
    w[t][y] = 8;
    w[x][t] = -2;
    w[y][z] = 9;
    w[y][x] = -3;
    w[z][x] = 7;
    w[z][s] = 2;*/

    vector<tuple<int, int, int>> E;
    
    E.push_back({s, t, 6});
    E.push_back({s, y, 7});
    E.push_back({t, x, 5});
    E.push_back({t, z, -4});
    E.push_back({t, y, 8});
    E.push_back({x, t, -2});
    E.push_back({y, z, 9});
    E.push_back({y, x, -3});
    E.push_back({z, x, 7});
    E.push_back({z, s, 2});

    Bellman_Ford(E, D, node_cnt);

    return 0;
}