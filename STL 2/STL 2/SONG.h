#ifndef _SONG_H_
#define _SONG_H_
#include <iomanip>
#include <string>

using std::string;
using std::ostream;

class Song {
	friend ostream &operator<<(ostream &os, const Song &s);
	string name;
	string artist;
	int rating;
public:
	Song() = default;
	Song(string name, string artist, int rating);
	
	string get_name() const;
	string get_artist() const;
	int get_rating() const;
	bool operator<(const Song &rhs) const;
	bool operator==(const Song &rhs) const;
};
#endif // !_SONG_H_

