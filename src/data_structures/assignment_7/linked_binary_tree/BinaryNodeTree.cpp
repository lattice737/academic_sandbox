#include "BinaryNodeTree.h"

// Root pointer set to nullptr
template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPointer(nullptr) {}

// Root pointer set a passed item
template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem) : rootPointer(std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr)) {}

// Root pointer set to a passed node and copies of its subtrees
template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem,
                                         const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePointer,
                                         const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePointer)
    : rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, copyTree(leftTreePointer->rootPointer), copyTree(rightTreePointer->rootPointer))) {}

// Copy constructor: uses copyTree()
template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const std::shared_ptr<BinaryNodeTree<ItemType>>& tree) {
    rootPointer = copyTree(treePointer.rootPointer);
}

// Destructor: uses destroyTree()
template<class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree() {
    destroyTree(rootPointer);
}

// Recursively determines height of tallest subtree
template<class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePointer) const {
    if (subTreePointer == nullptr) return 0;
    return 1 + max(getHeightHelper(subTreePointer->getLeftChildPointer()), getHeightHelper(subTreePointer->getRightChildPointer()));
}

// TODO
template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePointer) const {
    return -1;
}

// Adder helper: adds nodes to keep tree balanced
template<class ItemType>
auto BinaryNodeTree<ItemType>::balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePointer, std::shared_ptr<BinaryNode<ItemType>> newNodePointer) {
    if (subTreePointer == nullptr)
        return newNodePointer;
    
    auto leftPointer = subTreePointer->getLeftChild();
    auto rightPointer = subTreePointer->getRightChild();

    // Add new node to left or right tree--the larger of the two
    // 1) Return a pointer to the revised subtree (with new node)
    // 2) Link revised subtree to the rest of the tree
    if (getHeightHelper(leftPointer) > getHeightHelper(rightPointer)) {
        rightPointer = balancedAdd(rightPointer, newNodePointer);
        subTreePointer->setRightChildPointer(rightPointer);
    } else {
        leftPointer = balancedAdd(leftPointer, newNodePointer);
        subTreePointer->setLeftChildPointer(leftPointer);
    }

    return subTreePointer;
}

// TODO
template<class ItemType>
auto BinaryNodeTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePointer, const ItemType target, bool& isSuccessful) {
    return -1;
}

// TODO
template<class ItemType>
auto BinaryNodeTree<ItemType>::moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePointer) {
    return -1;
}

// TODO
template<class ItemType>
auto BinaryNodeTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> treePointer, const ItemType& target, bool& isSuccessful) const {
    return -1;
}

// Copying helper: preorder traverses and adds each item to a new node
template<class ItemType>
auto BinaryNodeTree<ItemType>::copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPointer) const {
    std::shared_ptr<BinaryNode<ItemType>> newTreePointer;
    
    if (oldTreeRootPointer == nullptr) return newTreePointer; // passed tree is empty

    // Copy tree nodes during a preorder traversal
    newTreePointer = std::make_shared<BinaryNode<ItemType>>(oldTreeRootPointer->getItem(), nullptr, nullptr);
    newTreePointer->setLeftChildPointer(copyTree(oldTreeRootPointer->getLeftChildPointer()));
    newTreePointer->setRightChildPointer(copyTree(oldTreeRootPointer->getRightChildPointer()));
}

// Destroying helper
template<class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePointer) {
    if (subTreePointer == nullptr) return; // passed tree is empty
    destroyTree(subTreePointer->getLeftChildPointer());
    destroyTree(subTreePointer->getRightChildPointer());
    subTreePointer.reset(); // Decrement reference count to node
}

// Preorder traversal helper
template<class ItemType>
void BinaryNodeTree<ItemType>::preorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePointer) const {
    if (treePointer == nullptr) return;
    ItemType theItem = treePointer->getItem();
    visit(theItem);
    inorder(visit, treePointer->getLeftChildPointer());
    inorder(visit, treePointer->getRightChildPointer());
}

// Inorder traversal helper
template<class ItemType>
void BinaryNodeTree<ItemType>::inorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePointer) const {
    if (treePointer == nullptr) return;
    inorder(visit, treePointer->getLeftChildPointer());
    ItemType theItem = treePointer->getItem();
    visit(theItem);
    inorder(visit, treePointer->getRightChildPointer());
}


// Postorder traversal helper
template<class ItemType>
void BinaryNodeTree<ItemType>::postorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePointer) const {
    if (treePointer == nullptr) return;
    inorder(visit, treePointer->getLeftChildPointer());
    inorder(visit, treePointer->getRightChildPointer());
    ItemType theItem = treePointer->getItem();
    visit(theItem);
}

// ----------------------------------------------------
//   Public Methods
// ----------------------------------------------------

// TODO
template<class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const {
    return false;
}

template<class ItemType>
int BinaryNodeTree<ItemType>::getHeight() const {
    return getHeightHelper(rootPointer);
}

// TODO
template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const {
    return -1;
}

// TODO
template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const noexcept(false) {

}

// TODO
template<class ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType& newData) {
    return;
}

template<class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData) {
    auto newNodePointer = std::make_shared<BinaryNode<ItemType>>(newData);
    rootPointer = balancedAdd(rootPointer, newNodePointer);
    return true;
}

// TODO
template<class ItemType>
bool BinaryNodeTree<ItemType>::remove(const ItemType& data) {
    return false;
}

// TODO
template<class ItemType>
void BinaryNodeTree<ItemType>::clear() {
    return;
}

// TODO
template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const ItemType& anEntry) const noexcept(false) {

}

// TODO
template<class ItemType>
bool BinaryNodeTree<ItemType>::contains(const ItemType& anEntry) const {
    return false;
}

template<class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&)) const {
    preorder(visit, rootPointer);
}

template<class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&)) const {
    inorder(visit, rootPointer);
}

template<class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&)) const {
    postorder(visit, rootPointer);
}