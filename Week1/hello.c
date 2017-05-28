#include <stdio.h>

int main(void){
  char str1[30], str2[30];

  printf("Enter some shit:\n");
  fgets(str1, sizeof str1, stdin);
  printf("Enter some shit:\n");
  scanf("%s", str2);

  puts(str1);
  printf("%s\n",str2);
}
