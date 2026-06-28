class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)
            return "N,";

        return to_string(root->val) + "," +
               serialize(root->left) +
               serialize(root->right);
    }

    // Helper function
    TreeNode* build(stringstream& ss) {
        string s;
        getline(ss, s, ',');

        if (s == "N")
            return NULL;

        TreeNode* root = new TreeNode(stoi(s));
        root->left = build(ss);
        root->right = build(ss);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return build(ss);
    }
};