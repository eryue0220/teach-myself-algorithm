class Node {
  constructor(key, value) {
    this.key = key;
    this.value = value;
    this.left = this.rigth = null;
  }

  cloneNode(node) {
    return { ...node };    
  }
}

function preOrder(node) {
  if (node != null) {
    console.log(node.key, node.value);
    preOrder(node.left);
    preOrder(node.right);
  }
}

function inOrder(node) {
  if (node != null) {
    inOrder(node.left);
    console.log(node.key, node.value);
    inOrder(node.right);
  }
}

function postOrder(node) {
  if (node != null) {
    postOrder(node.left);
    postOrder(node.right);
    console.log(node.key, node.value);
  }
}

class BST {
  constructor(key, value) {
    this.root = new Node(key, value);
    this.length = 0;
  }

  isEmpty() {
    return this.length == 0;
  }

  size() {
    return this.length;
  }

  preOrder() {
    preOrder(this.root);
  }

  inOrder() {
    inOrder(this.root);
  }

  postOrder() {
    postOrder(this.root);
  }
}

module.exports = BST;
