//
// Created by Maciej Rudy on 16/03/2023.
//

#include "algorithms.h"
#include "functions.h"

void bubbleSort(int *array, int instance){
    int buff = 0;
    for (int i = 0; i < instance+1; i++) {
        for (int j = 1; j < instance; j++) {
            if (array[j - 1] > array[j]) {
                buff = 0;
                buff = array[j - 1];
                array[j - 1] = array[j];
                array[j] = buff;
            }
        }
        //printf("\e[1;1H\e[2J"); /* for clearing console */
    }
}

void quickSort(int* array, int size) {
    if (size <= 1) {
        return;
    }
    int i = 0, j = size - 1;
    int contain = 0;
    int pivot = array[(0 + size - 1) / 2];
    while (i <= j) {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j) {
            contain = array[i];
            array[i] = array[j];
            array[j] = contain;
            i++;
            j--;
        }
    }
    quickSort(array, j + 1);
    quickSort(array + i, size - i);
}

void positioningSort(int* array, int size) {
    int max = array[0];
    int min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
        if (array[i] < min) {
            min = array[i];
        }
    }
    int* output = (int*)malloc(size * sizeof(int));
    int* count = (int*)calloc(10, sizeof(int));
    for (int exp = 1; (max - min) / exp > 0; exp *= 10) {
        for (int i = 0; i < size; i++) {
            int digit = (array[i] - min) / exp % 10;
            count[digit]++;
        }
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        for (int i = size - 1; i >= 0; i--) {
            int digit = (array[i] - min) / exp % 10;
            output[count[digit] - 1] = array[i];
            count[digit]--;
        }
        for (int i = 0; i < size; i++) {
            array[i] = output[i];
        }
        for (int i = 0; i < 10; i++) {
            count[i] = 0;
        }
    }
    free(output);
    free(count);
}