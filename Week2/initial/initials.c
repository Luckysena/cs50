#include <stdio.h>
#include <string.h>
#include <ctype.h>
int nameLen;
int startingIndex;
int charIndex;

// returns the index after the last whitespace
int removeSpaces(char name[], int startingIndex){
  for(int i = startingIndex, n = nameLen; i < n; i++){
    if(name[i] == ' '){
      continue;
    }
    else return i;
  }
}

// returns the next index which contains a whitespace
int getNextWhiteSpace(char name[], int charIndex){
  for(int i = charIndex; i < nameLen ; i++){
    if(name[i] == '\0'){
      return -1;
    }
    if(name[i] == ' '){
      return i;
    }
  }
}

// returns the next index which holds a non whitespace char
int getNextCharIndex(char name[], int startingIndex){
  if(name[startingIndex] == ' '){
    charIndex = removeSpaces(name, startingIndex);
  }
  return charIndex;
}


int main(void){

  // declare and accept input name
  char name[50];
  char initials[3];
  nameLen = sizeof name;
  startingIndex = 0;
  printf("Enter a name: ");
  fgets(name,nameLen,stdin);

  // fill the initials array
  for(int i = 0; i < (sizeof initials); i++){
    charIndex = getNextCharIndex(name, startingIndex);
    initials[i] = toupper(name[charIndex]);
    startingIndex = getNextWhiteSpace(name, charIndex);
    if(startingIndex == -1){
      break;
    }
  }

  for(int i = 0; i < (sizeof initials); i++){
    printf("%c",initials[i]);
  }
  printf("\n");

}
