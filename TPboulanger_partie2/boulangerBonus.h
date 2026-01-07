/*Bories Lucie
  Nguyen James
  TP2 : FOURNISSEURS/BOULANGERS 
  Date du TP : 26/03/2024 */

#ifndef BOULANGER_H
#define BOULANGER_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>



int S1 = 0; // stock boulanger 1 : FARINE
int S2 = 0; // stock boulanger 2 : LEVURE
int S3 = 0; // stock boulanger 3 : EAU

/*Création des mutex protection des stocks*/
pthread_mutex_t mutex_S1;
pthread_mutex_t mutex_S2;
pthread_mutex_t mutex_S3;

// Variable global 
int pain = 0 ; 

// Description des codes de threads



/*========== Boulanger 1 : Farine ==========*/
void* boulangerFARINE (void *arg){
  while (pain<=9)
  {
	
        if (S1 !=0)
	{
		pthread_mutex_lock(&mutex_S1);
		printf("Le Boulanger 1 pioche dans son stock (S1) \n");
		S1 = S1-1;
		pthread_mutex_unlock(&mutex_S1);

		usleep(300000); // temps de petrissage
       		printf("Boulanger 1 : La pate est petrit.\n");

        	usleep(700000); // temps de cuisson
        	printf("Boulanger 1 : Le pain est cuit.\n");
		pain = pain+1;
		printf("Fin de travail du boulanger 1 (FARINE)\n");	

	}else 
	{
		//printf("Boulanger 1 : attente ressource... \n");
	}
        
        
  }
  pthread_exit(0);
}

/*========== Boulanger 2 : Levure ==========*/
void* boulangerLEVURE (void *arg)
{
    while (pain<=9)
    {
        
        if (S2 !=0)
	{
		pthread_mutex_lock(&mutex_S2);
		printf("Le Boulanger 2 pioche dans son stock (S2) \n");
		S2 = S2-1;
		pthread_mutex_unlock(&mutex_S2);
		usleep(300000); // temps de petrissage
       		printf(" Boulanger 2 : La pate est petrit.\n");

        	usleep(700000); // temps de cuisson
        	printf("Boulanger 2 : Le pain est cuit.\n");
		pain = pain+1;
		printf("Fin de travail du boulanger 2 (LEVURE)\n");
		
	}else
	{
		//printf("Boulanger 2 : attente ressource... \n");
	}
        
        
   }
   pthread_exit(0);
}

/*========== Boulanger 3 : Eau ==========*/
void* boulangerEAU(void *arg){
  while (pain<=9)
  {
	
        if (S3 !=0)
	{
		pthread_mutex_lock(&mutex_S3);
		printf("Le Boulanger 3 pioche dans son stock (S3) \n");
		S3 = S3-1;	
		pthread_mutex_unlock(&mutex_S3);
		usleep(300000); // temps de petrissage
       		printf("Boulanger 3 : La pate est petrit.\n");

        	usleep(700000); // temps de cuisson
        	printf("Boulanger 3 : Le pain est cuit.\n");
		pain = pain+1;
        	printf("Fin de travail du boulanger 3 (EAU)\n");
		
	}else 
	{
		//printf("Boulanger 3 : attente ressource... \n");
	}
        

  }
  pthread_exit(0);
}

/*========== Fournisseur ==========*/
void* fournisseur (void *arg)
{
  int combinaison ;
  while(pain<=10)
  {
        printf("Le nombre de pain produit est de %d \n",pain);
        combinaison = rand()%3 + 1; // nombre entre 1 et 3
	usleep(300000); 
        if(combinaison == 1)
        {
		/* boulanger FARINE */

		pthread_mutex_lock(&mutex_S1);
		if(S1 <= 4)
		{
			S1 = S1+1; 
			printf("Le boulanger 1 a recu l'EAU et la LEVURE, dans son stock, pour lancer la preparation de son pain\n");
			printf("S1 : %d \n",S1);
		}
		else if(S1 > 5)
		{
			printf("Buffer boulanger FARINE plein : JETER ingrédients !\n");
		}
		pthread_mutex_unlock(&mutex_S1);              
        }
        else if(combinaison == 2)
        {
		/* boulanger LEVURE */

		pthread_mutex_lock(&mutex_S2);
		if(S2 <= 4)
		{
			S2 = S2+1; 
			printf("Le boulanger 2 a recu l'EAU et la FARINE, dans son stock, pour lancer la preparation de son pain\n");
			printf("S2 : %d \n",S2);
		}
		else if(S2 > 5)
		{
			printf("Buffer boulanger LEVURE plein : JETER ingrédients !\n");
		}
		pthread_mutex_unlock(&mutex_S2);
        }
        else if (combinaison == 3)
        {
            	/* boulanger EAU */

		pthread_mutex_lock(&mutex_S3);
		if(S3 <= 4)
		{
			S3 = S3+1; 
			printf("Le boulanger 3 a recu la FARINE et la LEVURE, dans son stock, pour lancer la preparation de son pain\n");
			printf("S3 : %d \n",S3);
		}
		else if(S3 > 5)
		{
			printf("Buffer boulanger EAU plein : JETER ingrédients !\n");
		}
		pthread_mutex_unlock(&mutex_S3);
        }
        
  }
  pthread_exit(0);
}
#endif
