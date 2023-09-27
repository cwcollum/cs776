#include "util.h"

void runFunc1GA(char userCHCChoice, int userPopChoice, int userGenChoice, float userXOverProb, float userMutateProb, int seed, ofstream& fout){
    int inDim = 3;
    int encodeLen = 10;

    Population popul(userPopChoice, userXOverProb, userMutateProb);
    for(int j = 0; j < userPopChoice; j++){
        Individual indiv(inDim, encodeLen);
        popul.addIndividual(indiv);
    }
    popul.calcFunc1Evals();
    popul.calcFitnessSum();

    popul.findMaxFitness();
    popul.findMinFitness();
    popul.findAvgFitness();
    std::cout << "Gen(0) ";
    popul.displayPopData();

    fout << seed << ',' << 0 << ',' << popul.getMaxFitness() << ',' << popul.getMinFitness() << ',' << popul.getAvgFitness() << endl;

    for(int j = 0; j < userGenChoice; j++){
        popul.selectNewPopulation();
        if(userCHCChoice == 'y'){
            Individual CHCpop[userPopChoice*2];
            for(int x = 0; x < userPopChoice*2; x++){
                Individual temp(inDim, encodeLen);
                CHCpop[x] = temp;
            }
            popul.performCHCCrossover(CHCpop);
            popul.CHCMutate(CHCpop);
            popul.calcCHCNewEncodes(CHCpop);
            popul.calcCHCFunc1Evals(CHCpop);

            popul.chooseCHCFittest(CHCpop);
        }
        else{
            popul.performCrossover();
            popul.mutate();
            popul.calcNewEncodes();
            popul.calcFunc1Evals();
        }

        popul.calcFitnessSum();

        popul.findMaxFitness();
        popul.findMinFitness();
        popul.findAvgFitness();
        std::cout << "Gen(" << j + 1 << ") ";
        popul.displayPopData();

        fout << seed << ',' << j+1 << ',' << popul.getMaxFitness() << ',' << popul.getMinFitness() << ',' << popul.getAvgFitness() << endl;
    }
    std::cout << endl;
}

void runFunc2GA(char userCHCChoice, int userPopChoice, int userGenChoice, float userXOverProb, float userMutateProb, int seed, ofstream& fout){
    int inDim = 2;
    int encodeLen = 12;

    Population popul(userPopChoice, userXOverProb, userMutateProb);
    for(int j = 0; j < userPopChoice; j++){
        Individual indiv(inDim, encodeLen);
        popul.addIndividual(indiv);
    }
    popul.calcFunc2Evals();
    popul.calcFitnessSum();

    popul.findMaxFitness();
    popul.findMinFitness();
    popul.findAvgFitness();
    std::cout << "Gen(0) ";
    popul.displayPopData();

    fout << seed << ',' << 0 << ',' << popul.getMaxFitness() << ',' << popul.getMinFitness() << ',' << popul.getAvgFitness() << endl;

    for(int j = 0; j < userGenChoice; j++){
        popul.selectNewPopulation();
        if(userCHCChoice == 'y'){
            Individual CHCpop[userPopChoice*2];
            for(int x = 0; x < userPopChoice*2; x++){
                Individual temp(inDim, encodeLen);
                CHCpop[x] = temp;
            }
            popul.performCHCCrossover(CHCpop);
            popul.CHCMutate(CHCpop);
            popul.calcCHCNewEncodes(CHCpop);
            popul.calcCHCFunc2Evals(CHCpop);

            popul.chooseCHCFittest(CHCpop);
        }
        else{
            popul.performCrossover();
            popul.mutate();
            popul.calcNewEncodes();
            popul.calcFunc2Evals();
        }

        popul.calcFitnessSum();

        popul.findMaxFitness();
        popul.findMinFitness();
        popul.findAvgFitness();
        std::cout << "Gen(" << j + 1 << ") ";
        popul.displayPopData();

        fout << seed << ',' << j+1 << ',' << popul.getMaxFitness() << ',' << popul.getMinFitness() << ',' << popul.getAvgFitness() << endl;
    }
    std::cout << endl;
}

