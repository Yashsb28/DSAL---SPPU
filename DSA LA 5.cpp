/* Name :- Yash S. Bhoge
   Roll no. :- 27003
   Class :- SE IT B
   Topic:- DSA Assignment 5 */ 

# include <iostream>
# include <cstdlib>
using namespace std;

//Declare Node
struct node
{
    int info;
    struct node *left;
    struct node *right;
    
}*root;
 
class BST
{ 
        
    public:
        void search(int, node **, node **);    
        void insert(node *, node *);
        void del(int);
        void A(node *,node *);
        void B(node *,node *);
        void C(node *,node *);
        void preorder(node *);
        void inorder(node *);
        void postorder(node *);
        void display(node *, int);
        int maxDepth(node *);
        void mirrorOfBst(node *);
        void LeafNode(node *);
        BST()
        {
            root = NULL;
        }
};

//Insert element in Tree
void BST::insert(node *tree, node *newnode)
{
    if (root == NULL)
    {
        root = new node;
        root->info = newnode->info;
        root->left = NULL;
        root->right = NULL;
        cout<<"Root Node is Added"<<endl;
        return;
    }
    if (tree->info == newnode->info)
    {
        cout<<"Element already in the tree"<<endl;
        return;
    }
    if (tree->info > newnode->info)
    {
        if (tree->left != NULL)
        {
            insert(tree->left, newnode);	
	}
	else
	{
            tree->left = newnode;
            (tree->left)->left = NULL;
            (tree->left)->right = NULL;
            cout<<"Node Added To Left"<<endl;
            return;
        }
    }
    else
    {
        if (tree->right != NULL)
        {
            insert(tree->right, newnode);
        }
        else
        {
            tree->right = newnode;
            (tree->right)->left = NULL;
            (tree->right)->right = NULL;
            cout<<"Node Added To Right"<<endl;
            return;
        }	
    }
}
 
//Search element in the Tree
void BST::search(int item, node **par, node **loc)
{
    node *ptr, *ptrsave;
    if (root == NULL)
    {
        *loc = NULL;
        *par = NULL;
        return;
    }
    if (item == root->info)
    {
        *loc = root;
        *par = NULL;
        return;
    }
    if (item < root->info)
        ptr = root->left;
    else
        ptr = root->right;
    ptrsave = root;
    while (ptr != NULL)
    {
        if (item == ptr->info)
        {
            *loc = ptr;
            *par = ptrsave;
            return;
        }
        ptrsave = ptr;
        if (item < ptr->info)
            ptr = ptr->left;
	else
	    ptr = ptr->right;
    }
    *loc = NULL;
    *par = ptrsave;
}

 
//Delete element in Tree
void BST::del(int item)
{
    node *parent, *location;
    if (root == NULL)
    {
        cout<<"Tree empty"<<endl;
        return;
    }
    search(item, &parent, &location);
    if (location == NULL)
    {
        cout<<"Item not present in tree"<<endl;
        return;
    }
    if (location->left == NULL && location->right == NULL)
        A(parent, location);
    if (location->left != NULL && location->right == NULL)
        B(parent, location);
    if (location->left == NULL && location->right != NULL)
        B(parent, location);
    if (location->left != NULL && location->right != NULL)
        C(parent, location);
    free(location);
}
 
//Case A 
void BST::A(node *par, node *loc )
{
    if (par == NULL)
    {
        root = NULL;
    }
    else
    {
        if (loc == par->left)
            par->left = NULL;
        else
            par->right = NULL;
    }
}
 
//Case B
void BST::B(node *par, node *loc)
{
    node *child;
    if (loc->left != NULL)
        child = loc->left;
    else
        child = loc->right;
    if (par == NULL)
    {
        root = child;
    }
    else
    {
        if (loc == par->left)
            par->left = child;
        else
            par->right = child;
    }
}
 
//Case C
void BST::C(node *par, node *loc)
{
    node *ptr, *ptrsave, *suc, *parsuc;
    ptrsave = loc;
    ptr = loc->right;
    while (ptr->left != NULL)
    {
        ptrsave = ptr;
        ptr = ptr->left;
    }
    suc = ptr;
    parsuc = ptrsave;
    if (suc->left == NULL && suc->right == NULL)
        A(parsuc, suc);
    else
        B(parsuc, suc);
    if (par == NULL)
    {
        root = suc;
    }
    else
    {
        if (loc == par->left)
            par->left = suc;
        else
            par->right = suc;
    }
    suc->left = loc->left;
    suc->right = loc->right;
}
 
