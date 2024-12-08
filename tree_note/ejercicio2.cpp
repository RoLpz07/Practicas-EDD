#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Node {
    string name;
    Node* parent;
    Node* firstChild;
    Node* nextSibling;

    Node(const string& name) : name(name), parent(nullptr), firstChild(nullptr), nextSibling(nullptr) {}
};

class FamilyTree {
public:
    FamilyTree(const string& rootName) {
        root = new Node(rootName);
    }


    void addChild(const string& parentName, const string& childName) {
        Node* parentNode = findNode(root, parentName);
        if (parentNode) {
            Node* childNode = new Node(childName);
            childNode->parent = parentNode;

            if (!parentNode->firstChild) {
                parentNode->firstChild = childNode;
            } else {
                Node* sibling = parentNode->firstChild;
                while (sibling->nextSibling) {
                    sibling = sibling->nextSibling;
                }
                sibling->nextSibling = childNode;
            }
        }
    }

    void printTree() {
        printNode(root, 0);
    }

private:
    Node* root;

    Node* findNode(Node* node, const string& name) {
        if (!node) return nullptr;
        if (node->name == name) return node;
        Node* found = findNode(node->firstChild, name);
        if (found) return found;
        return findNode(node->nextSibling, name);
    }

    void printNode(Node* node, int depth) {
        if (!node) return;
        for (int i = 0; i < depth; ++i) cout << "  ";
        cout << node->name << endl;
        printNode(node->firstChild, depth + 1);
        printNode(node->nextSibling, depth);
    }
};

void readCSV(const string& filename, FamilyTree& tree) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string parent, child;
        getline(ss, parent, ',');
        getline(ss, child, ',');
        tree.addChild(parent, child);
    }
}

int main() {
    FamilyTree tree("RootPerson");
    readCSV("family.csv", tree);
    tree.printTree();
    return 0;
}