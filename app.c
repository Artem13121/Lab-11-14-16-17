#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

#define N 200
#define MAX_SIZE 10000

// ==================== ОБЩИЕ ФУНКЦИИ ====================
void print_double(double* a, int n) {
    for (int i = 0; i < n; i++) printf("%.2f ", a[i]);
    printf("\n");
}

void print_int(int* a, int n) {
    for (int i = 0; i < (n > 20 ? 20 : n); i++)
        printf("%d ", a[i]);
    if (n > 20) printf("... (%d)", n);
    printf("\n");
}

// ==================== ПРОГРАММА 1 ====================
void prog1() {
    printf("\n=== Сумма элементов кроме min и max ===\n");

    int n, A[10];
    printf("Количество (1-10): ");
    scanf("%d", &n);

    printf("Введите %d чисел: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);

    int min = A[0], max = A[0], sum = 0;
    for (int i = 1; i < n; i++) {
        if (A[i] < min) min = A[i];
        if (A[i] > max) max = A[i];
    }

    for (int i = 0; i < n; i++)
        if (A[i] != min && A[i] != max) sum += A[i];

    printf("Сумма без %d и %d = %d\n", min, max, sum);
}

// ==================== ПРОГРАММА 2 ====================
void fill_double(double* a, int n) {
    double x, dx;
    printf("x dx: ");
    scanf("%lf %lf", &x, &dx);
    for (int i = 0; i < n; i++) {
        a[i] = 5 * x * x * x + 2 * x * x + 15 * x - 6;
        x += dx;
    }
}

double sum_range(double* a, int b, int e) {
    double s = 0;
    for (int i = b; i <= e; i++) s += a[i];
    return s;
}

int find_val(double* a, int n, double v) {
    for (int i = 0; i < n; i++)
        if (fabs(a[i] - v) < 0.001) return i;
    return -1;
}

void add_last(double* a, int n) {
    double last = a[n - 1];
    for (int i = 0; i < n; i++) a[i] += last;
}

void prog2() {
    printf("\n=== Работа с double массивом ===\n");

    double a[N];
    int n;
    printf("Размер (1-%d): ", N);
    scanf("%d", &n);

    fill_double(a, n);
    printf("Массив: "); print_double(a, n);

    int b, e;
    printf("Границы суммы: ");
    scanf("%d %d", &b, &e);
    if (b >= 0 && e < n && b <= e)
        printf("Сумма [%d..%d]: %.2f\n", b, e, sum_range(a, b, e));

    double v;
    printf("Найти значение: ");
    scanf("%lf", &v);
    int pos = find_val(a, n, v);
    printf("Позиция: %s\n", pos != -1 ? "найдена" : "не найдена");

    add_last(a, n);
    printf("После +последнего: "); print_double(a, n);
}

// ==================== ПРОГРАММА 3 ====================
int find_min_idx(double* a, int n) {
    int idx = 0;
    for (int i = 1; i < n; i++)
        if (a[i] < a[idx]) idx = i;
    return idx;
}

void insert_after_min(double* a, int* n, int k) {
    int min_idx = find_min_idx(a, *n);

    for (int i = *n - 1; i > min_idx; i--)
        a[i + k] = a[i];

    for (int i = 1; i <= k; i++)
        a[min_idx + i] = -999.0;

    *n += k;
}

void prog3() {
    printf("\n=== Вставка после минимального ===\n");

    double a[N];
    int n;
    printf("Размер (1-%d): ", N);
    scanf("%d", &n);

    fill_double(a, n);
    printf("Массив: "); print_double(a, n);

    int k;
    printf("Сколько -999 вставить: ");
    scanf("%d", &k);

    insert_after_min(a, &n, k);
    printf("После вставки: "); print_double(a, n);
}

// ==================== ПРОГРАММА 4 ====================
void fill_random(int* a, int n) {
    for (int i = 0; i < n; i++)
        a[i] = rand() % 1000 - 500;
}

void bubble(int* a, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) {
                int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
            }
}

void shaker(int* a, int n) {
    int l = 0, r = n - 1;
    while (l < r) {
        for (int i = l; i < r; i++)
            if (a[i] > a[i + 1]) { int t = a[i]; a[i] = a[i + 1]; a[i + 1] = t; }
        r--;
        for (int i = r; i > l; i--)
            if (a[i] < a[i - 1]) { int t = a[i]; a[i] = a[i - 1]; a[i - 1] = t; }
        l++;
    }
}
void selection(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min]) min = j;
        if (min != i) { int t = a[i]; a[i] = a[min]; a[min] = t; }
    }
}

void insertion(int* a, int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j]; j--;
        }
        a[j + 1] = key;
    }
}

void test_sort(void (*func)(int*, int), char* name, int size) {
    int* arr = malloc(size * sizeof(int));
    fill_random(arr, size);

    clock_t start = clock();
    func(arr, size);
    double time = (double)(clock() - start) / CLOCKS_PER_SEC;

    printf("%-15s: %.4f сек\n", name, time);
    free(arr);
}

void prog4() {
    printf("\n=== Сравнение сортировок ===\n");

    int size;
    printf("Размер массива: ");
    scanf("%d", &size);

    srand(time(NULL));
    printf("\nВремя сортировки:\n");
    test_sort(bubble, "Пузырьковая", size);
    test_sort(shaker, "Шейкерная", size);
    test_sort(selection, "Выбором", size);
    test_sort(insertion, "Вставками", size);
}

// ==================== ГЛАВНОЕ МЕНЮ ====================
int main() {
    setlocale(LC_ALL, "rus");

    while (1) {
        printf("\n=== МЕНЮ ===\n");
        printf("1. Сумма без min/max\n");
        printf("2. Double массив\n");
        printf("3. Вставка после min\n");
        printf("4. Сортировки\n");
        printf("0. Выход\nВыбор: ");

        int choice; scanf("%d", &choice);
        if (choice == 0) break;

        switch (choice) {
        case 1: prog1(); break;
        case 2: prog2(); break;
        case 3: prog3(); break;
        case 4: prog4(); break;
        }

        printf("\nEnter..."); getchar(); getchar();
    }

    return 0;
}