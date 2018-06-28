//
// Created by Matt on 6/13/18.
//

///// June 13th - Stacks, Queues, Recursion, Complexity Analysis /////

//<editor-fold desc="June 13" >

/*
 * Recursion notes:
 *  Recursion essentially uses a stack...
 *  - to convert a recursive function to a non-recursive fxn... use a stack
 */



class stack {
public:
    void    push   (int aData) {mLL.addFront(aData);}
    void    pop    () {if (!isEmpty) mLL.removeFront();}
    int     top    () {return mLL.front();}

    bool    isEmpty() {return mLL.isEmpty();}

private:
    // Linked list better than array because similar feature ease,
    // but no copy overhead on expansion...
    SLL mLL; //singly linked list - my linked list
};

/*
 * Queue is FIFO - First in First out
 * 3 Main operations:
 *  1. Enqueue
 *  2. Dequeue
 *  3. Front
 *
 *  Priority Queue (used in heap data structure)
 *  Benefit of queue - first come first serve...
 *  Priority Queue can prioritize...
 */
class queue {
public:
   void     enqueue (int aData) {mLL.addToBack(aData);} //mLL should have tail
    int     dequeue ()          {
        if(!isEmpty) {
            temp = this->front();
            mLL.removeFront;}
            return temp;
        }
    void    front   ()          {return mLL.front();}
    bool    isEmpty ()          {return mLL.isEmpty();}
private:
    SLL mLL;

};


/*
 * Recursive Sorting
 */

// Selection Sort (min sort)
sort(List, n) {
    Base:   (n==1) {sorted = list};

    Recursive:
            c = min(List);
            l2 = sort(l, n-1);
            sorted = append(c);
};


// Merge Sort
sort2(L) {
//Base:
(n==1) {SL = L;}
//Recursive:
(n > 1) //Implied
/*
 * 1. split L into two non-empty sets L1 and L2.
 *    can split by any strategy...
 * 2. Sort L1...
 *    Sort L2...
 * 3. Merge L1 and L2...
 */
};

// Quick Sort
sort3(L) {
        n = size(L);
        // Base:
        if (n==1) {SL = L;}

        // Recursion
        /// 2*n complexity
        x = Select(L);
        L1 = split<x (L);
        L2 = split>x (L);
        ///

        /// 2* T(n/2)
        L1- = sort3 (L1);
        L2- = sort3 (L2);
        ///

        /// Theta(1)
        SL = concat (L1-,x,L2-)
};
/// Complexity Analysis:
/*
 * T(1) = Theta(1)
 *
 * T(n) = 2 * T(2/n) + Theta(n)
 *      = 2 * ( 2* T(n/(2^2)) + Theta(n) ) + Theta(n)
 *      = 2^2 * T(n/(2^k)) + Theta(k*n)
 *      = 2^2 *( 2 * T(n/(n^3)) + Theta(n) ) + Theta(2*n) + Theta(n)
 *      ...
 *      = 2^k * T(n/(2^k)) + (2^k + 2^(k-1) + 2^(k-2)... + 1) * Theta(n)
 *      = 2^k * T(n/(n^k)) + (2^k - 1) * Theta(n)
 *      = n * T(1) + Theta(n^2)
 *      = Theta(n^2)
 */

// Recursive LL reverse
reverseLL() {
    first = mHead;
    rest = first->next;
    // Base:
    (rest == nullptr) {ret;}
    // Recursion:
    mHead = rest;
    reverseLL();
    rest->next = first; // Recomposition step
    first->next == nullprt;
}
//</editor-fold>

///// June 20th - Complexity Analysis File I/O, Templates /////

//<editor-fold desc="June 20">
/// Table of Big-oh sets
/*
 * Function:        Common Name:
 * O(1)             Constant
 * O(log n)         Logarithmic
 * O(log^2 n)       log-squared
 * O(n^(1/2))       root-n
 * O(n)             Linear
 * O(n * log n)     n-lg-n
 *
 * ^^^ Efficient Algorithms ^^^
 *
 * Useless for large n:
 * O(n^2)           Quadratic
 * O(2^n)           Exponential
 */

/// Examples of Complexity Analysis: ///

int A[] = {0 , 2, 5, 8 , 32, 76, 100}; // Sorted Array

// Linear Complexity Search - can write complexity is THETA(n)
// If checking takes 5 (arbitrary #)... then T(n) = 5n + 1
//                     5 from every check... 1 from final return
int search (A, s) {
    for (int i = 0; i < A.length(); ++i) {
        if (s == A[i])
            return i;
    }
    return -1;
}


// (log n) - Complexity Search...
int BinSearch (A, low, high, s) {
    /// Theta(1)
    if (high < low)
        return -1;
    // Mid point
    m = (low + high) / 2;
    ///
    /// Theta(1)
    if (s == A[m])
        return m;
    ///
    /// T(n/2)
    else if (s < A[m])
        return search(A, low, m, s);
    ///
    /// T(n/2)
    else
        return search(A, m + 1, high, s);
    ///
}


