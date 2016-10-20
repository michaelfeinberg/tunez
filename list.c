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
  //printf("!front = %d\n",!front);

  if(!front || strncmp(newArtist,front->artist,256)<0){
    return insert_front(front,newName,newArtist);
  }
  
  song_node * prev = front;
  song_node * curr = front->next;
  
  char *currArtist = curr->artist;
  //loop through list until null or until the song is alphabetically first
  while(curr && strncmp(newArtist,currArtist,256)>0){
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
    while(front != NULL){
      printf("Name: %s\n", front->name);
      printf("Artist: %s\n\n", front->artist);
      front = front->next;
    }
    
  }
}

song_node * free_list(song_node *front){
  if(front != NULL){
    song_node * next = front -> next;
    free(front);
    free_list(front->next);
  }else{
    return NULL;
  }
}

int main(){
  
  song_node * head; 
  char song1[256] = "Hello";
  char art1[256] = "Adele";
  
  char song2[256] = "Take On Me";
  char art2[256] = "A-Ha";
  printf("print 1\n");
  print_list(head);
  
  head = insert_song(head,song1,art1);
  printf("print 2\n"); 
  print_list(head);
  
  head = insert_song(head,song2,art2);
  printf("print 3\n"); 
  print_list(head);
  
  free_list(head);
  printf("print 4\n"); 
  print_list(head);
  return 0;
}
