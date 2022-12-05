#include <iostream>
#include <cstring>
#include "media.h"
#include "video_game.h"

using namespace std;

void video_game::setPublisher(char* new_publisher) {
	strcpy(publisher, new_publisher);
}

char* video_game::getPublisher() {
	return publisher;
}

void video_game::setRating(double new_rating) {
	rating = new_rating;
}

double video_game::getRating() {
	return rating;
}
