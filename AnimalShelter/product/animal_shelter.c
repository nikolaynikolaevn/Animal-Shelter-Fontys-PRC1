/*
 * Menu animal_shelter.c
 *
 *  
 */

#include <stdio.h>
#include "administration.h"

int main (void)
{
    ANIMAL animalArray[MaxArrayLength];
    char name[MaxNameLength];
    ANIMAL foundAnimals[MaxArrayLength];

    printf ("PRC assignment 'Animal Shelter' (version april 2019)");
          
    int choice, code = -1;
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
                showAnimals(animalArray);
                break;
            case 2: //Add Animal
                printf ("add Animal\n");
                ANIMAL animal;

                printf("\nName: ");
                scanf("%s", animal.Name);

                printf("\nWhat species would you like to add?\n");
                printf ("1: Cat\n2: Dog\n3: GuineaPig\n4: Parrot\n");
                int species;
                scanf("%u", &species);
                animal.Species = --species;
                if (animal.Species < 0 || animal.Species > 3) {
                    printf("Invalid species.\n");
                    break;
                }

                printf("\nAge: ");
                scanf("%d", &animal.Age);

                addAnimal(&animal, animalArray);
                break;
            case 3: //Remove Animal
                 printf ("remove Animal\n");
                 short removed = 0;
                 printf("\nEnter animal name to remove: ");
                 scanf("%s", name);
                 code = removeAnimal(name, animalArray, &removed);
                 code == 0 ? printf("\n%hu animals with name %s were successfully removed.", removed, name) : printf("\nNo animals with name %s were removed.", name);
                 break;
            case 4://find by name
                printf ("find by name\n");
                short found = 0;
                printf("\nEnter animal name to find: ");
                scanf("%s", name);
                code = findAnimal(name, animalArray, foundAnimals, &found);
                if (code == 0) {
                    printf("\n%hu animals with name %s were found.", found, name);
                    showAnimals(foundAnimals);
                }
                else printf("\nNo animals with name %s were found.", name);
                break;
            case 5: // show animal count
                printf("\nThere are %d animals.", animalCount);
                break;
            case 6: // show if there is empty space
                isFreeSpace() == 0 ? printf("\nThere is empty space.") : printf("\nThere is no empty space.");
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
