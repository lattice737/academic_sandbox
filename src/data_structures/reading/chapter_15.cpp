using namespace std;

/*
Vocabulary
==========
* Tree - An abstract hierarchical structure made up of connected nodes
* Vertex - a node in a tree
* Edge - a line between nodes in a tree
* Hierarchical tree - a tree characterized by parent-child node relationships
* Parent (or ancestor) - a tree node that has an edge to a lower node
* Child (or descendant) - a tree node that is beneath a parent node
* Sibling - a tree node that is a child of another node's parent
* First (or oldest) child - the leftmost child of a parent node in a tree
* Root - the node of a tree that has no parent
* Leaf - a tree node with no children
* Subtree - a tree rooted at some node of a larger tree
* General tree - a set T of one or more nodes such that T is partitioned into two disjoint subsets: root node r and subtrees of r
* n-ary tree - a set T of nodes that is either empty or partitioned into two disjoint subsets: root node r and n-ary subtrees (that
  may be empty); each node may have up to n children
* Binary tree - an n-ary tree with n=2, it is a set T of nodes that is either empty or partitioned into disjoint subsets: root node
  r and left & right subtrees of r (which are binary trees and may be empty)
* Binary search tree - a binary tree that is sorted according to its nodes' values
* Path-defined tree height - the number of nodes on the longest path from the root to a leaf
* Path - a trace of edges from one node to another
* Level-defined tree height - the maximum level of a tree's nodes, where an empty tree has height zero
* Node level - a node characteristic for defining tree height; if n is the root, it is at level 1, otherwise the level is 1 more
  than the level of its parent
* Full binary tree - a binary tree of height h where all nodes at a level less than h have two children each; full binary trees
  have as many leaves as possible, all at level h
* Complete binary tree - a binary tree of heigh h that is full down to level h-1, with level h filled from left to right
* Balanced (or height-balanced) binary tree - a binary tree where the height of any node's right subtree differs from the height
  of the node's left subtree by no more than 1
* Preorder traversal - visiting of a root node before traversing both its left & right subtrees
* inorder traversal - visiting of a root node after traversing its left subtree but before traversing its right subtree
* Preorder traversal - visiting of a root node after traversing both its left & right subtrees
* Free list - a collection of available nodes, referenced when items are added to or removed from a general ADT tree
* 

General
=======
~ The root of any tree is an ancestor of every node in the tree
~ Trees represent information that is hierarchical
~ An n-ary tree is not a special kind of general tree, because an n-ary tree can be empty, whereas a general tree cannot
~ T is a binary tree if T has no nodes or T has a node r with two children TL and TR that are also binary trees
~ Binary tree properties:
  1) n's value is greater than all values in its left subtree
  2) n's value is less than all values in its right subtree
  3) The left and right subtrees are binary search trees
~ Proving binary tree fullness:
  a) If T is empty, T is a full binary tree of height 0
  b) If T is not empty and has height h>0, T is a full binary tree if its root's subtrees are both full binary trees of height
     h-1
~ Proving binary tree completeness:
  1) All nodes at level h-2 and above have two children each
  2) When a  node at level h-1 has children, all nodes to its left at the same level have two children each
  3) When a node at level h-1 has one child, it is a left child
~ A binary tree's height can be maximized by adding exactly one child to each internal (noneleaf) node; the maximum height of an
  n-node binary tree is n
~ A binary tree's height for n nodes can be minimized by making the tree complete; the minimum height of an n-node binary tree
  is [log2(n+1)] (the ceiling of the logarithm)
~ For a given level h, there are 2^(h-1) nodes at that level and 2^h-1 total nodes at the level and all previous levels
~ Proving the minimum height of a binary tree:
  1) A binary tree whose height is less than or equal to h-1 has fewer than n nodes where h is not the smallest integer such
     that n<=2^h-1 if it's possible that n<=2^(h-1)-1, therefore 2^(h-1)-1<n
  2) For an n-node complete binary tree whose height h exists, there will be n nodes by the time level h is filled up because
     n>2^(h-1)-1 and a binary tree cannot have more than 2^h-1 nodes where n<=2^h-1
  3) The minimum height of a binary tree with n nodes and height<=h-1 is the smallest integer h such that n<=2^h-1, where h must
     be as small as possible such that n<=2^h-1 (rule 2)
~ Formal proof for the minimum height of a binary tree:
  1) 2^(h-1)-1 < n <= 2^h-1
  2) 2^(h01) < n+1 <= 2^h
  3) h-1 < log2(n+1) <= h
  * Therefore, h = [log2(n+1)]
~ Complete and full trees with n nodes have heights of [log2(n+1)] (theoretical minimum)
~ Indendent node operations are O(1), and traversal is O(n)
~ Postorder traversal maps to postfix expression evaluation
~ C++ allows for passing functions as arguments--omit parentheses
~ The bianry tree is ill suited for searching, since it may require visiting every node to discover a target entry; however,
  the binary search tree is a tree that corrects this deficiency by organizing its data by value
~ The shape of a binary search tree does not affect accuracy but does affect operation efficiency: the more balacned a
  binary search tree is, the farther it is from a linear structure and the closer the behavior of the search will be to a
  binary search of an array (in contrast to a linear search)
~ For a tree with unique entries, using a search to determine where to place a new entry in the tree is always easy, because
  the search will always terminate at an empty subtree--the proper place of the new entry
~ The inorder traversal of a binary search tree visits the tree's nodes in sorted order
~ Proof that inorder traversal = sorted order visitation by induction:
  1) For h=0 (empty T), no nodes are visited where a null tree is considered sorted
  2) Inductive hypothesis: For each level k where 0<k<h, inorder traversal visits nodes in sorted order
  * Therefore, for k=h (h>0), all nodes will be visited from left subtree to right subtree, where all subtrees have height<h
~ The maximum number of comparisons that each BST operation (i.e. retrieval, addition, or removal) can require is equal to the
  number of nodes on the longest path through the tree--therefore, the height of the tree
~ For BST with heigh log2(n+1), operation efficiency is O(log[n])
~ The determining factor for BST height is the order in which entries are added and removed, where entries added in sorted
  order produce a maximum-height BST and entries added to fill their children first produce a minimum-height BST
~ It can be proven mathematically that if additions and removals occur randomly (average-case analysis), the height of the BST
  will be close to log2(n); however, although it is reasonable to expect these operations randomly, it's important to be aware
  of the cause and possibility of poor performance due to some application characteristic or client use-case
~ Time requirement for BST operations:
     Operation  Average-case Worst-case
  1) Retrieval  O(logn)      O(n)
  2) Addition   O(logn)      O(n)
  3) Removal    O(logn)      O(n)
  4) Traversal  O(n)         O(n)
~ An array-based binary tree implementation uses arrays for both the tree and its free list; this solution is more attractive
  when the tree is complete, because the indices that link parents and their children are not stored, so the data structure is
  simpler--however, the tree must remain complete after additions & removals
~ 
*/

int preorderTraverse(BinaryTree);
int inorderTraverse(BinaryTree);
int postorderTraverse(BinaryTree);
int search(BinarySearchTree, int);

int main() {
    return 0;
}

int preorderTraverse(BinaryTree tree) {
    if (!tree.isEmpty()) {
        // visit root
        preorderTraverse(tree.leftSubtree());
        preorderTraverse(tree.rightSubtree());
    }
    return -1;
}

int inorderTraverse(BinaryTree tree) {
    if (!tree.isEmpty()) {
        inorderTraverse(tree.leftSubtree());
        // visit root
        inorderTraverse(tree.rightSubtree());
    }
    return -1;
}

int postorderTraverse(BinaryTree tree) {
    if (!tree.isEmpty()) {
        postorderTraverse(tree.leftSubtree());
        postorderTraverse(tree.rightSubtree());
        // visit root
    }
    return -1;
}

int search(BinarySearchTree tree, int target) {
    if (tree.isEmpty())
        return -1;
    else if (target == tree.getRootData())
        return 0;
    else if (target < tree.getRootData())
        search(tree.leftSubtree(), target);
    else
        search(tree.rightSubtree(), target);
}