// Complexity Analysis:
/*
 * T(n) = T(n/2) + Theta(1); T(n/2) = T(n/(2^2)) + Theta(1)
 * Substitute:
 * T(n) = (T(n/(2^2)) + Theta(1)) + Theta(1)
 * ...
 * T(n) = (T(n/(2^k)) + Theta(k)
 *
 * On termination, T(1) = Theta(1)
 * n/(2^k) = 1, when k = log n... so,
 * T(n/(2^k)) = 1, when k = log n
 * -> T(n) = Theta(1) + Theta(log n) = Theta(log n)
 */

/// See Complexity analysis on sorting above.... (June 13th notes)

/// File I/O

using namespace std;

// file stream...
#inlcude <fstream>

// Write:
ofsteam of("filename");
if (!of) { // of.operator! ()
    cerr << "could not write" << endl;
}
else {
// Write whatever you want...
of << "This will be written to of...";
}

// Read:
ifsteam ifs("filename");
if (!ifs) {
    // error
}
else {
    string s;
    while (true) {
        getLine(ifs, s);
        if (ifs.eof()) {
            break;
        }
    }
    // Do useful things with s....
}

// sstream (allows reading/writing of strings as stream...)
ostringstream os;
// Val is converted to string
os << val;
// get string from os:
os.str();


//// Templates ////

/// Function Template:
/*
 * Represents a family of functions...
 *  - specifies a pattern from which actual fxns can be generated
 * ->>> A Template is NOT a fxn
 */

// In Header File...
template < typename T >
// Function with return value T...
T max (const T &a1, const T &a2) {
    // Take Advantage of Overloaded "<" operator
    if (a1 > a2)
        return a1;
    else
        return a2;
}

// To use:
int main()
{
    max <int> (2,3); // works for an int
    max <float> (2.3, 5.6) // works for a float
}

/// Class Template:
/*
 * Represents a family of classes
 *  - specifies a patten from which actual classes can be generated
 */

template < typename T, T2 >
class A
{
    void foo();
private:
    T mData;
    T2 data2;
};

// To use:
int main ()
{
    A <int> a; // a is an A w/ mData of type int...
    A <B>   b; // b is an A w/ mData of type B (some other object...)
}

// To define foo() elsewhere...
template <typename T>
void A <T, T2> :: foo() {}
//</editor-fold>

///// June 27th - Trees /////

//<editor-fold desc="June 27">

/// Definitions ///
/*
 * Tree:
 *      a set of nodes and edges that connect the nodes
 *      **Exactly one path between any two nodes**
 * Path:
 *      connected sequence of edges
 * Rooted Tree:
 *      One distinguished node is a root
 *         - Every node, c, - except the root - has one parent, p,
 *          which is the first node on the path from c too the root
 *         - c is p's child
 *         - A node can have any number of children
 * Root:
 *      (front node) - origin of all branches
 * Leaf:
 *      Node with no children (end node of a branch...)
 * Siblings:
 *      Nodes with the same parent
 * Ancestors:
 *      Ancestors of a node, d, are the nodes on the path from d to the root
 *      *INCLUDING both d and the root*
 *      - If a is an ancestor of d, then d is a descendent of a
 * Length of a path:
 *      Number of edges on the path
 * Depth of a node, n:
 *      Length of path from n to the root
 * Height of a node, n:
 *      Length of path from n to the deepest leaf (descendent)
 * Height of tree = height of the root
 * Subtree, rooted at n:
 *      Tree formed by n and its descendents
 *
 *
 * Binary Tree:
 *      Tree where no node has >2 children
 *      - every node (child) is either a left or right child
 *      (even if it is the only child...)
 *
 *
 * :::Implementations:::
 *
 * 1. Each node has:
 * - data
 * - a list of children
 * - parent pointer
 *
 * 2. Each node has:
 * - data
 * - parent pointer
 * - siblings are directly linked
 *
 */

/*
 * Implementation #2
 */
class SibTreeNode {
private:

    int mData;
    SibTreeNode* mParent;
    SibTreeNode* mFirstChild;
    SibTreeNode* mNextSibling;
};

/*
 * Binary Tree Implementation
 */
class BinaryTreeNode {
public:
    BinaryTreeNode* left();
    BinaryTreeNode* right();
    void preOrder();
    void postOrder();
    void inOrder();
    void levelOrderTraverse();
private:
    int mData;
    BinaryTreeNode* mLeft;
    BinaryTreeNode* mRight;
    // Optional - problem dependent
    BinaryTreeNode* mParent;
};

/// Tree Traversals ///

