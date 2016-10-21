//Michael Feinberg + Felix Rieg-Baumhauer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "list.h"
#include "musicLib.h"

//This is the musicLib, it is where all the music is stored

// an array songnodes
//song_node *table[26];


int find_spot(char letter){
  return letter-97;//return 0 for a , 25 for z
}

void add_song( song_node *t[], char name[], char artist[] ){
  char fLetter = artist[0];
  int pos = find_spot(fLetter);
  printf("Adding %s by %s\n", name, artist);
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
    printf("[ %s-%s,", n->name, n->artist);
      while(n->next){
	n=n->next;
	if(strcmp(n->artist, artist)){//if not the same artist, break
	  break;
	}
	printf(" %s-%s,", n->name, n->artist);
      }
      printf("]\n");
  }
}

void shuffle(song_node *t[], int num){
  int i;
  printf("Lets Shuffle:\n");
  srand(time(NULL));
  //srandev();
  for(int i=0; i<num; i++){
    srand(time(NULL));
    //could use
    //srandev();
    int letter = rand() % 26;
    while(!(t[letter])){
      letter = rand() % 26;//reroll if nothing in that table slot
    }    
    printf("Song %d:\n", i+1);
    print_song(rand_song(t[letter]));
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
    print_list(t[i]);
    printf("\n");
  }
}

song_node * delete_song(song_node *t[], char name [], char artist []){
  int pos = find_spot(artist[0]);
  return (remove_song(t[pos], name));
}

void delete(song_node *t[]){
  int i;
  for(int i=0; i<26; i++){
    free_list(t[i]);
    t[i]=0;
  }
}

/*
int main(){
  
  add_song(table, "bigboy", "ajimi");
  add_song(table, "bigbered", "ajimi");
  add_song(table, "bigboy", "bjimi");
  add_song(table, "bigboy", "ejimi");
  add_song(table, "bigbiu", "ajimi");
  add_song(table, "bigboyes", "ajimi");
  add_song(table, "abc", "ajimboi");
  add_song(table, "dereeboy", "ajimil");
  add_song(table, "bigboydede", "ajimiede");
  
  printf("The reuslt of the search: %s\n", (search_song(table, "bigboy", "ajimi"))->name);
  struct song_node *artist_ptr = search_artist(table, "ajimi");
  printf("The result of the artist search: %s by %s\n", artist_ptr->name, artist_ptr->artist);
  
  print_artist(table, "ajimi");
  print_artist(table, "cjimi");
  print_letter(table, 'a');
  print_letter(table, 'd');
  print_library(table);
  delete_song(table, "bigbiu", "ajimi");
  print_library(table);
  
  shuffle(table, 2);
  delete(table);
  print_library(table);

  //print_song(rand_song(table[24]));
  
  //free_list(table[0]);
  //print_library(table);

  //
  //int i;
  //for(i=0; i<26; i++){
    //printf("%c", 97+i);
    //print_list(table[i]);
    //printf("\n");
  //}
  //
  return 0;
}
*/

