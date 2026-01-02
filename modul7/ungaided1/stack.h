#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define MAX 20

typedef int infotype;

struct Stack {
    infotype info[MAX];
    int top;
};

/* PRIMITIF STACK */
void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

/* TAMBAHAN LATIHAN */
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif
