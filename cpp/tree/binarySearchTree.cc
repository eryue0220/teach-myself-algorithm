#include <iostream>
#include <queue>
#include <cassert>

using namespace std;
/**
 * @file binarySearchTree.cc
 * @description 二分搜索树实现
 * @details 二分搜索树和堆实现的树结构不太一样，堆实现的是一个完全的二叉树，而
 * 二分搜索树并不是一个完全二叉树，因而在这里使用结构体来进行存储
 */
template<typename Key, typename Value>
class BST {
private:
  struct Node {
    Key key;
    Value value;
    Node * left;
    Node * right;

    Node( Key key, Value value ) {
      this->key = key;
      this->value = value;
      this->left = this->right = NULL;
    }

    Node( Node * node ) {
      this->key = node->key;
      this->value = node->value;
      this->left = node->left;
      this->right = node->right;
    }
  };

  Node * root;
  int length;

  // 以 Node 为根的二叉搜索树中插入节点 ( key, value )
  Node * insert( Node * node, Key key, Value value ) {
    if ( node == NULL ) {
      length++;
      return new Node( key, value );
    }

    if ( key == node->key ) node->value = value;
    else if ( key < node->key ) node->left = insert( node->left, key, value );
    else node->right = insert( node->right, key, value );

    return node;
  }

  bool contain( Node * node, Key key ) {
    if ( node == NULL ) return false;
    if ( key == node->key ) return true;
    else if ( key < node->key ) return contain( node->left, key );
    else return contain( node->right, key ); 
  }

  Value * search( Node * node, Key key ) {
    if ( node == NULL ) return NULL;
    if ( key == node->key ) return &( node->value );
    else if ( key < node->key ) return search( node->left, key );
    else return search( node-> right, key );
  }

  void preOrder( Node * node ) {
    if ( !node ) {
      cout << node->key << endl;
      preOrder( node->left );
      preOrder( node->right );
    }
  }

  void inOrder( Node * node ) {
    if ( node != NULL ) {
      inOrder( node->left );
      cout << node->key << endl;
      inOrder( node-> right );
    }
  }

  void postOrder( Node * node ) {
    if ( node != NULL ) {
      postOrder( node->left );
      postOrder( node->right );
      cout << node-> key << endl;
    }
  }

  void destroy( Node * node ) {
    if ( node != NULL ) {
      destroy( node->left );
      destroy( node->right );
      delete node;
      length --;
    }
  }

  Node * minimum( Node * node ) {
    if ( node->left == NULL ) return node;
    return minimum( node->left );
  }

  Node * maximum( Node * node ) {
    if ( node->right == NULL ) return node;
    return maximum( node->right );
  }

  Node * removeMin( Node * node ) {
    if ( node->left == NULL ) {
      Node * right = node->right;
      delete node;
      length --;

      return right;
    }

    node->left = removeMin( node->left );
    return node;
  }

  Node * removeMax( Node * node ) {
    if ( node->right == NULL ) {
      Node * left = node->left;
      delete node;
      length --;

      return left;
    }

    node->right = removeMx( node->right );
    return node;
  }

  Node * remove( Node * node, Key key ) {
    if ( node == NULL ) return NULL;
    if ( key < node->key ) {
      node->left = remove( node->left, key );
      return node;
    } else if ( node->key < key ) {
      node->right = remove( node->right, key );
      return node;
    } else {
      if ( node->left == NULL ) {
        Node * right = node->right;
        delete node;
        length --;

        return right;
      }

      Node * successor = new Node( minimum( node->right ) );
      length ++;

      successor->right = removeMin( node->right );
      successor->left = node->left;
      delete node;
      length --;

      return successor;
    }
  }

public:
  BST() {
    root = NULL;
    length = 0;
  }

  ~BST() {
    destroy( root );
  }

  int size() {
    return length;
  }

  bool isEmpty() {
    return length == 0;
  }

  void insert( Key key, Value value ) {
    root = insert( root, key, value );
  }

  bool contain( Key key ) {
    return contain( root, key );
  }

  Value * search( Key key ) {
    return search( root, key );
  }

  void postOrder() {
    postOrder( root );
  }

  void inOrder() {
    inOrder( root );
  }

  void preOrder() {
    preOrder( root );
  }

  void levelOrder() {
    queue<Node *> q;
    q.push( root );

    while( !q.empty() ) {
      Node * node = q.front();
      q.pop();
      cout << node->key << endl;
      if ( node->left != NULL ) q.push( node->left );
      if ( node->right != NULL ) q.push( node-> right );
    }
  }

  Key minimum() {
    assert( length != 0 );
    Node * minNode = minimum( root );
    return minNode->key;
  }

  Key maximum() {
    assert( length != 0 );
    Node * minNode = maximum( root );
    return minNode->key;
  }

  void removeMin() {
    if ( root ) root = removeMin( root );
  }

  void removeMax() {
    if ( root ) root = removeMax( root );
  }

  void remove( Key key ) {
    root = remove( root, key );
  }
};
