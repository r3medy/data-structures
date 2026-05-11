#include "BST.h"
#include <iostream>
using namespace std;

// ─── Constructor ────────────────────────────────────────────────────────────

BST::BST() {
    root = nullptr;
}

// ─── isEmpty ────────────────────────────────────────────────────────────────

bool BST::isEmpty() {
    return root == nullptr;
}

// ─── insert ─────────────────────────────────────────────────────────────────

void BST::insert(int val) {
    // if tree is empty, create root directly
    if (root == nullptr) {
        root = new Node();
        root->value = val;
        root->left  = nullptr;
        root->right = nullptr;
        return;
    }
    insertAUX(root, val);
}

void BST::insertAUX(Node *n, int val) {
    if (val < n->value) {
        // val belongs in the left subtree
        if (n->left == nullptr) {
            // found the empty spot — create the node here
            n->left = new Node();
            n->left->value = val;
            n->left->left  = nullptr;
            n->left->right = nullptr;
        } else {
            // keep searching left
            insertAUX(n->left, val);
        }
    } else {
        // val belongs in the right subtree
        if (n->right == nullptr) {
            n->right = new Node();
            n->right->value = val;
            n->right->left  = nullptr;
            n->right->right = nullptr;
        } else {
            insertAUX(n->right, val);
        }
    }
}

// ─── search ─────────────────────────────────────────────────────────────────

bool BST::search(int val) {
    return searchAUX(root, val);
}

bool BST::searchAUX(Node *n, int val) {
    // base case: fell off the tree — not found
    if (n == nullptr) return false;

    if (val == n->value) return true;           // found it
    if (val < n->value)  return searchAUX(n->left,  val); // go left
    else                 return searchAUX(n->right, val); // go right
}

// ─── Traversals ─────────────────────────────────────────────────────────────

void BST::inOrder(void (*pf)(int)) {
    inOrderAUX(root, pf);
}
void BST::inOrderAUX(Node *n, void (*pf)(int)) {
    if (n == nullptr) return;
    inOrderAUX(n->left,  pf); // left subtree first
    (*pf)(n->value);           // then current node
    inOrderAUX(n->right, pf); // then right subtree
}

void BST::preOrder(void (*pf)(int)) {
    preOrderAUX(root, pf);
}
void BST::preOrderAUX(Node *n, void (*pf)(int)) {
    if (n == nullptr) return;
    (*pf)(n->value);            // current node first
    preOrderAUX(n->left,  pf);
    preOrderAUX(n->right, pf);
}

void BST::postOrder(void (*pf)(int)) {
    postOrderAUX(root, pf);
}
void BST::postOrderAUX(Node *n, void (*pf)(int)) {
    if (n == nullptr) return;
    postOrderAUX(n->left,  pf);
    postOrderAUX(n->right, pf);
    (*pf)(n->value);            // current node last
}

// ─── countNodes ─────────────────────────────────────────────────────────────

int BST::countNodes() {
    return countNodesAUX(root);
}
int BST::countNodesAUX(Node *n) {
    if (n == nullptr) return 0;
    // count this node (1) + everything in left + everything in right
    return 1 + countNodesAUX(n->left) + countNodesAUX(n->right);
}

// ─── countLeafNodes ─────────────────────────────────────────────────────────

int BST::countLeafNodes() {
    return countLeafNodesAUX(root);
}
int BST::countLeafNodesAUX(Node *n) {
    if (n == nullptr) return 0;
    // a leaf has no children
    if (n->left == nullptr && n->right == nullptr) return 1;
    return countLeafNodesAUX(n->left) + countLeafNodesAUX(n->right);
}

// ─── height ─────────────────────────────────────────────────────────────────

