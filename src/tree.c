#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

node *create_node(int data, node *left, node *right) {
    node *n = (node *)malloc(sizeof(node));
    assert(n != NULL);
    n->data = data;
    n->left = left;
    n->right = right;
    return n;
}

void display_prefix(node *t){
    if(t == NULL) return;
    printf("%d ", t->data);
    display_prefix(t->left);
    display_prefix(t->right); 
}

void display_infix(node *t){
    if(t == NULL) return;
    display_infix(t->left);
    printf("%d ", t->data);
    display_infix(t->right); 
}

void display_suffix(node *t){
    if(t == NULL) return;
    display_suffix(t->left);
    display_suffix(t->right); 
    printf("%d ", t->data);
}

node *scan_tree(void) {
    int x;
    scanf("%d", &x);
    if (x == 0) {
        return NULL;
    } else {
        node *left = scan_tree();
        node *right = scan_tree();
        return create_node(x, left, right);
    }
}

int count_nodes(node *t){
    if (t == NULL)
        return 0;
    else
        return 1 + count_nodes(t->left) + count_nodes(t->right);
}

int count_leaves(node *t){
    if (t == NULL)
        return 0;
    else if (t->left == NULL && t->right == NULL)
        return 1;
    else
        return count_leaves(t->left) + count_leaves(t->right);
}

int count_only_children(node *t){
    if (t == NULL)
        return 0;
    else if ((t->left == NULL && t->right != NULL) || (t->left != NULL && t->right == NULL))
        return 1 + count_only_children(t->left) + count_only_children(t->right);
    else
        return count_only_children(t->left) + count_only_children(t->right);
}

int max(int a, int b){
    return (a > b) ? a : b;
}

int height(node *t){
    if (t == NULL)
        return -1;
    else
        return 1 + max(height(t->left), height(t->right));
}

void free_tree(node *t){
    if (t == NULL)
        return;
    free_tree(t->left);
    free_tree(t->right);
    free(t);
}

node *find_bst(node *t, int elt){
    node *ptr = t;
    while (ptr != NULL && ptr->data != elt)
    {
         if(ptr->data > elt){
            ptr = ptr->left;
         }else{
            ptr = ptr->right;
         }
    }
    return ptr;
}

node *insert_bst(node *t, int elt){
    if(t == NULL){
        return create_node(elt, NULL, NULL);
    }else if(t->data > elt){
        t->left = insert_bst(t->left, elt);
    }else if(t->data < elt){
        t->right = insert_bst(t->right, elt);
    }
    return t;
}

// Exercice 4
int is_bst(node* t){
    return is_bst_aux(t, NULL, NULL);
}

int is_bst_aux(node* t, node* lb, node* ub){
    if(t == NULL){
        return 1;
    }
    if((lb != NULL && t->data < lb->data) || (ub != NULL && t->data > ub->data)){
        return 0;
    }else{
        return is_bst_aux(t->left, lb, t) && is_bst_aux(t->right, t, ub);
    }
}

void fill_random_permutation(int *array, int size){
    for (int i = 0; i < size; i++){	
        array[i] = i + 1;
    }
    for (int i = size - 1; i > 0; i--){
        int j=rand()%(i + 1);
        int temp=array[i];
        array[i]=array[j];
        array[j]=temp;
    }
}

node *insert_random_permutation(int n){
    node *t = NULL;
    int *array = (int*)malloc(n*sizeof(int));
        for (int i = 0; i < n; i++) {
        t = insert_bst(t, array[i]); 
    }
    fill_random_permutation(array, n);
    for(int i = 0; i < n; i++){
        t = insert_bst(t, array[i]);
    }
    
    free(array);
    return t;
}

node *insert_order(int n){
    node *t = NULL;
    for(int i = 1; i < n; i++){
        t = insert_bst(t, i);
    }
    return t;
}

node *find_min(node *t) {
    while (t->left != NULL) {
        t = t->left;
    }
    return t;
}

node *extract_min_bst(node *t, node **min) {
    if (t == NULL) {
        *min = NULL;
        return NULL;
    }
    node *parent = NULL;
    node *current = t;
    while (current->left != NULL) {
        parent = current;
        current = current->left;
    }
    *min = current;
    if (parent != NULL) {
        parent->left = current->right;
    } else {
        t = current->right;
    }
    current->left = current->right = NULL;
    return t;
}

node *remove_bst(node *t, int data) {
    if (t == NULL) {
        return NULL;
    }
    if (data < t->data) {
        t->left = remove_bst(t->left, data);
    } else if (data > t->data) {
        t->right = remove_bst(t->right, data);
    } else {
        if (t->left == NULL) {
            node *tmp = t->right;
            free(t);
            return tmp;
        } else if (t->right == NULL) {
            node *tmp = t->left;
            free(t);
            return tmp;
        }
        node *min_right = find_min(t->right);
        t->data = min_right->data;
        t->right = remove_bst(t->right, min_right->data);
    }
    return t;
}
