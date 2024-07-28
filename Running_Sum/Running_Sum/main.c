#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIG_LENGTH 320

extern double InputSignal_f32_1kHz_15kHz[SIG_LENGTH];
double output_signal[SIG_LENGTH];

void runningSum(double *sig_source_arr, double *sig_dest_arr, int sig_length);

int main(int argc, const char * argv[])
{
    FILE *input_sig_file, *output_sig_file;
    
    
    runningSum((double*) &InputSignal_f32_1kHz_15kHz, (double*) &output_signal, (int) SIG_LENGTH);
    
    input_sig_file = fopen("input_signal.dat", "w");
    output_sig_file = fopen("output_signal.dat", "w");
    
    for (int i=0; i < SIG_LENGTH; i++){
        fprintf(input_sig_file, "\n%f", InputSignal_f32_1kHz_15kHz[i]);
    }
    fclose(input_sig_file);
    

    
    
    for (int i=0; i < SIG_LENGTH; i++){
        fprintf(output_sig_file, "\n%f", output_signal[i]);
    }
    fclose(output_sig_file);

    return 0;
}



void runningSum(double *sig_source_arr, double *sig_dest_arr, int sig_length){
    
    for (int i = 0; i < sig_length; i++) {
        sig_dest_arr[i] = sig_dest_arr[i-1] + sig_source_arr[i];
    }
    
}
