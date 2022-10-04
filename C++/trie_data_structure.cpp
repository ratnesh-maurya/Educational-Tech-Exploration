// TRIE DATA STRUCTURE IMPLEMENTATION
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char ch;
    unordered_map<char, Node*> children;
    bool terminal;
    Node(char data) {
        ch = data;
        terminal = false;
    }
};

class Trie {
    Node *root;
    int cnt;
public:
    Trie() {
        root = new Node('\0');
        cnt = 0;
    }
    void insert(char *w) {
        Node *temp = root;
        for (int i = 0; w[i] != '\0'; i++) {
            char ch = w[i];
            if (temp->children.count(ch) != 0) {
                temp = temp->children[ch];
            } else {
                Node *n = new Node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
        temp->terminal =  true;
    }

    bool find(char *w) {
        Node *temp = root;
        for (int i = 0; w[i] != '\0'; i++) {
            char ch = w[i];
            if (temp->children.count(ch) == 0) {
                return false;
            } else {
                temp = temp->children[ch];
            }
        }
        return temp->terminal;
    }
};

int main() {
    Trie t;
    char words[][10] = {"no", "a", "hello", "not", "news", "apple"};
    char w[20];
    cin >> w;
    for (int i = 0; i < 6; i++) {
        t.insert(words[i]);
    }
    if (t.find(w)) {
        cout << "Present" << endl;
    } else {
        cout << "Not Present" << endl;
    }
    return 0;
}
