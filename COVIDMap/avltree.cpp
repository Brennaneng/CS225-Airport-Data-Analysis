/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    // your code here
    Node *y = t->right;
    t->right =   y->left;
    y->left = t;
    t->height = std::max(heightOrNeg1(t->left),heightOrNeg1(t->right));
    t = y;
    t->height = std::max(heightOrNeg1(t->left),heightOrNeg1(t->right));

}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    // your code here
    Node *y = t->left;
    t->left =   y->right;
    y->right = t;
    t->height = std::max(heightOrNeg1(t->left),heightOrNeg1(t->right)) + 1;
    t = y;
    t->height = std::max(heightOrNeg1(t->left),heightOrNeg1(t->right)) + 1;

}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here
    if(subtree == NULL)
        return;
    int heightLeft = heightOrNeg1(subtree->left);
    int heightRight = heightOrNeg1(subtree->right);
    int balance = heightRight - heightLeft;

    if(balance == -2){
        int heightLeftRight = heightOrNeg1(subtree->left->right);
        int heightLeftLeft = heightOrNeg1(subtree->left->left);
        int l_balance = heightLeftRight - heightLeftLeft;

        if(l_balance == -1) 
            rotateRight(subtree);
        else            
            rotateLeftRight(subtree);
    }
    else if(balance == 2){
        int heightRightRight = heightOrNeg1(subtree->right->right);
        int heightRightLeft = heightOrNeg1(subtree->right->left);
        int r_balance = heightRightRight - heightRightLeft;

        if(r_balance == 1)
            rotateLeft(subtree);
        else    
            rotateRightLeft(subtree);
    }
    subtree->height = std::max(heightOrNeg1(subtree->left),heightOrNeg1(subtree->right)) + 1;
}

template <class K, class V>
void AVLTree<K, V>::insert(const K& key, const V& value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
    if(subtree == NULL){
        subtree = new Node(key,value);
        return;
    }
    else if(key < subtree->key)
        insert(subtree->left, key, value);
    else if(key > subtree->key)
        insert(subtree->right, key, value);
    rebalance(subtree);
}

template<class K, class V>
void AVLTree<K, V>::replace(const K& key, const V& value){
    Node* currNode = findNode(root, key);
    if(currNode == NULL)
        return;
    currNode->replaceValue(value);
    return;

}
template<class K, class V>
typename AVLTree<K, V>::Node* AVLTree<K, V>::findNode(Node* subtree, const K& key){
    if (subtree == NULL)
        return NULL;
    else if (key == subtree->key)
        return subtree;
    else {
        if (key < subtree->key)
            return findNode(subtree->left, key);
        else
            return findNode(subtree->right, key);
    }
}


template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{

    if (subtree == NULL)
        return;

    if (key < subtree->key) {
        // your code here
        remove(subtree->left, key);
    } else if (key > subtree->key) {
        // your code here
        remove(subtree->right,key);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
            delete subtree;
            subtree = NULL;
        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here
            Node * temp = subtree->left;
            while(temp->right != NULL)
                temp = temp->right;
            swap(subtree,temp);
            remove(subtree->left, key);
        } else {
            /* one-child remove */
            // your code here
            
            if(subtree->left != NULL){
            Node * temp = subtree->left;
            while(temp->right != NULL)
                temp = temp->right;
            swap(temp,subtree);
            remove(subtree->left, key);    
            }
            else{
            Node * temp = subtree->right;
            while(temp->left != NULL)
                temp = temp->left;
            swap(temp,subtree);
            remove(subtree->right, key);
            }
            
            } 
        }
        // your code here
        rebalance(subtree);

    }


