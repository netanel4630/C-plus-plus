#include "SONG.h"

using std::setw;
using std::left;
using std::right;

Song::Song(string name, string artist, int rating)
	: name{ name }, artist{ artist }, rating{ rating } {}
string Song::get_name() const {
	return name;
}
string Song::get_artist() const {
	return artist;
}
int Song::get_rating() const {
	return rating;
}

bool Song::operator<(const Song &rhs) const {
	return this->name < rhs.name;
}

bool Song::operator==(const Song &rhs) const {
	return this->name == rhs.name;
}

ostream &operator<<(ostream &os, const Song &s) {
	os << setw(20) << left << s.name
		<< setw(30) << left << s.artist
		<< setw(2) << left << s.rating;
	return os;
}