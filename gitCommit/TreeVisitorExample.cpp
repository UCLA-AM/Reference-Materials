/*
 * Outline of a Visitor class that would be used to traverse a tree with labeled nodes.  We consider the case that
 * the behavior of the visitor may depend on the label of the node. The GenericVisitor class contains
 * generic code to call a function "handle_RED" or "handle_BLUE" depending on the label of the TreeNode. The
 * "handle_RED" and "handle_BLUE" functions in GenericVisitor call the "handle_RED" and "handle_BLUE" functions
 * of GenericVisitor's derived class. Using the implementations in the derived class of these two functions
 * is the functionality allowed by CRTP.
 */ 
struct TreeNode
{
    enum Kind {RED, BLUE};

    TreeNode(Kind kind_, TreeNode* left_ = NULL, TreeNode* right_ = NULL)
        : kind(kind_), left(left_), right(right_)
    {}

    Kind kind;
    TreeNode *left, *right;
};

template <typename Derived>
class GenericVisitor
{
public:
    void visit_preorder(TreeNode* node)
    {
        if (node) {
            dispatch_node(node); // do something based on type of node
            visit_preorder(node->left);
            visit_preorder(node->right);
        }
    }

    void visit_inorder(TreeNode* node)
    {
        if (node) {
            visit_inorder(node->left);
            dispatch_node(node);
            visit_inorder(node->right);
        }
    }

    void visit_postorder(TreeNode* node)
    {
        if (node) {
            visit_postorder(node->left);
            visit_postorder(node->right);
            dispatch_node(node);
        }
    }

    void handle_RED(TreeNode* node)
    {
        derived().handle_RED(node);
    }

    void handle_BLUE(TreeNode* node)
    {
        derived().handle_BLUE(node);
    }

private:
    // Convenience method for CRTP
    //
    Derived& derived()
    {
        return *static_cast<Derived*>(this);
    }

    void dispatch_node(TreeNode* node)
    {
        switch (node->kind) {
            case TreeNode::RED:
                handle_RED(node);
                break;
            case TreeNode::BLUE:
                handle_BLUE(node);
                break;
            default:
                assert(0);
        }
    }
};

// Outline of simple derived class.

class SpecialVisitor : public GenericVisitor<SpecialVisitor>
{
private:
    void handle_RED(TreeNode* node)
    {
        cerr << "RED is special\n";
    }
};


int main() {

        SpecialVisitor sv;


        sv.visit_inorder(node);
}
