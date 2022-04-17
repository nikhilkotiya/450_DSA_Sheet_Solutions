// Time cpmplexity => O(N) (n=NUmber of nodes)
// Space compecity => O(H) (h= max height of a tree)


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* rec(Node* root,vector<int>&v)
    {
        if(root==NULL)
        {
            return NULL;    
        }    
        v.push_back(root->val);
        for(auto x : root->children)
        {
            rec(x,v);
        }
        //other type
        // for(Node* child : root->children)
        // {
        //     rec(child,v);
        // }
        return root;
    }
    vector<int> preorder(Node* root) {
        vector<int>v;
        root=rec(root,v);
        return v;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int>v;
        if(root==NULL)
        {
            return v;
        }
        stack<Node*>s;
        s.push(root);
        while(s.size())
        {
            Node* t=s.top();
            if(t==NULL)
            {
                continue;
            }
            v.push_back(t->val);
            s.pop();
            for(int i=t->children.size()-1;i>=0;i--)
            {
                s.push(t->children[i]);
            }
        }
        return v;
    }
}; 