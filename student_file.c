#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;
//int* result;
//int indice = 0;

// función: insert, agrega elementos en un árbol con puntero inicial root
void insert(int data) {
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

void postorder_recorrido(struct node * raiz) { //Type 2
    if(raiz != NULL) {
        //PREORDEN
        postorder_recorrido(raiz->left);
        //INORDEN
        postorder_recorrido(raiz->right);
        //POSTORDEN
        printf("%i, ", raiz->value);
        //result[indice] = raiz->value;
        //indice++;
    }
}

void preorder_recorrido(struct node * raiz) {//Type 1
    if(raiz != NULL) {
        //PREORDEN
        printf("%i \n", raiz->value);
        preorder_recorrido(raiz->left);
        //INORDEN:
        preorder_recorrido(raiz->right);
        //POSTORDEN
        
    }
}

//Hago el cambio de char a int -> me parece que el cambio de char a int es a base de funciones ya establecidas en librerias o por defecto se tendria
//que hacer un codigo con todas las posibles excepciones.

//volvi el bst_fun a void porque tenia la posibilida dde hacerlo de frente con la impresion enla consola del metodo postorder
void bst_fun(int* nodes) {
    for(int i = 0; i < 9; i++) {
        insert(nodes[i]);
    }
    postorder_recorrido(root);
   // return result;
}

int main() {

    int entrada[9] = {50,30,24,5,28,45,98,52,60};

    printf("\nRecorrido tipo 1: \n");
    for(int i = 0; i < 9; i++) {
        printf("%i, ", entrada[i]);
    }

    printf("\nRecorrido tipo 2: \n");
    bst_fun(entrada);

    /*
    for(int i = 0; i < 9; i++) {
        printf("%i\n", result[i]);
    }*/

    return 0;
}