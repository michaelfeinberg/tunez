

typedef struct song_node{
  char name[256];
  char artist[256];
  struct song_node *next;

} song_node;
int get_size(song_node *);
song_node * insert_front(song_node *,char[],char[]);
song_node * insert_song(song_node *,char[],char[]);
void print_song(song_node *);
void print_list(song_node *);
song_node * find_song(song_node *,char[]);
song_node * find_artist(song_node *,char[]);
song_node * rand_song(song_node *);
//song_node * remove_song(song_node *, song_node *);
song_node * free_list(song_node *);
