#include "src/tree.h"
#include "src/visualtree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <math.h>

#define NB_MAX 100

void display(){
    printf("\nMenu :\n");
    printf("\n    1. Construire un nouvel arbre à partir d'une suite d'entiers\n");
    printf("    2. Construire un arbre avec un nombre d'entiers aléatoires\n");
    printf("    3. Insérer un élément dans l'arbre\n");
    printf("    4. Faire une recherche dans l'arbre\n");
    printf("    5. Affiche l'arbre en ordre croissant\n");
    printf("    6. Supprimer un élément dans l'arbre\n");
    printf("    7. Terminer le programme\n\n");
}

void create_tree(node **t){
    printf("Saisir une suite d'entiers : \n");
    *t = scan_tree();
    write_tree(*t);
}

void create_random_tree(node **t){
    printf("Saisir un nombre à générer: \n");
    int n;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
    {
        int random_value = rand() % NB_MAX;
        *t = insert_bst(*t, random_value);
    }
    write_tree(*t);
}

void insert_in_tree(node **t){
    printf("Saisir une valeur à insérer : \n");
    int value;
    scanf(" %d", &value);
    *t = insert_bst(*t, value);
    write_tree(*t);
}

void search_in_tree(node *t){
    printf("Saisir une valeur à rechercher : \n");
    int value;
    scanf(" %d", &value);
    if(find_bst(t, value))
        printf("%d est présent dans l'arbre\n", value);
    else
        printf("%d n'est pas présent dans l'arbre\n", value);
}

void display_order(node *t){
    printf("L'arbre en ordre croissant : \n");
    display_infix(t);
    printf("\n");
}

void delete_in_tree(node **t){
    printf("Saisir une valeur à supprimer : \n");
    int value;
    scanf(" %d", &value);
    *t = remove_bst(*t, value);
    write_tree(*t);
}

void end_program(node **t, int *state){
    *state = 0;
    free_tree(*t);
}

void program(){
    int state = 1;
    node *t = NULL;
    srand(time(NULL));
    int choice;

    while(state == 1){
        printf("Entrez votre choix: ");
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n');
            printf("Choix invalide. Veuillez entrer un nombre entre 1 et 7.\n");
            continue;
        }
        switch(choice) {
        case 1:
            create_tree(&t);
            break;
        case 2:
            create_random_tree(&t);
            break;
        case 3:
            insert_in_tree(&t);
            break;
        case 4:
            search_in_tree(t);
            break;
        case 5:
            display_order(t);
            break;
        case 6:
            delete_in_tree(&t);
            break;
        case 7:
            end_program(&t, &state);
            break;
        default:
            printf("Choix invalide. Veuillez entrer un nombre entre 1 et 7.\n");
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    display();
    program();

    return 0;
}
