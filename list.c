#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
/*
typedef struct song_node{
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;
*/
song_node * insert_front(song_node *front, char newName[], char newArtist[]){
  song_node * newFront = (song_node *)malloc(sizeof(song_node));
  strncpy(newFront->name,newName,256);
  strncpy(newFront->artist,newArtist,256);
  newFront->next = front;

  return newFront;
}

song_node * insert_song(song_node *front, char newName[], char newArtist[]){
  //If list is null or song is alphabetically before first element
  if(!*front || strncmp(newArtist,front->artist,256)<0){
    return insert_front(front,newName,newArtist);
  }
  
  song_node * prev = front;
  song_node * curr = front->next;
  
  char *currArtist = curr->artist;
  //loop through list until null or until the song is alphabetically first
  while(*curr && strncmp(newArtist,currArtist,256)>0){
    prev = curr;
    curr = curr->next; 
  }
  //insert at stopped position
  song_node * endList = insert_front(curr,newName,newArtist);
  
  //link entire list and return front
  prev->next = endList;
  return front;
  
}

void print_list(song_node * front){
  if(front==NULL){
    printf("There are no songs on this list\n");
  }else{
    while(front->next != NULL){
      printf("Name: %s\n", front->name);
      printf("Artist: %s\n\n", front->artist);
      front = front->next;
    }
    
  }
}

//----------------------------Felix's work, you can break this if it not good

struct song_node * find_song(struct song_node * n, char name[]){
  if(!n){
    return 0;
  }
  while(n){
    //printf("%s--%s\n", n->name, name);
    if(!(strcmp(n->name,name))){
      return n;
    }
    n=n->next;
  }
  return 0;
}

struct song_node * find_artist(struct song_node * n, char artist[]){
  if(!n){
    return 0;
  }
  if(!(strcmp(n->artist,artist)))
    return n;
  while(n->next){
    n=n->next;
    //printf("%s--%s\n", n->name, n->artist);
    if(!(strcmp(n->artist,artist))){
      return n;
    }
  }
  return 0;
}


//-----



int main(){
  





  return 0;
}
