#include<iostream>
#include<list>
#include<queue>

#ifndef RK2_TASKS_RK2_H
#define RK2_TASKS_RK2_H

struct Node {
    Node();
    Node(int nameNode);
    ~Node();

    Node* parent;
    std::list<Node*> listChilds;
    bool IsHere;
    int name;
    static int countNodes;
};

class Graph {
private :
    Node* head;
    Node* current;
    void b_DFS(Node* current, int number);
    void DFS1(FILE* flog);
    int number;
public :
    Graph();
    Graph(int countNodes);
    ~Graph();
    /*
        output		:	-1 - если функция не реализована
                    :	положительное число -- число узлов
        author		:
        date		:
    */
    int buildTreeBFS(int countNodes);
    /*
        output		:	-1 - если функция не реализована
                    :	положительное число -- число узлов
        author		:
        date		:
    */
    int buildTreeDFS(int countNodes);

    void BFS();
    void DFS();
    /*
        description	:	функция поиска узла по его имени
        input 		:	nameNode -- имя узла
        output		:	{bool -- узел найден, list<int> -- список имён узлов до необходимого}
        description	:	приставка DFS -- поиск в глубину, BSF -- поиск в ширину
        author		:
        date		:
    */
    std::pair<bool, std::list<int>> searchDFS(int nameNode);
    std::pair<bool, std::list<int>> searchBFS(int nameNode);
};

#endif //RK2_TASKS_RK2_H