//Pre Order
void BST::preorder(node *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        cout<<ptr->info<<"  ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

//In order
void BST::inorder(node *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        inorder(ptr->left);
        cout<<ptr->info<<"  ";
        inorder(ptr->right);
    }
}
 
//Post Order
void BST::postorder(node *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<ptr->info<<"  ";
    }
}
 
//Display tree
void BST::display(node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level+1);
        cout<<endl;
        if (ptr == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"       ";
	}
        cout<<ptr->info;
        display(ptr->left, level+1);
    }
}

//Depth of Tree
int BST::maxDepth(node* node)
{
    if (node == NULL)
        return -1;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
     
        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}

//Mirror of BST
void BST::mirrorOfBst(node * root){
  if (root != NULL){
    mirrorOfBst(root->left);
    mirrorOfBst(root->right);
    node *temp = root->left;
    root->left = root->right;
    root->right = temp;
  }
}

//Display Leaf Node of BST
void BST::LeafNode(node *root){
  if (root == NULL){
    return;
  }
  if (root->left == NULL && root->right == NULL){
    cout << root->info << " ";
  }
  if (root->left != NULL){
    LeafNode(root->left);
  }
  if (root->right != NULL){
    LeafNode(root->right);
  }
}


int main()
{
    int choice, num;
    BST bst;
    node *temp;
    node *parent, *location;
    while (1)
    {
        cout<<"************************"<<endl;
        cout<<"  BINARY SEARCH TREE"<<endl;
        cout<<"************************"<<endl;
        cout<<"1.Insert element in BST "<<endl;
        cout<<"2.Delete element in BST "<<endl;
        cout<<"3.BST Traversal"<<endl;
        cout<<"4.Search element in BST"<<endl;
        cout<<"5.Display Tree"<<endl;
        cout<<"6.Depth of BST"<<endl;
        cout<<"7.Mirror of BST"<<endl;
        cout<<"8.Leaf Node of BST"<<endl;
        cout<<"9.Quit"<<endl;
        cout<<"************************"<<endl;
        cout<<"\nEnter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            temp = new node;
            cout<<"Enter the number to be inserted : ";
	    cin>>temp->info;
            bst.insert(root, temp);
            break;
        case 2:
            if (root == NULL)
            {
                cout<<"Tree is empty, nothing to delete"<<endl;
                continue;
            }
            cout<<"Enter the number to be deleted : ";
            cin>>num;
            bst.del(num);
            cout<<num<<" DELETED from Tree!!!"<<endl;
            break;
        case 3:
            cout<<"Inorder Traversal of BST:"<<endl;
            bst.inorder(root);
            cout<<endl;
        
            cout<<"Preorder Traversal of BST:"<<endl;
            bst.preorder(root);
            cout<<endl;
            
            cout<<"Postorder Traversal of BST:"<<endl;
            bst.postorder(root);
            cout<<endl;
            break;
            
        case 4:
            cout<<"Enter the number to be searched : ";
            cin>>num;
            bst.search(num,&parent,&location);
            if (location == NULL) {
                    cout<<"Item not present in tree"<<endl;
            }
            else {
                cout<<num<<" is FOUND at = "<<&location<<endl;
            }
            break;
            
        case 5:
            cout<<"Display BST:"<<endl;
            bst.display(root,1);
            cout<<endl;
            break;
            
        case 6:
            cout << "Depth of tree is " << bst.maxDepth(root)<<endl;
            break;
        
        case 7: 
            bst.mirrorOfBst(root);
            cout<<"Inorder Traversal of BST:"<<endl;
            bst.inorder(root);
            cout<<endl;
        
            cout<<"Preorder Traversal of BST:"<<endl;
            bst.preorder(root);
            cout<<endl;
            
            cout<<"Postorder Traversal of BST:"<<endl;
            bst.postorder(root);
            cout<<endl;
            break;
            
        case 8:
            cout<<"Leaf Node Of BST: ";
            bst.LeafNode(root);
            break;
            
        case 9:
            exit(1);
            cout<<"EXITING........!!!";
            
             
        default:
            cout<<"Wrong choice entered!!!"<<endl;
            cout<<"************************"<<endl;
        }
    }
}