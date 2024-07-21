#include <stdio.h>

#define MAX 10

/* Function prototypes */
void create();
void insert();
void deletion();
void search();
void display();

/* Global variables */
int b[MAX], n, p, e, i, pos;

int main() {
    int ch;
    char g = 'y';

    do {
        printf("\n Main Menu");
        printf("\n 1. Create \n 2. Delete \n 3. Search \n 4. Insert \n 5. Display\n 6. Exit \n");
        printf("\n Enter your Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;  // Exit from main function
            default:
                printf(" \n Enter the correct choice:\n");
        }

        printf("\n Do you want to continue (y/n): ");
        scanf(" %c", &g);  // Note the space before %c to consume any whitespace
    } while (g == 'y' || g == 'Y');

    return 0;
}

void create() {
    printf("\n Enter the number of nodes: ");
    scanf("%d", &n);

    printf("\n Enter the Elements:\n");
    for (i = 0; i < n; i++) {
        printf(" Element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    printf("\n Enter the position you want to delete: ");
    scanf("%d", &pos);

    if (pos >= n || pos < 0) {
        printf("\n Invalid Location\n");
    } else {
        for (i = pos; i < n - 1; i++) {
            b[i] = b[i + 1];
        }
        n--;
        printf("\n Element deleted successfully\n");
    }
}

void search() {
    printf("\n Enter the Element to be searched: ");
    scanf("%d", &e);

    for (i = 0; i < n; i++) {
        if (b[i] == e) {
            printf(" Element found at position %d\n", i + 1);
            return;
        }
    }
    printf(" Element %d not found\n", e);
}

void insert() {
    printf("\n Enter the position you need to insert: ");
    scanf("%d", &pos);

    if (pos >= n || pos < 0) {
        printf("\n Invalid Location\n");
    } else {
        printf("\n Enter the element to insert: ");
        scanf("%d", &p);

        for (i = n - 1; i >= pos; i--) {
            b[i + 1] = b[i];
        }
        b[pos] = p;
        n++;
        printf("\n Element inserted successfully\n");
    }
}

void display() {
    if (n == 0) {
        printf("\n The list is empty\n");
    } else {
        printf("\n The Elements of The list are:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", b[i]);
        }
        printf("\n");
    }
}
