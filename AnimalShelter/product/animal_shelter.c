/*
 * Menu animal_shelter.c
 *
 *  
 */

#include <stdio.h>
#include <stdlib.h>
#include "administration.h"

int main (void)
{
    ANIMAL animalArray[MaxArrayLength];
    int animalCount = 0;
    char name[MaxNameLength];

    printf ("PRC assignment 'Animal Shelter' (version april 2019)");

    int choice = -1, code = -1;
    while (choice != 0)
    {
        printf ("\n\nMENU\n====\n");
        printf ("1: Show Animals \n");
        printf ("2: Add Animal \n");
        printf ("3: Remove Animal \n");
        printf ("4: Find Animal by name \n");
        printf ("5: Show Animal count \n");
        printf ("6: Show if there is a free rom \n");
        printf ("0: quit \n");
                
        scanf ("%d", &choice);
		
        switch (choice)
        {
            case 1: //Show Animals
                printf ("show Animals\n");
                showAnimals(animalArray, animalCount);
                break;
            case 2: //Add Animal
                printf ("add Animal\n");
                ANIMAL animal;

                printf("\nName: ");
                scanf("%s", animal.Name);

                printf("\nWhat species would you like to add?\n");
                printf ("1: Cat\n2: Dog\n3: GuineaPig\n4: Parrot\n");
                scanf("%u", &animal.Species);

                printf("\nAge: ");
                scanf("%d", &animal.Age);

                code = addAnimal(&animal, animalArray, &animalCount);
                if (code == EXIT_SUCCESS) printf("\nAnimal added successfully.");
                else if (code == -2) printf("\nAnimal not added: Invalid name.\n");
                else if (code == -3) printf("\nAnimal not added: Invalid species.\n");
                else if (code == -4) printf("\nAnimal not added: Invalid age.\n");
                else printf("\nAnimal not added: Cannot add more animals.");
                break;
            case 3: //Remove Animal
                 printf ("remove Animal\n");
                 short removed = 0;
                 printf("\nEnter animal name to remove: ");
                 scanf("%s", name);
                 code = removeAnimalByName(name, animalArray, &animalCount, &removed);
                 if (code == 0) printf("\n%hu animals with name %s were successfully removed.", removed, name);
                 else printf("\nNo animals with name %s were removed.", name);
                 break;
            case 4://find by name
                printf ("find by name\n");
                short found = 0;
                printf("\nEnter animal name to find: ");
                scanf("%s", name);
                ANIMAL foundAnimals[MaxArrayLength];
                code = findAnimal(name, animalArray, animalCount, foundAnimals, &found);
                if (code == 0) {
                    showAnimals(foundAnimals, found);
                    printf("\n\n%hu animals with the name %s were found.", found, name);
                }
                else printf("\nNo animals with the name %s were found.", name);
                break;
            case 5: // show animal count
                printf("\nThere are %d animals.", animalCount);
                break;
            case 6: // show if there is empty space
                if (isFreeSpace(animalCount) == 0) printf("\nThere is empty space.");
                else printf("\nThere is no empty space.");
                break;
            case 0:
                break;
            default:
                printf ("\nERROR: invalid choice: %d\n", choice);
                break;
		}
	}
    return 0;
}
