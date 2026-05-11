#pragma once
class BST {
    struct Node {
        int value;
        Node *left;
        Node *right;
    };
    
    Node *root;

    // private helpers not exposed to the user
    bool isAVLAUX(Node *n);
    bool isFullAUX(Node *n);
    void clearAUX(Node *n);
    bool identicalAUX(Node *a, Node *b);

public:
    BST();

    bool isEmpty();
    bool isIdenticalTo(BST other);

    int countNodes();
    int countNodesAUX(Node *n);

    int findMax();
    int findMin();

    int countLeafNodes();
    int countLeafNodesAUX(Node *n);

    int height();
    int heightAUX(Node *n);

    int countNodesAtLevel(int level);
    int countNodesAtLevelAUX(Node *n, int level); // added int level

    bool isAVL();
    bool isFull();
    bool isComplete();

    int countNodesWith1Child();
    int countNodesWith1ChildAUX(Node *n);
    
    int countNodesWith2Children();
    int countNodesWith2ChildrenAUX(Node *n);

    void deleteNodesWith1Child();
    void deleteNodesWith1ChildAUX(Node *&n); // changed to Node *&

    void deleteNodesWith2Children();
    void deleteNodesWith2ChildrenAUX(Node *&n); // changed to Node *&

    void deleteLeafNodes();
    void deleteLeafNodesAUX(Node *&n); // changed to Node *&

    void insert(int val);
    void insertAUX(Node *n, int val);

    bool search(int val);
    bool searchAUX(Node *n, int val);

    void inOrder(void (*pf)(int));
    void inOrderAUX(Node *n, void (*pf)(int));

    void preOrder(void (*pf)(int));
    void preOrderAUX(Node *n, void (*pf)(int));

    void postOrder(void (*pf)(int));
    void postOrderAUX(Node *n, void (*pf)(int));

    int size();
    int sizeAUX(Node *n);

    void clearTree();
    void destroyTree();

    void display();
    void displayAUX(Node *n); // added Node *n parameter

    void printLevelByLevel();
};
