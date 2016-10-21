typedef struct song_node {
  char name[256];
  char artist[256];
  struct song_node *next;
}song_node;


void print_list( struct song_node *n );
void print_song( struct song_node *n );
song_node * insert_song( struct song_node *n, char name[], char artist[] );
song_node * insert_front( struct song_node *n, char name[], char artist[] );
song_node * free_list( struct song_node *n );
song_node * find_song(song_node *,char[]);
song_node * find_artist(song_node *, char[]);
int get_size(song_node *);
song_node * rand_song(song_node *);
song_node * remove_song(song_node *, char []);
