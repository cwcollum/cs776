void createHardOptimum(int* sol);
long int binToInt(int* array);

//converts an integer into a binary number and assigns it to an array
void intToBinary(int* binArray, long int n){
    int i = 0;
    while(n > 0){
        binArray[i] = n % 2;
        n = n / 2;
        i++;
    }
}

//The actual evaluation method for the solution.  Takes four integers and determines proximity to those values.  The middle two are multiplied together and overlapping bits need to be identical to the solution
double evalHard(int* pj){
    double fitness = 0;
    int solution[100] = {0};

    createHardOptimum(solution);
    int encode1[32];
    int encode2[32];
    int encode3[32];
    int encode4[32];

    int encode5[14];
    int encode6[14];

    int guess1[32];
    int guess2[32];
    int guess3[32];
    int guess4[32];

    int guess5[14];
    int guess6[14];

    for(int i = 0; i < 32; i++){
        encode1[i] = solution[i];
        guess1[i] = pj[i];
    }
    for(int i = 18; i < 50; i++){
        encode2[i - 18] = solution[i];
        guess2[i - 18] = pj[i];
    }
    for(int i = 50; i < 82; i++){
        encode3[i - 50] = solution[i];
        guess3[i - 50] = pj[i];
    }
    for(int i = 68; i < 100; i++){
        encode4[i - 68] = solution[i];
        guess4[i - 68] = pj[i];
    }
    for(int i = 18; i < 32; i++){
        encode5[i - 18] = solution[i];
        guess5[i - 18] = pj[i];
    }
    for(int i = 68; i < 82; i++){
        encode6[i - 68] = solution[i];
        guess6[i - 68] = pj[i];
    }

    //calculate the fitness of the first encoded long int
    double decEncode1 = binToInt(encode1);
    double decGuess1 = binToInt(guess1);
    double ratio = decEncode1 / decGuess1;
    double fitness1 = 0.0;
    if(ratio > 1.0){
        ratio = 1.0 / ratio;
        fitness1 = 30.0 * ratio;
    }
    else if(ratio < 1.0){
        fitness1 = 30.0 * ratio;
    }
    else{
        fitness1 = 30.0;
    }

    //calculate the fitness of the second encoded long int
    double decEncode4 = binToInt(encode4);
    double decGuess4 = binToInt(guess4);
    ratio = decEncode4 / decGuess4;
    double fitness2 = 0.0;
    if(ratio > 1.0){
        ratio = 1.0 / ratio;
        fitness2 = 30.0 * ratio;
    }
    else if(ratio < 1.0){
        fitness2 = 30.0 * ratio;
    }
    else{
        fitness2 = 30.0;
    }

    //calculate the fitness of the middle two encoded long ints and what they multiply to
    double decEncode2 = binToInt(encode2);
    double decEncode3 = binToInt(encode3);
    double decGuess2 = binToInt(guess2);
    double decGuess3 = binToInt(guess3);

    double encodeProd = decEncode2 * decEncode3;
    double guessProd = decGuess2 * decGuess3;
    ratio = encodeProd / guessProd;
    double fitness3 = 0.0;
    if(ratio > 1.0){
        ratio = 1.0 / ratio;
        fitness3 = 20.0 * ratio;
    }
    else if(ratio < 1.0){
        fitness3 = 20.0 * ratio;
    }
    else{
        fitness3 = 30.0;
    }

    //calculate the fitness of the two overlapping area of bits.  This is a binary you get the answer or you don't
    double decEncode5 = binToInt(encode5);
    double decEncode6 = binToInt(encode6);
    double decGuess5 = binToInt(guess5);
    double decGuess6 = binToInt(guess6);

    if(decEncode5 == decGuess5){
        fitness += 10.0;
    }
    if(decEncode6 == decGuess6){
        fitness += 10.0;
    }

    fitness = fitness + fitness1 + fitness2 + fitness3;

    return fitness;
}

void resetEncode(int* array){
    for(int i = 0; i < 32; i++){
        array[i] = 0;
    }
}

long int binToInt(int* array){
    long int decimal_value = 0;
    long int base = 1;
    for(int i = 0; i < 32; i++){
        if(array[i] == 1){
            decimal_value += base;
        }
        base = base * 2;
    }

    return decimal_value;
}

void createHardOptimum(int* sol){
    //                  01010100110001111010110100000000 | 00101011111000110100100110000100
    //10101110010110110001010100110001                                       00100110000100110100100000000000

    int encode[32] = {0};

    long int encodeBegin = 2359876213;
    long int encodeEnd = 1230948;
    long int encodeMiddleBegin = 11920170;
    long int encodeMiddleEnd = 563267540;

    intToBinary(encode, encodeBegin);
    for(int i = 0; i < 32; i++){
        sol[i] = encode[i];
    }
    resetEncode(encode);

    intToBinary(encode, encodeEnd);
    for(int i = 68; i < 100; i++){
        sol[i] = encode[i - 68];
    }
    resetEncode(encode);

    intToBinary(encode, encodeMiddleBegin);
    for(int i = 32; i < 50; i++){
        sol[i] = encode[i - 18];
    }
    resetEncode(encode);

    intToBinary(encode, encodeMiddleEnd);
    for(int i = 50; i < 68; i++){
        sol[i] = encode[i - 50];
    }
}