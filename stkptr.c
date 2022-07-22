/* 7.22.2022
   boogie de vera
   this is my initial stab at implementing a stack
   using dynamic allocation (heap) for the nodes;
   its a work in progress, functions have to be renamed like rmvend to pop
   and insend to push, additionally there's a need to test for NULL (determine if stock
   is empty before popping)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
  int info;
  struct node *next;
} node;

typedef struct node *NODEPTR;

NODEPTR getnode() {
  NODEPTR p;
  p =  (NODEPTR) malloc(sizeof(struct node));
  return (p);
}

void freenode(NODEPTR p) {
  free(p);
}
  
void traverse(NODEPTR beg) {
  NODEPTR p;
  for (p = beg;  p != NULL; p = p->next) {
    printf("%d ", p->info);
  }
  printf("\n");
}

void insend(NODEPTR plist, int x) {
  NODEPTR p, q;
  p = getnode();
  p->info = x;
  p->next = NULL;

  if (plist == NULL)
    plist =  p;
  else {
    for (q = plist;  q->next != NULL; q = q->next)
      ;
    q->next = p;
  }
}

void rmvend(NODEPTR plist) {
  NODEPTR p, q;
  for (q = plist;  q->next != NULL; q = q->next)
    p = q;
  p->next = q->next;
  freenode(q);
}

int main(int argc, const char *argv[]){
  printf("pretty cool \n");
  NODEPTR p = getnode();
  p->info = 100;
  p->next = NULL;

  NODEPTR list;
  list = p;
  insend(list, 200);
  insend(list, 300);
  insend(list, 400);
  traverse(list);
  rmvend(list);
  traverse(list);
  insend(list, 600);
  insend(list, 700);
  traverse(list);
  /* printf("\np info: %d\n", p->info); */
  
  return 0;
}
