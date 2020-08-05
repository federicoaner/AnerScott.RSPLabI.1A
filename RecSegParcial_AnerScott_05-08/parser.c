
#include "LinkedList.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//#include "ePost.h"
#include "posts.h"

int parser(FILE* pFile, LinkedList* pPosts)
{
    int todoOk = 1;
    ePost* pPost;
    char id[200];
    char user[200];
    char likes[200];
    char dislikes[200];
    char followers[200];



    if(pFile != NULL && pPosts != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, user, likes, dislikes,followers);
        do
        {
            if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, user, likes, dislikes,followers) == 5)
            {
                pPost = post_newParametros(id, user, likes, dislikes,followers);

                if(pPost != NULL)//osea si pudo cargar
                {
                    ll_add(pPosts, pPost);
                    todoOk = 0;
                }
            }
            else
            {
                break;
            }

        }
        while(feof(pFile) == 0);
    }

    return todoOk;
}

int loadFromText(LinkedList* pArrayListPosts)
{
    int todoOk = 1;
    char path[128];

    printf("Ingrese el nombre del archivo (sin extension): ");
    fflush(stdin);
    scanf("%s",path);

    strcat(path,".csv");


    FILE* f = fopen(path,"r");

    if(f != NULL)
    {
        if(!parser(f,pArrayListPosts))
        {
            todoOk = 0;
            printf("Se cargaron los datos\n");
        }
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }

    fclose(f);

    return todoOk;
}

int guardarTexto(char* path, LinkedList* pArrayList)
{
    int todoOk=-1;
    FILE* f=fopen(path,"w");
    int id;
	char user[128];
    int likes;
   int dislikes;
   int followers;



    ePost* auxPost;



    if(f!=NULL && pArrayList != NULL)
    {
        fprintf(f,"id,user,likes,dislikes,followers\n");

        for (int i=0; i<ll_len(pArrayList) ; i++ )
        {

            auxPost = ll_get(pArrayList,i);

            post_getId(auxPost, &id);
            post_getUser(auxPost, user);
            post_getLikes(auxPost, &likes);
            post_getDislikes(auxPost, &dislikes);
            post_getFollowers(auxPost,&followers);


            fprintf(f,"%d,%s,%d,%d,%d\n",id,user,likes,dislikes,followers );
            todoOk=1;

        }

        printf("\nArchivo guardado con exito!!!\n");

    }

    else
    {
        printf("error al guardar");
    }

    fclose(f);


    return todoOk;
}
