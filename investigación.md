## <string.h>

La biblioteca estándar de C, a través del archivo de encabezado <string.h>, proporciona una serie de funciones útiles para manipular cadenas de caracteres (arrays de tipo char terminados en un carácter nulo \0)

1. strlen: Calcula la longitud de una cadena de caracteres. No incluye el carácter nulo de terminación.

2. strcpy: Copia la cadena de caracteres apuntada por src (incluyendo el carácter nulo) al array apuntado por dest. ¡Es importante asegurarse de que dest tenga suficiente espacio para contener la cadena copiada!

3. strncpy: Copia hasta n caracteres de la cadena apuntada por src al array apuntado por dest. Si la longitud de src es menor que n, se rellenará dest con caracteres nulos hasta completar n. Si la longitud de src es mayor o igual que n, dest no estará terminado con un carácter nulo.

4. strcat: Concatena (añade) la cadena apuntada por src al final de la cadena apuntada por dest. El carácter nulo final de dest es sobrescrito por el primer carácter de src, y un nuevo carácter nulo se añade al final de la nueva cadena combinada. ¡Al igual que con strcpy, asegúrate de que dest tenga suficiente espacio!

5. strncat: Concatena como máximo n caracteres de la cadena apuntada por src al final de la cadena apuntada por dest. Se añade un carácter nulo al final de la cadena resultante. Si src contiene menos de n caracteres, solo se concatenarán los caracteres presentes hasta el carácter nulo.

6. strcmp: Compara dos cadenas de caracteres s1 y s2.
Valor de retorno:
Devuelve 0 si las cadenas son iguales.
Devuelve un valor negativo si s1 es lexicográficamente menor que s2.
Devuelve un valor positivo si s1 es lexicográficamente mayor que s2.

7. strncmp: Compara los primeros n caracteres de las cadenas s1 y s2.
Valor de retorno: Similar a strcmp, pero la comparación se detiene después de n caracteres o al encontrar un carácter nulo.

8. strchr: Localiza la primera ocurrencia del carácter c en la cadena apuntada por s.
Valor de retorno: Devuelve un puntero a la primera ocurrencia del carácter c en s, o NULL si el carácter no se encuentra

9. strstr
Propósito: Localiza la primera ocurrencia de la subcadena needle dentro de la cadena haystack.
Valor de retorno: Devuelve un puntero al comienzo de la primera ocurrencia de needle en haystack, o NULL si needle no se encuentra.

10. strtok
Propósito: Divide una cadena de caracteres en una secuencia de tokens (subcadenas) delimitados por caracteres especificados en delim. Es importante tener en cuenta que strtok modifica la cadena original.

11. 

12. calloc:
calloc es una función que se utiliza para reservar y inicializar memoria dinámica.La función calloc es similar a la función malloc, pero con una importante diferencia.
Mientras que malloc solo reserva memoria, calloc reserva memoria y la inicializa con ceros

