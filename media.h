#pragma once

#include <iostream>
#include <cstring>

using namespace std;

class media {
	public:
		virtual int getTypeID();
		virtual void setTitle(char* new_title);
		virtual char* getTitle();
		virtual void setYear(int new_year);
		virtual int getYear();

	protected: 
		int type_id;
		char title[25];  
		int year;
};
