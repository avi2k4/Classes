#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class movie: public media {
	public:
		movie() {
			type_id = 3;
		}

		virtual void setDirector(char* new_director);
		virtual char* getDirector();
		virtual void setRating(double new_rating);
		virtual double getRating();
		virtual void setDuration(int new_duration);
		virtual int getDuration();

	protected:
		char director[25];
		double rating;
		int duration;
};
