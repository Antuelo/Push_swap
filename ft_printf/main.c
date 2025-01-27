#include "libftprintf.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    int result;

    // Test 1: Cadena normal con ft_printf
    result = ft_printf("Hola mundo\n");
    printf("Resultado esperado: 11; Resultado obtenido: %d\n\n", result);

    // Test 2: Cadena vacía con ft_printf
    result = ft_printf("\n");
    printf("Resultado esperado: 0; Resultado obtenido: %d\n\n", result - 1);

    // Test 3: Cadena NULL con ft_printf
    result = ft_printf("%s\n", NULL);
    printf("Resultado esperado: 6; Resultado obtenido: %d\n\n", result - 1);

    // Test 4: Cadena larga con ft_printf
    const char *cadena_larga = "Esta es una cadena muy larga que se utiliza para probar si la funcion puede manejar grandes cantidades de caracteres sin problemas.";
    result = ft_printf("%s\n", cadena_larga);
    printf("Resultado esperado: %zu; Resultado obtenido: %d\n\n", strlen(cadena_larga), result - 1);

    // Test 5: Caracter individual con ft_printf
    char letra = 'A';
    result = ft_printf("%c\n", letra);
    printf("Resultado esperado: 1; Resultado obtenido: %d\n\n", result - 1);

    // Test 6: Entero positivo con ft_printf
    int numero = 12345;
    result = ft_printf("%d\n", numero);
    printf("Resultado esperado: 5; Resultado obtenido: %d\n\n", result - 1);

    // Test 7: Entero negativo con ft_printf
    numero = -12345;
    result = ft_printf("%d\n", numero);
    printf("Resultado esperado: 6; Resultado obtenido: %d\n\n", result - 1);

    // Test 8: Entero sin signo con ft_printf
    unsigned int unum = 4294967295;
    result = ft_printf("%u\n", unum);
    printf("Resultado esperado: 10; Resultado obtenido: %d\n\n", result - 1);

    // Test 9: Puntero NULL con ft_printf
    void *ptr = NULL;
    result = ft_printf("%p\n", ptr);
    printf("Resultado esperado: 5; Resultado obtenido: %d\n\n", result - 1);

    // Test 10: Puntero válido con ft_printf
    ptr = &numero;
    result = ft_printf("%p\n", ptr);
    printf("Resultado esperado: depende de la direccion de memoria; Resultado obtenido: %d\n\n", result - 1);

    // Test 11: Hexadecimal en minúsculas con ft_printf
    numero = 255;
    result = ft_printf("%x\n", numero);
    printf("Resultado esperado: 2; Resultado obtenido: %d\n\n", result - 1);

    // Test 12: Hexadecimal en mayúsculas con ft_printf
    result = ft_printf("%X\n", numero);
    printf("Resultado esperado: 2; Resultado obtenido: %d\n\n", result - 1);

    // Test 13: Porcentaje con ft_printf
    result = ft_printf("%%\n");
    printf("Resultado esperado: 1; Resultado obtenido: %d\n\n", result - 1);

    return 0;
}

