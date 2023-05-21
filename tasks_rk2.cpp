#include "tasks_rk2.h"
int Node::countNodes = 0;
Node::Node() {
    parent = nullptr;
    IsHere = false;
    name = 0;
}
Node::Node(int nameNode) {
    parent = nullptr;
    IsHere = false;
    name = nameNode;
}
Node::~Node() {
    listChilds.clear();
}
Graph::Graph() {
    head = nullptr;
}
Graph::Graph(int number) {
    head=new Node;
    head->parent= nullptr;
    buildTreeDFS(number);
}
Graph::~Graph() {
    delete head;
}

void Graph::b_DFS(Node* head, int number) {
    Node* parent = head;
    parent->name = Node::countNodes;
    for (int i = 0; i < number; i++){
        Node* child = new Node();
        Node::countNodes++;
        parent->listChilds.push_back(child);
        child->parent = parent;
        b_DFS(child, number - 1);
    }
}

int Graph::buildTreeDFS(int countNodes) {
    head = new Node();
    b_DFS(head, countNodes);
    return Node::countNodes;
}

void Graph::DFS1(FILE* res) {
    head->IsHere = true;
    fprintf(res, "%i%c", head->name, '{');
    for (auto n: head->listChilds) {
        head = n;
        if (!head->IsHere) {
            DFS1(res);
            fprintf(res, "%c", '}');
        }
    }
}
void Graph::DFS() {
    FILE* result = fopen("dfs_res.txt", "w");
    DFS1(result);
    fclose(result);
}

int Graph::buildTreeBFS(int countNodes) {
    
}