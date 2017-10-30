#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int getrand() {
  int random_fd = open("/dev/random", O_RDONLY);
  if (random_fd == -1) {
    printf("%s\n", strerror(errno));
    return -1;
  }

  int ret;
  int num_read = read(random_fd, &ret, sizeof(ret));
  if (num_read == -1) {
      printf("%s\n", strerror(errno));
      return -1;
  }

  close(random_fd);
  return ret;
}

int main(){ 
  
  int arr[10]; 
  int i; 
  
  printf("Generating random numbers:\n"); 
  
  for (i = 0; i < 10 ; i++){ 
    arr[i] = getrand(); 
    printf("\trandom %d: %d\n", i, arr[i]); 
  } 
  
  printf("Writing numbers to file...\n");
  int random_fd = open("new_file", O_CREAT | O_WRONLY, 0644);
  write(random_fd, arr, sizeof(arr));
  
  printf("Reading numbers from file...\n");
  random_fd = open("new_file", O_RDONLY);
  int arrureadykids[10];
  read(random_fd, arrureadykids, sizeof(arrureadykids));
  
  printf("Checking that written values are the same:\n");
  int f;
  for (f = 0 ; f < 10 ; f++){
    printf("\trandom %d: %d\n", f, arrureadykids[f]);
  }

  return 0;
}
