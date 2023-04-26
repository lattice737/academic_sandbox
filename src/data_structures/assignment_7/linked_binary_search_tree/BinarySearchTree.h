/** Link-based implementation of the ADT binary search tree.
 @file BinarySearchTree.h */

#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "BinaryNodeTree.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcept.h"
#include <memory>

template<class ItemType>
class BinarySearchTree : public BinaryNodeTree<ItemType> {
    private:
        std::shared_ptr<BinaryNode<ItemType>> rootPointer;
    protected:
        // ----------------------------------------------------
        //   Protected Helper Methods
        // ----------------------------------------------------
        auto placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePointer, std::shared_ptr<BinaryNode<ItemType>> newNode);
        auto removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePointer, const ItemType target, bool& isSuccessful) override;
        auto removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePointer);
        auto removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>> subTreePointer, ItemType& inorderSuccessor);
        auto findNode(std::shared_ptr<BinaryNode<ItemType>> treePointer, const ItemType& target) const;
    public:
        // ----------------------------------------------------
        //   Constructors & Destructor
        // ----------------------------------------------------
        BinarySearchTree();
        BinarySearchTree(const ItemType& rootItem);
        BinarySearchTree(const BinarySearchTree<ItemType>& tree);
        virtual ~BinarySearchTree();
        // ----------------------------------------------------
        //   Public Methods
        // ----------------------------------------------------
        bool isEmpty() const;
        int getHeight() const;
        int getNumberOfNodes() const;
        ItemType getRootData() const noexcept(false);
        void setRootData(const ItemType& newData);
        bool add(const ItemType& newEntry);
        bool remove(const ItemType& target);
        void clear();
        ItemType getEntry(const ItemType& anEntry) const noexcept(false);
        bool contains(const ItemType& anEntry) const;
        // ----------------------------------------------------
        //   Public Traversal Methods
        // ----------------------------------------------------
        void preorderTraverse(void visit(ItemType&)) const;
        void inorderTraverse(void visit(ItemType&)) const;
        void postorderTraverse(void visit(ItemType&)) const;
        // ----------------------------------------------------
        //   Overloaded Operator
        // ----------------------------------------------------
        BinarySearchTree<ItemType>& operator=(const BinarySearchTree<ItemType>& rightHandSide);
};

#include "BinarySearchTree.cpp"
#endif