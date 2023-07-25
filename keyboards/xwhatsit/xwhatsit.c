char *initial_fp;
extern char _end;
extern char __stack;

#define MAGIC 0xaa

__attribute__((constructor))
void stack_painter(void) {
    char *ptr = (char *) &_end;
    char *fp;
    asm volatile (
        "in      %A[fp], 0x3d\n\r"
        "in      %B[fp], 0x3e"
        : [fp] "=&w" (fp));
    initial_fp = fp;
    while (ptr <= fp) {
        *ptr = MAGIC;
        ++ptr;
    }
}

int stack_used(void) {
    char *ptr = (char *) &_end;
    while ((MAGIC == *ptr) && (ptr <= initial_fp)) {
        ++ptr;
    }
    return ((int) &__stack) - (int) ptr + 1;
}
