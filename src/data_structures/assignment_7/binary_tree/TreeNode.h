template<class ItemType>
class TreeNode {
    private:
        ItemType item;
        int leftChild;
        int rightChild;
    public:
        TreeNode();
        TreeNode(const ItemType& nodeItem, int left, int right);
        bool setItem(const ItemType& newItem);
        ItemType getItem() const;
        bool setLeft(const ItemType& newItem);
        ItemType getLeft() const;
        bool setRight(const ItemType& newItem);
        ItemType getRight() const;
};