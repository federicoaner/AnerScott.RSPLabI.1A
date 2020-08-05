#ifndef EPOST_H_INCLUDED
#define EPOST_H_INCLUDED

typedef struct
{
    int id;
   char  user[128];
    int likes;
    int dislikes;
    int followers;



} ePost;

#endif // EPOST_H_INCLUDED



ePost* post_new();
ePost* post_newParametros(char* idStr,char* userStr,char* likesStr,char* dislikesStr,char* followersStr);
void post_delete(ePost* unPost);
int post_getId(ePost* this, int* id);
int post_getUser(ePost* this, char* user);
int post_getLikes(ePost* this, int* likes);
int post_getDislikes(ePost* this, int* dislikes);
int post_getFollowers(ePost* this, int* followers);
int post_setId(ePost* this,int id);
int post_setUser(ePost* this,char* user);
int post_setLikes(ePost* this,int likes);
int post_setDislikes(ePost* this,int dislikes);
int post_setFollowers(ePost* this,int followers);
void listarPost(LinkedList* lista, int index);
int mostrarPosts(LinkedList* pArraylist);
int getRandomLikes();
int getRandomDislikes();
int getRandomFollowers();
void* asignarCamposPosts(void* pElement);
int post_setCampos(LinkedList* lista);
void settearLikes(void* element);
void settearDislikes(void* element);
void settearFollowers(void* element);






