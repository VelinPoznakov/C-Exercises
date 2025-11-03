#include <stdio.h>


#define ROWS 3
#define COLS 3


int main(){

  int a[ROWS][COLS];


  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      a[i][j] = i + j + 1;
    }
  }

  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      if(i = j){
        printf("%d ", a[i][j]);
      }
    }
  }

  for(int i = 0; i < ROWS; i++){
    for(int j = COLS; j > -1; j--){
      printf("%d", a[i][j]);
    }
  }

  for(int i = 0; i < COLS * ROWS; i++){
    printf("%d ", a[ROWS / i][COLS % i]);
  }

  for(int i = 0; i < ROWS - 1; i++){
    for(int j = 1; j < COLS; j++){
      if(i != j){
        printf("%d ", a[i][j]);
      }
    }
  }

  for(int i = 1; i < ROWS; i++){
    for(int j = 0; j < COLS - 1; j++){
      if(i != j){
        printf("%d ", a[i][j]);
      }
    }
  }


  // magic

  int matrix[ROWS][COLS];

  int sumRows = 0;
  int sumCols = 0;
  int flag = 1;

  for(int i = 0; i < ROWS; i++){
    sumRows = 0;
    sumCols = 0;
    for(int j = 0; j < COLS; j++){
      sumRows += matrix[i][j];
      sumCols += matrix[j][i];
    }
    if(sumCols != sumRows){
      flag = 0;
    }
  }

  if(flag = 0){
    printf("not equal");
  }
  else{
    printf("are equal");
  }





  return 0;

}