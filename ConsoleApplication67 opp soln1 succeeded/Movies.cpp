#include <iostream>
#include "Movies.h"
#include "Movie.h"
#include <vector>

Movies::Movies() {
}

Movies::Movies(const Movies& list_source) 
	: vec_of_movs{list_source.vec_of_movs} {
}
Movies::Movies(const Movies&& list_source) noexcept
	: Movies{ list_source } {
}

bool Movies::add_movie(std::string name_val, std::string rating_val, int watched_val) {
	for (size_t i{}; i < size(vec_of_movs); i++) {
		if (vec_of_movs.at(i).get_name() == name_val) {
			return false;
		}
	}
			Movie movie(name_val, rating_val, watched_val);
			/*movie.set_name(name_val);
			movie.set_rating(rating_val);
			movie.set_watched(watched_val);*/
			vec_of_movs.push_back(movie);
			return true;
	
}

bool Movies::increment_watched(std::string name) {
	for (size_t i{}; i < size(vec_of_movs); i++) {
		if (vec_of_movs.at(i).get_name() == name) {
			vec_of_movs.at(i).set_watched((vec_of_movs.at(i).get_watched()) + 1);
			return true;
		}
	}
	return false;
}

void Movies::display() const {
	if (size(vec_of_movs) == 0) {
		std::cout << "sorry, no movies to display." << std::endl << std::endl; 
	}
	else
	{
		std::cout << std::endl << "================================" << std::endl;
		for (size_t i{}; i < size(vec_of_movs); i++) {
			vec_of_movs.at(i).display_movie();
		}
		std::cout << "================================" << std::endl << std::endl;
	}
}
