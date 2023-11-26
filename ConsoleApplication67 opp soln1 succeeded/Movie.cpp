#include <iostream>
#include "Movie.h"
using namespace std;
#include <string>

Movie::Movie(std::string name, std::string rating, int watched)
	: name_p{ new std::string }, rating_p{ new std::string }, watched_p{ new int },
name {*name_p }, rating{ *rating_p }, watched{ *watched_p } {
	this->name = name;
	this->rating = rating;
	this->watched = watched;
	cout << "cons for:  " << name << endl;
}

Movie::Movie(const Movie& source)
	: Movie{source.name, source.rating, source.watched } {
	cout << "copy cons for:  " << name << endl;
}
Movie::Movie(Movie&& source) noexcept
    : name_p { source.name_p }, rating_p{ source.rating_p }, watched_p{ source.watched_p },
	name{ *source.name_p }, rating{ *source.rating_p }, watched{ *source.watched_p } {
	source.name_p = nullptr ;
	source.rating_p = nullptr ;
	source.watched_p = nullptr ;
	cout << "move cons for:  " << name << endl;
}

Movie::~Movie() {
	delete name_p;
	name_p = nullptr;
	delete rating_p;
	rating_p = nullptr;
	delete watched_p;
	watched_p = nullptr;
}

void Movie::display_movie() const {
	std::cout << get_name() << ", "
		<< get_rating() << ", "
		<< get_watched() << std::endl;
}
