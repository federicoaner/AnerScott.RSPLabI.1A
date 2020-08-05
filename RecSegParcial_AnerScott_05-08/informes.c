#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "posts.h"
#include "validacion.h"

int filtrarHeater( void* unPost){

    int auxReturn=0;
    ePost* x;
    int likes;
    int dislikes;

    if(unPost!=NULL){
      x=(ePost*)unPost;
    post_getLikes(x,&likes);
    post_getDislikes(x,&dislikes);


    if( dislikes>likes){

        auxReturn=1;
    }

}
return auxReturn;
}

int ordenarFollowers(void* a, void* b)
{
    int returnAux=0;
    ePost* p1;
    ePost* p2;
    int auxF1;
    int auxF2;

    if(a != NULL && b != NULL)
    {
        p1 = (ePost*)a;
        p2 = (ePost*)b;

       post_getFollowers(p1,&auxF1);
        post_getFollowers(p2,&auxF2);

        if(auxF1 < auxF2)
        {
            returnAux=1;
        }

    }
    return returnAux;
}



void mostrarMasPopular(LinkedList* lista)
{
    ePost* auxPost;
    int auxLikes;
    int maxLikes = 0;
    int flag = 0;

    if(lista != NULL)
    {

        for(int i = 0; i < ll_len(lista); i++)
        {
            auxPost = (ePost*) ll_get(lista,i);
            post_getLikes(auxPost,&auxLikes);
            if(auxLikes > maxLikes || !flag)
            {
                maxLikes = auxLikes;
                flag = 1;
            }
        }

        printf("Usuario con mas likes: %d\n",maxLikes);
        printf("  Id     User                   Likes      Dislikes    Followers\n");

        for(int i = 0; i < ll_len(lista); i++)
        {
            auxPost = (ePost*) ll_get(lista,i);
            post_getLikes(auxPost,&auxLikes);

            if(auxLikes >= maxLikes)
            {
                listarPost(lista,i);
            }
        }

    }

}
