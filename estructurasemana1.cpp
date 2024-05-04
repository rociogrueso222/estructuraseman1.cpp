#include <stdio.h>
#include <stdlib.h>
Using namespace std;

// Estructura de un nodo del árbol
typedef struct NodoArbol {
    int codigoRNT;
    int fechaVencimiento;
    struct NodoArbol* izquierda;
    struct NodoArbol* derecha;
} NodoArbol;

// Función para crear un nuevo nodo
NodoArbol* crearNodo(int codigoRNT, int fechaVencimiento) {
    NodoArbol* nuevoNodo = (NodoArbol*)malloc(sizeof(NodoArbol));
    nuevoNodo->codigoRNT = codigoRNT;
    nuevoNodo->fechaVencimiento = fechaVencimiento;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->derecha = NULL;
    return nuevoNodo;
}

// Función para insertar un nodo en el árbol
NodoArbol* insertarNodo(NodoArbol* raiz, int codigoRNT, int fechaVencimiento) {
    if (raiz == NULL) {
        return crearNodo(codigoRNT, fechaVencimiento);
    }

    if (codigoRNT < raiz->codigoRNT) {
        raiz->izquierda = insertarNodo(raiz->izquierda, codigoRNT, fechaVencimiento);
    } else {
        raiz->derecha = insertarNodo(raiz->derecha, codigoRNT, fechaVencimiento);
    }

    return raiz;
}

// Función para recorrer el árbol en preorden
void preorden(NodoArbol* raiz) {
    if (raiz != NULL) {
        printf("(%d, %d) ", raiz->codigoRNT, raiz->fechaVencimiento);
        preorden(raiz->izquierda);
        preorden(raiz->derecha);
    }
}

// Función para recorrer el árbol en inorden
void inorden(NodoArbol* raiz) {
    if (raiz != NULL) {
        inorden(raiz->izquierda);
        printf("(%d, %d) ", raiz->codigoRNT, raiz->fechaVencimiento);
        inorden(raiz->derecha);
    }
}

// Función para recorrer el árbol en posorden
void posorden(NodoArbol* raiz) {
    if (raiz != NULL) {
        posorden(raiz->izquierda);
        posorden(raiz->derecha);
        printf("(%d, %d) ", raiz->codigoRNT, raiz->fechaVencimiento);
    }
}

int main() {
    NodoArbol* raizPrincipal = NULL;
    NodoArbol* raizSubarbol = NULL;
    int opcion, codigoRNT, fechaVencimiento;

    do {
        printf("\nMENU\n");
        printf("1. Insertar nodo en el arbol principal\n");
        printf("2. Insertar nodo en el subarbol\n");
        printf("3. Recorrer arbol principal en preorden\n");
        printf("4. Recorrer arbol principal en inorden\n");
        printf("5. Recorrer arbol principal en posorden\n");
         printf("6. Salir\n");
         printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el codigo RNT del nodo: ");
                scanf("%d", &codigoRNT);
                printf("Ingrese la fecha de vencimiento del nodo: ");
                scanf("%d", &fechaVencimiento);
                raizPrincipal = insertarNodo(raizPrincipal, codigoRNT, fechaVencimiento);
                break;
            case 2:
                printf("Ingrese el codigo RNT del nodo: ");
                scanf("%d", &codigoRNT);	
                printf("Ingrese la fecha de vencimiento del nodo: ");
                scanf("%d", &fechaVencimiento);
                raizSubarbol = insertarNodo(raizSubarbol, codigoRNT, fechaVencimiento);
                break;
            case 3:
                printf("Recorrido en preorden del arbol principal: ");
                preorden(raizPrincipal);
                printf("\n");
                break;
            case 4:
                printf("Recorrido en inorden del arbol principal: ");
                inorden(raizPrincipal);
                printf("\n");
                break;
            case 5:
                printf("Recorrido en posorden del arbol principal: ");
                posorden(raizPrincipal);
                printf("\n");
                break;
           case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Por favor, ingrese una opcion valida.\n");
        }
        
               
            
        }
    } while (opcion !=6 );


    return 0;
}
