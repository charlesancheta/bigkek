#include <stdio.h>

#define MAXTITL 41 /* max title length + 1 */
#define MAXAUTL 31 /* max name length + 1 */



struct book {                   /* structure template: tag is book */
  char title[MAXTITL];
  char author[MAXAUTL];
  float value;
};                              /* end of structure template */


char title[MAXTITL];
char author[MAXAUTL];
float value;




int main(void)
{

 struct book library; /* declare library as a book variable */





 printf("Please enter the book title.\n");
 gets(library.title); /*access to the title portion*/

 printf("Now enter the author.\n");
 gets(library.author);

 printf("Now enter the value.\n");
 scanf("%f", &library.value);

 printf("%s by %s: $%.2f\n",library.title, library.author, library.value);
 printf("%s: \"%s\" ($%.2f)\n", library.author, library.title, library.value);

 printf("Done.\n");

 return 0;
}
