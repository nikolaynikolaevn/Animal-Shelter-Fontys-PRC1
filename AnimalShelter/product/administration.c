#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "administration.h"

const char* species[] = {"Cat", "Dog", "GuineaPig", "Parrot"};

void showAnimals(ANIMAL animalArray[], int animalCount) {
    if (animalCount > 0) {
        for (int i = 0; i < animalCount; i++) {
            printf("\n\nName: %s\nType: %s\nAge: %d", animalArray[i].Name, species[animalArray[i].Species], animalArray[i].Age);
        }
    }
    else printf("\nThere are no added animals.");
}

int addAnimal(ANIMAL *AnimalPtr, ANIMAL animalArray[], int* animalCount) {
    if (*animalCount < MaxArrayLength)  {
        // Validate name
        char c;
        for (int i = 0; i < strlen((*AnimalPtr).Name); i++) {
            c = (*AnimalPtr).Name[i];
            if (!isalpha(c)) return -2;
        }

        // Validate species
        (*AnimalPtr).Species--;
        if (((*AnimalPtr).Species < 0) || ((*AnimalPtr).Species > 3)) return -3;

        // Validate age
        if ((*AnimalPtr).Age < 0) return -4;

        animalArray[*animalCount] = *AnimalPtr;
        (*animalCount)++;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int findAnimal(char* name, ANIMAL animalArray[], int animalCount, ANIMAL foundAnimals[], short* found) {
    for (int i = 0; i < animalCount; i++) {
        if (strcmp(name, animalArray[i].Name) == 0) {
            foundAnimals[*found] = animalArray[i];
            (*found)++;
        }
    }
    return *found ? EXIT_SUCCESS : EXIT_FAILURE;
}

void removeAnimalByIndex(ANIMAL animalArray[], int index, int* animalCount) {
    for (int i = index; i < *animalCount - 1; i++) animalArray[i] = animalArray[i + 1];
    (*animalCount)--;
}

int removeAnimalByName(char* name, ANIMAL animalArray[], int* animalCount, short* removed) {
    for (int i = 0; i < *animalCount; i++) {
        if (strcmp(name, animalArray[i].Name) == 0) {
            removeAnimalByIndex(animalArray, i, animalCount);
            (*removed)++;
            i--;
        }
    }
    return *removed ? EXIT_SUCCESS : EXIT_FAILURE;
}

int isFreeSpace(int animalCount) {
    return animalCount < MaxArrayLength ? EXIT_SUCCESS : EXIT_FAILURE;
}
