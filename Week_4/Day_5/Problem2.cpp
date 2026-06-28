class Solution {
public:
    unordered_map<int, int> mp;
    int preIdx = 0;

    TreeNode* build(vector<int>& preorder, int l, int r) {
        if (l > r)
            return NULL;

        int val = preorder[preIdx++];
        TreeNode* root = new TreeNode(val);

        int mid = mp[val];

        root->left = build(preorder, l, mid - 1);
        root->right = build(preorder, mid + 1, r);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return build(preorder, 0, inorder.size() - 1);
    }
};