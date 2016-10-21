//Michael Feinberg + Felix Rieg-Baumhauer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "musicLib.h"

int main(){
  printf("The playlist prior to any actions\n");
  print_library(table);
  add_song(table, "alive", "pearl jam");
  add_song(table, "even flow", "pearl jam");
  add_song(table, "yellow ledbetter", "pearl jam");
  add_song(table, "time", "pink floyd");
  add_song(table, "another brick in the wall", "pink floyd");
  add_song(table, "little red corvette", "prince");
  add_song(table, "purple rain", "prince");
  add_song(table, "thunderstruck", "ac/dc");
  add_song(table, "highway to hell", "ac/dc");
  print_library(table);
  printf("\n");

  printf("Testing the find functions:\n");
  printf("Testing find song:\n");
  printf("Searching for time by pink floyd:\n");
  print_song(search_song(table, "time", "pink floyd"));
  printf("Searching for akewbemm by pink floyd:\n");
  print_song(search_song(table, "akewbemm", "pink floyd"));
  printf("\n");
  
  printf("Testing find artist:\n");
  printf("Searching for first song by pink floyd:\n");
  print_song(search_artist(table, "pink floyd"));
  printf("Searching for first song by queen:\n");
  print_song(search_artist(table, "queen"));
  printf("\n");
  
  printf("Testing print enteries under a certain letter:\n");
  printf("Print all songs under a:\n");
  print_letter(table, 'a');
  printf("Print all songs under b:\n");
  print_letter(table, 'b');
  printf("\n");
  
  printf("Testing print all songs by an artist:\n");
  printf("Print all songs by pearl jam:\n");
  print_artist(table, "pearl jam");
  printf("Print all songs by queen:\n");
  print_artist(table, "queen");
  printf("\n");
  
  shuffle(table, 3);
  printf("\n");

  printf("Testing delete a song:\n");
  printf("Deleting yellow ledbetter by pearl jam:\n");
  delete_song(table, "yellow ledbetter", "pearl jam");
  print_library(table);
  printf("\n");

  printf("Testing the delete all function:\n");
  delete(table);
  
  return 0;
}
