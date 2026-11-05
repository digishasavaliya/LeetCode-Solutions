class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        string ans = "";

        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();

            if(front == NULL)
            {
                ans.append("#,");
            }
            else
            {
                ans.append(to_string(front->val) + ",");

                q.push(front->left);
                q.push(front->right);
            }
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if(data.size() == 0) return NULL;

        stringstream s(data);
        string str;

        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();

            // Left child
            getline(s, str, ',');

            if(str == "#")
            {
                front->left = NULL;
            }
            else
            {
                TreeNode* leftNode = new TreeNode(stoi(str));
                front->left = leftNode;
                q.push(leftNode);
            }

            // Right child
            getline(s, str, ',');

            if(str == "#")
            {
                front->right = NULL;
            }
            else
            {
                TreeNode* rightNode = new TreeNode(stoi(str));
                front->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};