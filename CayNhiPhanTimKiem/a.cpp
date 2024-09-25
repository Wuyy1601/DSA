/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    void preOrder(Node* root) {

        if (root == NULL)
            return;

        std::cout << root->data << " ";

        preOrder(root->left);
        preOrder(root->right);
    }


    // dùng đệ quy
    /*Node* insert(Node* root, int data) {
        if (root == nullptr)
        {
            return new Node(data);
        }
        else
        {
            Node* cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }
        }
        return root;
    }*/

    //không dùng đệ quy
    Node* insert(Node* root, int data)
    {
        Node* cur = root;
        if (root == nullptr)
        {
            return new Node(data);
        }


        while (cur)
        {
            if (cur->data >= data)
            {
                if (cur->left == nullptr)
                {
                    cur->left = new Node(data);
                    break;
                }
                else
                    cur = cur->left;
            }
            else
            {
                if (cur->right == nullptr)
                {
                    cur->right = new Node(data);
                    break;
                }
                else
                    cur = cur->right;
            }
        }

        return root;
    }
    void DeleteNode(Node*& root, int x)
    {
        if (root == nullptr)
            return;
        
        if (x > root->data) {
            DeleteNode(root->right, x);
        }
        else if(x<root->data)
        {
            DeleteNode(root->left, x);
        }
        else
        {
            Node* temp = root;
            if (root->left == nullptr)
            {
                root = root->right;
            }
            else if (root->right == nullptr)
            {
                root = root->left;
            }
            delete temp;

        }

    }
};

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
    int x;
    cin >> x;
    myTree.DeleteNode(root, x);
    myTree.preOrder(root);

    return 0;
}