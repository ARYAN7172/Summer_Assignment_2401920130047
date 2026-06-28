class Solution {
public:
    bool check(TreeNode* root, long long mn, long long mx) {
        if (root == NULL)
            return true;

        if (root->val <= mn || root->val >= mx)
            return false;

        return check(root->left, mn, root->val) &&
               check(root->right, root->val, mx);
    }

    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};