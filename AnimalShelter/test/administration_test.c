#include <string.h>
#include "unity.h"
#include "administration.h"

ANIMAL animalArray[MaxArrayLength];
ANIMAL animal;
ANIMAL foundAnimals[MaxArrayLength];

short removed, found = 0;

void setUp(void)
{
    // This is run before EACH test
}

void tearDown(void)
{
    // This is run after EACH test
    memset(animalArray, 0, sizeof(animalArray));
    memset(foundAnimals, 0, sizeof(foundAnimals));
    animalCount = 0;
    removed = 0;
    found = 0;
}

void test_EmptyTestFail(void)
{
    strcpy(animal.Name, "John");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    TEST_ASSERT_NOT_EQUAL(0, animalCount);
}

void test_EmptyTestPass(void)
{
    TEST_ASSERT_EQUAL(0, animalCount);
}

void test_AnimalsCountFail(void)
{
    strcpy(animal.Name, "John");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    strcpy(animal.Name, "Franklin");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    TEST_ASSERT_NOT_EQUAL(1, animalCount);
}

void test_AnimalsCountPass(void)
{
    strcpy(animal.Name, "John");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    strcpy(animal.Name, "Franklin");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    TEST_ASSERT_EQUAL(2, animalCount);
}

void test_AnimalSpeciesFail(void)
{
    strcpy(animal.Name, "John");
    animal.Species = 2;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    TEST_ASSERT_NOT_EQUAL(1, animal.Species);
}

void test_AnimalSpeciesPass(void)
{
    strcpy(animal.Name, "John");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    TEST_ASSERT_EQUAL(1, animal.Species);
}

void test_AnimalRemove1Pass(void)
{
    strcpy(animal.Name, "John");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    removeAnimal("John", animalArray, &removed);

    TEST_ASSERT_EQUAL(1, removed);
}

void test_AnimalRemove2Pass(void)
{
    strcpy(animal.Name, "John");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    strcpy(animal.Name, "John");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    removeAnimal("John", animalArray, &removed);

    TEST_ASSERT_EQUAL(2, removed);
}

void test_AnimalRemoveOnlyOccurrencesPass(void)
{
    strcpy(animal.Name, "John");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    strcpy(animal.Name, "Johnny");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    removeAnimal("John", animalArray, &removed);

    TEST_ASSERT_EQUAL(1, removed);
}

void test_TestCountAfterRemovePass(void)
{
    strcpy(animal.Name, "John");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    strcpy(animal.Name, "Johnny");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    removeAnimal("John", animalArray, &removed);

    TEST_ASSERT_EQUAL(1, animalCount);
}

void test_TestReturnCodeAfterRemovePass(void)
{
    strcpy(animal.Name, "John");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    strcpy(animal.Name, "Johnny");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    int code = removeAnimal("John", animalArray, &removed);

    TEST_ASSERT_EQUAL(0, code);
}

void test_TestReturnCodeAfterRemoveFail(void)
{
    strcpy(animal.Name, "Johnny");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    strcpy(animal.Name, "Johnny");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    int code = removeAnimal("John", animalArray, &removed);

    TEST_ASSERT_EQUAL(-1, code);
}

void test_TestCorrectRemovePass(void)
{
    strcpy(animal.Name, "Johnny");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    strcpy(animal.Name, "John");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    strcpy(animal.Name, "Johnson");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    removeAnimal("John", animalArray, &removed);

    TEST_ASSERT_EQUAL_STRING("Johnny", animalArray[0].Name);
    TEST_ASSERT_EQUAL_STRING("Johnson", animalArray[1].Name);
}

void test_TestCorrectRemoveEndPass(void)
{
    strcpy(animal.Name, "Johnny");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    strcpy(animal.Name, "John");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    strcpy(animal.Name, "Johnson");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    removeAnimal("Johnson", animalArray, &removed);

    TEST_ASSERT_EQUAL_STRING("Johnny", animalArray[0].Name);
    TEST_ASSERT_EQUAL_STRING("John", animalArray[1].Name);
}

