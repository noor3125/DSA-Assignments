#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// ---------------- INSERT NODE -------------------
Node* insertnode(Node* root, int val)
{
    if (root == nullptr)
        return new Node(val);

    if (val < root->data)
        root->left = insertnode(root->left, val);
    else if (val > root->data)
        root->right = insertnode(root->right, val);

    return root;   // MUST RETURN ROOT
}

// ---------------- INORDER TRAVERSAL -------------------
void inorder(Node* root)
{
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// ---------------- RECURSIVE SEARCH -------------------
Node* searchrecursive(Node* root, int key)
{
    if (root == nullptr || root->data == key)
        return root;

    if (key < root->data)
        return searchrecursive(root->left, key);

    return searchrecursive(root->right, key);
}

// ---------------- ITERATIVE SEARCH -------------------
Node* searchitr(Node* root, int key)
{
    while (root != nullptr)
    {
        if (root->data == key)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;
}

// ---------------- FIND MIN -------------------
Node* findmin(Node* root)
{
    if (!root) return nullptr;
    while (root->left != nullptr)
        root = root->left;
    return root;
}

// ---------------- FIND MAX -------------------
Node* findmax(Node* root)
{
    if (!root) return nullptr;
    while (root->right != nullptr)
        root = root->right;
    return root;
}
Node* deletion(Node* root,int key)
{
	if(root==nullptr)
	{
		return nullptr;
	}
	if(key<root->data){
		root->left=deletion(root->left,key);
	}
	else if(key>root->data){
		root->right=deletion(root->right,key);
	}
	else{
		//no child
		if(root->left==nullptr&&root->right==nullptr)
		{
			delete root;
			return nullptr;
		}
		//one child
		else if(root->left==nullptr)
		{
			Node* temp=root->right;
			delete root;
			return temp;
		}
		else if(root->right==nullptr)
		{
			Node* temp=root->left;
			delete root;
			return temp;
		}
		//both children
		else{
			Node* succ=findmin(root->right);
			root->data=succ->data;
			root->right=deletion(root->right,succ->data);
		}
	}
	return root;
}
int maxdepth(Node* root)
{
	if(root==nullptr)
	{
		return 0;
	}
	int left=maxdepth(root->left);
	int right=maxdepth(root->right);
	return (left,right)+1;
}
int mindepth(Node* root)
{
	if(root==nullptr)
	{
		return 0;
	}
	else if(root->left==nullptr)
	{
		return mindepth(root->right)+1;
	}
	else if(root->right==nullptr)
	{
		return mindepth(root->left)+1;
	}
	return min(mindepth(root->right),mindepth(root->left)+1);
}
bool isBST(Node* root,int minval,int maxval){
	if(root==nullptr)
	{
		return true;
	}
	else if(minval>=root->data||maxval<=root->data)
	{
		return false;
	}
	return(isBST(root->left,minval,root->data)&&isBST(root->right,root->data,maxval));
}
bool isBST(Node* root)
{
	return isBST(root,INT_MIN,INT_MAX);
}
// ---------------- INORDER SUCCESSOR -------------------
Node* inordersuccessor(Node* root, int key)
{
    Node* curr = searchitr(root, key);
    if (!curr) return nullptr;

    // Case 1: right subtree exists ? successor = min of right subtree
    if (curr->right)
        return findmin(curr->right);

    // Case 2: No right subtree ? successor is an ancestor
    Node* successor = nullptr;
    Node* ancestor = root;

    while (ancestor != curr)
    {
        if (curr->data < ancestor->data)
        {
            successor = ancestor;
            ancestor = ancestor->left;
        }
        else
            ancestor = ancestor->right;
    }
    return successor;
}

// ---------------- INORDER PREDECESSOR -------------------
Node* inorderpred(Node* root, int key)
{
    Node* curr = searchitr(root, key);
    if (!curr) return nullptr;

    // Case 1: left subtree exists ? predecessor = max of left subtree
    if (curr->left)
        return findmax(curr->left);

    // Case 2: No left subtree ? predecessor is an ancestor
    Node* predecessor = nullptr;
    Node* ancestor = root;

    while (ancestor != curr)
    {
        if (curr->data > ancestor->data)
        {
            predecessor = ancestor;
            ancestor = ancestor->right;
        }
        else
            ancestor = ancestor->left;
    }
    return predecessor;
}
int sumofleftnodes(Node* root)
{
	int sum=0;
	if(root==nullptr)
	{
		return 0;
	}
	if(root->left!=nullptr)
		sum+=root->left->data;
		
		
		sum+=sumofleftnodes(root->left);
		sum+=sumofleftnodes(root->right);
		
	return sum;
}

// ---------------- MAIN FUNCTION -------------------
int main() {

    Node* root = nullptr;

    int arr[] = {10, 40, 70, 50, 30, 59, 80, 42};
    for (int x : arr)
        root = insertnode(root, x);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    int key = 40;

    // Recursive Search
    Node* s1 = searchrecursive(root, key);
    cout << "Recursive search for " << key << ": "
         << (s1 ? "found" : "not found") << endl;

    // Iterative Search
    Node* s2 = searchitr(root, key);
    cout << "Iterative search for " << key << ": "
         << (s2 ? "found" : "not found") << endl;

    // Min & Max
    cout << "Min element: " << findmin(root)->data << endl;
    cout << "Max element: " << findmax(root)->data << endl;

    // Successor
    Node* succ = inordersuccessor(root, key);
    if (succ)
        cout << "Successor of " << key << " = " << succ->data << endl;
    else
        cout << "No successor exists for " << key << endl;

    // Predecessor
    Node* pred = inorderpred(root, key);
    if (pred)
        cout << "Predecessor of " << key << " = " << pred->data << endl;
    else
        cout << "No predecessor exists for " << key << endl;
        
    root=deletion(root,key);
    cout<<"after deletion of "<<key<<":";
    inorder(root);
    cout<<endl;
    
    cout<<"Max depth BST:"<<maxdepth(root)<<endl;
    cout<<"Min depth BST:"<<mindepth(root)<<endl;
    
    cout<<"is this tree BST?"<<(isBST(root)? "YES":"NO")<<endl;
    cout<<"sum of left nodes:"<<sumofleftnodes(root)<<endl;

    return 0;
}

