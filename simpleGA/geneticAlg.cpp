#include "util.h"

int main(int argc, char** argv){
    //pseudocode
    //Generate pop(0)
    //Evaluate pop(0)
    //T=0
    //While(not converged)do
    //  Select pop(T+1) from pop(T)
    //  Recombine pop(T+1)
    //  Evaluate pop(T+1)
    //  T = T+1
    //Done

    int userFuncChoice = 1;
    cout << "Select Dejong Function to Evaluate [1-5]: ";
    cin >> userFuncChoice;

    char userCHCChoice = 'n';
    cout << "Run with CHC? [y/n] ";
    cin >> userCHCChoice;

    int userPopChoice = 50;
    int userGenChoice = 100;
    float userXOverProb = 0.667;
    float userMutateProb = 0.001;
    cout << "Set population size, generation size, crossover probability, mutation probability" << endl;
    cout << "Values (space separated): ";
    cin >> userPopChoice >> userGenChoice >> userXOverProb >> userMutateProb;

    string outputFiles[6] = {"", "func1GA.csv", "func2GA.csv", "func3GA.csv", "func4GA.csv", "func5GA.csv"};
    string outputCHCFiles[6] = {"", "func1CHC.csv", "func2CHC.csv", "func3CHC.csv", "func4CHC.csv", "func5CHC.csv"};
    if(userCHCChoice == 'y'){
        ofstream fout(outputCHCFiles[userFuncChoice]);
        if(!fout.is_open()){
            std::cout << "unable to create file" << endl;
        }
        fout << "Seed,Gen,MaxFitness,MinFitness,AvgFitness" << endl;

        //Main loop to run the GA utilizing all random seeds in order to determine reliability
        for(int i = 1; i < 30; i++){
            srand(i);
            cout << "Seed " << i << endl;

            switch(userFuncChoice){
                case 1:
                    runFunc1GA(userCHCChoice, userPopChoice, userGenChoice, userXOverProb, userMutateProb, i, fout);
                    break;
                case 2:
                    runFunc2GA(userCHCChoice, userPopChoice, userGenChoice, userXOverProb, userMutateProb, i, fout);
                    break;
                case 3:
                    runFunc3GA(userCHCChoice, userPopChoice, userGenChoice, userXOverProb, userMutateProb, i, fout);
                    break;
                case 4:
                    runFunc4GA(userCHCChoice, userPopChoice, userGenChoice, userXOverProb, userMutateProb, i, fout);
                    break;
                case 5:
                    runFunc5GA(userCHCChoice, userPopChoice, userGenChoice, userXOverProb, userMutateProb, i, fout);
                    break;
            }

        }

        fout.close();
    }
    else{
        ofstream fout(outputFiles[userFuncChoice]);
        if(!fout.is_open()){
            std::cout << "unable to create file" << endl;
        }
        fout << "Seed,Gen,MaxFitness,MinFitness,AvgFitness" << endl;

        //Main loop to run the GA utilizing all random seeds in order to determine reliability
        for(int i = 1; i < 30; i++){
            srand(i);
            cout << "Seed " << i << endl;

            switch(userFuncChoice){
                case 1:
                    runFunc1GA(userCHCChoice, userPopChoice, userGenChoice, userXOverProb, userMutateProb, i, fout);
                    break;
                case 2:
                    runFunc2GA(userCHCChoice, userPopChoice, userGenChoice, userXOverProb, userMutateProb, i, fout);
                    break;
                case 3:
                    runFunc3GA(userCHCChoice, userPopChoice, userGenChoice, userXOverProb, userMutateProb, i, fout);
                    break;
                case 4:
                    runFunc4GA(userCHCChoice, userPopChoice, userGenChoice, userXOverProb, userMutateProb, i, fout);
                    break;
                case 5:
                    runFunc5GA(userCHCChoice, userPopChoice, userGenChoice, userXOverProb, userMutateProb, i, fout);
                    break;
            }

        }

        fout.close();
    }

    return 0;
}