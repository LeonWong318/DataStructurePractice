#include<iostream>
#include<queue>// introduce queue's stl

using namespace std;

struct BstNode {
	int data;
	BstNode* left;
	BstNode* right;
};

BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}
BstNode* Insert(BstNode* root, int data) {
	if (root == NULL) {
		root = GetNewNode(data);
	}
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	else {
		root->right = Insert(root->right, data);
	}
	return root;
}

bool Search(BstNode* root, int data) {
	if (root == NULL)return false;
	else if (root->data == data)return true;
	else if (data <= root->data)return Search(root->left, data);
	else return Search(root->right, data);
}
// find max and min by interative method:
//int FindMax(BstNode* root) {
//	if (root == NULL) {
//		cout << "Error: Tree is empty" << endl;
//		return -1;
//	}
//	BstNode* current = root;
//	while (current->right != NULL) {
//		current = current->right;
//	}
//	return current->data;
//}
//
//int FindMin(BstNode* root) {
//	if (root == NULL) {
//		cout << "Error: Tree is empty" << endl;
//		return -1;
//	}
//	BstNode* current = root;
//	while (current->left != NULL) {
//		current = current->left;
//	}
//	return current->data;
//}

// find max and min by recursive method:

int FindMin(BstNode* root) {
	if (root == NULL) {
		cout << "Error: Tree is empty" << endl;
		return -1;
	}
	else if (root->left == NULL) {
		return root->data;
	}
	else return FindMin(root->left);
}

int FindMax(BstNode* root) {
	if (root == NULL) {
		cout << "Error: Tree is empty" << endl;
		return -1;
	}
	else if (root->right == NULL) {
		return root->data;
	}
	else return FindMax(root->right);
}

