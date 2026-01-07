/*Bories Lucie
  TP2 : FOURNISSEURS/BOULANGERS 
  Date du TP : 26/03/2024 */

#ifndef BOULANGER_H
#define BOULANGER_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>



// Declaration semaphore
sem_t BF, BL, BE, finTravail;

// Variable global 
int pain = 0 ; 

// Description des codes de threads



/*========== Boulanger 1 : Farine ==========*/
void* boulangerFARINE (void *arg){
  while (pain<=4)
  {
        sem_wait (&BF);
        printf("Le Boulanger 1 se met au travail !\n");

        usleep(300000); // temps de petrissage
        printf("La pate est petrit.\n");

        usleep(700000); // temps de cuisson
        printf("Le pain est cuit.\n");

        sem_post(&finTravail);
        pain = pain+1;
        printf("Fin de travail du boulanger 1 (FARINE)\n");
  }
  exit(0);
}

/*========== Boulanger 2 : Levure ==========*/
void* boulangerLEVURE (void *arg)
{
    while (pain<=4)
    {
        sem_wait (&BL);
        printf("Le Boulanger 2 se met au travail !\n");

        usleep(300000); // temps de petrissage
        printf("La pate est petrit.\n");

        usleep(700000); // temps de cuisson
        printf("Le pain est cuit.\n");

        sem_post(&finTravail);
        pain = pain+1;
        printf("Fin de travail du boulanger 2 (LEVURE)\n");
   }
   exit(0);
}

/*========== Boulanger 3 : Eau ==========*/
void* boulangerEAU(void *arg){
  while (pain<=4)
  {
        sem_wait (&BE);
        printf("Le Boulanger 3 se met au travail !\n");

        usleep(300000); // temps de petrissage
        printf("La pate est petrit.\n");

        usleep(700000); // temps de cuisson
        printf("Le pain est cuit.\n");

        sem_post(&finTravail);
        pain = pain+1;
        printf("Fin de travail du boulanger 3 (EAU)\n");
  }
  exit(0);
}

/*========== Fournisseur ==========*/
void* fournisseur (void *arg)
{
  int combinaison ;
  while(pain<=4)
  {
        sem_wait(&finTravail); // Validation de fin de travail de la part d'un boulanger
        printf("Le nombre de pain produit est de %d \n",pain);
        combinaison = rand()%3 + 1; // nombre entre 1 et 3 
        if(combinaison == 1)
        {
            sem_post(&BF);
            printf("Le boulanger 1 a recu l'EAU et la LEVURE pour lancer la preparation de son pain\n");
        }
        else if(combinaison == 2)
        {
            sem_post(&BL);
            printf("Le boulanger 2 a recu l'EAU et la FARINE pour lancer la preparation de son pain.\n");
        }
        else if (combinaison == 3)
        {
            sem_post(&BE);
            printf("Le boulanger 3 a recu la FARINE et la LEVURE pour lancer la preparation de son pain.\n");
        }
        
  }
  exit(0);
}
#endif
