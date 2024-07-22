#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIG_LENGTH 320
#define IMP_RSP_LENGTH 29

extern double InputSignal_f32_1kHz_15kHz[SIG_LENGTH];
extern double Impulse_response[IMP_RSP_LENGTH];
double output_signal[SIG_LENGTH+IMP_RSP_LENGTH];
void convoltion(double *sig_src_arr, double *sig_dest_arr, double *imp_response_arr, int sig_src_length, int imp_response_length);

int main(int argc, const char * argv[])
{
    FILE *input_sig_file, *imp_rsp_file, *output_sig_file;
    
    convoltion((double*) &InputSignal_f32_1kHz_15kHz[0], (double*) &output_signal, (double*) &Impulse_response[0], (int) SIG_LENGTH, (int) IMP_RSP_LENGTH);
    
    input_sig_file = fopen("input_signal.dat", "w");
    imp_rsp_file = fopen("impulse_response.dat", "w");
    output_sig_file = fopen("output_signal.dat", "w");
    
    for (int i=0; i < SIG_LENGTH; i++) {
        fprintf(input_sig_file, "\n%f", InputSignal_f32_1kHz_15kHz[i]);
    }
    fclose(input_sig_file);
    
    for (int i=0; i < IMP_RSP_LENGTH; i++) {
        fprintf(imp_rsp_file, "\n%f", Impulse_response[i]);
    }
    fclose(imp_rsp_file);
    
    
    for (int i=0; i < SIG_LENGTH+IMP_RSP_LENGTH; i++){
        fprintf(output_sig_file, "\n%f", output_signal[i]);
    }
    fclose(output_sig_file);

    return 0;
}

void convoltion(double *sig_src_arr, double *sig_dest_arr, double *imp_response_arr, int sig_src_length, int imp_response_length){
    
    for (int i = 0; i < sig_src_length + imp_response_length; i++) {
        
        sig_dest_arr[i] = 0;
        
    }
    
    for (int i = 0; i < sig_src_length; i++) {
        
        for (int j = 0; j < imp_response_length; j++) {
            
            sig_dest_arr[i+j] = sig_dest_arr[i+j] + sig_src_arr[i] * imp_response_arr[j];
        }
    }
    
    
}