/* #include "libftprintf.h"

int main(void)
{
    char *palabra = "hola";
    int num;

    // Test con %s (cadena de caracteres)
    num = printf("%s\n", palabra);
    printf("la cantidad de letras de la palabra %s, es de %d\n\n", palabra, num - 1);
    printf("ahora con mi funcion: \n\n");
    num = ft_printf("%s\n", palabra);
    ft_printf("la cantidad de letras de la palabra %s, es de %d\n", palabra, num - 1);

    ft_printf("--------------------------------------------------------\n");

    // Test con %s (cadena vacía)
    palabra = "";
    num = printf("%s\n", palabra);
    printf("la cantidad de letras de la cadena vacia es %d\n\n", num - 1);
    printf("ahora con mi funcion: \n\n");
    num = ft_printf("%s\n", palabra);
    ft_printf("la cantidad de letras de la cadena vacia es %d\n", num - 1);

    ft_printf("--------------------------------------------------------\n");

    // Test con %s (cadena NULL)
    palabra = NULL;
    num = printf("%s\n", palabra);
    printf("la cantidad de letras de la cadena NULL es %d\n\n", num - 1);
    printf("ahora con mi funcion: \n\n");
    num = ft_printf("%s\n", palabra);
    ft_printf("la cantidad de letras de la cadena NULL es %d\n", num - 1);

    ft_printf("--------------------------------------------------------\n");

    // Test con %c (caracter)
    char letra = 'a';
    num = printf("%c\n", letra);
    printf("la cantidad de letras de la palabra %c, es de %d\n\n", letra, num - 1);
    printf("ahora con mi funcion: \n\n");
    num = ft_printf("%c\n", letra);
    ft_printf("la cantidad de letras de la palabra %c, es de %d\n", letra, num - 1);

    ft_printf("--------------------------------------------------------\n");

    // Test con %d (entero positivo)
    int numero = 8616168;
    num = printf("%d\n", numero);
    printf("la cantidad de letras del numero %d, es de %d\n\n", numero, num - 1);
    printf("ahora con mi funcion: \n\n");
    num = ft_printf("%d\n", numero);
    ft_printf("la cantidad de letras del numero %d, es de %d\n", numero, num - 1);

    ft_printf("--------------------------------------------------------\n");

    // Test con %d (entero negativo)
    numero = -68163;
    num = printf("%d\n", numero);
    printf("la cantidad de letras del numero %d, es de %d\n\n", numero, num - 1);
    printf("ahora con mi funcion: \n\n");
    num = ft_printf("%d\n", numero);
    ft_printf("la cantidad de letras del numero %d, es de %d\n", numero, num - 1);

    ft_printf("--------------------------------------------------------\n");

    // Test con %p (puntero)
    void *hexa;
    hexa = &numero;
    num = printf("%p\n", hexa);
    printf("la cantidad de letras de la direccion %p, es de %d\n\n", hexa, num - 1);
    printf("ahora con mi funcion: \n\n");
    num = ft_printf("%p\n", hexa);
    ft_printf("la cantidad de letras de la direccion %p, es de %d\n", hexa, num - 1);

    ft_printf("--------------------------------------------------------\n");

    // Test con %p (puntero NULL)
    hexa = NULL;
    num = printf("%p\n", hexa);
    printf("la cantidad de letras de la direccion NULL es %d\n\n", num - 1);
    printf("ahora con mi funcion: \n\n");
    num = ft_printf("%p\n", hexa);
    ft_printf("la cantidad de letras de la direccion NULL es %d\n", num - 1);

    ft_printf("--------------------------------------------------------\n");

    // Test con %u (entero sin signo)
    unsigned int unum = 4294967295;
    num = printf("%u\n", unum);
    printf("la cantidad de digitos del numero %u, es de %d\n\n", unum, num);
    printf("ahora con mi funcion: \n\n");
    num = ft_printf("%u\n", unum);
    ft_printf("la cantidad de digitos del numero %u, es de %d\n", unum, num);

    ft_printf("--------------------------------------------------------\n");

    // Test con %x (hexadecimal en minúsculas)
    num = printf("%x\n", numero);
    printf("la cantidad de letras del numero en hexadecimal %x, es de %d\n\n", numero, num);
    printf("ahora con mi funcion: \n\n");
    num = ft_printf("%x\n", numero);
    ft_printf("la cantidad de letras del numero en hexadecimal %x, es de %d\n", numero, num);

    ft_printf("--------------------------------------------------------\n");

    // Test con %X (hexadecimal en mayúsculas)
    num = printf("%X\n", numero);
    printf("la cantidad de letras del numero en hexadecimal %X, es de %d\n\n", numero, num);
    printf("ahora con mi funcion: \n\n");
    num = ft_printf("%X\n", numero);
    ft_printf("la cantidad de letras del numero en hexadecimal %X, es de %d\n", numero, num);

    ft_printf("--------------------------------------------------------\n");

    // Test con %% (porcentaje)
    num = printf("%%\n");
    printf("la cantidad de caracteres del porcentaje es de %d\n\n", num);
    printf("ahora con mi funcion: \n\n");
    num = ft_printf("%%\n");
    ft_printf("la cantidad de caracteres del porcentaje es de %d\n", num);

    return 0;
}

//  gcc -Wall -Wextra -Werror -o test_ftprintf main.c -L. -lftprintf */