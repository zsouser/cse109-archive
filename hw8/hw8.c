#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Bogus{
  int key;
  double data;
};

void  check(int b,const char *mess);
void display(FILE *f);
FILE* openFile(const char * name,const char*mode);
void createDB(FILE *f,FILE*g);

int main(){
  FILE*f,*g;
  f=openFile("update.dat","r");
  g=openFile("hw8.db","w+b");
  createDB(f,g);
  printf("Here is an echo of 'hw8.db'\n");
  display(g);
  fclose(g);
  return 0;
}
      
void display(FILE *f){
  int ok;
  struct Bogus a;
  fseek(f,0,SEEK_SET);
  ok=fread(&a,sizeof(struct Bogus),1,f);
  while(ok){
    printf(" %d  %f\n",a.key,a.data);
    ok=fread(&a,sizeof(struct Bogus),1,f);
  }
}

FILE* openFile(const char * name,const char*mode){
  FILE * f;
  char temp[200];
  f=fopen(name,mode);
  strcpy(temp,"Failure to open file '");
  strcat(temp,name);
  strcat(temp,"'");
  check(f!=NULL,temp);
  return f;
}
  
void  check(int b,const char *mess){
  if(!b){
    printf(" boo\n");
    exit(1);
  }
}

void createDB(FILE *f,FILE*g){
  int ok;
  struct Bogus a;
  ok=fscanf(f," %d %lf",&(a.key),&(a.data));
  while(ok>0){
    printf("Storing %d %f\n",a.key,a.data);
    fwrite(&a,sizeof(struct Bogus),1,g);
    ok=fscanf(f," %d %lf",&(a.key),&(a.data));
    // --------------^^^----------
    //NOTE: The compiler warns agains %f but accepts %lf
    //      I assume the l stands for long
  }
}
