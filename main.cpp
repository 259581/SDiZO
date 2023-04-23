#include <string>
#include <vector>
#include <thread>
#include "functions.h"  // header file
#include "algorithms.h" //header file

/******** Config instruction ********/
/* index 0 - file with numbers */
/* index 1 - file with modified numbers */
/* index 2 - name of the algorithm */
/* index 3 - file with algorithm's run-time */
/* index 4 - amount of repetitions */
/* index 5 - how many numbers to read */

int main() {

    std::vector <int> firstInstance = {10,20,30,40,50,75,100,150,200,350,500,750,1000,1500,2000,3000,4000,5000,7500,10000};
    std::vector <int> secondInstance = {12000,15000,17000,20000,30000,40000,50000,75000,100000};
    std::vector <int> thirdInstance = {150000,200000,300000,400000,500000,700000,900000,1000000};

    std::string *configs = new std::string[6];

    readConfig("/Users/maciejrudy/CLionProjects/SDiZO/config.txt",6,configs);
    int *array = new int[stoi(configs[5])];
    int choice = algorithmName(configs[2]);
    switch(choice){
        case 1:
            printf("You have chosen bubble-sort\n");
            workingLoop(stoi(configs[4]), array,configs[0], configs[3], bubbleSort, firstInstance);
            saveModifiedNumbers(configs[1], array, stoi(configs[5]));
            break;

        case 2:
            printf("You have chosen quick-sort\n");
            workingLoop(stoi(configs[4]), array,configs[0], configs[3], quickSort, firstInstance);
            saveModifiedNumbers(configs[1], array, stoi(configs[5]));
            break;
        case 3:
            printf("You have chosen positioning-sort\n");
            workingLoop(stoi(configs[4]), array,configs[0], configs[3], positioningSort, firstInstance);
            saveModifiedNumbers(configs[1], array, stoi(configs[5]));
            break;
        default:
            printf("You haven't chosen anything from the list\n");
            exit(1);
    }

    //displayArray(array,10002);
    delete[] array;
    delete[] configs;
    return 0;
}

