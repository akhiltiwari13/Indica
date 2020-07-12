#include <iostream>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::ws;

/* class representing the node of the binary search tree */
template <class T> class BstNode {
public:
  T data;
  BstNode<T> *leftChild;
  BstNode<T> *rightChild;
  BstNode(T data = 0, BstNode<T> *leftChild = nullptr,
          BstNode<T> *rightChild = nullptr)
      : data(data), leftChild(leftChild), rightChild(rightChild) {}
  bool operator<(const BstNode &node) { return node.data < this->data; }
};

/* class representing the binary search tree */
template <class T> class BinarySearchTree {
private:
  BstNode<T> *root;
  unsigned int count;

  /* Member Function to add a node to the Binary Search Tree.Used Internally */
  BstNode<T> *addTo(BstNode<T> *ptr, T value) {
    if (ptr == nullptr) {
      ptr = new BstNode<T>(value);
      return ptr;
    } else if (value < ptr->data) {
      ptr->leftChild = addTo(ptr->leftChild, value);
      return ptr;
    } else {
      ptr->rightChild = addTo(ptr->rightChild, value);
      return ptr;
    }
  }

  /*INTERNAL: Member function for the inorder traversal of the tree. */
  void inorder(BstNode<T> *root) {
    if (root) {
      inorder(root->leftChild);
      cout << root->data << endl;
      inorder(root->rightChild);
    }
  }
  /*INTERNAL: Member function for the pre-order traversal of the tree. */
  void preorder(BstNode<T> *root) {
    if (root) {
      cout << root->data << endl;
      preorder(root->leftChild);
      preorder(root->rightChild);
    }
  }

  /*INTERNAL: Member function for the post-order traversal of the tree. */
  void postorderDelete(BstNode<T> *root) {
    if (root) {
      postorderDelete(root->leftChild);
      postorderDelete(root->rightChild);
      delete root;
    }
  }

  /*INTERNAL: Member Function to return maximum value for a subtree. */
  T getMax(BstNode<T> *ptr) {
    if (ptr == nullptr)
      return static_cast<T>(NULL);
    else if (ptr->rightChild == nullptr)
      return ptr->data;
    else
      return getMax(ptr->rightChild);
  }

  // Member Function to delete the node with specified value.
  BstNode<T> *deleteNode(BstNode<T> *ptr, T value) {
    if (ptr == nullptr) {
      return nullptr;
    }
    /* there can be 3 types to nodes to be deleted: leaf node, node with one
       child, node with 2 childs. */
    else if (value < ptr->data) {
      ptr->leftChild = deleteNode(ptr->leftChild, value);
      return ptr;
    } else if (value > ptr->data) {
      ptr->rightChild = deleteNode(ptr->rightChild, value);
      return ptr;
    }
    // The node to be deleted has been found
    else {
      /* LEAF NODE */
      if (ptr->leftChild == nullptr && ptr->rightChild == nullptr) {
        delete ptr;
        return nullptr;
      }
      /* NODE WITH ONLY RIGHT CHILD */
      if (ptr->leftChild == nullptr) {
        auto tmp = ptr->rightChild;
        delete ptr;
        return tmp;
      }
      /* NODE WITH ONLY LEFT CHILD */
      if (ptr->rightChild == nullptr) {
        auto tmp = ptr->leftChild;
        delete ptr;
        return tmp;
      }
      /* NODE WITH BOTH CHILDREN */
      else {
        ptr->data = getMax(ptr->leftChild);
        ptr->leftChild = deleteNode(ptr->leftChild, ptr->data);
        return ptr;
      }
    }
  }

public:
  /* Constructor for the Binary Search Tree */
  BinarySearchTree(BstNode<T> *ptr = nullptr, unsigned int cnt = 0)
      : root(ptr), count(cnt) {}

  /* Member Function to add a node to the Binary Search Tree. */
  void add(T value) {
    // checking for the condition with an empty tree
    if (root == nullptr) {
      root = new BstNode<T>(value);
    } else {
      root = addTo(root, value);
    }
    count++;
  }

  /* Member function for the inorder traversal of the tree. */
  void inorderPrint() { inorder(root); }

  /* Member function for the preorder traversal of the tree. */
  void preorderPrint() { preorder(root); }
  /* Member function for the postorder traversal of the tree. */
  void postorderPrint() { postorder(root); }
  /* Member function to delete a node */
  void delNode(T value) {
    root = deleteNode(root, value);
    count--;
  }

  /* Member function to delete the BST. */
  void clear() {
    postorderDelete(root);
    root = nullptr;
    count = 0;
  }

  unsigned int getCount() { return count; }
};

int main() {
  BinarySearchTree<int> bst;
  bst.add(23);
  bst.add(3);
  bst.add(33);
  bst.add(13);
  bst.inorderPrint();
  cout << "count:" << bst.getCount() << endl;
  bst.delNode(23);
  bst.inorderPrint();
  cout << "count:" << bst.getCount() << endl;
  cout << "deletion" << endl;
  bst.inorderPrint();
  cout << "count:" << bst.getCount() << endl;

  bst.clear();

  cout << "TESTING" << endl;
  BinarySearchTree<string> tree;
  string str;
  cout << "Enter BST node data (No validity checks are in place)" << endl;
  getline(cin >> ws, str);
  stringstream obj(str);
  while (getline(obj, str, ' ')) {
    tree.add(str);
  }
  tree.inorderPrint();

  return 0;
}
