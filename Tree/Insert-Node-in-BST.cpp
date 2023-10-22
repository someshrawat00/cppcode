#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// build Tree;
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

//1st Approach
void insert(Node *root, int k)
{
    if (!root)
        return;
    if (root->data > k)
    {
        if (!root->left)
        {
            Node *t = new Node(k);
            root->left = t;
        }
        insert(root->left, k);
    }
    else if (root->data < k)
    {
        if (!root->right)
        {
            Node *t = new Node(k);
            root->right = t;
        }
        insert(root->right, k);
    }
}

//2nd Approach
Node* insertNode(Node* root, int key){
    
    if(root == NULL){
        Node* temp = new Node(key);
        return temp;
    }
    
    if(root->data < key){
        root->right = insertNode(root->right,key);
    }else{
        root->left = insertNode(root->left,key);
    }
    return root; 
}


void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = buildTree("2 1 3");

    inorder(root);
    cout << endl;
    insert(root, 4);
    insert(root, 6);
    inorder(root);

    return 0;
}