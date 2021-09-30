#include <stdio.h>

int main() {
    char c;
    int i;
    long l;
    
    c = 'a';
    i = 17;
    l = 999999999999;
    
    printf("Variable addresses:\n\nc: %p\ni: %p\nl: %p\n", &c, &i, &l);
    
    char *pc;
    int *pi;
    long *pl;
    
    pc = &c;
    pi = &i;
    pl = &l;
    
    printf("\nValues of pointers:\n\npc: %p\npi: %p\npl: %p\n", pc, pi, pl);
    
    *pc = '!';
    *pi = -12;
    *pl = 123456789;
    
    printf("\nNew values:\n\nc: %c\ni: %d\nl: %ld\n", c, i, l);
    
    unsigned int ui;
    ui = 100;
    
    int *pui_0 = &ui;
    char *pui_1 = &ui;
    
    printf("\nValues of pointers:\n\npui_0:\tAddress: %p\tValue: %d\npui_1:\tAddress: %p\tValue: %c\n", pui_0, *pui_0, pui_1, *pui_1);
    
    printf("\nUnsigned int: %u\nHex: %x\n", ui, ui);
    
    printf("\nByte by byte: ");
    
    int count = 0;
    while (count < sizeof(ui)) {
        printf("%hhu", *((char *) pui_1 + count));
        count++;
    }
    
    printf("\n\nModifying byte by byte:\n\n");
    
    count = 0;
    while (count < sizeof(ui)) {
        *((char *) pui_1 + count) += 1;
        printf("Unsigned int: %u\tHex: %x\n", ui, ui);
        count++;
    }
    
    printf("\n\nModifying byte by byte by 16:\n\n");
    
    ui = 100;
    
    count = 0;
    while (count < sizeof(ui)) {
        *((char *) pui_1 + count) += 16;
        printf("Unsigned int: %u\tHex: %x\n", ui, ui);
        count++;
    }
}