void runFunc3GA(char userCHCChoice, int userPopChoice, int userGenChoice, float userXOverProb, float userMutateProb, int seed, ofstream& fout){
    int inDim = 5;
    int encodeLen = 10;

    Population popul(userPopChoice, userXOverProb, userMutateProb);
    for(int j = 0; j < userPopChoice; j++){
        Individual indiv(inDim, encodeLen);
        popul.addIndividual(indiv);
    }
    popul.calcFunc3Evals();
    popul.calcFitnessSum();

    popul.findMaxFitness();
    popul.findMinFitness();
    popul.findAvgFitness();
    std::cout << "Gen(0) ";
    popul.displayPopData();

    fout << seed << ',' << 0 << ',' << popul.getMaxFitness() << ',' << popul.getMinFitness() << ',' << popul.getAvgFitness() << endl;

    for(int j = 0; j < userGenChoice; j++){
        popul.selectNewPopulation();
        if(userCHCChoice == 'y'){
            Individual CHCpop[userPopChoice*2];
            for(int x = 0; x < userPopChoice*2; x++){
                Individual temp(inDim, encodeLen);
                CHCpop[x] = temp;
            }
            popul.performCHCCrossover(CHCpop);
            popul.CHCMutate(CHCpop);
            popul.calcCHCNewEncodes(CHCpop);
            popul.calcCHCFunc3Evals(CHCpop);

            popul.chooseCHCFittest(CHCpop);
        }
        else{
            popul.performCrossover();
            popul.mutate();
            popul.calcNewEncodes();
            popul.calcFunc3Evals();
        }

        popul.calcFitnessSum();

        popul.findMaxFitness();
        popul.findMinFitness();
        popul.findAvgFitness();
        std::cout << "Gen(" << j + 1 << ") ";
        popul.displayPopData();

        fout << seed << ',' << j+1 << ',' << popul.getMaxFitness() << ',' << popul.getMinFitness() << ',' << popul.getAvgFitness() << endl;
    }
    std::cout << endl;
}

void runFunc4GA(char userCHCChoice, int userPopChoice, int userGenChoice, float userXOverProb, float userMutateProb, int seed, ofstream& fout){
    int inDim = 30;
    int encodeLen = 8;

    Population popul(userPopChoice, userXOverProb, userMutateProb);
    for(int j = 0; j < userPopChoice; j++){
        Individual indiv(inDim, encodeLen);
        popul.addIndividual(indiv);
    }
    popul.calcFunc4Evals();
    popul.calcFitnessSum();

    popul.findMaxFitness();
    popul.findMinFitness();
    popul.findAvgFitness();
    std::cout << "Gen(0) ";
    popul.displayPopData();

    fout << seed << ',' << 0 << ',' << popul.getMaxFitness() << ',' << popul.getMinFitness() << ',' << popul.getAvgFitness() << endl;

    for(int j = 0; j < userGenChoice; j++){
        popul.selectNewPopulation();
        if(userCHCChoice == 'y'){
            Individual CHCpop[userPopChoice*2];
            for(int x = 0; x < userPopChoice*2; x++){
                Individual temp(inDim, encodeLen);
                CHCpop[x] = temp;
            }
            popul.performCHCCrossover(CHCpop);
            popul.CHCMutate(CHCpop);
            popul.calcCHCNewEncodes(CHCpop);
            popul.calcCHCFunc4Evals(CHCpop);

            popul.chooseCHCFittest(CHCpop);
        }
        else{
            popul.performCrossover();
            popul.mutate();
            popul.calcNewEncodes();
            popul.calcFunc4Evals();
        }

        popul.calcFitnessSum();

        popul.findMaxFitness();
        popul.findMinFitness();
        popul.findAvgFitness();
        std::cout << "Gen(" << j + 1 << ") ";
        popul.displayPopData();

        fout << seed << ',' << j+1 << ',' << popul.getMaxFitness() << ',' << popul.getMinFitness() << ',' << popul.getAvgFitness() << endl;
    }
    std::cout << endl;
}

void runFunc5GA(char userCHCChoice, int userPopChoice, int userGenChoice, float userXOverProb, float userMutateProb, int seed, ofstream& fout){
    int inDim = 2;
    int encodeLen = 17;

    Population popul(userPopChoice, userXOverProb, userMutateProb);
    for(int j = 0; j < userPopChoice; j++){
        Individual indiv(inDim, encodeLen);
        popul.addIndividual(indiv);
    }
    popul.calcFunc5Evals();
    popul.calcFitnessSum();

    popul.findMaxFitness();
    popul.findMinFitness();
    popul.findAvgFitness();
    std::cout << "Gen(0) ";
    popul.displayPopData();

    fout << seed << ',' << 0 << ',' << popul.getMaxFitness() << ',' << popul.getMinFitness() << ',' << popul.getAvgFitness() << endl;

    for(int j = 0; j < userGenChoice; j++){
        popul.selectNewPopulation();
        if(userCHCChoice == 'y'){
            Individual CHCpop[userPopChoice*2];
            for(int x = 0; x < userPopChoice*2; x++){
                Individual temp(inDim, encodeLen);
                CHCpop[x] = temp;
            }
            popul.performCHCCrossover(CHCpop);
            popul.CHCMutate(CHCpop);
            popul.calcCHCNewEncodes(CHCpop);
            popul.calcCHCFunc5Evals(CHCpop);

            popul.chooseCHCFittest(CHCpop);
        }
        else{
            popul.performCrossover();
            popul.mutate();
            popul.calcNewEncodes();
            popul.calcFunc5Evals();
        }

        popul.calcFitnessSum();

        popul.findMaxFitness();
        popul.findMinFitness();
        popul.findAvgFitness();
        std::cout << "Gen(" << j + 1 << ") ";
        popul.displayPopData();

        fout << seed << ',' << j+1 << ',' << popul.getMaxFitness() << ',' << popul.getMinFitness() << ',' << popul.getAvgFitness() << endl;
    }
    std::cout << endl;
}