#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Node
{
	public :
		int data;
		Node* left;
		Node* right;
		Node(int d)
		{
			data = d;
			left = nullptr;
			right = nullptr;
		}
};

class solution
{
public:
	Node* Insert(Node* root, int data)
	{
		if (root == nullptr)
		{
			return new Node(data);
		}
		else
		{
			Node* cur;
			if (data <= root->data)
			{
				cur = Insert(root->left, data);
				root->left = cur;
			}
			else
			{
				cur = Insert(root->right, data);
				root->right = cur;

			}
			return root;
		}
	}

	void DuyetLRN(Node* root)
	{
		if (root != nullptr)
		{
			DuyetLRN(root->left);
			DuyetLRN(root->right);
			cout << root->data << " ";
		}
	}

	void DuyetNLR(Node* root)
	{
		if (root != nullptr)
		{
			cout << root->data << " ";
			DuyetNLR(root->left);
			DuyetNLR(root->right);
		}
	}

	void DuyetLNR(Node* root)
	{
		if (root != nullptr)
		{
			DuyetLNR(root->left);
			cout << root->data << " ";
			DuyetLNR(root->right);
		}
	}

	void DuyetNLRKhongdequy(Node* root)
	{
		if (root == nullptr)
			return;
		stack<Node*> Stackroot;
		Stackroot.push(root);

		while (!Stackroot.empty())
		{
			Node* current = Stackroot.top();
			Stackroot.pop();

			cout << current->data << " ";
			//thêm phải trước để duyệt sau, thêm trái sau để được duyệt trước
			if (current->right != nullptr)
			{
				Stackroot.push(current->right);
			}
			if (current->left != nullptr)
			{
				Stackroot.push(current->left);
			}
		}
	}

	void DuyetRNL(Node* root)
	{
		if (root != nullptr)
		{
			DuyetRNL(root->right);
			cout << root->data << " ";
			DuyetRNL(root->left);
			
		}
	}

	void DuyetLNRKhongdequy(Node* root)
	{
		if (root == nullptr)
			return;

		stack<Node*> Stackroot;

		Node* current = root;

		while (current != nullptr || !Stackroot.empty())
		{
			while (current != nullptr)
			{
				Stackroot.push(current);
				current = current->left;
			}
			current = Stackroot.top();
			Stackroot.pop();
			cout << current->data << " ";
			current = current->right;
		}
	}

	void DuyetLRNKhongdequy(Node* root)
	{
		if (root == nullptr)
			return;

		stack<Node*> nodeStack1;
		stack<Node*> nodeStack2;
		nodeStack1.push(root);

		while (!nodeStack1.empty()) {
			Node* current = nodeStack1.top();
			nodeStack1.pop();
			nodeStack2.push(current);

			if (current->left != nullptr)
				nodeStack1.push(current->left);

			if (current->right != nullptr)
				nodeStack1.push(current->right);
		}

		while (!nodeStack2.empty()) {
			cout << nodeStack2.top()->data << " ";
			nodeStack2.pop();
		}
	}

	//Duyet theo chieu rong dung stack(chua fix)
	/*void levelOrder(Node* root)
	{
		if (root == nullptr)
			return;
		stack<Node*> nodeStack;
		
		nodeStack.push(root);

		while (!nodeStack.empty())
		{
			
				Node* cur = nodeStack.top();
				nodeStack.pop();
				cout << cur->data << " ";
				if (cur->right)
				{
					nodeStack.push(cur->right);
				}
				if (cur->left)
				{
					nodeStack.push(cur->left);
				}
			
			
		}
	}*/

	//duyet theo chieu rong dung queue
	void levelOrder(Node* root) {
		queue<Node*> queue;
		queue.push(root);

		while (!queue.empty()) {
			int nodesInCurrentLevel = queue.size();
			// do some logic here for the current level

			for (int i = 0; i < nodesInCurrentLevel; i++) {
				Node* node = queue.front();
				queue.pop();

				// do some logic here on the current node
				cout << node->data << " ";

				// put the next level onto the queue
				if (node->left) {
					queue.push(node->left);
				}

				if (node->right) {
					queue.push(node->right);
				}
			}
		}
	}
	// check cây nhị phân
	bool checkBST(Node* root) {
		bool leftBST = false;

		bool rightBST = false;

		if (root == nullptr)
			return true;
		if (root->left != nullptr && root->left->data < root->data)
		{
			leftBST = checkBST(root->left);
		}
		else if (root->left == nullptr)
		{
			leftBST = true;
		}	

		else if (root->left != nullptr && root->left->data >= root->data)
		{
			leftBST = false;
		}


		if (root->right != nullptr && root->right->data > root->data)
		{
			rightBST = checkBST(root->right);
		}
		else if (root->right == nullptr)
		{
			rightBST = true;
		}

		else if (root->right != nullptr && root->right->data >= root->data)
		{
			rightBST = false;
		}


		return (leftBST && rightBST);
	}

	//Tính độ cao cây nhị phân
	int height(Node* root)
	{
		if (root == nullptr)
			return 0;

		int LeftHeigh = height(root->left);
		int RightHeigh = height(root->right);

		return max(LeftHeigh, RightHeigh) + 1;
	}
};


int main() {

	solution myTree;
	Node* root = NULL;

	int t;
	int data;

	std::cin >> t;

	while (t-- > 0) {
		std::cin >> data;
		root = myTree.Insert(root, data);
	}

	myTree.DuyetRNL(root);

	return 0;
}