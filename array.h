#ifndef ARRAY_H
#define ARRAY_H

#include <math.h>
#include <stdlib.h>

// ==================== БАЗОВЫЕ ФУНКЦИИ ====================

/**
 * Заполнение массива значениями функции fa(i)
 * @param ptr_array указатель на массив
 * @param size размер массива
 * @return указатель на заполненный массив
 */
double* full_elements(double* ptr_array, int size);

/**
 * Печать элементов массива
 * @param ptr_array указатель на массив
 * @param n количество элементов
 * @return количество выведенных элементов
 */
int put_elements(double* ptr_array, int n);

/**
 * Обнуление отрицательных элементов массива
 * @param ptr_array указатель на массив
 * @param n количество элементов
 * @return указатель на изменённый массив
 */
double* calc_elements(double* ptr_array, int n);

// ==================== ВЫЧИСЛИТЕЛЬНЫЕ ФУНКЦИИ ====================

/**
 * Сумма элементов на интервале [begin..end]
 * @param ptr_array указатель на массив
 * @param begin начальный индекс
 * @param end конечный индекс
 * @param n размер массива
 * @return сумма элементов или 0.0
 */
double sum_elements(double* ptr_array, int begin, int end, int n);

/**
 * Поиск первого вхождения элемента в массиве
 * @param ptr_array указатель на массив
 * @param n количество элементов
 * @param element искомое значение
 * @return индекс первого совпадения или -1
 */
int find_element(double* ptr_array, int n, double element);

/**
 * Максимальное по модулю значение, не равное A
 * @param ptr_array указатель на массив
 * @param n количество элементов
 * @param A исключаемое значение
 * @return максимум |x_i| где x_i <> A
 */
double max_abs(double* ptr_array, int n, double A);

// ==================== МАТЕМАТИЧЕСКИЕ ФУНКЦИИ ====================

/**
 * Вычисление функции y = x²·π·cos(π·x)
 * @param x аргумент функции
 * @return значение функции в точке x
 */
double fa(double x);

/**
 * Разность максимума и минимума на интервале [begin..end]
 * @param ptr_array указатель на массив
 * @param begin начальный индекс интервала
 * @param end конечный индекс интервала
 * @param n размер массива
 * @return разность max-min или -1.0 при ошибке
 */
double max_min_diff(double* ptr_array, int begin, int end, int n);

// ==================== ДИНАМИЧЕСКИЕ ОПЕРАЦИИ ====================

/**
 * Удаление всех отрицательных элементов
 * @param ptr_arr указатель на массив
 * @param size текущее количество элементов
 * @return новое количество элементов после удаления
 */
int delete_negatives(double* ptr_arr, int size);

/**
 * Вставка -999.0 после каждого положительного элемента
 * @param ptr_arr указатель на массив
 * @param size указатель на размер массива
 * @return указатель на расширенный массив
 */
double* insert(double* ptr_arr, int* size);

/**
 * Генерация случайного массива
 * @param size указатель на размер массива
 * @return указатель на новый массив со случайными double [-50, +50]
 */
double* generate_array(int* size);

/**
 * Создание массива D из трёх массивов по специальным правилам
 * @param arr_a, arr_b, arr_c исходные массивы
 * @param size_a, size_b, size_c их размеры
 * @param size_d указатель на размер результирующего массива
 * @return указатель на новый динамический массив D
 */
double* create_arr_d(double* arr_a, double* arr_b, double* arr_c, 
                     int size_a, int size_b, int size_c, int* size_d);

// ==================== ФУНКЦИИ СОРТИРОВКИ ====================

/**
 * Пузырьковая сортировка по возрастанию
 * @param ptr_array указатель на массив
 * @param n количество элементов
 */
void sort_bubble(double* ptr_array, int n);

/**
 * Сортировка выбором по убыванию
 * @param ptr_array указатель на массив
 * @param n количество элементов
 */
void sort_select(double* ptr_array, int n);

/**
 * Сортировка вставками по возрастанию
 * @param ptr_array указатель на массив
 * @param n количество элементов
 */
void sort_insert(double* ptr_array, int n);

/**
 * Шейкерная сортировка по возрастанию
 * @param arr указатель на массив
 * @param size количество элементов
 * @return 0 при успешном выполнении
 */
int sort_cocktail(double* arr, int size);

#endif 
