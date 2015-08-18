
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int roll(char *d);
void helpmessage(void);

int main(int argc, char **argv){

  if (argc > 1 && !strncmp(argv[1],"-h",2)){
    helpmessage();
    return 1;
  }

  int seed;
  FILE *seedfile;
  if (!(seedfile = fopen("/dev/urandom","r"))){
    seed = clock();
  } else {
    seed = getc(seedfile);
  }
  
  srand(seed);

  char dicestr[5];

  if (argc > 1){
    strncpy(dicestr,argv[1],5);
    printf("%d\n", roll(dicestr));
    return 0;
  } else {
    while (1){
      printf("\n==> ");
      scanf("%s",&dicestr);
      if (dicestr[0] != 'q')
        printf("%d\n", roll(dicestr));
      else
        return 0;
    }
  }

}

int roll(char *d){
  int i, num, die, result = 0;
  if ((sscanf(d,"%dd%d",&num, &die) != 2) || num < 0 || die < 0){
    fprintf(stderr, "ERROR: please use XdY format.\n");
    return -1;
  }

  for (i=0; i < num; i++)
    result += rand() % die + 1;
  
  return result;
}

void helpmessage(){
  printf("   _       _                  _          _   ___  _\n");
  printf("  /_\\ _  _| |_ ___ _ __  __ _| |_ ___ __| | |   \\(_)__ ___\n");
  printf(" / _ \\ || |  _/ _ \\ '  \\/ _` |  _/ -_) _` | | |) | / _/ -_)\n");
  printf("/_/ \\_\\_,_|\\__\\___/_|_|_\\__,_|\\__\\___\\__,_| |___/|_\\__\\___|\n");
  printf(" ___     _ _\n");
  printf("| _ \\___| | |___ _ _\n");
  printf("|   / _ \\ | / -_) '_|\n");
  printf("|_|_\\___/_|_\\___|_|\n");

  printf("\nFor interactive use, just run \"dice\", and then enter\n");
  printf("the number and kind of dice to roll at the prompt, in the\n");
  printf("format \"XdY\", where X is the number and Y is the kind of\n");
  printf("dice to roll.\n");
  printf("\nOr, you can supply the number-d-kind string as a command-\n");
  printf("line argument, and roll dice directly from the shell.\n");
}





