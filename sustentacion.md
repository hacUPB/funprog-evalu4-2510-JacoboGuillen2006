## Sustentación Técnica del Proyecto: Analizador de Texto en Consola

1. Análisis del Problema

    El objetivo principal del programa es leer un archivo de texto e interactuar con él mediante un menú de opciones para realizar distintos tipos de análisis y tambien manipular el archivo de texto desde el programa.


2. Solución al problema

    El programa está estructurado en torno a un ciclo principal que presenta un menú al usuario. Dependiendo de la opción seleccionada, aparecen funciones específicas. La estructura general se puede dividir en los siguientes bloques funcionales:

    main(): Control central del programa. Inicializa variables, llama a la lectura de archivo y ejecuta el menú.

    leer_archivo(): Carga el contenido de un archivo de texto a memoria.

    estadistica_texto(): Calcula número de caracteres, palabras, espacios y líneas.

    frecuencia_vocales(): Cuenta la cantidad de vocales.

    cambiar_palabra(): Reemplaza todas las apariciones de una palabra por otra.

    guardar_resultados(): Guarda el texto actualizado en un archivo nuevo.

    menu() y encabezado(): Manejan la interfaz de usuario.



3. Tablas de Variables

    Función: leer_archivo


   | Variable | Tipo | Rol |
   |----------|------|-----|
   | texto    | char**| salida |
   | nombre archivo    | char*  | entrada |


    Función: estadistica_texto


    | Variable     | Tipo   | Rol     |
    |--------------|--------|---------|
    | texto        | char*  | Entrada |
    | caracteres   | int    | Interna |
    | palabras     | int    | Interna |
    | espacios     | int    | Interna |
    | lineas       | int    | Interna |
    | en_palabra   | int    | Interna |

    Función: frecuencia_vocales

    | Variable     | Tipo   | Rol     |
    |--------------|--------|---------|
    | texto        | char*  | Entrada |
    | a, e, i, o, u| int    | Interna |
    | c            | char   | Interna |


    Función: cambiar_palabra

    | Variable      | Tipo     | Rol            |
    |---------------|----------|----------------|
    | texto         | char**   | Entrada/Salida |
    | buscar        | char[]   | Entrada        |
    | reemplazo     | char[]   | Entrada        |
    | nuevo_texto   | char*    | Interna        |
    | pos, temp     | char*    | Interna        |
    | count         | int      | Interna        |
    | nuevo_tam     | int      | Interna        |


    Función: guardar_resultados

    | Variable       | Tipo   | Rol     |
    |----------------|--------|---------|
    | texto          | char*  | Entrada |
    | nombre_salida  | char*  | Entrada |
    | salida         | FILE*  | Interna |
