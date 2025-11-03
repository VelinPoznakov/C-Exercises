#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct treatment
{
  int id;
  char date[10];
  char name[30];
  char diagnose[50];
}Treatment;

int countTreatment(Treatment *history, int elements, char name[50], char diagnose[50]){

  int counter = 0;

  for(int i = 0; i < elements; i++){

    if(strcmp(history[i].diagnose, diagnose) == 0 && strcmp(history[i].name, name) == 0){
      counter += 1;
    }
  }

  return counter;
}

Treatment *addNewTreatment(Treatment *history, int elements){
  Treatment tr;

  scanf("%d", &tr.id);
  fgets(tr.date, 10, stdin);
  fgets(tr.name, 30, stdin);
  fgets(tr.diagnose, 50, stdin);

  Treatment *temp = realloc(history, (elements + 1) * sizeof(Treatment));
  if(temp == NULL){
    return NULL;
  }

  history = temp;
  history[elements] = tr;

  return history;
}





int main(){

  FILE *fp = fopen("history.bin", "rb");

  fseek(fp, 0, SEEK_END);

  int len = ftell(fp);

  int numberOfTreatments = len / sizeof(Treatment);

  rewind(fp);

  Treatment *history = (Treatment*)malloc(len);

  if(history == NULL){
    exit(1);
  }

  for(int i = 0; i < numberOfTreatments; i++){

    if(fread(&history[i], sizeof(Treatment), 1, fp) != 1){
      exit(1);
    }
  }

  fclose(fp);



  return 0;
}
