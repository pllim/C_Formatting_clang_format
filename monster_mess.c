#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define FILE_NAME "monster_mess.c"

// some typedef nonsense
typedef struct point {
    int x;
    int y;
} Point;
typedef unsigned long ulong;

enum Colors { RED, GREEN, BLUE, YELLOW, ORANGE };

struct Car {
    char brand[20];
    int year;
    float mileage;
};

struct Person {
    char name[30];
    int age;
    struct Car car;
    bool hasLicense;
};

// function prototypes
int factorial(int n);
void printPerson(struct Person p);
void nestedConditionals(int a, int b, int c);
int crazyFunction(int a, int b, int c, int d, int e, int f, int g, int h, int i);
void useFuncPtr(int (*fp)(int));
int square(int x);
void drawTriangle(int size);
void messyLoops(int n);

void
printPerson(struct Person p)
{
    printf(
        "Person:%s Age:%d Car:%s Year:%d Miles:%.2f License:%s\n", p.name, p.age, p.car.brand,
        p.car.year, p.car.mileage, p.hasLicense ? "yes" : "no");
}

int
factorial(int n)
{
    int i, f = 1;
    for (i = 1; i <= n; i++) {
        f *= i;
    }
    return f;
}

double
messyMath(int a, int b, int c, int d)
{
    double val = a + b - c * d + (a * b) / (c + 1.0) - (d % 3) * 2.5 + (a * a * a) - (b * b) / 3.0 +
                 (c * c * c * c) / (d + 1.0) +
                 (a + b + c + d) * (a - b + c - d) / ((a + 1) * (b + 2)) -
                 ((a * d) + (b * c) - (a * c) + (b * d)) + ((a + b) * (c + d)) / 2.0 -
                 ((a * b * c * d) / (a + 1.0)) + (a ? b : c) * (d ? c : b) - ((a & b) | (c ^ d)) +
                 ((a << 2) + (b >> 1)) - ((c | d) & (a ^ b)) + ((a && b) || (c || d)) +
                 ((a > c) ? (b < d ? 1 : 2) : 3);
    return val;
}

void
testSwitch(int x)
{
    switch (x) {
        case 1:
            printf("Case1!\n");
            switch (x + 1) {
                case 2:
                    printf("NestedCase2!\n");
                    break;
                case 3:
                    printf("NestedCase3!\n");
                    break;
                default:
                    printf("NestedDefault!\n");
            }
            break;
        case 2:
            printf("Case2!\n");
            break;
        case 3:
            printf("Case3!\n");
            break;
        default:
            printf("Unknown!\n");
    }
}

int
crazyFunction(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    int r = a + b - c + d * e - f + g * h - i;
    return r;
}

void
useFuncPtr(int (*fp)(int))
{
    int j, k;
    for (j = 0; j < 4; j++) {
        for (k = 0; k < 3; k++) {
            printf("fp(%d*%d)=%d\n", j, k, fp(j * k));
        }
    }
}

int
square(int x)
{
    return x * x;
}

void
nestedConditionals(int a, int b, int c)
{
    if (a > 0) {
        if (b > 0) {
            if (c > 0) {
                printf("all >0\n");
            } else {
                if (c == 0) {
                    printf("c is zero\n");
                } else {
                    if (a > 5 && (b < 10 || c < -5)) {
                        printf("weird cond true\n");
                    }
                }
            }
        } else {
            if (a == 1 && !(c == 2)) {
                printf("a==1 but c!=2\n");
            }
        }
    } else {
        printf("a<=0\n");
    }
}

void
drawTriangle(int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void
messyLoops(int n)
{
    int i = 0;
    while (i < n) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0) {
                printf("(%d,%d) even\n", i, j);
            } else {
                printf("(%d,%d) odd\n", i, j);
            }
            if (j % 3 == 0) {
                for (int k = 0; k < 2; k++) {
                    printf("nested %d-%d-%d\n", i, j, k);
                }
            }
        }
        i++;
    }
}

// main
int
main()
{
    struct Car c1;
    strcpy(c1.brand, "Toyota");
    c1.year = 2010;
    c1.mileage = 123456.7;
    struct Person p1;
    strcpy(p1.name, "Bob");
    p1.age = 40;
    p1.car = c1;
    p1.hasLicense = true;
    printPerson(p1);
    printf("File Name: %s\n", FILE_NAME);
    for (int i = 0; i < 6; i++) {
        int f = factorial(i);
        printf("fact(%d)=%d\n", i, f);
        if (f % 2 == 0) {
            printf("even\n");
            for (int j = 0; j < 2; j++) {
                printf("nested j=%d\n", j);
            }
        } else {
            printf("odd\n");
        }
    }

    testSwitch(1);
    testSwitch(5);

    int result = crazyFunction(1, 2, 3, 4, 5, 6, 7, 8, 9);
    printf("crazy result=%d\n", result);

    int (*fp)(int);
    fp = square;
    useFuncPtr(fp);

    int x = 5, y = 10;
    if (x < y && y > 0) {
        printf("x<y && y>0\n");
        if (x == 5) {
            if (y == 10) {
                printf("nested condition!\n");
            }
        }
    }
    if (x == 5 || y == 0) {
        printf("x==5||y==0\n");
    }
    bool flag = true;
    if (flag) {
        printf("flag true\n");
        if (!flag) {
            printf("never happens\n");
        } else {
            if (flag && x < y) {
                printf("double nested\n");
            }
        }
    }

    nestedConditionals(1, 2, 3);
    nestedConditionals(1, -1, 2);
    nestedConditionals(6, 9, -6);

    drawTriangle(5);

    messyLoops(4);

    // enum usage
    enum Colors col = GREEN;
    switch (col) {
        case RED:
            printf("RED\n");
            break;
        case GREEN:
            printf("GREEN\n");
            break;
        default:
            printf("Other color\n");
    }

    Point pt;
    pt.x = 10;
    pt.y = 20;
    printf("Point:(%d,%d)\n", pt.x, pt.y);

    ulong big = 123456789UL;
    printf("ulong=%lu\n", big);
    double bigCalc = (1 + 2 * 3 - 4 / 5.0 + 6 % 2) - (7 * 8 - 9 / 10.0 + 11) +
                     (12 * 13 - 14 + 15 / 16.0) + (17 % 3) * (18 + 19 - 20 / 21.0 + 22 * 23) -
                     (24 * 25 / 26.0 - 27 + 28 * 29) + (30 ^ 31) - (32 | 33) + (34 & 35) +
                     ((36 + 37) * (38 - 39) / (40 + 41 - 42)) + (43 * 44 * 45 * 46 / 47.0) -
                     ((48 % 5) + (49 / 50.0) - (51 * 52)) +
                     ((53 + 54 + 55 + 56 + 57) / (58 * 59 - 60)) + ((61 << 2) - (62 >> 1)) +
                     ((63 && 64) || (65 || 66)) - ((67 ? 68 : 69) + (70 ? 71 : 72));
    printf("bigCalc=%f\n", bigCalc);

    double mm = messyMath(3, 5, 7, 9);
    printf("messyMath=%f\n", mm);

    Point *np = (Point *)calloc(1, sizeof(*np));
    if (np) {
        free(np);
    }
    np = NULL;

    return 0;
}
