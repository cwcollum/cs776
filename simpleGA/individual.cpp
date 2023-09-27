#include "individual.h"

Individual::Individual(){
    fitness = 0;
    inputDim = 1;
    alleleLen = 1;
    chromLen = 1;
    chromosome = new int[1];
    encodes = new int[1];
}

Individual::Individual(int inDim, int bitLen){
    inputDim = inDim;
    alleleLen = bitLen;
    chromLen = inputDim * alleleLen;
    chromosome = new int[chromLen];
    encodes = new int[inputDim];

    initIndividual();
    calculateEncodes();
}

Individual::Individual(const Individual& rhs){
    inputDim = rhs.inputDim;
    alleleLen = rhs.alleleLen;
    chromLen = rhs.chromLen;
    fitness = rhs.fitness;
    chromosome = new int[chromLen];
    encodes = new int[inputDim];

    for(int i = 0; i < chromLen; i++){
        chromosome[i] = rhs.chromosome[i];
    }
    for(int i = 0; i < inputDim; i++){
        encodes[i] = rhs.encodes[i];
    }
}

Individual::~Individual(){

}

float Individual::getFitness(){
    return fitness;
}

void Individual::setFitness(float fit){
    fitness = fit;
}

int Individual::getInputDim(){
    return inputDim;
}

int Individual::getChromLen(){
    return chromLen;
}

int* Individual::getChromosome(){
    return chromosome;
}

void Individual::setChromosome(int* chrom){
    for(int i = 0; i < chromLen; i++){
        chromosome[i] = chrom[i];
    }
}

void Individual::initIndividual(){
    for(int i = 0; i < chromLen; i++){
        chromosome[i] = rand() % 2;
    }
}

void Individual::calculateEncodes(){
    for(int n = 0; n < inputDim; n++){
        int decimal = 0;
        int power = 1;
        for(int i = 0; i < alleleLen; i++){ 
            decimal += chromosome[((alleleLen * (n + 1)) - 1) - i] * power;
            power *= 2;
        }
        encodes[n] = decimal;
    }
}

void Individual::printChromose(){
    for(int i = 0; i < chromLen; i++){
        cout << chromosome[i];
    }
    for(int i = 0; i < inputDim; i++){
        cout << " " << (float(encodes[i]) / 100.0) - 5.12;
    }
    cout << " " << fitness;
    cout << endl;
}

void Individual::performMutation(float prob){
    for(int i = 0; i < chromLen; i++){
        int chance = rand() % 1000;
        if(chance <= (prob * 1000)){
            chromosome[i] = 1 - chromosome[i];
        }
    }
}

void Individual::dejongFunc1Eval(){
    // f1(x) = sum(x(i)^2), i=1:n, -5.12 < x(i) < 5.12
    // -5.12 to 5.11 | 10 bits | (x(i) / 100 - 5.12) to convert to value in range

    float sum = 0.0;
    for(int i = 0; i < inputDim; i++){
        float rangeConv = (float(encodes[i]) / 100.0) - 5.12;
        sum += pow(rangeConv, 2);
    }
    fitness = 1 / (sum + 1);
}

void Individual::dejongFunc2Eval(){
    // f1(x) = 100(x(2) - x(1)^2)^2 + (1 - x(1))^2, -2.048 < x(i) < 2.048
    // -2.048 to 2.047 | 12 bits | x(i) / 1000 - 2.048

    float sum = 0.0;
    for(int i = 0; i < inputDim - 1; i++){
        float rangeConv1 = (float(encodes[i]) / 1000) - 2.048;
        float rangeConv2 = (float(encodes[i+1]) / 1000) - 2.048;
        float eq2 = (1 - rangeConv1) * (1 - rangeConv1);
        float eq1 = rangeConv2 - (rangeConv1 * rangeConv1);
        float eqsqr = eq1 * eq1;
        sum += 100 * eqsqr + eq2;
    }
    fitness = 1 / (sum + 1);
}

void Individual::dejongFunc3Eval(){
    // f1(x) = sum(integer(x(i))), i=1:n, -5.12 < x(i) < 5.12
    // -5.12 to 5.11 | 10 bits | (x(i) / 100 - 5.12)

    float sum = 0.0;
    for(int i = 0; i < inputDim; i++){
        float rangeConv = (float(encodes[i]) / 100.0) - 5.12;
        sum += floor(rangeConv);
    }

    fitness = 50 / (sum + 50);
}

void Individual::dejongFunc4Eval(){
    // f5(x) = sum(i * x(i)^4) + gauss(0,1), i = 1:n, -1.28 < x(i) < 1.28
    // -1.28 to 1.27 | 8 bits | (x(i) / 100 - 1.28)

    float sum = 0.0;
    for(int i = 0; i < inputDim; i++){
        float rangeConv = (float(encodes[i]) / 100.0) - 1.28;
        sum += (i+1) * pow(rangeConv, 4);
    }
    float noise = ((float) rand() / (RAND_MAX));
    sum += noise;

    fitness = 10 / (sum + 10);
}

void Individual::dejongFunc5Eval(){
    // -65.536 to 65.535 | 17 bits | x(i) / 1000 - 65.536
    static int a[2][25] = {
        {-32, -16, 0, 16, 32, -32, -16, 0, 16, 32, -32, -16, 0, 16, 32,
         -32, -16, 0, 16, 32, -32, -16, 0, 16, 32},
        {-32, -32, -32, -32, -32, -16, -16, -16, -16, -16,
         16, 16, 16, 16, 16, 32, 32, 32, 32, 32}
    };

    float sum = 0.0;
    float val = 0.0;

    for(int i = 0; i < 25; i++){
        for(int j = 0; j < inputDim; j++){
            float rangeConv = (float(encodes[j]) / 1000.0) - 65.536;
            float eq = rangeConv - a[j][i];
            val += pow(eq, 6);
        }
        sum += 1.0 / (i + val);
    }
    sum += 0.002;
    sum = (1.0 / sum);

    fitness = 100 / (sum + 100);
}