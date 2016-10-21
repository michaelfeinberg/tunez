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

  if(!front || strncmp(newName,front->name,256)<0){
    return insert_front(front,newName,newArtist);
  }
  
  song_node * prev = front;
  song_node * curr = front->next;
  
  //loop through list until null or until the song is alphabetically first
  while(curr && strncmp(newName,curr->name,256)>0){
    prev = curr;
    curr = curr->next; 
  }
  //insert at stopped position
  song_node * endList = insert_front(curr,newName,newArtist);
  
  //link entire list and return front
  prev->next = endList;
  return front;
  
}
void print_song(song_node * front){
  if(front==NULL){
    printf("This song does not exist\n\n");
  }else{
    printf("Name: %s\n",front->name);
    printf("Artist: %s\n",front->artist);
  }
}
void print_list(song_node * front){
  if(!front){
    printf("There are no songs on this list\n\n");
  }else{
    while(front){
      print_song(front);
      printf("\n");
      front = front->next;
    }
    
  }
}
/*
song_node * free_list(song_node *front){
  if(front != NULL){
    song_node * next = front -> next;
    free(front);
    free_list(front->next);
  }else{
    return NULL;
  }
*/
song_node * find_song(song_node * front, char name[]){
  song_node * curr = front;
  while(curr){
    if(!strcmp(curr->name,name)){
      return curr;
    }
    curr = curr->next;
  }
  return 0;
}

song_node * find_artist(song_node * front, char artist[]){
  song_node * curr = front;
  while(curr){
    if(!strcmp(curr->artist,artist)){
      return curr;
    }
    curr = curr->next;
  }
  return 0;
}


int get_size(song_node * front){
  int length = 0;
  while(front){
    front = front -> next;
    length++;
  }
  return length;
}

song_node * rand_song(song_node * front){
  int length = get_size(front);
  sranddev();
  int place = rand() % length;
  while(place){
    front = front->next;
    place--;
  }
  return front;
}

song_node * free_list(song_node * front){
  
  if(!front){
    return 0;
  }else{
    song_node * next = front->next;
    free(front);
    return free_list(next);
  }
  
}
song_node * remove_song(song_node * front, char songName[]) {
  if(!front){
    return NULL;
  }else if(!strncmp(songName,front -> name,256)){
    song_node * newHead = front -> next;
    free(front);
    return newHead;
  }
  else{
    song_node * prev = front;
    song_node * current = front->next;

    while(current){
      if(!strncmp(current -> name,songName,256)){
        prev -> next = current -> next;
	free(current);
	return front;
      }
      prev = current;
      current = current->next;
    }
    return front;
  }
}
int main(){
  
  song_node * head; 
  char song1[256] = "Hello";
  char art1[256] = "Adele";
  
  char song2[256] = "Take On Me";
  char art2[256] = "A-Ha";

  char song3[256] = "Rolling in the Deep";
  char art3[256] = "Adele";

  printf("print 1\n");
  print_list(head);
  
  head = insert_song(head,song1,art1);
  printf("print 2\n"); 
  print_list(head);
  
  head = insert_song(head,song2,art2);
  head = insert_song(head,song3,art3);

  printf("print 3\n"); 
  print_list(head);
  
  song_node * rando = rand_song(head);
  printf("print 4\n");
  print_song(rando);
  
  head = remove_song(head,rando->name);
  
  printf("print 5\n");
  print_list(head);

  head = free_list(head);
  printf("print 6\n"); 
  print_list(head);
  
  
  return 0;
}
