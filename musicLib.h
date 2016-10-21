song_node *table[26];

int find_spot(char);
void add_song(song_node *[], char [], char []);
struct song_node * search_song(song_node *[], char [], char []);
struct song_node * search_artist(song_node *[], char []);
void print_artist(song_node *[], char []);
void shuffle(song_node *[], int);
void print_letter(song_node *[], char);
void print_library(song_node * t[]);
struct song_node * delete_song(song_node *[], char [], char []);
void delete(song_node *[]);
