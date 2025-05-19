#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encabezado(void);
int menu(void); 
void leer_archivo(char **texto, char *nombre_archivo);
void estadistica_texto(const char *texto);
void frecuencia_vocales(const char *texto);
void cambiar_palabra(char **texto);
void guardar_resultados(const char *texto, const char *nombre_salida);

int main(void)
{
    int opcion;
    char nombre_archivo[100];
    char *texto = NULL;

    encabezado();
    printf("Ingrese el nombre del archivo de texto (.txt): ");
    scanf("%s", nombre_archivo);

    leer_archivo(&texto, nombre_archivo);
    if (texto == NULL) {
        printf("Error al leer el archivo.\n");
        return 1;
    }

    do {
        opcion = menu();
        switch (opcion) {
            case 1:
                estadistica_texto(texto);
                break;
            case 2:
                frecuencia_vocales(texto);
                break;
            case 3:
                cambiar_palabra(&texto);
                break;
            case 4: {
                char nombre_salida[100];
                printf("Ingrese el nombre del archivo de salida: ");
                scanf("%s", nombre_salida);
                guardar_resultados(texto, nombre_salida);
                break;
            }
            case 5:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 5);

    free(texto);
    return 0;
}

void encabezado(void)
{   
    printf("ANALIZADOR DE TEXTO EN CONSOLA\n");  
}

int menu(void)
{
    int opcion;
    printf("Menú de opciones:\n");
    printf("1. Calcular estadísticas del texto\n");
    printf("2. Calcular frecuencia de vocales\n");
    printf("3. Reemplazar una palabra\n");
    printf("4. Guardar resultados en archivo\n");
    printf("5. Salir\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);
    return opcion;
}

void leer_archivo(char **texto, char *nombre_archivo)
{
    FILE *archivo = fopen(nombre_archivo, "r");
    if (!archivo) {
        *texto = NULL;
        return;
    }

    fseek(archivo, 0, SEEK_END);
    long tam = ftell(archivo);
    rewind(archivo);

    *texto = (char *)malloc((tam + 1) * sizeof(char));
    fread(*texto, 1, tam, archivo);
    (*texto)[tam] = '\0';

    fclose(archivo);
}

void estadistica_texto(const char *texto)
{
    int caracteres = 0, palabras = 0, espacios = 0, lineas = 0;
    int en_palabra = 0;

    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] != '\n')
            caracteres++;
        if (isspace(texto[i])) {
            espacios++;
            en_palabra = 0;
            if (texto[i] == '\n')
                lineas++;
        } else if (!en_palabra) {
            palabras++;
            en_palabra = 1;
        }
    }

    printf("\n--- Estadísticas del texto ---\n");
    printf("Total de caracteres (sin \\n): %d\n", caracteres);
    printf("Total de palabras: %d\n", palabras);
    printf("Total de espacios: %d\n", espacios);
    printf("Total de líneas: %d\n", lineas + 1);
}

void frecuencia_vocales(const char *texto)
{
    int a = 0, e = 0, i = 0, o = 0, u = 0;
    for (int j = 0; texto[j] != '\0'; j++) {
        char c = tolower(texto[j]);
        switch (c) {
            case 'a': a++; break;
            case 'e': e++; break;
            case 'i': i++; break;
            case 'o': o++; break;
            case 'u': u++; break;
        }
    }
    printf("\n--- Frecuencia de vocales ---\n");
    printf("a: %d\n", a);
    printf("e: %d\n", e);
    printf("i: %d\n", i);
    printf("o: %d\n", o);
    printf("u: %d\n", u);
}

void cambiar_palabra(char **texto)
{
    char buscar[100], reemplazo[100];
    printf("Palabra a buscar: ");
    scanf("%s", buscar);
    printf("Palabra de reemplazo: ");
    scanf("%s", reemplazo);

    char *nuevo_texto = NULL;
    char *pos = *texto;
    int count = 0;

    while ((pos = strstr(pos, buscar)) != NULL) {
        count++;
        pos += strlen(buscar);
    }

    int nuevo_tam = strlen(*texto) + count * (strlen(reemplazo) - strlen(buscar)) + 1;
    nuevo_texto = malloc(nuevo_tam);
    nuevo_texto[0] = '\0';

    pos = *texto;
    char *temp;

    while ((temp = strstr(pos, buscar)) != NULL) {
        strncat(nuevo_texto, pos, temp - pos);
        strcat(nuevo_texto, reemplazo);
        pos = temp + strlen(buscar);
    }
    strcat(nuevo_texto, pos);

    free(*texto);
    *texto = nuevo_texto;

    printf("Reemplazo realizado con éxito.\n");
}

void guardar_resultados(const char *texto, const char *nombre_salida)
{
    FILE *salida = fopen(nombre_salida, "w");
    if (!salida) {
        printf("Error al crear el archivo.\n");
        return;
    }

    fprintf(salida, "--- Texto final ---\n\n%s\n", texto);
    fclose(salida);
    printf("Resultados guardados en '%s'\n", nombre_salida);
}