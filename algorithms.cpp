//
// Created by Maciej Rudy on 16/03/2023.
//

#include "algorithms.h"
#include "functions.h"
#include <thread>

void bubbleSort(int *array, int instance){
    int buff = 0;
    bool should_animate = true;
    std::thread animation(printingProgress,&should_animate);
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
    should_animate = false;
    animation.join();
}

void quickSort(int* array, int size) {
    if (size <= 1) {
        return;
    }
    int i = 0, j = size - 1;
    int contain = 0;
    int pivot = array[(0 + size - 1) / 2];
    bool should_animate = true;
    std::thread animation(printingProgress,&should_animate);
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
    should_animate = false;
    animation.join();
    quickSort(array, j + 1);
    quickSort(array + i, size - i);
}

void countingSort(int* array, int size){
    int max = array[0];
    for(int i = 0; i<size-1; i++){  //znajdowanie max w tablicy
        if(array[i]>max){
            max = array[i];
        }
    }

    int appears[max];   //tablica wystapien
    for(int i = 0; i<max-1; i++){
        appears[i] = 0;
    }

    for(int i = 0 ; i < size ; ++i){
        ++appears[array[i]];
    }

    for(int i = 1 ; i < max ; ++i){
        appears[i] += appears[i - 1];
    }
    int pomocnicza[max];
    for(int i = 0; i<max-1; i++){
        pomocnicza[i] = 0;
    }

    for(int i = size-1 ; i >= 0 ; --i) {
        pomocnicza[--appears[array[i]]] = array[i];  //POMOCNICZA MOZE?
    }

    for(int i = 0; i<max-1; i++){
        printf("%d\n",pomocnicza[i]);
    }
}