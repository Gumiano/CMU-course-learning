#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; ++i)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

int main() {
    // char *str = "hello world";
    // show_pointer(str);
    // int a = 233;
    // show_int(a);
    const char *s = "abcdef";
    show_bytes((byte_pointer) s, strlen(s));

    // 数字位模式的扩展
    short sx = -12345;
    unsigned short usx = sx;
    int x = sx;
    unsigned int ux = usx;

    printf("sx = %d:\t", sx);
    show_bytes((byte_pointer) &sx, sizeof(short));
    printf("usx = %d:\t", usx);
    show_bytes((byte_pointer) &usx, sizeof(unsigned short));
    printf("x = %d:\t", x);
    show_bytes((byte_pointer) &x, sizeof(int));
    printf("ux = %d:\t", ux);
    show_bytes((byte_pointer) &ux, sizeof(unsigned));
}

//       0000 0001 ~ 1111 1110
// bias:  111 1111 ~  111 1111
//        000 0000 ~  111 1111