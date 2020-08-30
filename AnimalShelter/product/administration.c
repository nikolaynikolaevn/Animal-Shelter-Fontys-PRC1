#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "administration.h"

int animalCount;
const char* species[] = {"Cat", "Dog", "GuineaPig", "Parrot"};

//implement your own functions
void showAnimals(ANIMAL animalArray[]) {
    if (animalCount) {
        for (int i = 0; i < animalCount; i++) {
            printf("\n\nName: %s\nType: %s\nAge: %d", animalArray[i].Name, species[animalArray[i].Species], animalArray[i].Age);
        }
    }
    else printf("\nThere are no added animals.");
}

int addAnimal(ANIMAL *AnimalPtr, ANIMAL animalArray[]) {
    if (animalCount < MaxArrayLength)  {
        animalArray[animalCount] = *AnimalPtr;
        animalCount++;
        return 0;
    }
    return -1;
}

int findAnimal(char* name, ANIMAL animalArray[], ANIMAL foundAnimals[], short* found) {
    for (int i = 0; i < animalCount; i++) {
        if (strcmp(name, animalArray[i].Name) == 0) {
            foundAnimals[*found] = animalArray[i];
            (*found)++;
        }
    }
    return *found ? 0 : -1;
}

int removeAnimal(char* name, ANIMAL animalArray[], short* removed) {
    for (int i = 0; i < animalCount; i++) {
        if (strcmp(name, animalArray[i].Name) == 0) {
            for (int k = i; k < animalCount - 1; k++) {
                animalArray[k] = animalArray[k + 1];
            }
            (*removed)++;
        }
    }
    animalCount -= *removed;
    return *removed ? 0 : -1;
}

int isFreeSpace() {
    return animalCount < MaxArrayLength ? 0 : -1;
}
