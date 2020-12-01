#include "SONGS_HANDLER.h"

static void display_menu();
static void display_playlist(const list<Song> &playlist, const Song &current_song);
static void play_first_song(list<Song> &playlist, list<Song>::iterator &current_song);
static void play_next_song(list<Song> &playlist, list<Song>::iterator &current_song);
static void play_previus_song(list<Song> &playlist, list<Song>::iterator &current_song);
static void add_song(list<Song> &playlist, list<Song>::iterator &current_song);
static void play_current_song(const Song &song);
static void display_playlist(const list<Song> &playlist, const Song &current_song);

static void display_menu() {
	cout << "\nF - Play First Song" << endl;
	cout << "N - Play Next song" << endl;
	cout << "P - Play Previous song" << endl;
	cout << "A - Add and play a new Song at current location" << endl;
	cout << "L - List the current playlist" << endl;
	cout << "===============================================" << endl;
	cout << "Enter a selection (Q to quit): ";
}

static void play_first_song( list<Song> &playlist, list<Song>::iterator &current_song) {
	current_song = playlist.begin();
	play_current_song(*current_song);
}

static void play_next_song(list<Song> &playlist, list<Song>::iterator &current_song) {
	current_song++;
	if (current_song == playlist.end()) {
		current_song = playlist.begin();
	}
	play_current_song(*current_song);
}

static void play_previus_song(list<Song> &playlist, list<Song>::iterator &current_song) {
	if (current_song == playlist.begin()) {
		current_song = playlist.end();
	}
	else {
		current_song--;
	}
	play_current_song(*current_song);
}

static void add_song(list<Song> &playlist, list<Song>::iterator &current_song) {
	string name, artist;
	int rating;

	std::cout << "Enter song name:";
	cin >> name;
	std::cout << "Enter song artist: ";
	cin >> artist;
	std::cout << "Enter your rating (1-5): ";
	cin >> rating;
	playlist.insert(current_song, Song{ name, artist, rating });
	current_song--;
	play_current_song(*current_song);
}

static void play_current_song(const Song &song) {
	cout << "Playing: " << std::endl;
	cout << song << std::endl;
}

static void display_playlist(const list<Song> &playlist, const Song &current_song) {
	for (auto &i : playlist) {
		cout << i << endl;
	}
	cout << "The current song is: " << endl;
	cout << current_song << endl;
}

void turn_on( list<Song> &playlist, list<Song>::iterator &current_song) {
	char action {'\0'};
	cin.clear();
	while (toupper(action) != 'Q') {
		display_menu();
		cin >> action;
		switch (toupper(action)) {
			case 'F': {
				play_first_song(playlist, current_song);
				break;
			}
			case 'N': {
				play_next_song(playlist, current_song);
				break;
			}
			case 'P': {
				play_previus_song(playlist, current_song);
				break;
			}
			case 'A': {
				add_song(playlist, current_song);
				break;
			}
			case 'L': {
				display_playlist(playlist, (*(current_song)));
				break;
			}
			default: {
				cout << "Not an autorize character" << endl;
				break;
			}
		}
	}
}