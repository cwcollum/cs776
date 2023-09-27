#include <iostream>
#include <fstream>
#include <thread>
#include <cmath>

using namespace std;

class Individual{
    float fitness;
    float objFuncValue;

    int inputDim;
    int alleleLen;
    int chromLen;

    int* chromosome;
    int* encodes;

    public:
        Individual();
        Individual(int, int);
        Individual(const Individual&);
        ~Individual();

        float getFitness();
        void setFitness(float);

        float getObjFuncValue();
        void setObjFuncValue(float);

        int getInputDim();
        int getChromLen();

        int* getChromosome();
        void setChromosome(int*);

        void initIndividual();
        void calculateEncodes();

        void printChromose();

        void performMutation(float);

        void dejongFunc1Eval();
        void dejongFunc2Eval();
        void dejongFunc3Eval();
        void dejongFunc4Eval();
        void dejongFunc5Eval();
};