int FindHeight(BstNode* root) {
	if (root == NULL) {
		return -1;
	}
	return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

void levelOrderTraversal(BstNode* root) {//level ordar traversal
	if (root == NULL) {
		cout << "Error: the tree is tempty" << endl;
		return;
	}
	queue<BstNode*> Q;
	Q.push(root);
	cout << "Level order traversal is: ";
	while (!Q.empty()) {
		BstNode* current = Q.front();
		cout << current->data << " ";
		if (current->left != NULL) Q.push(current->left);
		if (current->right != NULL) Q.push(current->right);
		Q.pop();
	}
	cout << endl;
}

void Preorder(BstNode* root) {//data left right order traversal
	if (root == NULL) return; 
	cout << root->data << " ";
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(BstNode* root) {// left data right order traversal
	if (root == NULL) 	return;
	Inorder(root->left);
	cout << root->data << " ";
	Inorder(root->right);
	
}

void Postorder(BstNode* root) {// left right data order traversal
	if (root == NULL) return;
	Postorder(root->left);
	Postorder(root->right);
	cout << root->data << " ";
}

//bool IsSubtreeLesser(BstNode* root, int value){
//	if (root == NULL) return true;
//	if (root->data <= value
//		&& IsSubtreeLesser(root->left, value)
//		&& IsSubtreeLesser(root->right, value))
//		return true;
//	else
//		return false;
//}
//bool IsSubtreeGreater(BstNode* root, int value){
//	if (root == NULL) return true;
//	if (root->data > value
//		&& IsSubtreeGreater(root->left, value)
//		&& IsSubtreeGreater(root->right, value))
//		return true;
//	else
//		return false;
//}

bool IsBstUntil(BstNode* root, int minValue, int maxValue) {
	//return true if bst, false otherwise
	if (root == NULL) return true;
	if (/*IsSubtreeLesser(root->left, root->data)
		&& IsSubtreeGreater(root->right, root->data)*/
		root->data > minValue
		&& root->data < maxValue
		&& IsBstUntil(root->left, minValue, root->data)
		&& IsBstUntil(root->right, root->data, maxValue))
		return true;
	else
		return false;
}

bool IsBinarySearchTree(BstNode* root) {// this function aims to only pass one variable from main function
	return IsBstUntil(root, INT_MIN, INT_MAX);
}
void InOrder(BstNode* root, int arr[], int& index) {// store inorder traversal result in array
	// Note: if we want to change the value of both arr and index, we must use address pass rather than value pass
	if (root == NULL) 	return ;
	InOrder(root->left, arr, index);
	arr[index++] = root->data;
	InOrder(root->right, arr, index);

}
bool IsBST_Inorder(BstNode* root) {
	/* this function aims to check whether a binary tree is a BST by Inorder traversal */
	const int MAX_INDEX = 100;
	int arr[MAX_INDEX];
	int index = 0;
	InOrder(root, arr, index);
	
	for (int i = 0; i < index; i++) {
		if (arr[i] > arr[i + 1]) return false;
		else if (arr[i] == NULL && arr[i + 1] == NULL) return false;
		else return true;
	}
}

BstNode* FindMin_(BstNode* root) {
	if (root == NULL) {
		cout << "Error: Tree is empty" << endl;
		return root;
	}
	else if (root->left == NULL) {
		return root;
	}
	else return FindMin_(root->right);
}

BstNode* Delete(BstNode* root, int data) {
	if (root == NULL) return root;
	// find target node:
	else if (data < root->data) root->left = Delete(root->left, data);
	else if (data > root->data) root->right = Delete(root->right, data);
	else {// found target node:
		// case 1: no child
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		// case 2: one child
		else if (root->left == NULL) {
			BstNode* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL) {
			BstNode* temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else {
			BstNode* temp = FindMin_(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}

BstNode* Find(BstNode* root, int data) {
	if (root->data == data) return root;
	else if (root->data > data) return Find(root->left, data);
	else return Find(root->right, data);
}
// function to find the successor along with the process of inorder traversal
BstNode* GetSuccessor(BstNode* root, int data) {
	// search the node - O(h)
	BstNode* current = Find(root, data);
	if (current == NULL) return NULL;
	//case 1: node has right subtree
	if (current->right != NULL) {
		BstNode* temp = current->right;
		while (temp->left != NULL) temp = temp->left;
		return temp;
	}
	//case 2: no right subtree
	else {
		BstNode* successor = NULL;
		BstNode* ancestor = root;
		while (ancestor != current) {
			if (current->data < ancestor->data) {
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else {
				ancestor = ancestor->right;
			}
		}
		return successor;
	}
}

int main() {

	BstNode* root = NULL;
	root = Insert(root, 15);root = Insert(root, 10);root = Insert(root, 20);
	root = Insert(root, 25);root = Insert(root, 8);root = Insert(root, 12);
	/*we've created a tree like: 
	    15
	    / \
	   10  20
	  / \    \
	 8  12    25  */
	int number;
	/*cout << "Enter number to be searched:" << endl;
	cin >> number;
	if (Search(root, number) == true) cout << "Found" << endl;
	else cout << "Not Found" << endl;*/
	cout << "Max number is: " << FindMax(root) << endl;
	cout << "Min number is: " << FindMin(root) << endl;
	cout << "The height of this tree is: " << FindHeight(root) << endl;
	levelOrderTraversal(root);
	cout << "Preorder traversal is: ";Preorder(root);cout << endl;
	cout << "Inorder traversal is: ";Inorder(root);cout << endl;
	cout << "Postorder traversal is: ";Postorder(root);cout << endl;
	cout << IsBinarySearchTree(root) << endl;
	cout << IsBST_Inorder(root) << endl;

	/*check function InOrder
	const int MAX_INDEX = 100;
	int arr[MAX_INDEX];
	int index = 0;
	InOrder(root, arr, index);
	for (int j = 0; j < index; j++) {
		cout << arr[j] << " ";
	}
	cout << endl;*/

	Delete(root, 15);
	/*
	     20	
		/  \
	   10   25
	   / \    
	 8  12    
	*/
	/* validation of Delete function:
	cout << "Inorder traversal is: ";Inorder(root);cout << endl;
	cout << root->data << endl;
	cout << root->left->data << " " << root->right->data << endl;
	cout << root->left->left->data << " " << root->left->right->data << endl;*/
	cout << GetSuccessor(root, 12)->data << endl;
	system("pause");
	return 0;
}