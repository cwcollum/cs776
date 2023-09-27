#include "population.h"

Population::Population(){
    popSize = 1;
    count = 0;
    fitnessSum = 0;
    xoverProb = 0.6;
    mutateProb = 0.001;
    individual = new Individual[1];
    newIndividual = new Individual[1];
}

Population::Population(int size, float xover, float mutate){
    popSize = size;
    count = 0;
    fitnessSum = 0;
    xoverProb = xover;
    mutateProb = mutate;
    individual = new Individual[popSize];
    newIndividual = new Individual[popSize];
}

Population::Population(const Population& rhs){
    popSize = rhs.popSize;
    count = rhs.count;
    fitnessSum = rhs.fitnessSum;
    xoverProb = rhs.xoverProb;
    mutateProb = rhs.mutateProb;
    individual = new Individual[popSize];
    for(int i = 0; i < popSize; i++){
        individual[i] = rhs.individual[i];
    }

    newIndividual = new Individual[popSize];
    for(int i = 0; i < popSize; i++){
        newIndividual[i] = rhs.newIndividual[i];
    }
}

Population::~Population(){
    delete [] individual;
    delete [] newIndividual;

    cout << "Population deleted" << endl;
}

int Population::getPopSize(){
    return popSize;
}

void Population::setPopSize(int size){
    popSize = size;
}

float Population::getMaxFitness(){
    return maxFitness;
}

float Population::getMinFitness(){
    return minFitness;
}

float Population::getAvgFitness(){
    return avgFitness;
}

float Population::getfitnessSum(){
    return fitnessSum;
}

void Population::addIndividual(Individual indiv){
    if(count < popSize){
        individual[count] = indiv;
        newIndividual[count] = indiv;
        count++;
    }
    else{
        cout << "Population filled. Ignoring new individual" << endl;
    }
}

void Population::printPopulation(){
    for(int i = 0; i < popSize; i++){
        cout << "Indiv #" << i << " ";
        individual[i].printChromose();
    }
}

void Population::printNewPopulation(){
    for(int i = 0; i < popSize; i++){
        cout << "Indiv #" << i << " " << newIndividual[i].getInputDim() << " ";
        newIndividual[i].printChromose();
    }
}

void Population::calcFitnessSum(){
    fitnessSum = 0;
    for(int i = 0; i < popSize; i++){
        fitnessSum += individual[i].getFitness();
    }
}

void Population::selectNewPopulation(){
    int scale = 100000000;
    for(int i = 0; i < popSize; i++){
        int rouletteSum = 0;
        int n = 0;
        unsigned int pick = rand() % int((scale * fitnessSum));
        while(pick > rouletteSum){
            rouletteSum += individual[n].getFitness() * scale;
            n++;
        }
        newIndividual[i] = individual[n-1];
    }
}

void Population::performCrossover(){
    int length = newIndividual[0].getChromLen();
    for(int i = 0; i < popSize; i+=2){
        int xoverChance = rand() % 1000;
        if(xoverChance < (xoverProb * 1000)){
            int xoverLoc = (rand() % (length - 1)) + 1;
            
            int child1[length];
            int* tempChild1 = newIndividual[i].getChromosome();

            int child2[length];
            int* tempChild2 = newIndividual[i+1].getChromosome();
            
            for(int j = 0; j < xoverLoc; j++){
                child1[j] = tempChild1[j];
                child2[j] = tempChild2[j];
            }
            for(int j = xoverLoc; j < length; j++){
                child1[j] = tempChild2[j];
                child2[j] = tempChild1[j];
            }

            individual[i].setChromosome(child1);
            individual[i+1].setChromosome(child2);
        }
        else{
            individual[i].setChromosome(newIndividual[i].getChromosome());
            individual[i+1].setChromosome(newIndividual[i+1].getChromosome());
        }
    }
}

