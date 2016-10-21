//Michael Feinberg + Felix Rieg-Baumhauer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "list.h"

void print_list( struct song_node *n ) {
  printf("[ ");
  while(n) {
    printf("%s-%s, ", n->name, n->artist);
    n = n->next;
  }
  printf("]\n");
}

void print_song(struct song_node *n){
  if(!n){
    printf("That song does not exist\n");
  }
  else{
    printf("%s-%s\n", n->name, n->artist);
  }
}


struct song_node * insert_front( struct song_node *n, char name[], char artist[]) {

  struct song_node *new = (struct song_node *)malloc(sizeof(struct song_node));

  new->next = n;
  strcpy(new->name, name);
  strcpy(new->artist, artist);

  return new;
}

song_node * insert_song(song_node *front, char newName[], char newArtist[]){
  //If list is null or song is alphabetically before first element
  //printf("!front = %d\n",!front);

  if(!front || strncmp(newArtist,front->artist,256)<0){
    return insert_front(front,newName,newArtist);
  }
  
  song_node * prev = front;
  song_node * curr = front->next;
  
  //loop through list until null or until the song is alphabetically first
  while(curr && strncmp(newArtist,curr->artist,256)>0){
    prev = curr;
    curr = curr->next; 
  }
  //insert at stopped position
  song_node * endList = insert_front(curr,newName,newArtist);
  
  //link entire list and return front
  prev->next = endList;
  return front;
}

struct song_node * free_list( struct song_node *n ) {

  struct song_node *f = n;
  while ( n ) {
    n = n->next;
    printf("freeing node: [%s-%s]\n", f->name, f->artist );
    free(f);
    f = n;    
  }
  return n;
}

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
  //srand(time(NULL));
  //sranddev();
  int place = rand() % length;//was divison before
  while(place){
    front = front->next;
    place--;
  }
  return front;
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

//--------------------------------
/*
int main(){
  
  struct song_node * head = 0; 
  char song1[256] = "hello";
  char art1[256] = "adele";
  
  char song2[256] = "take On Me";
  char art2[256] = "a-Ha";
  char song3[256] = "btake On Me";
  char art3[256] = "ba-Ha";
  printf("print 1\n");
  //print_list(head);
  
  head = insert_song(head,song1,art1);
  printf("print 2\n"); 
  print_list(head);
  
  head = insert_song(head,song2,art2);
  head = insert_song(head,song3,art3);
  printf("print 3\n"); 
  print_list(head);

  head = remove_song(head, "take On Me");

  print_list(head);
  
  head = free_list(head);
  printf("print 4\n"); 
  print_list(head);
  return 0;
}
*/

/*
int main(){
  struct song_node *list = 0;
  
  print_list( list );
 
  list = insert_song( list, "hot rod", "beatles");

  list = insert_song( list, "hot red", "beatlos");
  list = insert_song( list, "hot rad", "beatles");
  list = insert_song( list, "hot rud", "beatlas");
  
  print_list( list );

  struct song_node *found = 0;
  found = find_song(list, "hot red");
  print_list(found);
  printf("%s-%s\n", found->name, found->artist);
  
  list = free_list( list );

  print_list( list );
  
  return 0;
}
*/

/*
int main() {

  struct node *list = 0;

  print_list( list );

  int i;
  for (i=0; i < 10; i++)
    list = insert_front( list, i);

  print_list( list );

  list = free_list( list );

  print_list( list );
  
  return 0;
}
*/
