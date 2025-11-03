#include <stdio.h>


// 1

// int num(char name[]){
//   int counter = 0;

//   for(char *i = name; *i != '\0'; i++){
//     counter += 1;
//   }

//   return counter;
// }

int main(){

  // 1

  // char name[512];

  // fgets(name, sizeof(name), stdin);
  // int a = num(name);

  // printf("%d\n", a);

  // 2

  // char name[512];
  // int currentChar, allCount = 0;

  // fgets(name, sizeof(name), stdin);

  // while (1)
  // {
  //   if(name[currentChar] == '\0'){
  //     allCount += 1;
  //     break;
  //   }

  //   if(name[currentChar] == ' '){
  //     allCount += 1;
  //   }

  //   currentChar += 1;


  // }

  // printf("%d\n", allCount);


  // 3

  // char word[26];
  // char symbols[26];
  // int num[26];

  // for(int i = 0; i < 26; i++){
  //   symbols[i] = i + 97;
  //   num[i] = 0;
  // }

  // // printf("%c", (char)symbols[0]);

  // fgets(word, sizeof(word), stdin);

  // for(int i = 0; word[i] != '\0'; i++){

  //   for(int j = 0; j < 26; j++){
  //     if(symbols[j] == (int)word[i]){
  //       num[j] += 1;
  //       continue;
  //     }
  //   }
  // }

  // for(int i = 0; i < 26; i++){
  //   printf("%c - %d\n", (char)symbols[i], num[i]);
  // }


  // 4

  // char str1[10], str2[10];
  // int flag = 0;

  // fgets(str1, sizeof(str1), stdin);
  // fgets(str2, sizeof(str2), stdin);

  // for(int i = 0; i < 5; i++){
  //   if(str1[i] == str2[i]){
  //     flag = 1;
  //     continue;
  //   }
  //   else{
  //     printf("there is no mach between %c and %c\n", str1[i], str2[i]);
  //     flag = 0;
  //     break;
  //   }
  // }
  
  // if (flag){
  //   printf("%s is equal to %s\n", str1, str2);
  // }
  // else{
  //   printf("end of the programm with false result.\n");
  // }


  // 5

  // char word[50];
  // char letters[] = {'a', 'i', 'u', 'e', 'o'};
  // int counter = 0;

  // fgets(word, sizeof(word), stdin);

  // for(int i = 0; i < sizeof(word) / sizeof(char); i++){
  //   for(int j = 0; j < sizeof(letters) / sizeof(char); j++){
  //       if(word[i] == letters[j]){
  //         counter += 1;
  //     }
  //   }
  // }

  // printf("the number is %d\n", counter);




  return 0;
}