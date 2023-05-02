//
// Created by Maciej Rudy on 16/03/2023.
//

#include "functions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>

void readConfig(std::string fileName, int rows, std::string *configs){
    std::fstream file;
    file.open(fileName, std::ios::in);
    if(file.is_open()){
        for(int i = 0; i<rows; i++){
            getline(file, configs[i]);
        }
    } else {
        printf("Something went wrong, couldn't open the file\n");
        exit(1);
    }
    file.close();
}

void readNumbers(std::string fileName, int *array, int amount){
    std::fstream file;
    std::string BUFF;
    file.open(fileName, std::ios::in);
    if (file.is_open()){
        for(int i = 0; i<amount; i++){
            file >> BUFF;
            array[i] = stoi(BUFF);
        }
        file.close();
    }else {
        printf("Something went wrong, couldn't open the file\n");
    }
}

void workingLoop(int repetition, int *array, std::string readFile, std::string saveFile, void (*f)(int*,int), std::vector<int> instance){
    std::string progress_bar;
    double percentage = 0;
    double time = 0.0;
    int size = instance.size();
    double average = 0.0;
    double progress_level = 100/double(repetition*size);
    std::fstream file;
    file.open(saveFile,std::ios::out);
    if (file.is_open()){
    for(int i=0; i<size; i++){
        for(int j=0; j<repetition; j++){
            readNumbers(readFile, array, instance[i]);
            clock_t start = clock();
            f(array, instance[i]);
            clock_t end = clock();
            time = double(end - start);
            time = (time/CLOCKS_PER_SEC)*1000;
            file << time << std::endl;
            average += time;
            percentage += progress_level;
            progress_bar.insert(0,1, '#');
            std::cout << "\r [" << std::floor(percentage) << '%' << "] " << progress_bar;
        }
        average = average/repetition;
        file << average << "\t" << instance[i] << "\t" << "average time|instance size" << std::endl;
        average = 0;
    }
    }else {
        printf("Something went wrong, couldn't open the file\n");
        exit(2);
    }
    file.close();
    std::cout << "\n\n";
    file.close();

}

int algorithmName(std::string name){
    if(name == "bubblesort"){
        return 1;
    }else if(name == "quicksort") {
        return 2;
    }else if(name == "positioning"){
        return 3;
    }else{
        return 0;
    }
}

void saveModifiedNumbers(std::string fileName, int array[], int amount){
    std::fstream file;
    file.open(fileName, std::ios::out);
    if (file.is_open()){
        for(int i = 0; i<amount; i++){
            file << array[i] << ',';
        }
        file.close();
    }else {
        printf("Something went wrong, couldn't open the file\n");
    }
}

void displayArray(int arr[], int size){
    for (int i=0; i < size-1; i++)
        std::cout<<arr[i]<<"\n";

}
