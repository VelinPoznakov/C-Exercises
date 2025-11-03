#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct medicine{
  char name[30];
  char date[7];
  int code;
  double price;
  int quantity;
}Medicine;


Medicine *search(Medicine *pMedicines[], int numberOfElements, char date[7]){
  // the func returns all med with date before our given date

  int mm, yyyy;
  int counter = 0;

  // separating the date
  sscanf(date, "%d.%d", &mm, &yyyy);

  // iterate to find how many elements mach our description
  for(int i = 0; i < numberOfElements; i++){
    int m, y;

    //take the date from current med
    sscanf((*(pMedicines + i))->date, "%d.%d", &m, &y);

    //check the dates
    if(y < yyyy || (y == yyyy && m < mm)){
      counter += 1;
    }
  }

  // if the counter is 0 that means that there is no meds to get
  if(counter == 0){
    return NULL;
  }

  //creating dynamic array that will contain the med that match what we want
  Medicine *foundMeds = (Medicine*)malloc(counter * sizeof(Medicine));
  if(foundMeds == NULL){
    exit(1);
  }

  // reset the counter to 0 to use it to put the elements in the new dynamic array
  counter = 0;

  // make the same for cycle but now put the element in the new created dynamic array
  for(int i = 0; i < numberOfElements; i++){
    int m, y;

    sscanf((*(pMedicines + i))->date, "%d.%d", &m, &y);

    if(y < yyyy || (y == yyyy && m < mm)){
      foundMeds[counter] = *(pMedicines[i]);
      counter += 1;
    }
  }

  // return the array
  return foundMeds;
}


int enterTextFile(Medicine *meds, int elements, double minPrice, double maxPrice){

  int counter = 0;

  // open the text file
  FILE *tfp = fopen("offer.txt", "w");
  if(tfp == NULL){
    exit(1);
  }

  for(int i = 0; i < elements; i++){

    if(minPrice < (*(meds + i)).price && maxPrice > (*(meds + i)).price){

      // put the name into the file, do not set new line it has one on default 
      fprintf(tfp, "%s", (*(meds + i)).name);

      // put the date into the file, do not set new line it has one on default
      fprintf(tfp, "%s", (*(meds + i)).date);
      
      // put the code into the text file, dont forget to set new line
      fprintf(tfp, "%d\n", (*(meds + i)).code);
     
      // put the price into the text file, dont forget to set new line and to set "leva" and format to the second number
      fprintf(tfp, "%.2lfleva\n", (*(meds + i)).price);

      // put the quantity into the text file, dont forget to set new line and another new line that mark the end of one med
      fprintf(tfp, "%d\n\n", (*(meds + i)).quantity);

      counter += 1;
    }
  }
  fclose(tfp);

  return counter;
}


int delete(Medicine *meds, int elements, char name[], char date[]){

  // cycle to find the correct element
  for(int i = 0; i < elements; i++){
    if(strcmp(name, (*(meds + i)).name) == 0 && strcmp(date, (*(meds + i)).date) == 0){

      // if it is the last element realloc to -1
      if(i == elements - 1){
        realloc(meds, (elements - 1) * sizeof(Medicine));
        return 1;
      }

      // else change the last element with current element and realloc 
      else{
        Medicine temp = *(meds + (elements - 1));
        *(meds + (elements - 1)) = *(meds + i);
        *(meds + i) = temp;
        realloc(meds, (elements - 1) * sizeof(Medicine));
        return 1;
      }

    }
  }
  return 0;
}



int main(){

  // file open
  FILE *fp = fopen("medicine.bin", "wb");
  if(fp == NULL){
    exit(1);
  }

  // moving cursor
  fseek(fp, 0, SEEK_END);

  // finding the len of the file
  // ftell() - where is the cursor
  int len = ftell(fp);

  // finding the len of 1 struct of med
  int numberOfMedsInFile = len / sizeof(Medicine);

  // retuning the cursor to the start of the file
  rewind(fp);

  // creating dynamic array for all meds in the file
  Medicine *pMedicines = (Medicine*)malloc(len);
  if(pMedicines == NULL){
    exit(1);
  }

  // getting all meds from the file
  for(int i = 0; i < numberOfMedsInFile; i++){
    Medicine *med;

    fread(med, sizeof(med), 1, fp);
    if(med == NULL){
      exit(1);
    }

    pMedicines[i] = *med;
  }

  fclose(fp);

  Medicine *result = search(pMedicines, numberOfMedsInFile, "20.2020");

  int res = enterTextFile(pMedicines, numberOfMedsInFile, 2.33, 10.33);

  int del = delete(pMedicines, numberOfMedsInFile, "name", "11.1111");

  if(del == 0){
    printf("nothing was found");
  }

  free(pMedicines);
  free(result);


  return 0;
}