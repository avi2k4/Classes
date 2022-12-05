#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class video_game: public media {
	public:
		video_game() {
			type_id = 1;
		}
		
		virtual void setPublisher(char* new_publisher);
		virtual char* getPublisher();
		virtual void setRating(double new_rating);
		virtual double getRating();

	protected:
		char publisher[25];
		double rating;
};
