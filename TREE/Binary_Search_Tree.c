#include <stdio.h>
#include <stdlib.h>

/* Basic BST node */
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

/* Allocate a new node and initialize it with `value`. Returns pointer or NULL on failure. */
Node *Create_Node_With_Value(int value)
{
    Node *ptr = malloc(sizeof(Node));
    if (!ptr)
    {
        printf("Memory Allocation Failed\n");
        return NULL;
    }
    ptr->data = value;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

/* Prompt the user with `msg`, read an integer, and return a new node with that value. */
Node *Create_Node(const char *msg)
{
    int value;
    printf("%s", msg);
    scanf("%d", &value);
    return Create_Node_With_Value(value);
}

/*
 * Helper for isBST.
 * Performs an inorder traversal. `prev` is a pointer to a Node* that stores
 * the previously visited node in the inorder sequence.
 * If the inorder sequence ever decreases (current <= prev), it's not a BST.
 * Returns 1 if subtree is BST, 0 otherwise.
 */
int isBSTUtil(Node *root, Node **prev)
{
    if (root != NULL)
    {
        /* Check left subtree first */
        if (!isBSTUtil(root->left, prev))
            return 0;

        /* If previous node exists and current data is not strictly greater -> not BST */
        if (*prev != NULL && root->data <= (*prev)->data)
            return 0;

        /* Update previous to current before moving to right subtree */
        *prev = root;

        /* Check right subtree */
        return isBSTUtil(root->right, prev);
    }
    /* Empty subtree is BST */
    return 1;
}

/* Public wrapper: initializes prev as NULL and calls helper. */
int isBST(Node *root)
{
    Node *prev = NULL;
    return isBSTUtil(root, &prev);
}

/*
 * Insert `key` into BST. This is iterative:
 * - Walk down from root to find parent (`prev`) where the new node should be attached.
 * - If key already exists, print message and return.
 * Note: This function assumes `root` is not NULL (the program always starts with a root).
 */
void Insert(Node *root, int key)
{
    Node *prev = NULL;

    /* Traverse to find insertion point or detect duplicate */
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Insertion failed: %d already exists.\n", key);
            return;
        }
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }

    /* Create new node and attach to prev (left or right) */
    Node *newNode = Create_Node_With_Value(key);

    if (key < prev->data)
        prev->left = newNode;
    else
        prev->right = newNode;

    printf("Inserted %d successfully.\n", key);
}

/*
 * Find the inorder predecessor: the maximum node in the left subtree.
 * Called when deleting a node with two children; we replace the node's data
 * with its inorder predecessor's data.
 */
Node *inOrderPredecessor(Node *root)
{
    root = root->left;  /* go to left subtree */
    while (root->right) /* then go as far right as possible */
        root = root->right;
    return root;
}

/*
 * Delete a node with value `value` from BST rooted at `root`.
 * Returns (possibly new) root to maintain links for recursive callers.
 * Cases:
 *  - value < root->data : delete from left subtree
 *  - value > root->data : delete from right subtree
 *  - value == root->data: delete this node:
 *      * If leaf -> free and return NULL
 *      * Else (has at least left child) -> replace data with inorder predecessor,
 *        then delete that predecessor recursively from left subtree.
 *
 * Note: This implementation uses inorder predecessor approach for nodes with two children.
 */
Node *Delete(Node *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value < root->data)
    {
        root->left = Delete(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = Delete(root->right, value);
    }
    else
    {
        printf("Deleting %d...\n", value);

        /* If node is a leaf, free it and return NULL to parent */
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        /* Node has at least one child: use inorder predecessor (max in left subtree) */
        Node *iPre = inOrderPredecessor(root);
        root->data = iPre->data;                     /* copy predecessor value */
        root->left = Delete(root->left, iPre->data); /* delete predecessor node */
    }

    return root;
}

/* Iterative search for key in BST. Returns pointer to node or NULL if not found. */
Node *Search(Node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

/* Recursively free all nodes in the tree (post-order) */
void free_node(Node *root)
{
    if (!root)
        return;
    free_node(root->left);
    free_node(root->right);
    free(root);
}

int main()
{
    /* Build a small tree by user input. The program expects these nodes exist. */
    Node *ROOT = Create_Node("Enter the root node data: ");
    ROOT->left = Create_Node("Enter the left child: ");
    ROOT->right = Create_Node("Enter the right child: ");
    ROOT->left->left = Create_Node("Enter left->left: ");
    ROOT->left->right = Create_Node("Enter left->right: ");

    /* Check if the built tree is a BST */
    if (isBST(ROOT))
        printf("The Tree IS a Binary Search Tree.\n");
    else
        printf("The Tree is NOT a Binary Search Tree.\n");

    /* Search */
    int key_search;
    printf("Enter key to search: ");
    scanf("%d", &key_search);
    if (Search(ROOT, key_search))
        printf("Key %d found.\n", key_search);
    else
        printf("Key %d not found.\n", key_search);

    /* Insert */
    int key_insert;
    printf("Enter key to insert: ");
    scanf("%d", &key_insert);
    Insert(ROOT, key_insert);

    /* Delete */
    int key_delete;
    printf("Enter key to delete: ");
    scanf("%d", &key_delete);
    ROOT = Delete(ROOT, key_delete); /* update ROOT because delete returns new subtree root */

    /* Cleanup memory before exit */
    free_node(ROOT);
    return 0;
}
