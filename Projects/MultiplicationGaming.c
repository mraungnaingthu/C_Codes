//
// Created by Aung Naing Thu on 1/11/2025.
//

#include <stdio.h>
#include <stdlib.h>
int multiplication(int a, int b);
int main(){
  int a, b;
  int guessResult;

  while(1){
    a = rand() % 100;
    b = rand() % 100;

    int result = multiplication(a, b);

    printf("what is %d * %d ?: ", a, b);
    scanf("%d", &guessResult);

    if(result == guessResult){
      printf("Your guess is correct\n");
    }
    else{
      printf("Your guess is incorrect! Thanks for playing the game...\n");
      break;
    }
  }
}

int multiplication(int a, int b){
  int result;
  result = a * b;
  return result;
}