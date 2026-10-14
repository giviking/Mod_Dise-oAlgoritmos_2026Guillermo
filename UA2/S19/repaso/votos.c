/* El grupo va a elegir a su representante entre tres candidatos: 1 Ana, 2 Luis y 3 Sofía.Cada estudiante pasa a la computadora
 y digita el número de su candidato. No se sabe cuántas  personas votarán: la votación termina cuando alguien
  digita 0 Cualquier otro numero es voto nulo. Al final se muestra una barra de * con los votos del candidato */

  #include <stdio.h>    // printf y scanf
  #define FIN 0         //se definen e inicializan constantes

  int main(void) {      // es la funcion principal
    int voto;           //nnumer que digita cada estudiante -> 1, 2, 3, otro o 0
    int total = 0;      //contador de votos recibidos (validos como nulos)
    int ana = 0;     //CONTADOR: de votos de Ana (candidato 1)
    int luis = 0;
    int sofia = 0;
    int nulos = 0;   //CONTADOR: de votos no validos
    int c;           //candidato que dibuja el for externo 1 a 3
    int i;           //contador del for interno: una vuelta por *
    int cantidad;    //votos del candidato
    int mayor;       //mayor cantidad de votos por candidato
    int empatados;   //candidatos con la misma cantidad de votos

    printf("====== Eleccion de representante ======\n");
    printf("1 Ana    2 Luis    3 Sofia (0 cierra)\n\n");

    //LECTURAS PREVIAS
    printf("Voto: ");
    scanf("%d", &voto);

    //WHILE con centinela. Se repite mientras el voto no sea 0
    while (voto != FIN) {
        total++;            //cuenta el voto -> 1, 2, ....,

        //SWITCH: sumar 1 al contador del candidato elegido
        switch (voto) {
        case 1: ana++; break; //break: sale del switch
        case 2: luis++; break;
        case 3: sofia++; break;        
        default:                   //cualquier otro nnumero ->5
            nulos++;
            printf("   Voto nulo\n");

        }       
        //NUEVA LECTURA: Sin la nueva lectura el voto no cambia y el while no termina
        printf("voto: ");
        scanf("%d", &voto);
    }
    printf("\nVotos recibidos: %d\n", total);

    //FOR EXTERNO: Una vuelta por candidato -> c = 1, 2, 3
        for (c = 1; c <=3; c++) {
            switch (c) {
            case 1: printf("Ana "); cantidad = ana; break;
            case 2: printf("Luis "); cantidad = luis; break;            
            default: printf("Sofia"); cantidad = sofia; break;
            }
            //FOR INTERNO: (anidado) un for * y otro por voto -> Ana ***
        for(i = 1; i <= cantidad; i++)
            printf("*");
        printf(" (%d)\n", cantidad);
        }

        printf("Nulos: %d\n", nulos);

        //MAYOR de tres: el primer lugar
        mayor = ana;
        if (luis > mayor) mayor = luis;
        if (sofia > mayor) mayor = sofia;
        //empatados
        empatados = 0;
        if (ana == mayor) empatados++;
        if (luis == mayor) empatados++;
        if (sofia == mayor) empatados++;

        //DECISION: solo se ejecuta el primer bloque que se cumpla
        if (mayor == 0)
        printf("No hubo votos validos\n");
        else if (empatados > 1)
        printf("Empate con %d votos: se repite la votacion\n", mayor);

        else if (ana == mayor)
        printf("Gana Ana con %d votos\n", mayor); //3 votos

        else if (luis == mayor)
        printf("Gana Luis con %d votos\n", mayor); //3 votos

        else if (sofia == mayor)
        printf("Gana Sofia con %d votos\n", mayor); //3 votos
        

        
            




    return 0;    //fin normal del programa

  }