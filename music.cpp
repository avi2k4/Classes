#include <iostream>
#include <cstring>
#include "music.h"

using namespace std;

void music::setPublisher(char* new_publisher) {
	strcpy(publisher, new_publisher);
}

char* music::getPublisher() {
	return publisher;
}

void music::setArtist(char* new_artist) {
	strcpy(artist, new_artist);
}

char* music::getArtist() {
	return artist;
}

void music::setDuration(int new_duration) {
	duration = new_duration;
}

int music::getDuration() {
	return duration;
}
