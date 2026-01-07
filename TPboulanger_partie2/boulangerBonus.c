/*Bories Lucie
  TP2 : FOURNISSEURS/BOULANGERS 
  Date du TP : 26/03/2024 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include "boulangerBonus.h"


int main (void)
{
    /*Initialisation thread*/
    pthread_t f;
    pthread_t bEAU;
    pthread_t bLEVURE;
    pthread_t bFARINE;
    
    int err_code ;


    /* lancement des threads */
    if((err_code = pthread_create(&f, NULL,fournisseur, NULL)) != 0)
    { printf("Erreur à la création du fournisseur (%d)\n", err_code);
        exit(1);
    }

    if((err_code =  pthread_create (&bEAU, NULL,boulangerEAU, NULL)) != 0)
    { printf("Erreur à la création du boulangerEAU (%d)\n", err_code);
        exit(1);
    }

    if((err_code =  pthread_create (&bLEVURE, NULL,boulangerLEVURE, NULL)) != 0)
    { printf("Erreur à la création du boulangerLEVURE (%d)\n", err_code);
        exit(1);
    }

    if((err_code =  pthread_create (&bFARINE, NULL,boulangerFARINE, NULL)) != 0)
    { printf("Erreur à la création du boulangerFARINE (%d)\n", err_code);
        exit(1);
    }


    /*Liberation de la memoire des threads*/
    printf("attente du f \n"); 
    pthread_join(f,NULL);

    printf("attente du bEAU \n"); 
    pthread_join(bEAU,NULL);

    printf("attente du bLEVURE \n");
    pthread_join(bLEVURE,NULL);

    printf("attente du bFARINE \n");
    pthread_join(bFARINE,NULL);


    return 0;
}
