/*Bories Lucie
  TP2 : FOURNISSEURS/BOULANGERS
  Date du TP : 26/03/2024 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include "boulanger.h"

// Declaration semaphore
//sem_t BF, BL, BE, finTravail;

// Variable global
 //int pain = 0 ;

int main (void)
{
    /*Initialisation thread*/
    pthread_t f;
    pthread_t bEAU;
    pthread_t bLEVURE;
    pthread_t bFARINE;

    int err_code ;

    /*Initialisation Semaphore*/
    sem_init(&BF,0,0);
    sem_init(&BL,0,0);
    sem_init(&BE,0,0);
    sem_init(&finTravail,0,1);

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

    /*Liberation de la memoire des semaphore*/
    sem_destroy(&BF);
    sem_destroy(&BL);
    sem_destroy(&BE);
    sem_destroy(&finTravail);

    return 0;
}
