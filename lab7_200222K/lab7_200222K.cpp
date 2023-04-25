#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if (root == NULL) {
        return;
    }
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);


}

// Insert a node
struct node *getNewNode(int val)
{
    struct node *newNode = new node;
    if (!newNode) {
        cout << "Memory allocation failed";
        return NULL;
    }
    newNode->key   = val;
    newNode->left  = NULL;
    newNode->right = NULL;

    return newNode;
}
struct node *insertNode(struct node *node, int key) {
    if(node == NULL){
        return getNewNode(key);
    }if(node->key < key){
        node->right = insertNode(node->right,key);
    }else if(node->key > key){
        node->left = insertNode(node->left,key);
    }
    return node;
    
    
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if (root == NULL) 
    {
      return NULL;
    }
    
    else
    {
      // node is found and needs to be deleted 
      if(key == root->key) 
      {
        // scenario 1 
        if (root->left == NULL && root->right == NULL) 
        {
          delete root;
          return NULL;
        } 

        // scenario 2
        else if(root->left == NULL)
        {
          node * temp = root->right;
          delete root;
          return temp;
        }

        // scenario 3
        else if (root->right == NULL) 
        {
          node * temp = root->left;
          delete root;
          return temp;
        } 

        // scenario 4
        else 
        {
          // finding the minimum value in the right subtree
          node * min_right_subtree ; 
          node * current = root->right;
          while (current->left != NULL) 
          {
            current = current->left;
          }
          min_right_subtree = current;
        
          // switching the values 
          root->key = min_right_subtree->key;

          // Deleting the node with val_to_delete now as a leaf node
          root->right = deleteNode(root->right, min_right_subtree->key);
        }
      }
    
      // keep searching for node
      else
      {
        if (key< root->key) 
        {
          root->left = deleteNode(root->left, key);
        }
        
        else if (key > root->key) 
        {
          root->right = deleteNode(root->right, key);
        }
      }
      
      return root ;
    }
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}