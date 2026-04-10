#include <stdio.h>
#define TAM 3

void lectura(int [TAM][TAM]);
void muestra(int [TAM][TAM]);
void proceso(int [TAM][TAM], int *);
int suma_filas(int [TAM][TAM], int);
int suma_columnas(int [TAM][TAM], int);
int suma_diagonales(int [TAM][TAM], int);
void resultado(int [TAM][TAM], int);

int main() {
    int matriz[TAM][TAM];
    int respuesta = 0;

    lectura(matriz);
    //muestra(matriz);
    proceso(matriz, &respuesta);
    resultado(matriz, respuesta);
    return 0;
}

void lectura(int matriz[TAM][TAM]) {
    int i, j;
    printf("Elementos de la matriz:\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("Posicion [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void muestra(int matriz[TAM][TAM]){
    int i, j;
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%3d", matriz[i][j]);
        }
        printf("\n");
    }
    printf("Eso es todo ...\n");
}

void proceso(int matriz[TAM][TAM], int *respuesta) {
    int j;
    int valor = 0;
    for (j = 0; j < TAM; j++) {
        valor = valor + matriz[0][j];
    }

    if (suma_filas(matriz, valor) && suma_columnas(matriz, valor) && suma_diagonales(matriz, valor)) {
        *respuesta = 1;
    } 
    else {
        *respuesta = 0;
    }
}

int suma_filas(int matriz[TAM][TAM], int valor) {
    int i, j, suma;
    for (i = 0; i < TAM; i++) {
        suma = 0;
        for (j = 0; j < TAM; j++) {
            suma = suma + matriz[i][j];
        }
        if (suma != valor) 
            return 0;
    }
    return 1;
}

int suma_columnas(int matriz[TAM][TAM], int valor) {
    int i, j, suma;
    for (j = 0; j < TAM; j++) {
        suma = 0;
        for (i = 0; i < TAM; i++) {
            suma = suma + matriz[i][j];
        }
        if (suma != valor) 
            return 0;
    }
    return 1;
}

int suma_diagonales(int matriz[TAM][TAM], int valor) {
    int i;
    int diag1 = 0, diag2 = 0;
    for (i = 0; i < TAM; i++) {
        diag1 = diag1 + matriz[i][i];
        diag2 = diag2 + matriz[i][TAM - 1 - i];
    }
    return (diag1 == valor && diag2 == valor);
}

void resultado(int matriz[TAM][TAM], int respuesta) {
    printf("La matriz: \n");
    muestra(matriz);
    if (respuesta) {
        printf("\nEs un cuadrado magico.\n");
    } else {
        printf("\nNO es un cuadrado magico.\n");
    }
}