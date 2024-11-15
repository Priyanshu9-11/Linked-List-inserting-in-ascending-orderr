#include <stdio.h>
#include <stdlib.h>

struct list {
    int info;
    struct list *next;
};

typedef struct list node;

node *insertasc(node *, int);
void display(node *);
node *create();

main() {
    node *s = NULL;
    int n;


    s = create();

    printf("Enter the number to be inserted in sorted order: ");
    scanf("%d", &n);

    s = insertasc(s, n);
    display(s);


}

node *insertasc(node *s, int n) {
    node *nn, *temp;
    nn = (node *)malloc(sizeof(node));
    nn->info = n;
    nn->next = NULL;


    if (s == NULL || n < s->info) {
        nn->next = s;
        s = nn;
    } else {
        temp = s;
        while (temp->next != NULL && temp->next->info < n) {
            temp = temp->next;
        }
        nn->next = temp->next;
        temp->next = nn;
    }
    return s;
}

void display(node *s) {
    node *temp = s;
    while (temp != NULL) {
        printf("%d\n", temp->info);
        temp = temp->next;
    }
}

node *create() {
    node *s = NULL, *p = NULL, *nn;
    int n;
    char ano = 'y';

    while (ano == 'y' || ano == 'Y') {
        printf("Enter the number: ");
        scanf("%d", &n);

        nn = (node *)malloc(sizeof(node));
        nn->info = n;
        nn->next = NULL;

        if (s == NULL) {
            s = nn;
        } else {
            p->next = nn;
        }
        p = nn;

        printf("Continue? [y/n]: ");
        fflush(stdin);
        scanf(" %c", &ano);
    }

    return s;
}
