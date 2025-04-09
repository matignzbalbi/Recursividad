#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool esPalindromo(const char* palabra, int inicio, int fin) {
    if (inicio == fin) {
        return true;
    }

    if (palabra[inicio] != palabra[fin]) {
        return false;
    }

    return esPalindromo(palabra, inicio + 1, fin - 1);
}


