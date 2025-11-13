//
// Algoritmos e Estruturas de Dados --- 2024/2025
//
// Joaquim Madeira, Nov 2023, Nov 2024
//

// Complete the functions (marked by ...)
// so that they pass all tests.

#include "PersonSet.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SortedList.h"

// NOTE THAT:
// - Field capacity was eliminated.
// - Field size was eliminated, because size==ListGetSize(...).

// Definition of the structure
struct _PersonSet_ {
  List *persons;  // points to a SortedList of Person pointers
};

// Comparison function to be used in generic SortedList.
// Comparison is based on Person ID
static int cmpP(const void *a, const void *b) {
  Person *p1 = (Person *)a;
  Person *p2 = (Person *)b;
  int d = p1->id - p2->id;
  return (d > 0) - (d < 0);
}

// Create a PersonSet.
PersonSet *PersonSetCreate() {
  // You must allocate space for the struct and create an empty persons list!
  PersonSet *ps = (PersonSet *)malloc(sizeof(PersonSet));
  assert(ps != NULL);
  ps->persons = ListCreate(cmpP);
  return ps;
}

// Destroy PersonSet *pps
void PersonSetDestroy(PersonSet **pps) {
  assert(*pps != NULL);
  PersonSet *ps = *pps;
  ListDestroy(&(ps->persons));
  free(ps);
  *pps = NULL;
}

int PersonSetSize(const PersonSet *ps) { return ListGetSize(ps->persons); }

int PersonSetIsEmpty(const PersonSet *ps) { return ListIsEmpty(ps->persons); }

void PersonSetPrint(const PersonSet *ps) {
  printf("{\n");
  for (ListMoveToHead(ps->persons); ListCurrentIsInside(ps->persons);
       ListMoveToNext(ps->persons)) {
    Person *p = (Person *)ListGetCurrentItem(ps->persons);
    PersonPrintf(p, ";\n");
  }
  printf("}(size=%d)\n", PersonSetSize(ps));
  ListTestInvariants(ps->persons);
}

// Find node in list ps->persons of person with given id.
// (INTERNAL function.)
static int search(const PersonSet *ps, int id) {
  Person miguelperson;
  miguelperson.id = id;
  return ListSearch(ps->persons, &miguelperson);
}

// Add person *p to *ps.
// Do nothing if *ps already contains a person with the same id.
void PersonSetAdd(PersonSet *ps, Person *p) {
  Person Miguel;
  Miguel.id = p->id;

  //se ja existir
  if(ListSearch(ps->persons, &Miguel)==0){
    return;
  }
  ListInsert(ps->persons, p);
}

// Pop one person out of *ps.
Person *PersonSetPop(PersonSet *ps) {
  assert(!PersonSetIsEmpty(ps));
  // It is easiest to pop and return the person in the first position!
  ListMoveToHead(ps->persons);
  return (Person *)ListRemoveHead(ps->persons);
}

// Remove the person with given id from *ps, and return it.
// If no such person is found, return NULL and leave set untouched.
Person *PersonSetRemove(PersonSet *ps, int id) {
  // You may call search here!
  assert(ps != NULL);

  Person miguel;
  miguel.id = id;

  if (ListSearch(ps->persons, &miguel) < 0){
    return NULL;
  } 

  return (Person *)ListRemoveCurrent(ps->persons);
}

// Get the person with given id of *ps.
// return NULL if it is not in the set.
Person *PersonSetGet(const PersonSet *ps, int id) {
  // You may call search here!
  assert(ps != NULL);

  Person miguel;
  miguel.id = id;

  if (ListSearch(ps->persons, &miguel) < 0) return NULL;

  return (Person *)ListGetCurrentItem(ps->persons);

  return NULL;
}

// Return true (!= 0) if set contains person wiht given id, false otherwise.
int PersonSetContains(const PersonSet *ps, int id) {
  return search(ps, id) >= 0;
}