void Population::performCHCCrossover(Individual* population){
    int length = newIndividual[0].getChromLen();
    for(int i = 0; i < popSize; i+=2){
        int xoverChance = rand() % 1000;
        if(xoverChance < (xoverProb * 1000)){
            int xoverLoc = (rand() % (length - 1)) + 1;
            
            int child1[length];
            int* tempChild1 = newIndividual[i].getChromosome();

            int child2[length];
            int* tempChild2 = newIndividual[i+1].getChromosome();
            
            for(int j = 0; j < xoverLoc; j++){
                child1[j] = tempChild1[j];
                child2[j] = tempChild2[j];
            }
            for(int j = xoverLoc; j < length; j++){
                child1[j] = tempChild2[j];
                child2[j] = tempChild1[j];
            }

            for(int j = 0; j < length; j++){
                population[i].setChromosome(tempChild1);
                population[i+1].setChromosome(tempChild2);

                population[i+popSize].setChromosome(child1);
                population[i+1+popSize].setChromosome(child2);
            }
        }
        else{
            int* child1 = newIndividual[i].getChromosome();
            int* child2 = newIndividual[i+1].getChromosome();

            for(int j = 0; j < length; j++){
                population[i].setChromosome(child1);
                population[i+1].setChromosome(child2);

                population[i+popSize].setChromosome(child1);
                population[i+1+popSize].setChromosome(child2);
            }
        }
    }
}

void Population::calcCHCNewEncodes(Individual* population){
    for(int i = 0; i < popSize*2; i++){
        population[i].calculateEncodes();
    }
}

void Population::CHCMutate(Individual* population){
    for(int i = 0; i < popSize*2; i++){
        population[i].performMutation(mutateProb);
    }
}

void Population::chooseCHCFittest(Individual* population){
    Individual temp;
    for(int i = 0; i < popSize*2; i++){
        for(int j = 0; j+1 < (popSize*2) - i; j++){
            if(population[j].getFitness() < population[j+1].getFitness()){
                temp = population[j];
                population[j] = population[j+1];
                population[j+1] = temp;
            }
        }
    }
    for(int i = 0; i < popSize; i++){
        individual[i] = population[i];
    }
}

void Population::calcNewEncodes(){
    for(int i = 0; i < popSize; i++){
        individual[i].calculateEncodes();
    }
}

void Population::mutate(){
    for(int i = 0; i < popSize; i++){
        individual[i].performMutation(mutateProb);
    }
}

void Population::findMaxFitness(){
    maxFitness = individual[0].getFitness();
    for(int i = 1; i < popSize; i++){
        if(individual[i].getFitness() > maxFitness){
            maxFitness = individual[i].getFitness();
        }
    }
}

void Population::findMinFitness(){
    minFitness = individual[0].getFitness();
    for(int i = 1; i < popSize; i++){
        if(individual[i].getFitness() < minFitness){
            minFitness = individual[i].getFitness();
        }
    }
}

void Population::findAvgFitness(){
    avgFitness = fitnessSum / float(popSize);
}

void Population::displayPopData(){
    cout << "Max: " << maxFitness << " | " 
         << "Min: " << minFitness << " | " 
         << "Avg: " << avgFitness << endl;
}

void Population::calcFunc1Evals(){
    for(int i = 0; i < popSize; i++){
        individual[i].dejongFunc1Eval();
    }
}

void Population::calcFunc2Evals(){
    for(int i = 0; i < popSize; i++){
        individual[i].dejongFunc2Eval();
    }
}

void Population::calcFunc3Evals(){
    for(int i = 0; i < popSize; i++){
        individual[i].dejongFunc3Eval();
    }
}

void Population::calcFunc4Evals(){
    for(int i = 0; i < popSize; i++){
        individual[i].dejongFunc4Eval();
    }
}

void Population::calcFunc5Evals(){
    for(int i = 0; i < popSize; i++){
        individual[i].dejongFunc5Eval();
    }
}

void Population::calcCHCFunc1Evals(Individual* population){
    for(int i = 0; i < popSize*2; i++){
        population[i].dejongFunc1Eval();
    }
}

void Population::calcCHCFunc2Evals(Individual* population){
    for(int i = 0; i < popSize*2; i++){
        population[i].dejongFunc2Eval();
    }
}

void Population::calcCHCFunc3Evals(Individual* population){
    for(int i = 0; i < popSize*2; i++){
        population[i].dejongFunc3Eval();
    }
}

void Population::calcCHCFunc4Evals(Individual* population){
    for(int i = 0; i < popSize*2; i++){
        population[i].dejongFunc4Eval();
    }
}

void Population::calcCHCFunc5Evals(Individual* population){
    for(int i = 0; i < popSize*2; i++){
        population[i].dejongFunc5Eval();
    }
}