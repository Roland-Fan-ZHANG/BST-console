#ifndef TREE_H
#define TREE_H

typedef struct _node {
    int data;                /* data stored : an integer    */
    struct _node *left;      /* pointer to the left child   */
    struct _node *right;     /* pointer to the right child  */
} node;

/*
 * Allocate memory for a new node.
 */
node *create_node(int data, node *left, node *right);

/* Display the nodes of the tree t following a pre-order traversal */
void display_prefix(node *t);

/* Display the nodes of the tree t following a in-order traversal */
void display_infix(node *t);

/* Display the nodes of the tree t following a post-order traversal */
void display_suffix(node *t);

node *scan_tree(void);

int count_nodes(node *t);
int count_leaves(node *t);
int count_only_children(node *t);
int height(node *t);

void free_tree(node *t);

// TP 2 
// Exercice 1
node *find_bst(node *t, int elt);

// Exercice 2
node *insert_bst(node *t, int elt);

// Exercice 4
int is_bst(node* t);
int is_bst_aux(node* t, node* lb, node* ub);

// Exercice 5
void fill_random_permutation(int *array, int size);
node *insert_random_permutation(int n);
node *insert_order(int n);

// Exercice 6
node *find_min(node *t);
node *extract_min_bst(node *t, node **min);
node *remove_bst(node *t, int data);

// Exercice 7
int equal(char *s1, char *s2);
int less(char *s1, char *s2);

#endif /* TREE_H */
