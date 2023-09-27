#include "individual.h"

class Population{
    int popSize;
    int count;
    float fitnessSum;
    float objValSum;

    float xoverProb;
    float mutateProb;

    float maxFitness;
    float minFitness;
    float avgFitness;

    float maxObjVal;
    float minObjVal;
    float avgObjVal;

    Individual* individual;
    Individual* newIndividual;

    public:
        Population();
        Population(int, float, float);
        Population(const Population&);
        ~Population();

        int getPopSize();
        void setPopSize(int);

        float getMaxFitness();
        float getMinFitness();
        float getAvgFitness();
        float getfitnessSum();

        float getMaxObjVal();
        float getMinObjVal();
        float getAvgObjVal();

        void addIndividual(Individual);
        void printPopulation();
        void printNewPopulation();

        void calcFitnessSum();

        void selectNewPopulation();
        
        void performCrossover();

        void performCHCCrossover(Individual*);
        void calcCHCNewEncodes(Individual*);
        void CHCMutate(Individual*);
        void chooseCHCFittest(Individual*);

        void calcNewEncodes();
        void mutate();

        void findMaxFitness();
        void findMinFitness();
        void findAvgFitness();

        void displayPopData();

        void calcFunc1Evals();
        void calcFunc2Evals();
        void calcFunc3Evals();
        void calcFunc4Evals();
        void calcFunc5Evals();

        void calcCHCFunc1Evals(Individual*);
        void calcCHCFunc2Evals(Individual*);
        void calcCHCFunc3Evals(Individual*);
        void calcCHCFunc4Evals(Individual*);
        void calcCHCFunc5Evals(Individual*);
};