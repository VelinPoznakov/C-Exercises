#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct icecream{
  char id[3];
  char name[20];
  int weight;
  float price;
}IceCream;


float prices(IceCream *array, int elements, char ch){
  float count = 0.0;

  for(int i = 0; i < elements; i++){
    if(ch == array[i].name[0]){
      count += array[i].price;
    }
  }

  return count;
}


int toTextFile(IceCream *array, int elements, float price, int weight){
  int counter = 0;

  FILE *fp = fopen("info.txt", "w");
  if(fp == NULL){
    exit(1);
  }

  for(int i = 0; i < elements; i++){
    if(array[i].price < price && array[i].weight > weight){
      counter += 1;

      if(fscanf(fp, "%s;%s;%d;%.2fleva\n", array[i].id, array[i].name, &array[i].weight, &array[i].price) != 4){
        exit(1);
      }
    }
  }

  fclose(fp);

  return counter;
}


void printIceCreams(char id[3]){
  int counter = 0;

  FILE *fp = fopen("icecream.bin", "rb");
  if(fp == NULL){
    exit(1);
  }

  fseek(fp, 0, SEEK_END);

  int len = ftell(fp);

  int structs = len / sizeof(IceCream);

  rewind(fp);

  for(int i = 0; i < structs; i++){
    IceCream a;

    if(fread(&a, sizeof(IceCream), 1, fp) != 1){
      exit(1);
    }

    if(strcmp(id, a.id) == 0){
      printf("==================\n");
      printf("IceCream - %s\n", a.name);
      printf("Price - %.2f\n", a.price);
      printf("==================\n\n");
      
      counter += 1;
    }
  }

  if(counter == 0){
    printf("Nothing found....");
  }

  fclose(fp);
}


int main(){

  int n;
  while(1 == 1){
    scanf("%d", &n);

    if(n > 5 && n < 15){
      break;
    }
  }

  IceCream *array = (IceCream*)malloc(n * sizeof(IceCream));

  if(array == NULL){
    exit(1);
  }

  for(int i = 0; i < n; i++){
    IceCream a;

    scanf("%s", &a.id);
    getchar();
    fgets(a.name, sizeof(a.name), stdin);
    scanf("%d", &a.weight);
    scanf("%f", &a.price);

    *(array + i) = a;
  }

  int res = prices(array, n, 'a');

  int added = toTextFile(array, n, 23.9, 23);

  free(array);

  printIceCreams("A2");


  return 0;
}