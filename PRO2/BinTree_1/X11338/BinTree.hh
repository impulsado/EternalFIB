#ifndef BINTREE_HH
#define BINTREE_HH

#include <cassert>
#include <memory>
using namespace std;

// A BinTree<T> implements binary trees with values of type T.
template <typename T> class BinTree {

    struct Node {
        T x;
        shared_ptr<Node> left;
        shared_ptr<Node> right;

        Node (const T& x, shared_ptr<Node> left, shared_ptr<Node> right)
        :   x(x), left(left), right(right)
        {   }

    };

    // A tree only holds a node pointer.
    shared_ptr<Node> p;

    // Constructs a tree from a node pointer.
    BinTree (shared_ptr<Node> p)
    :   p(p)
    {   }

    // Notes:
    //   - default operator=() is good.
    //   - default destructor is good. Θ(n) where n is the number of nodes in the tree.
    //   - std::swap() already works by default.

public:

    // Constructs an empty tree. Θ(1).
    BinTree ()
    :   p(nullptr)
    {   }

    // Constructs a tree with a value x and no subtrees. Θ(1).
    BinTree (const T& x) {
        p = make_shared<Node>(x, nullptr, nullptr);
    }

    // Constructs a tree with a value x and two subtrees left and right. Θ(1).
    BinTree (const T& x, const BinTree& left, const BinTree& right) {
        p = make_shared<Node>(x, left.p, right.p);
    }

    // Tells if this tree is empty. Θ(1).
    bool empty () const {
        return not p;
    }

    // Returns the left subtree of this tree (cannot be empty). Θ(1).
    BinTree left () const {
        assert(not empty());
        return BinTree(p->left);
    }

    // Returns the right subtree of this tree (cannot be empty). Θ(1).
    BinTree right () const {
        assert(not empty());
        return BinTree(p->right);
    }

    // Returns the value of this tree (cannot be empty). Θ(1).
    const T& value () const {
        assert(not empty());
        return p->x;
    }
};

#endif
