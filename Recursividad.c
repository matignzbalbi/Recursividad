#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Ejercicio 1
bool esPalindromo(const char* palabra, int inicio, int fin) {

    // Caso base
    if (inicio == fin) {
        return true;
    }

    if (palabra[inicio] != palabra[fin]) {
        return false;
    }

    return esPalindromo(palabra, inicio + 1, fin - 1);
}


// Ejercicio 2

int producto(int m, int n) {
    // Caso base
    if (n == 0) {
        return 0;
    }

    // Recursividad
    return m + producto(m, n - 1);
}

// Ejercicio 3

int terminoSerieFibonacci(int k) {
    
    // Caso base
    
    if (k == 1 || k == 2) {
        return 1;
    }
    
    // Recursividad 
    return terminoSerieFibonacci(k - 1) + terminoSerieFibonacci(k - 2);
}

// Ejercicio 5

char* agregarSeparadorMiles(const char* numero) {
    int len = strlen(numero); 

    // Caso base
    if (len <= 3) {
        char* resultado = malloc(len + 1); 
        strcpy(resultado, numero);       
        return resultado;
    }


    // Recursividad 
    char ultimos3[4];
    strcpy(ultimos3, &numero[len - 3]); 
    
    char izquierda[len - 2]; 
    strncpy(izquierda, numero, len - 3); 
    izquierda[len - 3] = '\0'; 
    char* izquierdaConPuntos = agregarSeparadorMiles(izquierda);

    char* resultado = malloc(strlen(izquierdaConPuntos) + 1 + 3 + 1);
    sprintf(resultado, "%s.%s", izquierdaConPuntos, ultimos3); 

    free(izquierdaConPuntos); 
    return resultado;
}

// Ejercicio 7

char *reunionMafia(int nivel) {
    // Caso base
    if (nivel == 1) {
        char *base = (char *)malloc(6 * sizeof(char));
        strcpy(base, "(-.-)");
        return base;
    }
    
    // Recursividad 
    char *interno = reunionMafia(nivel - 1);
    

    int tam = strlen(interno) + 6; 
    char *resultado = (char *)malloc(tam * sizeof(char));
    
    strcpy(resultado, "(-.");
    strcat(resultado, interno);
    strcat(resultado, ".-)");

    // Liberamos memoria 
    free(interno);

    return resultado;
}

// Ejercicio 9

bool divisiblePor7(int numero) {
    if (numero < 70) {
        return numero % 7 == 0;
    }

    int ultimaCifra = numero % 10;
    int resto = numero / 10;

    int nuevoNumero = resto - 2 * ultimaCifra;

    return divisiblePor7(nuevoNumero);
}

