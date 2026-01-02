#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} node;

node* newnode(int v) {
    node* newl = (node*)malloc(sizeof(node));
    newl->value = v;
    newl->left = newl->right = NULL;
    return newl;
}

node* creeArbre(node* n) {
    return NULL;
}

node* addnoeud(node* n, int v) {
    if (n == NULL) {
        return newnode(v);
    } else {
        if (v < n->value) {
            n->left = addnoeud(n->left, v);
        } else if (v > n->value) {
            n->right = addnoeud(n->right, v);
        }
    }
    return n;
}

void deleteTree(node* n) {
    if (n != NULL) {
        deleteTree(n->left);
        deleteTree(n->right);
        free(n);
    }
}

int height(node *n) {
    if (n == NULL) {
        return 0;
    }
    int Hl = height(n->left);
    int Hr = height(n->right);
    return Hl > Hr ? Hl + 1 : Hr + 1;
}

int tailleTree(node* n) {
    if (n == NULL) {
        return 0;
    } else {
        return tailleTree(n->left) + tailleTree(n->right) + 1;
    }
}

int nbNodesInterne(node* n) {
    if (n == NULL || (n->left == NULL && n->right == NULL)) {
        return 0;
    } else {
        return nbNodesInterne(n->left) + nbNodesInterne(n->right) + 1;
    }
}

int nbNodesExterne(node* n) {
    if (n == NULL) {
        return 0;
    } else if (n->left == NULL && n->right == NULL) {
        return 1;
    } else {
        return nbNodesExterne(n->left) + nbNodesExterne(n->right);
    }
}

void bfs(node* n) {
    if (n != NULL) {
        printf("%d ", n->value);
        bfs(n->left);
        bfs(n->right);
    }
}

void Dfs(node* n) {
    if (n != NULL) {
        Dfs(n->left);
        printf("%d ", n->value);
        Dfs(n->right);
    }
}

void parcourPostfixe(node* n) {
    if (n != NULL) {
        parcourPostfixe(n->left);
        parcourPostfixe(n->right);
        printf("%d ", n->value);
    }
}

int rechercherElt(node* n, int v) {
    if (n == NULL) {
        return 0;
    }
    if (n->value == v) return 1;
    if (v < n->value) return rechercherElt(n->left, v);
    else return rechercherElt(n->right, v);
}

node* plusPetit(node* n) {
    if (n == NULL) {
        return NULL;
    }
    node* tmp = n;
    while (tmp->left != NULL) {
        tmp = tmp->left;
    }
    return tmp;
}

node* plusGrand(node* n) {
    if (n == NULL) {
        return NULL;
    }
    node* tmp = n;
    while (tmp->right != NULL) {
        tmp = tmp->right;
    }
    return tmp;
}

node* suppElt(node* n, int v) {
    if (n == NULL) {
        return NULL;
    }
    if (v < n->value) {
        n->left = suppElt(n->left, v);
    } else if (v > n->value) {
        n->right = suppElt(n->right, v);
    } else {
        if (n->left == NULL) {
            node* tmp = n->right;
            free(n);
            return tmp;
        } else if (n->right == NULL) {
            node* tmp = n->left;
            free(n);
            return tmp;
        } else {
            node* tmp = plusPetit(n->right);
            n->value = tmp->value;
            n->right = suppElt(n->right, tmp->value);
        }
    }
    return n;
}

void display(node* n, int space, int level) {
    if (n == NULL) {
        return;
    }
    space += 10;
    display(n->right, space, level + 1);
    printf("\n");
    int i;
    for (i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", n->value);
    display(n->left, space, level + 1);
}

int main() {
    node* n = creeArbre(n);
    n = addnoeud(n, 50);
    n = addnoeud(n, 30);
    n = addnoeud(n, 20);
    n = addnoeud(n, 40);
    n = addnoeud(n, 70);
    n = addnoeud(n, 60);
    n = addnoeud(n, 80);

    printf("Parcours Infixe: ");
    Dfs(n);
    printf("\n");

    printf("Hauteur de l'arbre: %d\n", height(n));
    printf("Taille de l'arbre: %d\n", tailleTree(n));
    printf("Nombre de noeuds internes: %d\n", nbNodesInterne(n));
    printf("Nombre de noeuds externes: %d\n", nbNodesExterne(n));
    printf("Le plus petit élément: %d\n", plusPetit(n)->value);
    printf("Le plus grand élément: %d\n", plusGrand(n)->value);

    if (rechercherElt(n, 40))
        printf("Élément 40 trouvé dans l'arbre.\n");
    else
        printf("Élément 40 non trouvé dans l'arbre.\n");

    printf("L'affichage de l'arbre binaire: \n");
    display(n, 0, 0);

    suppElt(n, 70);
    printf("Affichage de l'arbre binaire après la suppression de 70:\n");
    display(n, 0, 0);

    deleteTree(n);

    return 0;
}
