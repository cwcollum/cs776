//easy evaluation function.  optimum solution is alternating zeros and ones
double evalEasy(int* pj){
    double fitness = 0;

    int solution[100] = {0};
    for(int i = 0; i < 100; i+=2){
        solution[i] = 1;
    }

    for(int i = 0; i < 100; i++){
        if(solution[i] == pj[i]){
            fitness++;
        }
    }

    return fitness;
}