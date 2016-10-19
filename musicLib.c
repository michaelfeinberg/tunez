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

/*
struct song_node * search_articst(song_node *t[], char artist[]){
  int pos = find_spot(artist[0]);
  struct song_node *a_node = t[pos];
  struct song
  a_node = find_artist(a_node, artist);
  if(!a_node){
    return 0;
  }
  
