/*
 * pr06.c
 *
 */

#include <stdio.h>
#include <string.h> //for strcpy(), strlen()
#include <stdlib.h> //for malloc(), free()

#define MAX_SIZE 81
struct namect {
  char * fname; //using pointers
  char * lname;
  int letters;
};

void getinfo(struct namect *); // allocates memory
void makeinfo(struct namect *);
void showinfo(const struct namect *);
void cleanup(struct namect *); // free memory when done

int main(void)
{
 struct namect person;

 getinfo(&person);
 makeinfo(&person);
 showinfo(&person);
 cleanup(&person);

 return 0;
}

void getinfo (struct namect * pst) {
 char temp[MAX_SIZE];

 printf("Please enter your first name.\n");
 scanf("%s",temp);
 pst->fname = (char *) malloc(strlen(temp)+1);
 strcpy(pst->fname, temp); //char *strcpy(char *dest, const char *src)

 printf("Please enter your last name.\n");
 scanf("%s",temp);
 pst->lname = (char *) malloc(strlen(temp)+1);
 strcpy(pst->lname, temp);  //char *strcpy(char *dest, const char *src)
}

void makeinfo (struct namect * pst) {
 pst->letters = strlen(pst->fname) +
                strlen(pst->lname);
}

void showinfo (const struct namect * pst) {
 printf("%s %s, your name contains %d letters.\n",pst->fname, pst->lname, pst->letters);
}

void cleanup(struct namect * pst) {
 free(pst->fname);
 free(pst->lname);
}