void test_TestCorrectRemoveBeginPass(void)
{
    strcpy(animal.Name, "Johnny");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    strcpy(animal.Name, "John");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    strcpy(animal.Name, "Johnson");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    removeAnimal("Johnny", animalArray, &removed);

    TEST_ASSERT_EQUAL_STRING("John", animalArray[0].Name);
    TEST_ASSERT_EQUAL_STRING("Johnson", animalArray[1].Name);
}

void test_TestAnimalFindCountPass(void)
{
    strcpy(animal.Name, "Johnny");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    strcpy(animal.Name, "Johnny");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    strcpy(animal.Name, "Johnson");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    findAnimal("Johnny", animalArray, foundAnimals, &found);

    TEST_ASSERT_EQUAL(2, found);
}

void test_TestAnimalFindPass(void)
{
    strcpy(animal.Name, "Johnny");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    strcpy(animal.Name, "Johnny");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    strcpy(animal.Name, "Johnson");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    findAnimal("Johnny", animalArray, foundAnimals, &found);

    TEST_ASSERT_EQUAL_STRING("Johnny", foundAnimals[0].Name);
    TEST_ASSERT_EQUAL_STRING("Johnny", foundAnimals[1].Name);
}

void test_TestAnimalFindReturnCodePass(void)
{
    strcpy(animal.Name, "Johnny");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    int code = findAnimal("Johnny", animalArray, foundAnimals, &found);

    TEST_ASSERT_EQUAL(0, code);
}

void test_TestAnimalFindReturnCodeFail(void)
{
    strcpy(animal.Name, "Johnny");
    animal.Species = 1;
    animal.Age = 5;
    addAnimal(&animal, animalArray);

    int code = findAnimal("John", animalArray, foundAnimals, &found);

    TEST_ASSERT_EQUAL(-1, code);
}

void test_TestEmptySpaceFail(void)
{
    for (int i = 0; i < 10; i++) {
        strcpy(animal.Name, "Johnny");
        animal.Species = 1;
        animal.Age = 5;
        addAnimal(&animal, animalArray);
    }

    TEST_ASSERT_EQUAL(-1, isFreeSpace());
}

void test_TestEmptySpacePass(void)
{
    for (int i = 0; i < 9; i++) {
        strcpy(animal.Name, "Johnny");
        animal.Species = 1;
        animal.Age = 5;
        addAnimal(&animal, animalArray);
    }

    TEST_ASSERT_EQUAL(0, isFreeSpace());
}

int main (void)
{
    UnityBegin();

    RUN_TEST(test_EmptyTestFail, 1);
	RUN_TEST(test_EmptyTestPass, 2);
    RUN_TEST(test_AnimalsCountFail, 3);
    RUN_TEST(test_AnimalsCountPass, 4);
    RUN_TEST(test_AnimalSpeciesFail, 5);
    RUN_TEST(test_AnimalSpeciesPass, 6);
    RUN_TEST(test_AnimalRemove1Pass, 7);
    RUN_TEST(test_AnimalRemove2Pass, 8);
    RUN_TEST(test_AnimalRemoveOnlyOccurrencesPass, 9);
    RUN_TEST(test_TestCountAfterRemovePass, 10);
    RUN_TEST(test_TestReturnCodeAfterRemovePass, 11);
    RUN_TEST(test_TestReturnCodeAfterRemoveFail, 12);
    RUN_TEST(test_TestCorrectRemovePass, 13);
    RUN_TEST(test_TestCorrectRemoveEndPass, 14);
    RUN_TEST(test_TestCorrectRemoveBeginPass, 15);
    RUN_TEST(test_TestAnimalFindCountPass, 16);
    RUN_TEST(test_TestAnimalFindPass, 17);
    RUN_TEST(test_TestAnimalFindReturnCodePass, 18);
    RUN_TEST(test_TestAnimalFindReturnCodePass, 19);
    RUN_TEST(test_TestEmptySpaceFail, 20);
    RUN_TEST(test_TestEmptySpacePass, 21);

    return UnityEnd();
}
