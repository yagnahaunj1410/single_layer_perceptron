#include <stdio.h>

float inputThreshold();

float inputLearningRate();

float predict(float mass, float speed, float weight1, float weight2, float threshold);

float activationFunction(float sum_prod);

float outputVerify(FILE * fp, float out_actual);

