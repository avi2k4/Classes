#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

int media::getTypeID() {
	return type_id;
}

void media::setTitle(char* new_title) {
	strcpy(title, new_title);
}

char* media::getTitle() {
	return title;
}

void media::setYear(int new_year) {
	year = new_year;
};

int media::getYear() {
	return year;
}
