/*Source: https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem

 

 

image
Cho một cây nhị phân tìm kiếm (BST), sinh viên hãy cài đặt hàm lca để tìm ra nút tổ tiên thấp nhất của cây BST đã cho với các tham số.

- root: con trỏ trỏ đến nút gốc
- v1, v2: giá trị 2 nút cần tìm nút tổ tiên gần nhất
 Hàm này sẽ trả về con trỏ trỏ đến nút tổ tiên gần nhất của 2 nút 

Ví dụ

Input

6
4 2 3 1 7 6
1 7
Output

Con trỏ trỏ đến nút có giá trị 4.

Diễn giải: 

Sinh viên xem cây BST được tạo ra từ dữ liệu input ở trên 

image

Với v1= 1 and v2= 7 thì hàm sẽ trả về con trỏ trỏ đến nút có giá trị là 4

 */

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    Node* insert(Node* root, int data) {
        if (root == nullptr) {
            return new Node(data);
        }
        else {
            Node* cur;
            if (data <= root->data) {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    /*The tree node has data, left child and right child
    class Node {
        int data;
        Node* left;
        Node* right;
    };

    */
    Node* lca(Node* root, int v1, int v2) {
        Node* ancestor = root;
        while (ancestor != nullptr) {
            if (ancestor->data > v1 && ancestor->data > v2) {
                ancestor = ancestor->left;
            }
            else if (ancestor->data < v1 && ancestor->data < v2) {
                ancestor = ancestor->right;
            }
            else {
                break;
            }
        }
        return ancestor;
    }

}; //End of Solution

int main() {

    Solution myTree;
    Node* root = nullptr;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    int v1, v2;
    std::cin >> v1 >> v2;

    Node* ans = myTree.lca(root, v1, v2);

    std::cout << ans->data;

    return 0;
}