int BST::height() {
    return heightAUX(root);
}
int BST::heightAUX(Node *n) {
    if (n == nullptr) return 0;
    int leftHeight  = heightAUX(n->left);
    int rightHeight = heightAUX(n->right);
    // height is 1 (this node) + the taller of the two subtrees
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// ─── size (alias for countNodes) ────────────────────────────────────────────

int BST::size() {
    return sizeAUX(root);
}
int BST::sizeAUX(Node *n) {
    if (n == nullptr) return 0;
    return 1 + sizeAUX(n->left) + sizeAUX(n->right);
}

// ─── countNodesAtLevel ──────────────────────────────────────────────────────

int BST::countNodesAtLevel(int level) {
    return countNodesAtLevelAUX(root, level);
}
// note: we add a second parameter to the AUX that the header doesn't show yet
// you may need to update the header to: int countNodesAtLevelAUX(Node *n, int level);
int BST::countNodesAtLevelAUX(Node *n, int level) {
    if (n == nullptr) return 0;
    // level 0 means we ARE at the target level — count this node
    if (level == 0) return 1;
    // otherwise go deeper, reducing level by 1 each time
    return countNodesAtLevelAUX(n->left,  level - 1)
         + countNodesAtLevelAUX(n->right, level - 1);
}

// ─── isAVL ──────────────────────────────────────────────────────────────────

// A tree is AVL if at every node, the height difference between
// left and right subtrees is at most 1
bool BST::isAVL() {
    return isAVLAUX(root);
}
bool BST::isAVLAUX(Node *n) {
    if (n == nullptr) return true;
    int leftH  = heightAUX(n->left);
    int rightH = heightAUX(n->right);
    int diff   = leftH - rightH;
    if (diff < -1 || diff > 1) return false; // unbalanced at this node
    // also check every subtree recursively
    return isAVLAUX(n->left) && isAVLAUX(n->right);
}

// ─── isFull ─────────────────────────────────────────────────────────────────

// A full BST means every node has either 0 or 2 children (never just 1)
bool BST::isFull() {
    return isFullAUX(root);
}
bool BST::isFullAUX(Node *n) {
    if (n == nullptr) return true;
    // leaf node is fine
    if (n->left == nullptr && n->right == nullptr) return true;
    // one child only — not full
    if (n->left == nullptr || n->right == nullptr) return false;
    return isFullAUX(n->left) && isFullAUX(n->right);
}

// ─── isComplete ─────────────────────────────────────────────────────────────

// A complete tree fills levels left-to-right with no gaps.
// Once we see a node that is missing a child, all following nodes must be leaves.
bool BST::isComplete() {
    if (root == nullptr) return true;

    // use a simple array-based queue to do level-order traversal
    Node *queue[1024];
    int front = 0, back = 0;
    queue[back++] = root;

    bool foundIncomplete = false; // have we seen a non-full node yet?

    while (front < back) {
        Node *curr = queue[front++];

        if (curr->left != nullptr) {
            if (foundIncomplete) return false; // node after a gap has a child
            queue[back++] = curr->left;
        } else {
            foundIncomplete = true; // missing left child = gap
        }

        if (curr->right != nullptr) {
            if (foundIncomplete) return false;
            queue[back++] = curr->right;
        } else {
            foundIncomplete = true;
        }
    }
    return true;
}

// ─── clearTree / destroyTree ────────────────────────────────────────────────

void BST::clearTree() {
    clearAUX(root);
    root = nullptr; // reset root after clearing
}
void BST::clearAUX(Node *n) {
    if (n == nullptr) return;
    clearAUX(n->left);   // delete left subtree first
    clearAUX(n->right);  // then right subtree
    delete n;            // then this node (post-order)
}

void BST::destroyTree() {
    clearTree(); // same thing — destroyTree just calls clearTree
}

// ─── deleteLeafNodes ────────────────────────────────────────────────────────

void BST::deleteLeafNodes() {
    // we pass root by reference so we can set it to nullptr if it's a leaf
    deleteLeafNodesAUX(root);
}
void BST::deleteLeafNodesAUX(Node *&n) {
    if (n == nullptr) return;
    // if this node is a leaf, delete it and set the pointer to nullptr
    if (n->left == nullptr && n->right == nullptr) {
        delete n;
        n = nullptr;
        return;
    }
    deleteLeafNodesAUX(n->left);
    deleteLeafNodesAUX(n->right);
}

// ─── deleteNodesWith1Child ──────────────────────────────────────────────────

void BST::deleteNodesWith1Child() {
    deleteNodesWith1ChildAUX(root);
}
void BST::deleteNodesWith1ChildAUX(Node *&n) {
    if (n == nullptr) return;
    // recurse first so we handle children before parent
    deleteNodesWith1ChildAUX(n->left);
    deleteNodesWith1ChildAUX(n->right);

    bool hasLeft  = n->left  != nullptr;
    bool hasRight = n->right != nullptr;

    // only one child — bypass this node
    if (hasLeft && !hasRight) {
        Node *temp = n;
        n = n->left;  // parent now points to our only child
        delete temp;
    } else if (!hasLeft && hasRight) {
        Node *temp = n;
        n = n->right;
        delete temp;
    }
    // 0 children (leaf) or 2 children — leave it alone
}

// ─── deleteNodesWith2Children ───────────────────────────────────────────────

void BST::deleteNodesWith2Children() {
    deleteNodesWith2ChildrenAUX(root);
}
void BST::deleteNodesWith2ChildrenAUX(Node *&n) {
    if (n == nullptr) return;
    // recurse into children first
    deleteNodesWith2ChildrenAUX(n->left);
    deleteNodesWith2ChildrenAUX(n->right);

    // if this node has both children, delete it
    if (n->left != nullptr && n->right != nullptr) {
        // to keep BST valid, replace with in-order predecessor
        // (largest value in the left subtree)
        Node *pred = n->left;
        while (pred->right != nullptr) pred = pred->right;
        n->value = pred->value; // copy predecessor's value up
        // now delete the predecessor from the left subtree
        deleteNodesWith2ChildrenAUX(n->left);
    }
}

// ─── isIdenticalTo ──────────────────────────────────────────────────────────

bool BST::isIdenticalTo(BST other) {
    return identicalAUX(root, other.root);
}
bool BST::identicalAUX(Node *a, Node *b) {
    if (a == nullptr && b == nullptr) return true;  // both empty — identical
    if (a == nullptr || b == nullptr) return false; // one empty, one not
    if (a->value != b->value) return false;         // different values
    // check both subtrees
    return identicalAUX(a->left,  b->left)
        && identicalAUX(a->right, b->right);
}

// ─── findMin ────────────────────────────────────────────────────────────────

// In a BST the minimum is always the leftmost node
int BST::findMin() {
    Node *curr = root;
    while (curr->left != nullptr)
        curr = curr->left; // keep going left until we can't
    return curr->value;
}

// ─── findMax ────────────────────────────────────────────────────────────────

// In a BST the maximum is always the rightmost node
int BST::findMax() {
    Node *curr = root;
    while (curr->right != nullptr)
        curr = curr->right; // keep going right until we can't
    return curr->value;
}

// ─── printLevelByLevel ──────────────────────────────────────────────────────

// Also called level-order or BFS traversal.
// We use a queue: enqueue root, then for each node we dequeue,
// print it and enqueue its children.
void BST::printLevelByLevel() {
    if (root == nullptr) return;

    Node *queue[1024];
    int front = 0, back = 0;

    queue[back++] = root; // start with root in queue

    while (front < back) {
        Node *curr = queue[front++]; // dequeue front node
        cout << curr->value << " ";  // print it

        // enqueue left child if it exists
        if (curr->left  != nullptr) queue[back++] = curr->left;
        // enqueue right child if it exists
        if (curr->right != nullptr) queue[back++] = curr->right;
    }
    cout << "\n";
}

// ─── countNodesWith1Child ───────────────────────────────────────────────────

int BST::countNodesWith1Child() {
    return countNodesWith1ChildAUX(root);
}
int BST::countNodesWith1ChildAUX(Node *n) {
    if (n == nullptr) return 0;
    bool hasLeft  = n->left  != nullptr;
    bool hasRight = n->right != nullptr;
    // XOR — true only when exactly one child exists
    int current = (hasLeft != hasRight) ? 1 : 0;
    return current
         + countNodesWith1ChildAUX(n->left)
         + countNodesWith1ChildAUX(n->right);
}

// ─── countNodesWith2Children ────────────────────────────────────────────────

int BST::countNodesWith2Children() {
    return countNodesWith2ChildrenAUX(root);
}
int BST::countNodesWith2ChildrenAUX(Node *n) {
    if (n == nullptr) return 0;
    // count this node if it has both children
    int current = (n->left != nullptr && n->right != nullptr) ? 1 : 0;
    return current
         + countNodesWith2ChildrenAUX(n->left)
         + countNodesWith2ChildrenAUX(n->right);
}

// ─── display (in-order print) ───────────────────────────────────────────────

void BST::display() {
    displayAUX(root);
    cout << "\n";
}
void BST::displayAUX(Node *n) {
    if (n == nullptr) return;
    displayAUX(n->left);
    cout << n->value << " ";
    displayAUX(n->right);
}
