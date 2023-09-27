#include "util.h"

int runFunc1GA(char userCHCChoice, int userPopChoice, int userGenChoice, float userXOverProb, float userMutateProb, int seed, ofstream& fout){
    int inDim = 3;
    int encodeLen = 10;
    bool found = false;
    int generations = 0;

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

    fout << seed << ',' << 0 << ',' << popul.getMaxFitness() << ',' << popul.getMinFitness() << ',' << popul.getAvgFitness() <<
        ',' << popul.getMaxObjVal() << ',' << popul.getMinObjVal() << ',' << popul.getAvgObjVal() << endl;

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
        if(popul.getMaxObjVal() <= 0.786432 && found == false){
            found = true;
            generations = j;
        }
        else if(found == false){
            generations = 1000;
        }
        popul.findMinFitness();
        popul.findAvgFitness();
        std::cout << "Gen(" << j + 1 << ") ";
        popul.displayPopData();

        fout << seed << ',' << j+1 << ',' << popul.getMaxFitness() << ',' << popul.getMinFitness() << ',' << popul.getAvgFitness() <<
        ',' << popul.getMaxObjVal() << ',' << popul.getMinObjVal() << ',' << popul.getAvgObjVal() << endl;
    }
    std::cout << endl;
    return generations;
}

int runFunc2GA(char userCHCChoice, int userPopChoice, int userGenChoice, float userXOverProb, float userMutateProb, int seed, ofstream& fout){
    int inDim = 2;
    int encodeLen = 12;
    bool found = false;
    int generations = 0;

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

    fout << seed << ',' << 0 << ',' << popul.getMaxFitness() << ',' << popul.getMinFitness() << ',' << popul.getAvgFitness() <<
        ',' << popul.getMaxObjVal() << ',' << popul.getMinObjVal() << ',' << popul.getAvgObjVal() << endl;

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
        if(popul.getMaxObjVal() <= 6.5 && found == false){
            found = true;
            generations = j;
        }
        else if(found == false){
            generations = 1000;
        }
        popul.findMinFitness();
        popul.findAvgFitness();
        std::cout << "Gen(" << j + 1 << ") ";
        popul.displayPopData();

        fout << seed << ',' << j+1 << ',' << popul.getMaxFitness() << ',' << popul.getMinFitness() << ',' << popul.getAvgFitness() <<
        ',' << popul.getMaxObjVal() << ',' << popul.getMinObjVal() << ',' << popul.getAvgObjVal() << endl;
    }
    std::cout << endl;
    return generations;
}

int runFunc3GA(char userCHCChoice, int userPopChoice, int userGenChoice, float userXOverProb, float userMutateProb, int seed, ofstream& fout){
    int inDim = 5;
    int encodeLen = 10;
    bool found = false;
    int generations = 0;

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

    fout << seed << ',' << 0 << ',' << popul.getMaxFitness() << ',' << popul.getMinFitness() << ',' << popul.getAvgFitness() <<
        ',' << popul.getMaxObjVal() << ',' << popul.getMinObjVal() << ',' << popul.getAvgObjVal() << endl;

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
        if(popul.getMaxObjVal() <= -25 && found == false){
            cout << popul.getMaxObjVal() << endl;
            found = true;
            generations = j;
        }
        else if(found == false){
            generations = 1000;
        }
        popul.findMinFitness();
        popul.findAvgFitness();
        std::cout << "Gen(" << j + 1 << ") ";
        popul.displayPopData();

        fout << seed << ',' << j+1 << ',' << popul.getMaxFitness() << ',' << popul.getMinFitness() << ',' << popul.getAvgFitness() <<
            ',' << popul.getMaxObjVal() << ',' << popul.getMinObjVal() << ',' << popul.getAvgObjVal() << endl;
    }
    std::cout << endl;
    return generations;
}

int runFunc4GA(char userCHCChoice, int userPopChoice, int userGenChoice, float userXOverProb, float userMutateProb, int seed, ofstream& fout){
    int inDim = 30;
    int encodeLen = 8;
    bool found = false;
    int generations = 0;

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

    fout << seed << ',' << 0 << ',' << popul.getMaxFitness() << ',' << popul.getMinFitness() << ',' << popul.getAvgFitness() <<
        ',' << popul.getMaxObjVal() << ',' << popul.getMinObjVal() << ',' << popul.getAvgObjVal() << endl;

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
        if(popul.getMaxObjVal() <= 5 && found == false){
            found = true;
            generations = j;
        }
        else if(found == false){
            generations = 1000;
        }
        popul.findMinFitness();
        popul.findAvgFitness();
        std::cout << "Gen(" << j + 1 << ") ";
        popul.displayPopData();

        fout << seed << ',' << j+1 << ',' << popul.getMaxFitness() << ',' << popul.getMinFitness() << ',' << popul.getAvgFitness() <<
            ',' << popul.getMaxObjVal() << ',' << popul.getMinObjVal() << ',' << popul.getAvgObjVal() << endl;
    }
    std::cout << endl;
    return generations;
}

int runFunc5GA(char userCHCChoice, int userPopChoice, int userGenChoice, float userXOverProb, float userMutateProb, int seed, ofstream& fout){
    int inDim = 2;
    int encodeLen = 17;
    bool found = false;
    int generations = 0;

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

    fout << seed << ',' << 0 << ',' << popul.getMaxFitness() << ',' << popul.getMinFitness() << ',' << popul.getAvgFitness() <<
        ',' << popul.getMaxObjVal() << ',' << popul.getMinObjVal() << ',' << popul.getAvgObjVal() << endl;

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
        if(popul.getMaxObjVal() <= 5 && found == false){
            found = true;
            generations = j;
        }
        else if(found == false){
            generations = 1000;
        }
        popul.findMinFitness();
        popul.findAvgFitness();
        std::cout << "Gen(" << j + 1 << ") ";
        popul.displayPopData();

        fout << seed << ',' << j+1 << ',' << popul.getMaxFitness() << ',' << popul.getMinFitness() << ',' << popul.getAvgFitness() <<
            ',' << popul.getMaxObjVal() << ',' << popul.getMinObjVal() << ',' << popul.getAvgObjVal() << endl;
    }
    std::cout << endl;
    return generations;
}