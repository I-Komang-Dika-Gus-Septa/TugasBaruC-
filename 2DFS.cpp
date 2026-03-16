#include <iostream>
#include <vector>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    char data;

    Node(char x) {
        data = x;
        left = right = nullptr;
    }
};

void DFS(Node* node, vector<char>& hasil) {
    if(node == nullptr) return;
    hasil.push_back(node -> data);
    DFS(node -> left, hasil); DFS(node -> right, hasil);
}

int main() {

    Node* root = new Node('A'); root -> left = new Node('B');
    root -> right = new Node('C'); root -> left -> left = new Node('D');
    root -> left -> right = new Node('E'); root -> right -> right = new Node('F');

    vector<char> hasil;
    DFS(root, hasil);
    cout << "Hasil DFS: ";

    for(char x : hasil) {
            cout << x;
        if(x != hasil.back())
            cout << " --> ";
    }
    return 0;
}