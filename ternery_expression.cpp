#include "leetcode.h"

struct TreeNode {
	char val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(char c): val(c), left(0), right(0) {}
};

void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		cout << root->val << endl;
		inorder(root->right);
	}
}

TreeNode* terneryToBinaryTree(string input) {
	int n = input.size();
	if (!n)
		return 0;
	TreeNode* root = new TreeNode(input[0]);
	TreeNode* t = root;
	stack<TreeNode*> stk;
	stk.push(t);
	for (int i = 1; i < n; i += 2) {
		if (input[i] == '?') {
			t = stk.top();
			t->left = new TreeNode(input[i + 1]);
			stk.push(t->left);
		}
		else {
			stk.pop();
			t = stk.top();
			t->right = new TreeNode(input[i + 1]);
		}
	}
	return root;
}

int main() {
	TreeNode* root = terneryToBinaryTree("a?b?c:d:e");
	inorder(root);
}