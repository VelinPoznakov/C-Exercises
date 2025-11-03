#include <stdio.h>
#include <stdlib.h>

int sqare(){
  int a;
  printf("Enter side");
  scanf("%d", &a);

  return a * a;
}

int rectangle(){
  int a, b;
  scanf("%d", &a);
  scanf("%d", &b);

  return a * b;
}

int triangle(){
  int a, b;
  scanf("%d", &a);
  scanf("%d", &b);

  return (a * b) / 2; 
}

double circle(){
  int r;
  scanf("%d", &r);

  return 3.14 * r * r;
}

//2

int change(int *a, int *b, int *c){
  *c = *a;
  *a = *b;
  *b = *c;

  //*a = *c;
  //*b = *a;
  //*b = *c;

  //int arr[2] = {a, b};

  return 0;
}


int main(void){

  //1

  // int num;
  // scanf("%d", &num);

  // switch (num){

  //   case 1:
  //     int result = sqare();
  //     printf("%d", result);
  //     break;
    
  //   case 2:
  //     printf("%d", rectangle());
  //     break;

  //   case 3:
  //     printf("%d", triangle());
  //     break;

  //   case 4:
  //     printf("%lf", circle());
  //     break;

  //   default:
  //     printf("Invalid numbear restart and try again.");
  //     break;  
  // }

  int a, b, c;

  scanf("%d", &a);
  scanf("%d", &b);

  //int arr[2] = change(a, b, c);

  //printf("a = %d, b = %d\n", arr[0], arr[1]);
  change(&a, &b, &c);
  printf("%d\n", a);
  printf("%d\n", b);
  return 0;
}