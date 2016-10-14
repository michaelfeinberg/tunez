#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct song_node{
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

song_node * insert_front(song_node *front, char newName[], char newArtist[]){
  song_node * newFront = (song_node *)malloc(sizeof(song_node));
  strncpy(newFront->name,newName,256);
  strncpy(newFront->artist,newArtist,256);
  newFront->next = front;

  return newFront;
}

void insert_song(song_node *front, char newName[], char newArtist[]){
  song_node * newSong =  (song_node *)malloc(sizeof(song_node));

  song_node * p = front;
  if(!*p){
    insertFront(front,newName,newArtist);
  }else if(!*(p->next)){
    p = p->next;
    front->next = insertFront(p,newName,newArtist);
  }else{
    while(!*((p->next)->next)){
      if(strncmp(newArtist,p->artist,256)<0){
	
      }
    }
  }
}
