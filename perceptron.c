#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>

#include "user_functions.h"

FILE *fp, *outFile, *line;

int main(int argc, char *argv[])
{
	if ( argc != 2 )
    {
            printf("Usage: %s <input-dataset> \n",argv[0]);

    }

    fp = fopen(argv[1], "r");
    outFile =fopen("random.csv", "w");
    line = fopen("line.csv", "w");

	if ( fp == NULL )
    {
            fprintf(stderr, "Cannot open the training data set file. \n");
            exit(1);
    }

    int i = 0;
    int j = 0;
    float tot_error = 0;
    float threshold, learning_rate;
    float weight1 = 0, weight2 = 0;
    float res;
    float error;

    float mass[10], speed[10];
    int out_actual[10]; 

    res =0;
    error = 0;
    threshold = 0; learning_rate = 0;

    threshold = inputThreshold();
    learning_rate = inputLearningRate();

	weight1 = (float)(rand() % 5); 
	weight2 = (float)(rand() % 5);

    while(fscanf(fp, "%f %f %d", &mass[i], &speed[i], &out_actual[i]) != EOF)
    {
            i++;

    }

    for ( j = 0; j < 10000; j++)
    {
            tot_error = 0;

            for ( int k = 0 ; k < i; k++ )
            {

	            res = predict(mass[k], speed[k], weight1, weight2, threshold);
	
			    error = out_actual[k] -res;

				printf("Updating the weights for error correction.\n");
				weight1 = weight1+learning_rate*mass[k]* error;
				weight2 = weight2+learning_rate*speed[k]*error;
                
                threshold -= learning_rate*error;

                tot_error += error*error;
            }

            printf("Epoch: %d Error: %f\n",j+1, tot_error);

            fprintf(outFile,"%d,%f\n",j+1,tot_error);
    }

    fprintf(line, "%f,%f,%f", weight1, weight2, threshold);

    fclose(fp);
    fclose(outFile);
    fclose(line);

	return 0;

}

