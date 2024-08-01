//
//  main.c
//  DFT
//
//  Created by Farhan Ali on 7/31/24.
//

#include <stdio.h>
#include <math.h>

#define SIGNAL_LENGTH 320
extern double InputSignal_f32_1kHz_15kHz[SIGNAL_LENGTH];
double output_real[SIGNAL_LENGTH/2];
double output_imaginary[SIGNAL_LENGTH/2];
double output_mag[SIGNAL_LENGTH/2];

void clac_sig_dft(double *sig_src_arr, double *sig_real_arr, double *sig_imaginary_arr, int sig_length);
void gft_mag(double *sig_dest_mag_arr);

int main(int argc, const char * argv[]) {
    
    FILE *fileIn, *fileOutReal, *fileOutImag, *fileOutMag;
    
    clac_sig_dft((double*) &InputSignal_f32_1kHz_15kHz[0], (double*) &output_real[0], (double*) &output_imaginary[0], (int) SIGNAL_LENGTH);
    gft_mag((double*) output_mag);
    
    fileIn = fopen("input_signal.dat", "w");
    fileOutReal = fopen("output_real.dat", "w");
    fileOutImag = fopen("output_imagninary.dat", "w");
    fileOutMag = fopen("output_magnitude.dat", "w");
    
    for (int i = 0; i < SIGNAL_LENGTH; i++) {
        
        fprintf(fileIn,"\n%f", InputSignal_f32_1kHz_15kHz[i]);
    }
    
    for (int i = 0; i < (SIGNAL_LENGTH/2); i++) {
        fprintf(fileOutReal, "\n%f", output_real[i]);
        fprintf(fileOutImag, "\n%f", output_imaginary[i]);
        fprintf(fileOutMag, "\n%f", output_mag[i]);
    }
    
    fclose(fileIn);
    fclose(fileOutReal);
    fclose(fileOutImag);
    fclose(fileOutMag);
    
    return 0;
}

void clac_sig_dft(double *sig_src_arr, double *sig_dest_real_arr, double *sig_dest_imaginary_arr, int sig_length)
{
    
    //we devide sig_length by 2 because N/2+1*cosin and sin
    for (int j=0; j < sig_length/2; j++) {
        sig_dest_real_arr[j] = 0;
        sig_dest_imaginary_arr[j] = 0;
    }
    
    for (int k=0; k < sig_length/2; k++){
        for(int i=0; i < sig_length; i++){
            //k, determines the frequency of the wave. In an N point DFT, k takes on values between 0 and N/2 .
            sig_dest_real_arr[k] = sig_dest_real_arr[k] + cos((2*M_PI*k*i)/sig_length)*sig_src_arr[i];
            sig_dest_imaginary_arr[k] = sig_dest_imaginary_arr[k] - sin((2*M_PI*k*i)/sig_length)*sig_src_arr[i];
        }
    }
    
    
}

void gft_mag(double *sig_dest_mag_arr){
    for(int i=0; i < SIGNAL_LENGTH; i++){
        sig_dest_mag_arr[i] = sig_dest_mag_arr[i] + sqrt(pow(output_real[i], 2) + pow(output_imaginary[i], 2));
    }
}
