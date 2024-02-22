//
// Autore: Lorenzo Rocca
//
#include <stdio.h>
#include "securereading.h"

//
// Creare un menù a quattro entrate, ciascuna che mostri una operazione matematica.
// Successivamente chiederà 3 ingressi: il valore x, il valore y e il contatore, ovvero quante volte dovrà essere
// eseguita l'operazione. Ritornerà il valore finale (risultato).
//

typedef struct {
    int x, y, c;
} Parameters;

void askForParameters(Parameters *destination) {
    // Definisci le variabili di ingresso
    int x = 0, y = 0, c = 0;

    // Richiedi i parametri
    scanInteger("Inserisci il primo valore >> ", "Valore non valido! Riprova\n", &x);
    scanInteger("Inserisci il secondo valore >> ", "Valore non valido! Riprova\n", &y);
    scanInteger("Inserisci quante  volte vuoi eseguire questa operazione >> ", "Valore non valido! Riprova\n", &c);

    // Crea il nuovo oggetto da assegnare all'indirizzo passato nei parametri
    Parameters result;
    result.x = x;
    result.y = y;
    result.c = c;
    *destination = result;
}

#pragma region Logical Recursive Operations

int sum(Parameters params) {
    int result = params.x;
    for (int i = params.c; i > 0; i--) {
        result += params.y;
    }
    return result;
}

int sub(Parameters params) {
    int result = params.x;
    for (int i = params.c; i > 0; i--) {
        result -= params.y;
    }
    return result;
}

int mul(Parameters params) {
    int result = params.x;
    for (int i = params.c; i > 0; i--) {
        result *= params.y;
    }
    return result;
}

int div(Parameters params) {
    int result = params.x;
    for (int i = params.c; i > 0; i--) {
        result /= params.y;
    }
    return result;
}

#pragma endregion

int main() {
    char operation = '\0';

    printf("Scegli un operazione:\n A. %s\n B. %s\n C. %s\n D. %s\n Q. Esci\n",
           "Addizione",
           "Sottrazione",
           "Moltiplicazione",
           "Divisione"
    );

    while (operation != 'Q' && operation != 'q') {
        scanCharacter("Inserisci una scelta\n>> ", &operation);

        Parameters params;
        if (operation == 'a' || operation == 'A') {
            askForParameters(&params);
            printf("Ecco il valore della somma: %d\n", sum(params));
        }
        else if (operation == 'b' || operation == 'B') {
            askForParameters(&params);
            printf("Ecco il valore della sottrazione: %d\n", sub(params));
        }
        else if (operation == 'c' || operation == 'C') {
            askForParameters(&params);
            printf("Ecco il valore della moltiplicazione: %d\n", mul(params));
        }
        else if (operation == 'd' || operation == 'D') {
            askForParameters(&params);
            printf("Ecco il valore della divisione: %d\n", div(params));
        }
        else if (operation == 'q' || operation == 'Q') {
            printf("Arrivederci!\n");
        }
        else {
            printf("Azione non riconosciuta! Riprova\n");
        }
    }
    return 0;
}
