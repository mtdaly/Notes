//
// Created by Matt on 6/13/18.
//

///// June 13th - Stacks, Queues, Recursion, Complexity Analysis /////

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
    void    dequeue ()          {if(!isEmpty) mLL.removeFront;}
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

///// June 20th - Complexity Analysis File I/O, Templates /////

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


