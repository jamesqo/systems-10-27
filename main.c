#include <stdlib.h>
#include <stdio.h> 
#include <getrand.h> 
#include <unistd.h> 

int main(){ 
  
  int arr[10]; 
  int i; 
  
  printf("Generating random numbers:\n"); 
  
  for (i = 0; i < 10 ; i++){ 
    arr[i] = getrand(); 
    printf("random %d: %d", i, arr[i]); 
  } 
  
  printf("Writing numbers to file...\n"); 
  printf("Reading numbers from file...\n"); 
  
  printf("Checking that written values are the same:\n");
  

}
