/*
 ============================================================================
 Enunciado:
 Una plataforma educativa crea las cuentas de sus estudiantes. Escriba un programa 
 en C que:
 1. Pida el nombre completo (con espacios; no se acepta vacio).
 2. Arme el nombre de usuario con la primera letra del nombre seguida del primer 
    apellido (la palabra despues del primer espacio): Ana Rojas Mena -> ARojas. 
    Si el nombre tiene una sola palabra, el usuario es esa palabra.
 3. Pida una contrasena y su confirmacion (una palabra cada una) y repita hasta 
    que tenga al menos 8 caracteres y las dos coincidan; muestre un mensaje 
    distinto para cada error.
 4. Muestre el usuario con su cantidad de caracteres y el mensaje Cuenta creada 
    para ... armado en una cadena con strcpy y strcat.

 Que se logra:
 Procesar cadenas de caracteres avanzadas mediante lecturas seguras (fgets), 
 busqueda de caracteres especificos en arreglos, construccion dinamica de 
 identificadores de usuario, validacion estricta de credenciales con bucles y 
 manipulacion de cadenas utilizando funciones de la libreria <string.h>.

 Como se logra:
 Se lee el nombre completo utilizando fgets y se limpia el salto de linea con strcspn. 
 Se recorre la cadena caracter por caracter para localizar el primer espacio; 
 al encontrarlo, se toma la inicial del nombre y se copian los caracteres del primer 
 apellido de manera secuencial al arreglo de usuario cerrandolo con '\0'. Si no hay espacios, 
 se copia el nombre completo. Para la contrasena, se utiliza un ciclo que valida la longitud 
 minima mediante strlen() y la igualdad exacta usando strcmp(). Finalmente, se ensambla 
 el mensaje de salida empleando strcpy() y strcat().

 Resultado esperado:
 Solicitar nombre y contrasenas con mensajes de error especificos ante fallos de longitud 
 o discrepancias, para luego desplegar de forma limpia el usuario generado con su longitud 
 en caracteres y el mensaje final de creacion de cuenta.
 ============================================================================
*/

#include <stdio.h>
#include <string.h>

int main(void) {
    char nombre[100];
    char usuario[100];
    char password[50];
    char confirmacion[50];
    char mensaje[150];
    int valido = 0;

    printf("=== Crear cuenta de usuario ===\n");

    // 1. Pedir nombre completo (con espacios)
    do {
        printf("Nombre completo: ");
        fgets(nombre, sizeof(nombre), stdin);
        nombre[strcspn(nombre, "\n")] = '\0'; // Quitar salto de linea
    } while (strlen(nombre) == 0);

    // 2. Armar usuario: primera letra del nombre + primer apellido
    usuario[0] = nombre[0]; // Primera letra
    int i = 0;
    int tiene_espacio = 0;

    while (nombre[i] != '\0') {
        if (nombre[i] == ' ') {
            tiene_espacio = 1;
            int j = 1;     // Indice para usuario
            int k = i + 1; // Indice para el apellido en nombre
            
            // Copiar el apellido caracter por caracter
            while (nombre[k] != '\0' && nombre[k] != ' ') {
                usuario[j] = nombre[k];
                j++;
                k++;
            }
            usuario[j] = '\0';
            break;
        }
        i++;
    }

    // Si solo tiene una palabra, el usuario es esa palabra
    if (!tiene_espacio) {
        strcpy(usuario, nombre);
    }

    // 3. Pedir contrasena y confirmacion (minimo 8 caracteres y que coincidan)
    while (!valido) {
        printf("Contrasena (minimo 8 caracteres): ");
        scanf("%s", password);
        printf("Confirme la contrasena: ");
        scanf("%s", confirmacion);

        if (strlen(password) < 8) {
            printf("  Muy corta: debe tener al menos 8 caracteres\n");
        } else if (strcmp(password, confirmacion) != 0) {
            printf("  Las contrasenas no coinciden\n");
        } else {
            valido = 1;
        }
    }

    // 4. Armar el mensaje final con strcpy y strcat
    strcpy(mensaje, "Cuenta creada para ");
    strcat(mensaje, nombre);

    // Mostrar resultados (usamos (int)strlen para evitar warnings en MINGW64)
    printf("\nUsuario: %s (%d caracteres)\n", usuario, (int)strlen(usuario));
    printf("%s\n", mensaje);

    return 0;
}