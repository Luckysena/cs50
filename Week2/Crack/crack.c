#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void iterator();
char *tmpHash;
char *salt;
char *hash;
typedef int bool;
#define true 1
#define false 0
bool found = false;
int main(int argc, char * argv[]){


  if(argc != 2){
    printf("Proper use: ./crack password\n");
    return 1;
  }

  // temp hash creation for testing purposes
  salt = "50";
  hash = malloc(sizeof(argv[1]));
  strcpy(hash,crypt(argv[1],salt));
  printf("Hash is: %s\n",hash);

  // use a ptr to iterater through all possible combinations
  char *ptr = malloc((sizeof (char))*5);
  for(int i = 1; i < 5; i++){
    iterator(ptr, 0, i);
    if(found){
      break;
    }
  }

  // free allocated memory
  free(ptr);
  free(hash);
  return 0;
}

// iterator will generate all possible combinations up to a given length of chars
void iterator(char *str, int index, int len){
    char c;
    if (index < (len - 1)) {
        for (c = 'A'; c <= 'z'; ++c) {
          if(found){
            return;
          }
            str[index] = c;
            iterator(str, index + 1, len);
        }
    } else {
        for (c = 'A'; c <= 'z'; ++c) {
            str[index] = c;
            tmpHash = crypt(str, salt);
            if(strcmp(tmpHash,hash) == 0){
              printf("The password is %s, which has the hash %s\n",str,tmpHash);
              found = true;
              return;
            }
        }
    }
}
