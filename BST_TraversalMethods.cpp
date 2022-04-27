#include <iostream>
using namespace std;

struct bt_data
{
	bt_data* left;
	bt_data* right;
	int data;
};

class BinarySearchTree
{
public:
	  BinarySearchTree()
	  {
		  this->root = nullptr;
	  }

	  void insertNode(int item)
	  {
		  // Create a new node
		  bt_data* new_node = new bt_data;
		  if (new_node != nullptr)
		  {
			  new_node->left = nullptr;
			  new_node->right = nullptr;
			  new_node->data = item;
		  }

		  //If bst is empty, new_node itself is first node
		  if (root == nullptr)
		  {
			  // When adds a first node in bst
			  root = new_node;
			  return;
		  }

		  bt_data* copy_of_root = root;
			  
		  // Add new node to proper position
		  while (copy_of_root != nullptr)
		  {
			  //BST Condition - All the left hand side elements greater than right hand side elements
			  if (copy_of_root->data >= item)
			  {
				  if (copy_of_root->left == nullptr)
				  {
					  copy_of_root->left = new_node;
					  return;
				  }
				  else
				  {
					  copy_of_root = copy_of_root->left;
				  }
			  }
			  else
			  {
				  if (copy_of_root->right == nullptr)
				  {
					  copy_of_root->right = new_node;
					  return;
				  }
				  else
				  {
					  copy_of_root = copy_of_root->right;
				  }
			  }
		  }
	  }

	  void printInorderTraversal(bt_data* node)
	  {
		  if (node != nullptr)
		  {
			  // Visit to left subtree
			  this->printInorderTraversal(node->left);
			  // Display node value
			  cout << "  " << node->data;
			  // Visit to right subtree
			  this->printInorderTraversal(node->right);
		  }
	  }

	  void printPreorderTraversal(bt_data* node)
	  {
		  if (node != nullptr)
		  {
			  // Display node value
			  cout << "  " << node->data;
			  // Visit to left subtree
			  this->printPreorderTraversal(node->left);
			  // Visit to right subtree
			  this->printPreorderTraversal(node->right);
		  }
	  }

	  void printPostorderTraversal(bt_data* node)
	  {
		  if (node != nullptr)
		  {
			  // Visit to left subtree
			  this->printInorderTraversal(node->left);
			  // Visit to right subtree
			  this->printInorderTraversal(node->right);
			  // Display node value
			  cout << "  " << node->data;
		  }
	  }

	  void inorderTraversal()
	  {
		  if (root == nullptr)
		  {
			  return;
		  }
		  bt_data* copy_of_root = root;
		  printInorderTraversal(copy_of_root);
	  }

	  void preOrderTraversal()
	  {
		  if (root == nullptr)
		  {
			  return;
		  }
		  bt_data* copy_of_root = root;
		  printPreorderTraversal(copy_of_root);
	  }

	  void postOrderTraversal()
	  {
		  if (root == nullptr)
		  {
			  return;
		  }
		  bt_data* copy_of_root = root;
		  printPostorderTraversal(copy_of_root);
	  }

public:
	bt_data* root = nullptr;
};
int main()
{
	BinarySearchTree* tree = new BinarySearchTree();
	tree->insertNode(10);
	tree->insertNode(4);
	tree->insertNode(3);
	tree->insertNode(5);
	tree->insertNode(15);
	tree->insertNode(12);

	cout << "\nInorder " << endl;
	tree->inorderTraversal();

	cout << "\nPreorder " << endl;
	tree->preOrderTraversal();

	cout << "\nPostorder " << endl;
	tree->postOrderTraversal();

	return 0;
}