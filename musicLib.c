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
