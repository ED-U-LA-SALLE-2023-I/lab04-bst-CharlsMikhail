#include <stdio.h>
#include <stdlib.h>

struct node {
    char value;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

// función: insert, agrega elementos en un árbol con puntero inicial root
void insert(char data) {
    struct node *tempNode = (struct node*) malloc(sizeof(struct node));
    struct node *actual;
    struct node *padre;

   //agregamos los valores en node

    tempNode->value = data;
    tempNode->left = NULL;
    tempNode->right = NULL;

   //si el árbol está vacio

   if(root == NULL) {
        root = tempNode;
        actual = root; //no es obligatorio
        padre = root;
   } else {
        actual = root;//siempre iniciamos en la raiz
        padre = NULL;//aun no hay un padre
        while(1) {
            padre = actual;

            //recorrido por la izquierda del árbol

            if(data < padre->value) {
                actual = actual->left;//vole

                //insertamos en izquierda

                if(actual == NULL) {
                    padre->left = tempNode;
                    return;
                }
            }

            //recorrido por la derecha del árbol

            else {
                actual = actual->right;

                //insertamos en derecha

                if(actual == NULL) {
                    padre->right = tempNode;
                    return;
                }
            }
        }
    }
}

void inorder_recorrido(struct node* raiz) {
    if(raiz != NULL) {
        //PREORDEN
        inorder_recorrido(raiz->left);
        //INORDEN
        printf("%i \n", raiz->value);
        inorder_recorrido(raiz->right);
        //POSTORDEN
    }
}

void postorder_recorrido(struct node * raiz) {
    if(raiz != NULL) {
        //PREORDEN
        inorder_recorrido(raiz->left);
        //INORDEN
        inorder_recorrido(raiz->right);
        //POSTORDEN
        printf("%i \n", raiz->value);
    }
}

void preorder_recorrido(struct node * raiz) {
    if(raiz != NULL) {
        //PREORDEN
        printf("%i \n", raiz->value);
        inorder_recorrido(raiz->left);
        //INORDEN: raiz
        inorder_recorrido(raiz->right);
        //POSTORDEN
        
    }
}

char* bst_fun(char* nodes) {
    char* result;
    for(int i = 0; i < sizeof(nodes); i++) {
        if(nodes[i] =! ',') {
            insert(nodes[i]);
        } 
    }
    return result;
}

int main() {
   
    char* entrada = "4,5,76,2";

    char* salida = bst_fun(entrada);

    printf("Salida: %s", salida);

    return 0;
}