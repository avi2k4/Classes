#include <iostream>
#include <cstring>
#include "movie.h"

using namespace std;

void movie::setDirector(char* new_director) {
	strcpy(director, new_director);
}

char* movie::getDirector() {
	return director;
}

void movie::setRating(double new_rating) {
	rating = new_rating;
}

double movie::getRating() {
	return rating;
}

void movie::setDuration(int new_duration) {
	duration = new_duration;
}

int movie::getDuration() {
	return duration;
}
