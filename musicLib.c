
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

//This is the musicLib, it is where all the music is stored

// an array songnodes
song_node *table[26];


int find_spot(char letter){
  return letter-97;//return 0 for a , 25 for z
}

void add_song( song_node *t[], char name[], char artist[] ){
  char fLetter = artist[0];
  int pos = find_spot(fLetter);
  t[pos] = insert_song(table[pos], name, artist);
}

struct song_node * search_song(song_node *t[], char name[], char artist[]){
  int pos = find_spot(artist[0]);
  return (find_song(t[pos], name));
}

struct song_node * search_artist(song_node *t[], char artist[]){
  int pos = find_spot(artist[0]);
  return (find_artist(t[pos], artist));
}

void print_artist(song_node *t[],  char artist[]){
  int pos = find_spot(artist[0]);
  struct song_node *n = (find_artist(t[pos], artist));
  if(!n){
    printf("There are no songs by that artist\n");
  }
  else{
    printf("*%s-%s*", n->name, n->artist);
      while(n->next){
	n=n->next;
	if(strcmp(n->artist, artist)){//if not the same artist, break
	  break;
	}
	printf("*%s-%s*", n->name, n->artist);
      }
      printf("\n");
  }
}

void print_letter(song_node *t[], char letter){
  int pos = find_spot(letter);
  printf("%c",letter);
  print_list(t[pos]);
}

void print_library(song_node *t[]){
  int i;
  for(i=0; i<26; i++){
    printf("%c", 97+i);
    print_list(table[i]);
    printf("\n");
  }
}
