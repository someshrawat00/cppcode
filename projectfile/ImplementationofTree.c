#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

struct node *deletenode(struct node *root, int k)
{
    if (root == NULL)
        return root;

    if (root->data > k)
    {
        root->left = deletenode(root->left, k);
        return root;
    }
    else if (root->data < k)
    {
        root->right = deletenode(root->right, k);
        return root;
    }

    if (root->left == NULL)
    {
        struct node *temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL)
    {
        struct node *temp = root->left;
        free(root);
        return temp;
    }

    else
    {

        struct node *succParent = root;

        struct node *succ = root->right;
        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }

        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        root->data = succ->data;

        free(succ);
        return root;
    }
}

struct node *insert(struct node *node, int key)
{

    if (node == NULL)
        return newNode(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    return node;
}

int main()
{
    struct node* root = newNode(-1);
    while(1)
    {
        int choice, key;

        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Print preorder\n");
        printf("4.Print postorder\n");
        printf("5.Print inorder\n");
        printf("6.Exit\n");

        scanf("%d", &choice);
        if (root->data == -1)
        {
            int rvalue;
            printf("Give root value: ");
            scanf("%d", &rvalue);
            root->data = rvalue;
        }
        switch (choice)
        {
        case 1:

            printf("Enter key to insert");
            scanf("%d", &key);
            root = insert(root, key);
            printf("Inserted: ");
            inorder(root);
            printf("\n");
            break;
        case 2:

            printf("Enter key to Delete");
            scanf("%d", &key);
            root = deletenode(root, key);
            printf("Deleted: ");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;
        case 5:
            printf("inorder: ");
            inorder(root);
            printf("\n");
            break;
        case 6:
            exit(1);
        }
    }

    return 0;
}