#include <iostream>
#include <vector>

using namespace std;

int cnt;

typedef struct Node {
    vector<int> adj;
};
void search(Node* nodes, int length, int index, vector<int> &visited, int level) {
    if (visited[index] == 1) {
        return;
    } 
    
    visited[index] = 1;
    if (level == length-1) {
        for (int i = 0; i < size(nodes[index].adj); i++) {
            if (nodes[index].adj[i] == 0) {
                
                cnt++;
                
            } 
        }
    } else {
        for (int i = 0; i < size(nodes[index].adj); i++) {
        search(nodes, length, nodes[index].adj[i], visited, level+1);
            
        }
    }
    
    visited[index] = 0;
    return;
}
void hamiltonian(Node* nodes, int length) {
    vector<int> visited(length, 0);

    search(nodes, length, 0, visited, 0);

}

int main() {
    int n, input;
    cin >> n;

    Node* nodes = new Node[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> input;
            if (input == 1) {
                nodes[i].adj.push_back(j);
            }
        }
    }

    hamiltonian(nodes, n);

    if (cnt > 0) 
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    cout << "The count: " << cnt;


    return 0;
}