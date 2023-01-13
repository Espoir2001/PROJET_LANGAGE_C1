#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mylib/mylib.h"

//#define L 50

/*! 
   \brief Programme treetest, on charge une arborescence  et on cherche un fichier dans l'arborescence.

   \author Espoir HOUEDJI 
*/

int main(int argc, char **argv)
{
   
    char v1[BUFSIZ];
    char v2[BUFSIZ];


FILE *fp;

char s[BUFSIZ];

fp=fopen("tree.conf","r");

if(fp==NULL)
{
    perror("tree.conf");
    return 1;
}

while(fgets(s,BUFSIZ,fp)!=NULL)
{     
    s[strlen(s)]='\0' ; // supprime le \n final
    char *ptr = strchr(s,'#');

    if(ptr!=NULL)
    {
        *ptr='\0' ; //pour ne pas tenir compte des lignes de commentaire
    }
    else
    {
        continue;
    }
}

fclose(fp);
parse(s,v1,v2);

struct TreeNode *root =load((const char *) v2);


if(argc !=2 )
{
    printf("Usage:\n\t./treetest file\n");
    return 0;
}

//printf("\n");
search(root,argv[1]);

    return 0;
}