// Return a NEW PersonSet with the union of *ps1 and *ps2.
// NOTE: memory is allocated.  Client must call PersonSetDestroy!
PersonSet *PersonSetUnion(const PersonSet *ps1, const PersonSet *ps2) {
  PersonSet *ps = PersonSetCreate();

  // Add all persons from ps1
  for (ListMoveToHead(ps1->persons); ListCurrentIsInside(ps1->persons);
       ListMoveToNext(ps1->persons)) {
    Person *p = (Person *)ListGetCurrentItem(ps1->persons);
    ListInsert(ps->persons, p);
  }

  // Add persons from ps2 that are not in ps1
  for (ListMoveToHead(ps2->persons); ListCurrentIsInside(ps2->persons);
       ListMoveToNext(ps2->persons)) {
    Person *p = (Person *)ListGetCurrentItem(ps2->persons);
    if (!PersonSetContains(ps, p->id)) {
      ListInsert(ps->persons, p);
    }
  }

  return ps;
}

// Return a NEW PersonSet with the intersection of *ps1 and *ps2.
// NOTE: memory is allocated.  Client must call PersonSetDestroy!
PersonSet *PersonSetIntersection(const PersonSet *ps1, const PersonSet *ps2) {
  PersonSet *ps = PersonSetCreate();

  ListMoveToHead(ps1->persons);
  ListMoveToHead(ps2->persons);

  while (ListCurrentIsInside(ps1->persons) && ListCurrentIsInside(ps2->persons)) {
    Person *p1 = (Person *)ListGetCurrentItem(ps1->persons);
    Person *p2 = (Person *)ListGetCurrentItem(ps2->persons);

    if (p1->id == p2->id) {
      ListInsert(ps->persons, p1);
      ListMoveToNext(ps1->persons);
      ListMoveToNext(ps2->persons);
    } else if (p1->id < p2->id) {
      ListMoveToNext(ps1->persons);
    } else {
      ListMoveToNext(ps2->persons);
    }
  }

  return ps;
}

// Return a NEW PersonSet with the set difference of *ps1 and *ps2.
// NOTE: memory is allocated.  Client must call PersonSetDestroy!
PersonSet *PersonSetDifference(const PersonSet *ps1, const PersonSet *ps2) {
  PersonSet *ps = PersonSetCreate();

  ListMoveToHead(ps1->persons);
  ListMoveToHead(ps2->persons);

  while (ListCurrentIsInside(ps1->persons)) {
    Person *p1 = (Person *)ListGetCurrentItem(ps1->persons);
    Person *p2;

    if (ListCurrentIsInside(ps2->persons)) {
      p2 = (Person *)ListGetCurrentItem(ps2->persons);
    } else {
      p2 = NULL;
    }

    if (p2 == NULL || p1->id < p2->id) {
      ListInsert(ps->persons, p1);
      ListMoveToNext(ps1->persons);
    } else if (p1->id > p2->id) {
      ListMoveToNext(ps2->persons);
    } else {  // iguais → ignora p1
      ListMoveToNext(ps1->persons);
      ListMoveToNext(ps2->persons);
    }
  }
  return ps;
}

// Return true iff *ps1 is a subset of *ps2.
int PersonSetIsSubset(const PersonSet *ps1, const PersonSet *ps2) {
  ListMoveToHead(ps1->persons);
  ListMoveToHead(ps2->persons);

  while (ListCurrentIsInside(ps1->persons)) {
    if (!ListCurrentIsInside(ps2->persons)) return 0;

    Person *p1 = (Person *)ListGetCurrentItem(ps1->persons);
    Person *p2 = (Person *)ListGetCurrentItem(ps2->persons);

    if (p1->id == p2->id) {
      ListMoveToNext(ps1->persons);
      ListMoveToNext(ps2->persons);
    } else if (p1->id > p2->id) {
      ListMoveToNext(ps2->persons);
    } else {
      return 0;  // p1->id < p2->id → falta em ps2
    }
  }
  return 1;
}

// Return true if the two sets contain exactly the same elements.
int PersonSetEquals(const PersonSet *ps1, const PersonSet *ps2) {
  // You may call PersonSetIsSubset here!
  if (PersonSetSize(ps1) != PersonSetSize(ps2)) return 0;
  return PersonSetIsSubset(ps1, ps2);
}
