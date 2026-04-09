#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Prototipos de funciones
int generar_aleatorio(int min, int max);
int es_fin(char *entrada);

int main() {
    int inf, sup, secreto, intentos = 0, numero_usuario;
    char entrada[50];

    // Inicializar semilla para números aleatorios
    srand(time(NULL));

    printf("Ingrese el Limite Inferior: ");
    scanf("%d", &inf);
    printf("Ingrese el Limite Superior: ");
    scanf("%d", &sup);
    getchar(); // Limpiar el buffer del salto de línea

    secreto = generar_aleatorio(inf, sup);

    printf("-------------------------------------------------------------\n");
    printf("Adivina el numero entre %d y %d\n", inf, sup);
    printf("-------------------------------------------------------------\n");

    while (1) {
        printf("Introduce un numero o pulsa FIN para salir: ");
        if (fgets(entrada, sizeof(entrada), stdin) == NULL) break;
        
        // Quitar el salto de línea al final de la entrada
        entrada[strcspn(entrada, "\n")] = 0;

        // Verificar si el usuario quiere salir
        if (es_fin(entrada)) {
            printf("Programa finalizado por el usuario.\n");
            break;
        }

        // Convertir entrada a entero
        numero_usuario = atoi(entrada);
        intentos++;

        // Lógica del juego
        if (numero_usuario < inf || numero_usuario > sup) {
            printf("Fuera de rango. Intentalo de nuevo\n");
        } else if (numero_usuario < secreto) {
            printf("El numero buscado es mayor\n");
        } else if (numero_usuario > secreto) {
            printf("El numero buscado es menor\n");
        } else {
            printf("HAS ACERTADO!!! Despues de %d intentos\n", intentos);
            break;
        }
    }

    return 0;
}

// Función para generar un número aleatorio en un rango cerrado [min, max]
int generar_aleatorio(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Función para verificar si la cadena es "FIN" (sin importar mayúsculas/minúsculas)
int es_fin(char *entrada) {
    char temp[50];
    strcpy(temp, entrada);
    for (int i = 0; temp[i]; i++) {
        temp[i] = tolower(temp[i]);
    }
    return strcmp(temp, "fin") == 0;
}