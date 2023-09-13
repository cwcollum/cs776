#include <iostream>

using namespace std;

double eval(int *pj);

double evalEasy(int* pj);
double evalHard(int* pj);

void generateRandomSolution(int* vector);
void createHardOptimum(int* sol);

void modifySolution(int* vector, int* newVec);

void bruteForce(int* vector, double fitness);
void intToBinary(int* binArray, long int n);

void copyArray(int* arr1, int* arr2);
void printArray(int* vector);
void resetEncode(int* array);

int main(){
    srand(time(0));

    int initSol[100] = {0};
    int newSol[100] = {0};
    double fitnessBase = 0;
    double fitnessNew = 0;
    int iter = 0;
    int fitnessChange = 0;

    generateRandomSolution(initSol);

    // including the following lines of code to prove there is a solution
    // createHardOptimum(initSol);
    // fitnessBase = evalHard(initSol);
    // cout << fitnessBase << endl;

    // PSEUDOCODE
    while(fitnessBase != 100){
        modifySolution(initSol, newSol);
        fitnessNew = evalHard(newSol);
        if(fitnessNew > fitnessBase){
            copyArray(initSol, newSol);
            fitnessBase = fitnessNew;
            fitnessChange = 0;
        }
        iter++;
        fitnessChange++;
        if(fitnessChange == 100000){
            //If running for eval1, brute force solution
            // bruteForce(initSol, fitnessBase);

            //If running for evalHard, simply terminate program.
            break;
        }
        cout << "Iter: " << iter << " | Fitness: " << fitnessBase << endl;
    }

    printArray(initSol);

    return 0;
}

////////////////////////Functions//////////////////////////

void generateRandomSolution(int* vector){
    for(int i = 0; i < 100; i++){
        vector[i] = rand() % 2;
    }
}

//This is the algorithm for solving eval.o.  Simply flips bits until solution is found
void modifySolution(int* vector, int* newVec){
    int index = rand() % 100;
    copyArray(newVec, vector);
    newVec[index] = 1 - vector[index];
}

void copyArray(int* arr1, int* arr2){
    for(int i = 0; i < 100; i++){
        arr1[i] = arr2[i];
    }
}

void printArray(int* vector){
    for(int i = 0; i < 100; i++){
        cout << vector[i];
    }
    cout << endl;
}

//This is the final part of the algorithm for solving the first 30 bits
void bruteForce(int* vector, double fitness){
    int value = 0;
    int binary[30] = {0};
    while(fitness != 100){
        intToBinary(binary, value);
        cout << "Brute Iter: " << value << endl;
        for(int i = 0; i < 30; i++){
            vector[i] = binary[i];
            cout << binary[i];
        }
        cout << endl;
        fitness = eval(vector);
        value++;
    }
}