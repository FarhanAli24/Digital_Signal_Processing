#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIG_LENGTH 320
extern double InputSignal_f32_1kHz_15kHz[SIG_LENGTH];
double calc_signal_mean(double *sig_src_arr, int sig_length);
double calc_signal_variance(double *sig_src_array, double sig_mean, int sig_legth);
double calc_signal_std(double sig_variance);

double MEAN;
double VARIANCE;
double STD;

int main()
{
    MEAN = calc_signal_mean(&InputSignal_f32_1kHz_15kHz[0],SIG_LENGTH);
    VARIANCE = calc_signal_variance(&InputSignal_f32_1kHz_15kHz[0],MEAN,SIG_LENGTH);
    STD = calc_signal_std(VARIANCE);

    //printf("Mean = %f", MEAN);
    //printf("Variance = %f", VARIANCE);
    printf("STD = %f", STD);

    return 0;
}

double calc_signal_mean(double *sig_src_arr, int sig_length)
{
    double mean = 0.0;

    for(int i =0; i < sig_length; i++)
    {
        mean = mean + sig_src_arr[i];
    }
    mean = mean/(double)sig_length;
    return mean;
}

double calc_signal_variance(double *sig_src_array, double sig_mean, int sig_legth)
{
    double variance = 0.0;

    for(int i = 0; i < sig_legth; i++)
    {
        variance = variance + pow((sig_src_array[i]-sig_mean),2);
    }

    variance = variance/(sig_legth-1);
    return variance;
}

double calc_signal_std(double sig_variance)
{
    double std = sqrt(sig_variance);
    return std;
}
