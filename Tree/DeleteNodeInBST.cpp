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

Node *getLargestNode(Node *root)
{
    if (root->right == NULL)
    {
        return root;
    }
    return getLargestNode(root->right);
}

Node *getSmallestNode(Node *root)
{
    if (root->left == NULL)
    {
        return root;
    }
    return getSmallestNode(root->left);
}

Node *del(Node *root, int x)
{
    if (root == NULL)
    {
        return root;
    }

    else if (x > root->data)
    {
        root->right = del(root->right, x);
    }

    else if (x < root->data)
    {
        root->left = del(root->left, x);
    }

    else if (root->left != NULL)
    {
        Node *temp = getLargestNode(root->left);
        root->data = temp->data;
        root->left = del(root->left, temp->data);
    }

    else if (root->right != NULL)
    {
        Node *temp = getSmallestNode(root->right);
        root->data = temp->data;
        root->right = del(root->right, temp->data);
    }

    else if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
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
    del(root, 2);
    inorder(root);

    return 0;
}