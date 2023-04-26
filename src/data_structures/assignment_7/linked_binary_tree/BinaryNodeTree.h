/** ADT binary tree: Link-based implementation.
 @file BinaryNodeTree.h */

#ifndef BINARY_NODE_TREE_
#define BINARY_NODE_TREE_

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "PrecondViolatedExcept.h"
#include "NotFoundException.h"
#include <memory>

template<class ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType> {
    private:
        std::shared_ptr<BinaryNode<ItemType>> rootPointer;
    protected:
        // ----------------------------------------------------
        //   Protected Utility Methods Section
        //   Recursive helper methods for the public methods.
        // ----------------------------------------------------
        int getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePointer) const;
        int getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePointer) const;
        auto balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePointer, std::shared_ptr<BinaryNode<ItemType>> newNodePointer);
        virtual auto removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePointer, const ItemType target, bool& isSuccessful);
        auto moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePointer);
        virtual auto findNode(std::shared_ptr<BinaryNode<ItemType>> treePointer, const ItemType& target, bool& isSuccessful) const;
        auto copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPointer) const;
        void destroyTree(const std::shared_ptr<BinaryNode<ItemType>> subTreePointer);
        void preorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePointer) const;
        void inorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePointer) const;
        void postorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePointer) const;
    public:
        // ----------------------------------------------------
        //   Constructors & Destructors
        // ----------------------------------------------------
        BinaryNodeTree();
        BinaryNodeTree(const ItemType& rootItem);
        BinaryNodeTree(const ItemType& rootItem,
                       const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePointer,
                       const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePointer);
        BinaryNodeTree(const std::shared_ptr<BinaryNodeTree<ItemType>>& tree);
        virtual ~BinaryNodeTree();
        // ----------------------------------------------------
        //   Public BinaryTreeInterface Methods
        // ----------------------------------------------------
        bool isEmpty() const;
        int getHeight() const;
        int getNumberOfNodes() const;
        ItemType getRootData() const noexcept(false);
        void setRootData(const ItemType& newData);
        bool add(const ItemType& newData);
        bool remove(const ItemType& data);
        void clear();
        ItemType getEntry(const ItemType& anEntry) const noexcept(false);
        bool contains(const ItemType& anEntry) const;
        // ----------------------------------------------------
        //   Public Traversals
        // ----------------------------------------------------
        void preorderTraverse(void visit(ItemType&)) const;
        void inorderTraverse(void visit(ItemType&)) const;
        void postorderTraverse(void visit(ItemType&)) const;
        // ----------------------------------------------------
        //   Overloaded Operator
        // ----------------------------------------------------
        BinaryNodeTree& operator=(const BinaryNodeTree& rightHandSide);
};

#include "BinaryNodeTree.cpp"
#endif