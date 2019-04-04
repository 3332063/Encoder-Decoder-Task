#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int op1, op2, op3, op4, op5;

int main()
{
  printf("----Welcome to the encoder and decoder program----\n\n");
  printf("Main Menu\n");
  printf("1. Encode Text\n");
  printf("2. Decode Text\n");
  printf("3. Exit Program\n");
  printf("Enter your option: ");
  scanf("%d", &op1);
  switch(op1)
    {
      case 1:
        {
          printf("\nWould you like to encode your text\n");
          printf("1. From a .txt file\n");
          printf("2. From inside the console\n");
          printf("Enter your option: ");
          scanf("%d", &op2);
          switch(op2)
            {
              case 1:
                {
                  FILE *fr, *fw;
                  char ch, fileread[40], filewrite[40];
                  int op, kv;
                  printf("\nEnter the file name to be encoded: ");
                  scanf("%s", fileread);
                  fr=fopen(fileread, "r");
                  fw=fopen(filewrite, "w");
                  printf("Enter the key value: ");
                  scanf("%d", &kv);
                  printf("Enter the name of the output file: ");
                  scanf("%s", filewrite);
                  fr=fopen(fileread, "r");
                  fw=fopen(filewrite, "w");
                  if(fr==NULL)
                    {
                      perror("");
                      return 0;
                    }
                  ch=fgetc(fr);
                  while (ch!=EOF)
                    {
                      op=(int)ch;
                      op=op+kv;
                      fprintf(fw, "%c", op);
                      ch=fgetc(fr);
                    }
                  fclose(fr);
                  fclose(fw);
                  printf("\nThe file has sucessfully been encoded and saved as %s\n", filewrite);
                  return 0;
                }
              case 2:
                {
                  int kv, n;
                  char ch[40];
                  printf("\nEnter the code to be encoded: ");
                  scanf("%s", &ch);
                  printf("Enter the key value: ");
                  scanf("%d", &kv);
                  for(n=0; n<strlen(ch); n++)
                    {
                      if (ch[n]==' ') { }
                      else
                        {
                          ch[n]=ch[n]+kv;
                        }
                    }
                  printf("Your encoded text is: %s\n", ch);
                  return 0;
                }
              default: perror("");
                {
                  return 0;
                }
            }
        }
      case 2:
        {
          printf("\nWould you like to decode your text\n");
          printf("1. From a .txt file\n");
          printf("2. From inside the console\n");
          printf("Enter your option: ");
          scanf("%d", &op3);
          switch(op3)
            {
              case 1:
                {
                  FILE *fr, *fw;
                  char ch, fileread[40], filewrite[40];
                  int op, kv;
                  printf("\nEnter the file name to be decoded: ");
                  scanf("%s", fileread);
                  printf("Enter the key value: ");
                  scanf("%d", &kv);
                  printf("Enter the name of the output file: ");
                  scanf("%s", filewrite);
                  fr=fopen(fileread, "r");
                  fw=fopen(filewrite, "w");
                  if (fr==NULL)
                    {
                      perror("");
                      return 0;
                    }
                  ch=fgetc(fr);
                  while(ch!=EOF)
                    {
                      op=(int)ch;
                      op=op-kv;
                      fprintf(fw, "%c", op);
                      ch=fgetc(fr);
                    }
                  fclose(fr);
                  fclose(fw);
                  printf("\nThe file has sucessfully been decoded and saved as %s\n", filewrite);
                  return 0;
                }
              case 2:
                {
                  int kv, n;
                  char ch[100];
                  printf("\nEnter the code to be decoded: ");
                  scanf("%[^\n]s", ch);
                  printf("Enter the key value: ");
                  scanf("%d", &kv);
                  for(n=0; n<strlen(ch); n++)
                    {
                      if(ch[n]==' ') { }
                      else
                        {
                          ch[n]=ch[n]-kv;
                        }
                    }
                  printf("\nYour decoded text is: %s\n", ch);
                  return 0;
                }
              default: perror("");
                {
                  return 0;
                }
            }
        }
    }
}
