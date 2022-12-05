#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class music: public media {
	public:
		music() {
			type_id = 2;
		}

		virtual void setPublisher(char* new_publisher);
		virtual char* getPublisher();
		virtual void setArtist(char* new_artist);
		virtual char* getArtist();
		virtual void setDuration(int new_duration);
		virtual int getDuration();
	
	protected:
		char publisher[25];
		char artist[25];
		int duration;
};
