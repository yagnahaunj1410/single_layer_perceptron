#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "user_functions.h"

#define lower 0
#define upper 1


float inputThreshold()
{
        float threshold;
        time_t t;

        srand((unsigned) time(&t));

        threshold = (float)(rand() % 5);

        printf("The threshold value is %f\n", threshold);
        
        return threshold;
}

float inputLearningRate()
{

        float learning_rate;

        printf("Enter the learning rate for the neuron between 0 and 1:\n");
        scanf("%f", &learning_rate);

        return learning_rate;

}

float activationFunction(float sum_prod)
{
        float val = 1 / (1 + exp(-sum_prod));
        
        return val;
  
}

float predict(float mass, float speed, float weight1, float weight2, float threshold)
{
  
  	float sum_prod = 0;

  	sum_prod = (mass * weight1) + (speed * weight2);
	sum_prod = sum_prod - threshold; 
  
    sum_prod = activationFunction(sum_prod);

  	return sum_prod;
}