// Def: a manner of visiting every node in a tree once

/*
 * 4 Types of Traversals: *All traversals are Ø(n)
 *
 *  Depth First: Recursion (or stack) is very nice here...
 *      Pre-order:
 *          Root (action here) - left - right
 *      Post-order:
 *          Left - right - root (action on root...)
 *      In-order:
 *          Left - root (action here) - right
 *  Breadth First: Use a queue...
 *      Level-order:
 *          print each level of siblings, in order from left to right
 *
 */

class BinaryTree {
public:
    void preOrder();
    void postOrder();
    void inOrder();

public:
    BinaryTreeNode* mRoot;
};

void BinaryTree::preOrder() {
    if (mRoot)
        mRoot->preOrder();
}

void BinaryTreeNode::preOrder() {
    // Do something with this

    // Access the child nodes...
    if (left())
        left()->preOrder();
    if (right())
        right()->preOrder();
}

void BinaryTree::postOrder() {
    if (mRoot)
        mRoot->postOrder();
}

void BinaryTreeNode::postOrder() {
    if (left())
        left()->postOrder();
    if (right())
        right()->postOrder();

    // Do something with this
}

void BinaryTree::inOrder() {
    if(mRoot) {
        mRoot->inOrder();
        // Do something with this
    }
}

/*
 * Generally, add root to queue, add children to queue...
 * when out of children, pop front of queue
 */
void BinaryTreeNode::levelOrderTraverse() {
    queue q;
    q.enqueue(this->mData);

    while (!q.isEmpty()) {
        node  = q.dequeue();
        // Act on node
        if (node->left())
            q.enqueue(node -> left());
        if (node->right())
            q.enqueue(node -> right());
    }

}

/// Tree types ///

/*
 * Binary Search Tree:
 *  Invariant:
 *      Keys in left subtrees are always <= root.data
 *      Keys in right subtrees are always > root.data
 *  ***Complexity of searching is the height of the tree (n)***
 *  ***Complexity of finding specific key... is (log n)***
 *
 *  • inOrder traversal of BST visits nodes in sorted order
 *
 *
 *  Running time:
 *      Completely (Balanced) tree - or subtree - with depth, d:
 *          • # of nodes, n = 2^(d+1) - 1
 *          • No node has depth > log2 n
 *          • All operations in the BST have Ø(n) in worst case running time
 *
 * BST Types:
 *  • AVL
 *  • 2-3-4
 *  • Red-Black
 *  • Splay **** Using this in Comp15 ****
 */

class BSTNode : public BinaryTreeNode
{
public:
    BSTNode* find();
    BSTNode* inExactFind();

private:
    T mKey;
};


// Operations:

BSTNode* BSTNode::find (Object k)
{
    // Need stipulation for not finding the key...


    if (k < mKey)
        return left()->find(k);
    if (k > mKey)
        return right()->find(k);
    // if k == mKey
    return this;
}

/*
 * Inexact match is hallmark of BST
 *  - find the smallest key >= k or largest key <=k
 *
 * When searching the tree for a key, k, that is NOT in the tree,
 * we encounter both the node with the largest key <= k (if any)
 * and the node with the smallest key >= k (if any)
 *
 * While searching... track:
 *  last time went right (lower bound)
 *  last time went left  (upper bound)
 */

BSTNode* BSTNode::inExactFind() {}

/*
 * Insert (key, value):
 *      Follow the same path through the tree as find()
 *      When nullptr is reached, replace nullptr with the new node...
 *
 * Always inserts as "high" on the tree as possible (I think...)
 */

/*
 * Delete (object k)
 *
 *      Find a node n with key k
 *      Return nullptr if k is not in the BST.
 *
 *      Cases:
 *          • If n has no children, detach n from the its parent
 *          • If n has 1 child, move n's child up to take n's place
 *          • If n has 2 children,
 *              let x be a node in n's right subtree with the smallest key:
 *                  1. remove x
 *                  2. replace n's key with x's key
 */


/// Dictionaries... ///

/*
 * Ordered Dict:
 *      dictionary in which keys have a total order
 *      Binary Search Tree is efficient For:
 *      • Insert, find, remove entries
 *      • Quickly find the min/max key
 *      • Get entry nearest to another entry (inexact matches)
 *          (ex: cannot remember exact spelling of key)
 */
//</editor-fold>

//// **** Material Above Here on Midterm Exam - content before splay trees **** ////

//<editor-fold desc="Aside - Towers of Hanoi">

toh (n, a, b, c);
/*
 * Base:
 *      n == 0
 *          do nothing
 *      n == 1
 *          shift A to C
 * Recursive...
 *      toh(n-1, a,c,b); // shift from A to B cia C
 *          shift the nth disc from A to C
 *      toh(n-1, B, A, C) // shift from B to C via A
 */

//</editor-fold>
