#include <iostream>
#include <queue>

using namespace std;

class node {
public:
    node *left, *right;
    int data;
};

class Breadthfs {
public:
    node *insert(node *, int);
    void bfs(node *);
};

node *Breadthfs::insert(node *root, int data) {
    if (!root) {
        root = new node;
        root->left = NULL;
        root->right = NULL;
        root->data = data;
        return root;
    }
    queue<node *> q;
    q.push(root);

    while (!q.empty()) {
        node *temp = q.front();
        q.pop();
        if (temp->left == NULL) {
            temp->left = new node;
            temp->left->left = NULL;
            temp->left->right = NULL;
            temp->left->data = data;
            return root;
        } else {
            q.push(temp->left);
        }

        if (temp->right == NULL) {
            temp->right = new node;
            temp->right->left = NULL;
            temp->right->right = NULL;
            temp->right->data = data;
            return root;
        } else {
            q.push(temp->right);
        }
    }
    return root; // added return statement to fix control reaches end of non-void function warning
}

void Breadthfs::bfs(node *head) {
    queue<node*> q;
    q.push(head);

    while (!q.empty()) {
        int qSize = q.size();
        // Iterate through the current level
        for (int i = 0; i < qSize; i++) {
            node* currNode = q.front();
            q.pop();
            cout << "\t" << currNode->data;

            // Enqueue the children (if any) of the current node
            if (currNode->left)
                q.push(currNode->left);
            if (currNode->right)
                q.push(currNode->right);
        }
    }
}

int main() {
    node *root = NULL;
    int data;
    char ans;
    Breadthfs bfs_obj;

    do {
        cout << "\nEnter data: ";
        cin >> data;
        root = bfs_obj.insert(root, data);
        cout << "Do you want to insert one more node? (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    cout << "Breadth First Search Traversal:" << endl;
    bfs_obj.bfs(root);

    return 0;
}
