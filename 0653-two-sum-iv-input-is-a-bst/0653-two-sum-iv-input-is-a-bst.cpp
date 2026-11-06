
class BST {
public:
    stack<TreeNode*> st;
    bool reverse;

    BST(TreeNode* root, bool isreverse) {
        reverse = isreverse;
        pushall(root);
    }

    bool hasnext() {
        return !st.empty();
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();

        if (!reverse)
            pushall(temp->right);
        else
            pushall(temp->left);

        return temp->val;
    }

    void pushall(TreeNode* root) {
        while (root != NULL) {
            st.push(root);

            if (!reverse)
                root = root->left;
            else
                root = root->right;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {

        if (root == NULL)
            return false;

        BST l(root, false);  
        BST r(root, true);  
        int i = l.next();
        int j = r.next();

        while (i < j) {

            int sum = i + j;

            if (sum == k)
                return true;

            else if (sum < k)
                i = l.next();

            else
                j = r.next();
        }

        return false;
    }
};
