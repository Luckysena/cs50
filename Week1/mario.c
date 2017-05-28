#include <stdio.h>

void printFirstHalf(int i, int n);
void printSpaces(int n);
void printSecondHalf(int i, int n);

int main(void){
  printf("Height: ");
  int n;
  scanf("%d",&n);

while(n>23 || n<0){
  printf("Enter a positive integer no greater than 23: ");
  scanf("%d", &n);
}

  for(int i = 1; i <= n; i++){
    printFirstHalf(i, n);
    printSpaces(2);
    printSecondHalf(i, n);

  }

}

void printFirstHalf(int i, int n){
  printSpaces(n-i);

  for(int j = 0; j < i; j++){
    printf("#");
  }

}

void printSecondHalf(int i, int n){
  for(int j = 0; j < i; j++){
    printf("#");
  }

  printSpaces(n-i);
  printf("\n");
}
void printSpaces(int n){
  for(int j = 0; j < n; j++){
    printf(" ");
  }
}
