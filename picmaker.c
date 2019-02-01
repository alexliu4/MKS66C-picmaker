#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(){
  int fd, i, j;
  char line[20];
  int rgb[3];

  fd = open("image.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644);
  snprintf(line, sizeof(line), "P3 500 500 255\n");
  write(fd, line, strlen(line));
  for(i=0; i<500; i++){
    for(j=0; j<500; j++){
      // rgb[0] = i % 256;
      // rgb[1] = j % 256;
      // rgb[2] = 255;
      rgb[0]= i % 70;
      if (i % 2){
        rgb[0]= (i % 70) + 11;
      }
      rgb[1]= j % 70;
      if (j % 2){
        rgb[1]= (j % 70) + 11;
      }
      rgb[2]= 50;
      snprintf(line, sizeof(line), "%d %d %d ", rgb[0], rgb[1], rgb[2]);
      write(fd, line, strlen(line));
    }
  }
}
