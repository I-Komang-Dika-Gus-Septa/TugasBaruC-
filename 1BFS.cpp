#include <iostream>
#include <vector>
#include <queue>
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

void BFS(Node* root, vector<char>& hasil) {
    if(root == nullptr)
        return;

    queue<Node*> input;
    input.push(root);

    while(!input.empty()) {
        Node* temp = input.front();
        input.pop();

        hasil.push_back(temp->data);

        if(temp -> left != nullptr)
            input.push(temp->left);

        if(temp -> right != nullptr)
            input.push(temp->right);
    }
}

int main() {

    Node* root = new Node('A'); root -> left = new Node('B');
    root -> right = new Node('C'); root -> left -> left = new Node('D');
    root -> left -> right = new Node('E'); root -> right -> right = new Node('F');

    vector<char> hasil;
    BFS(root, hasil);
    cout << "Hasil BFS: ";

    for(char x : hasil) {
            cout << x;
        if(x != hasil.back())
            cout << " --> ";
    }
    return 0;
}