//
// Created by Maciej Rudy on 16/03/2023.
//
#include <string>
#include <vector>
#ifndef SDIZO_FUNCTIONS_H
#define SDIZO_FUNCTIONS_H
void readConfig(std::string fileName, int rows, std::string *configs);
void readNumbers(std::string fileName, int array[], int amount);
void workingLoop(int repetition, int *array, std::string readFile, std::string saveFile,void (*f)(int*,int), std::vector<int> instance);
int algorithmName(std::string name);
void printingProgress(bool*);
void saveModifiedNumbers(std::string fileName, int array[], int amount);
void displayArray(int arr[], int size);
#endif //SDIZO_FUNCTIONS_H
