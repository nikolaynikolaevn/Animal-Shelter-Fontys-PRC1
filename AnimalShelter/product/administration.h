#ifndef _ADMINISTRATION_H
#define _ADMINISTRATION_H

#include "animal.h"

void showAnimals(ANIMAL animalArray[], int animalCount);
// pre: true
// post: all animals that are present in animalArray are shown on the monitor

int addAnimal(ANIMAL *AnimalPtr, ANIMAL animalArray[], int* animalCount);
// pre: true
// post: if there is a free spot in animalArray, *AnimalPtr is added to the array
// and 0 is returned
// else -1 is returned

int findAnimal(char* name, ANIMAL animalArray[], int animalCount, ANIMAL foundAnimals[], short* found);
// *name is searched in the animalArray, an ANIMAL array is returned with the found results, found indicates the number of occurrences
// 0 is returned if occurrences are found
// otherwise -1 is returned

void removeAnimalByIndex(ANIMAL animalArray[], int index, int* animalCount);
// animalArray is the array containing animals, index indicates the index of the element to be removed, animalCount is the total count of animals

int removeAnimalByName(char* name, ANIMAL animalArray[], int* animalCount, short* removed);
// *name is searched in the animalArray, found indicates the number of occurrences
// 0 is returned if occurrences are removed
// otherwise -1 is returned

int isFreeSpace(int animalCount);
// 0 is returned if there is an space
// otherwise -1 is returned

#endif
