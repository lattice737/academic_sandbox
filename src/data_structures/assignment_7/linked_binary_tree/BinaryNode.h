/** A class of nodes for a link-based binary tree. 
 @file BinaryNode.h */

#ifndef BINARY_NODE_
#define BINARY_NODE_

#include <memory>

template<class ItemType>
class BinaryNode {
    private:
        ItemType item;
        std::shared_ptr<BinaryNode<ItemType>> leftChildPointer;
        std::shared_ptr<BinaryNode<ItemType>> rightChildPointer;
    public:
        BinaryNode();
        BinaryNode(const ItemType& anItem);
        BinaryNode(const ItemType& anItem, std::shared_ptr<BinaryNode<ItemType>> leftPointer, std::shared_ptr<BinaryNode<ItemType>> rightPointer);
        void setItem(const ItemType& anItem);
        ItemType getItem() const;
        bool isLeaf() const;
        auto getLeftChildPointer() const;
        auto getRightChildPointer() const;
        void setLeftChild(std::shared_ptr<BinaryNode<ItemType>> leftPointer);
        void setRightChild(std::shared_ptr<BinaryNode<ItemType>> rightPointer);
};

#include "BinaryNode.cpp"
#endif