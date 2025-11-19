//
// Algoritmos e Estruturas de Dados --- 2024/2025
//
// J Madeira, J M Rodrigues, Nov 2023, Nov 2024
//

// Complete the functions (marked by ...)
// so that they pass all tests.

#include "PersonSet.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BSTree.h"

// NOTE THAT:
// - Field capacity was eliminated.
// - Field size was eliminated, because size==BSTreeGetNumberOfNodes(...).

// Definition of the structure
struct _PersonSet_ {
  BSTree *persons;  // points to a BSTree of Person pointers
};

// Comparison function to be used in generic BSTree.
// Comparison is based on Person ID
static int cmpP(const void *a, const void *b) {
  Person *p1 = (Person *)a;
  Person *p2 = (Person *)b;
  int d = p1->id - p2->id;
  return (d > 0) - (d < 0);
}

// Print function to be used in generic BSTree.
static void printP(void *p) { PersonPrintf((Person *)p, ""); }

// Create a PersonSet.
PersonSet *PersonSetCreate() {

  PersonSet *ps = (PersonSet *)malloc(sizeof(PersonSet));
  if (ps == NULL) abort();
  ps->persons = BSTreeCreate(cmpP, printP);
  return ps;
}

// Destroy PersonSet *pps
void PersonSetDestroy(PersonSet **pps) {
  assert(pps != NULL);
  assert(*pps != NULL);

  PersonSet *ps = *pps;

  BSTreeDestroy(&(ps->persons));

  free(ps);

  *pps = NULL;
}

int PersonSetSize(const PersonSet *ps) {
  return BSTreeGetNumberOfNodes(ps->persons);
}

int PersonSetIsEmpty(const PersonSet *ps) { return BSTreeIsEmpty(ps->persons); }

// Print function to use in PersonSetPrint
static void printlnP(void *p) { PersonPrintf((Person *)p, ";\n"); }

void PersonSetPrint(const PersonSet *ps) {
  printf("{\n");
  BSTreeTraverseINOrder(ps->persons, printlnP);
  printf("}(size=%d)\n", PersonSetSize(ps));
}

// Find node in BSTree ps->persons of person with given id.
// Return a pointer to the stored Person instance.
// Or NULL, if it does not belong to the BSTree.
// (INTERNAL function.)
static Person *search(const PersonSet *ps, int id) {
  Person dummyPerson;
  dummyPerson.id = id;
  return BSTreeSearch(ps->persons, &dummyPerson);
}

// Add person *p to *ps.
// Do nothing if *ps already contains a person with the same id.
void PersonSetAdd(PersonSet *ps, Person *p) {
  // COMPLETE
  BSTreeAdd(ps->persons, p);
}

// Pop one person out of *ps.
Person *PersonSetPop(PersonSet *ps) {
  assert(!PersonSetIsEmpty(ps));
  // It is easiest to pop and return the first person in the set!
  Person *p = (Person *)BSTreeGetMin(ps->persons);

  int ok = BSTreeRemove(ps->persons, p);
  assert(ok == 1);
  return p;
}

// Remove the person with given id from *ps, and return it.
// If no such person is found, return NULL and leave set untouched.
Person *PersonSetRemove(PersonSet *ps, int id) {
  // You may call search here!

  Person *p = search(ps, id);
  if (p == NULL) {
    return NULL;
  }

  int ok = BSTreeRemove(ps->persons, p);
  assert(ok == 1);

  return p;
}

// Get the person with given id of *ps.
// return NULL if it is not in the set.
Person *PersonSetGet(const PersonSet *ps, int id) {
  // You may call search here!
  return search(ps, id);
}

// Return true (!= 0) if set contains person with given id, false otherwise.
int PersonSetContains(const PersonSet *ps, int id) {
  return search(ps, id) != NULL;
}

// Return a NEW PersonSet with the union of *ps1 and *ps2.
// NOTE: memory is allocated.  Client must call PersonSetDestroy!
PersonSet *PersonSetUnion(const PersonSet *ps1, const PersonSet *ps2) {
  PersonSet *ps = PersonSetCreate();

  // Adicionar todos os elementos de ps1
  Queue *q1 = BSTreeGetItems(ps1->persons);
  while (!QueueIsEmpty(q1)) {
    Person *p = (Person *)QueueDequeue(q1);
    PersonSetAdd(ps, p);
  }
  QueueDestroy(&q1);

  // Adicionar todos os elementos de ps2 (duplicados ignorados pela BST)
  Queue *q2 = BSTreeGetItems(ps2->persons);
  while (!QueueIsEmpty(q2)) {
    Person *p = (Person *)QueueDequeue(q2);
    PersonSetAdd(ps, p);
  }
  QueueDestroy(&q2);

  return ps;
}


// Return a NEW PersonSet with the intersection of *ps1 and *ps2.
// NOTE: memory is allocated.  Client must call PersonSetDestroy!
PersonSet *PersonSetIntersection(const PersonSet *ps1, const PersonSet *ps2) {
  PersonSet *ps = PersonSetCreate();

  // Percorrer todos os elementos de ps1
  Queue *q1 = BSTreeGetItems(ps1->persons);
  while (!QueueIsEmpty(q1)) {
    Person *p = (Person *)QueueDequeue(q1);
    // Se também estiver em ps2, pertence à interseção
    if (PersonSetContains(ps2, p->id)) {
      PersonSetAdd(ps, p);
    }
  }
  QueueDestroy(&q1);

  return ps;
}


// Return a NEW PersonSet with the set difference of *ps1 and *ps2.
// NOTE: memory is allocated.  Client must call PersonSetDestroy!
PersonSet *PersonSetDifference(const PersonSet *ps1, const PersonSet *ps2) {
  PersonSet *ps = PersonSetCreate();

  // Percorrer todos os elementos de ps1
  Queue *q1 = BSTreeGetItems(ps1->persons);
  while (!QueueIsEmpty(q1)) {
    Person *p = (Person *)QueueDequeue(q1);
    // Só entra na diferença se NÃO estiver em ps2
    if (!PersonSetContains(ps2, p->id)) {
      PersonSetAdd(ps, p);
    }
  }
  QueueDestroy(&q1);

  return ps;
}


// Return true iff *ps1 is a subset of *ps2.
int PersonSetIsSubset(const PersonSet *ps1, const PersonSet *ps2) {
  assert(ps1 != NULL);
  assert(ps2 != NULL);

  // Se ps1 tiver mais elementos que ps2, não pode ser subconjunto
  if (PersonSetSize(ps1) > PersonSetSize(ps2)) {
    return 0;
  }

  // Verificar se todos os elementos de ps1 estão em ps2
  Queue *q1 = BSTreeGetItems(ps1->persons);
  while (!QueueIsEmpty(q1)) {
    Person *p = (Person *)QueueDequeue(q1);
    if (!PersonSetContains(ps2, p->id)) {
      QueueDestroy(&q1);
      return 0;
    }
  }
  QueueDestroy(&q1);

  return 1;
}


// Return true if the two sets contain exactly the same elements.
int PersonSetEquals(const PersonSet *ps1, const PersonSet *ps2) {
  return PersonSetSize(ps1) == PersonSetSize(ps2) &&
         PersonSetIsSubset(ps1, ps2);
}
