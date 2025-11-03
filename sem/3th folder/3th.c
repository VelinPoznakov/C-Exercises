#include <stdio.h>

int main(){

  // 1

  int a;
  int size;
  int counter = 0;
  int seconCounter = 0;

  scanf("%d", &a);

  printf("Enter size");

  scanf("%d", &size);
  int list[size];


  for(int i = 0; i < size; i++){
    scanf("%d", &list[i]);
  }

  int temp;

  for(int i = 0; i < (size - 1); ++i){
    for(int j = 0; j < (size - 1 - i); ++j){
      if(list[j] > list[j + 1]){

        temp = list[j + 1];
        list[j + 1] = list[j];
        list[j] = temp;
      }
    }
  }

  int currentNum = list[0];
  int max;

  for(int i = 1; i < size; i++){
    if(list[i - 1] != currentNum){
      seconCounter = counter;
      counter = 1;
      currentNum = list[i - 1];
      continue;
    }

    counter += 1;
    max = currentNum;

  }

  printf("lenght - %d, number - %d\n", seconCounter, max);

  // 2 

  // int size;

  // scanf("%d", &size);

  // int arr[size];

  // int odd, even;

  // even = arr[0];
  // odd = arr[1];

  // for(int i = 0; i < size; i++){
  //   scanf("%d", &arr[i]);
  // }

  // for(int i = 0; i< size; i++){
  //   if(i % 2 == 0){
  //     even += arr[i];
  //     continue;
  //   }

  //   odd += arr[i];
  // }

  // if(even == odd){
  //   printf("Correct numbers\n");
  // }
  // else{
  //   printf("Incorrect numbers");
  // }


  // 3

  // int size;

  // scanf("%d", &size);

  // int arr1[size], arr2[size];

  // for(int i = 0; i < size; i++){
  //   scanf("%d", &arr1[i]);
  // }

  // int temp = size;

  // for(int i = 0; temp > i; temp--){
  //   int n1 = arr1[temp - 1];
  //   arr2[size - temp] = n1;
  // }

  // for(int i = 0; i < size; i++){
  //   arr1[i] = arr2[i];
  // }

  // for(int i = 0; i < size; i++){
  //   printf("%d - %d\n", i, arr1[i]);
  // }


  // 4 

  // int size;

  // scanf("%d", &size);

  // int arr[size];

  // for(int i = 0; i < size; i++){
  //   scanf("%d", &arr);
  // }

  // int temp;

  // for(int i = 0; size > 0; size--){
  //   for(int j = 0; j < size; j++){
      
  //     temp = arr[i];
  //     arr[i] = arr[j - 1];
  //     continue;

  //   }
  // }

  




  return 0;
}