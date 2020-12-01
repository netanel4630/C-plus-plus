#include "SONGS_HANDLER.h"

int main() {
	std::list<Song> playlist{
			{"God's Plan",        "Drake",                     5},
			{"Never Be The Same", "Camila Cabello",            5},
			{"Pray For Me",       "The Weekend and K. Lamar",  4},
			{"The Middle",        "Zedd, Maren Morris & Grey", 5},
			{"Wait",              "Maroone 5",                 4},
			{"Whatever It Takes", "Imagine Dragons",           3}
	};

	std::list<Song>::iterator current_song = playlist.begin();

	turn_on(playlist, current_song);
	
	return 0;
}