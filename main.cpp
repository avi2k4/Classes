/*
 * Classes by Avighnash Kumar. 12/3/2022.
 * Database that stores media: video games, music, and movies.
 * Includes commands to insert, query, and delete.
*/

#include <iostream>
#include <cstring>
#include <vector>
#include "video_game.h"
#include "music.h"
#include "movie.h"

using namespace std;

// function prototypes
void clearInput();
void add();
void search();
void del();
void print(media* m);

vector<media*> db;

// main
int main() {
	cout << "\n------------------------------------------------------------------------" << endl;
	cout << "Welcome to the Media Database - we store video games, music, and movies!\n" << endl;
	cout << "Commands:\n>[ADD] to add any type of media.\n>[SEARCH] to query the database by title or year\n>[DELETE] to delete media by query.\n>[QUIT] to quit the program." << endl;
	cout << "------------------------------------------------------------------------\n" << endl;

	while (true) {
		char input[7];
		cin >> input;

		if (strcmp(input, "ADD") == 0) {
			add();
		}
		else if (strcmp(input, "SEARCH") == 0) {
			search();
		}
		else if (strcmp(input, "DELETE") == 0) {
			del();
		}
		else if (strcmp(input, "QUIT") == 0) {
			break;
		}
	}

	return 0;
}

void clearInput() {
	cin.clear();
	cin.ignore();
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// handles adding media sequence
void add() {
	cout << "\nWhat kind of media would you like to add?" << endl;
	cout << "\nOptions:\n>[VG] for video game\n>[MUSIC] for music\n>[MOVIE] for movie" << endl;

	char add_option_input[5];
	clearInput();
	cin >> add_option_input;

	// getting title
	cout << "\nWhat is the title?" << endl;
	char title_input[25];
	clearInput();
	cin.get(title_input, sizeof(title_input));
	cin.get();

	// getting year
	cout << "\nWhat is the year?" << endl;
	int year_input;

	// ensures year is integer
	while (true) {	
		clearInput();
		cin >> year_input;

		if (cin.fail() == 0) {
			break;
		}
		else {
			cout << "The year must be an integer!" << endl;
		}
	}

	if (strcmp(add_option_input, "VG") == 0) {
		video_game* vg = new video_game();
		
		// setting title
		vg->setTitle(title_input);
		
		// setting year
		vg->setYear(year_input);

		// setting publisher
		cout << "\nWho is the publisher?" << endl;
		char publisher_input[25];
		clearInput();
		cin.get(publisher_input, sizeof(publisher_input));
		cin.get();
		vg->setPublisher(publisher_input);

		// setting rating
		cout << "\nWhat is the rating?" << endl;
		double rating_input;

		// ensures rating is double
		while (true) {
			clearInput();
			cin >> rating_input;

			if (cin.fail() == 0) {
				break;
			}
			else {
				cout << "The input must be a whole/decimal number!" << endl;
			}
		}

		vg->setRating(rating_input);

		db.insert(db.begin(), vg);
		cout << "\nSuccessfully added video game with the title '" << vg->getTitle() << "' to the database!" << endl;
	}
	else if (strcmp(add_option_input, "MUSIC") == 0) {
		music* m = new music();
		
		// setting title
		m->setTitle(title_input);
		
		// setting year
		m->setYear(year_input);

		// setting publisher
		cout << "\nWho is the publisher?" << endl;
		char publisher_input[25];
		clearInput();
		cin.get(publisher_input, sizeof(publisher_input));
		cin.get();
		m->setPublisher(publisher_input);

		// setting artist
		cout << "\nWho is the artist?" << endl;
		char artist_input[25];
		clearInput();
		cin.get(artist_input, sizeof(artist_input));
		cin.get();
		m->setArtist(artist_input);

		// setting duration
		cout << "\nWhat is the duration in minutes?" << endl;
		double duration_input;

		// ensures duration is integer
		while (true) {
			clearInput();
			cin >> duration_input;

			if (cin.fail() == 0) {
				break;
			}
			else {
				cout << "The input must be an integer!" << endl;
			}
		}

		m->setDuration(duration_input);

		db.insert(db.begin(), m);
		cout << "\nSuccessfully added music with the title '" << m->getTitle() << "' to the database!" << endl;
	}
	else if (strcmp(add_option_input, "MOVIE") == 0) {
		movie* m = new movie();

		// setting title
		m->setTitle(title_input);
		
		// setting year
		m->setYear(year_input);

		// setting director
		cout << "\nWho is the director?" << endl;
		char director_input[25];
		clearInput();
		cin.get(director_input, sizeof(director_input));
		cin.get();
		m->setDirector(director_input);

		// setting rating
		cout << "\nWhat is the rating?" << endl;
		double rating_input;

		// ensures rating is double
		while (true) {
			clearInput();
			cin >> rating_input;

			if (cin.fail() == 0) {
				break;
			}
			else {
				cout << "The input must be a whole/decimal number!" << endl;
			}
		}

		m->setRating(rating_input);

		// setting duration
		cout << "\nWhat is the duration in minutes?" << endl;
		double duration_input;

		// ensures duration is integer
		while (true) {
			clearInput();
			cin >> duration_input;

			if (cin.fail() == 0) {
				break;
			}
			else {
				cout << "The input must be an integer!" << endl;
			}
		}

		m->setDuration(duration_input);

		db.insert(db.begin(), m);
		cout << "\nSuccessfully added movie with the title '" << m->getTitle() << "' to the database!" << endl;
	}
}

// handles search sequence
void search() {
	cout << "\nHow would you like to query the database?" << endl;
	cout << "Options:\n>[TITLE] by title\n>[YEAR] by year" << endl;
			
	char search_option_input[5];
	clearInput();
	cin >> search_option_input;

	if (strcmp(search_option_input, "TITLE") == 0) { // if the user wants to search by title
		cout << "\nEnter the title of the media you are looking for." << endl;
			
		char search_title_input[25];
		clearInput();
		cin.get(search_title_input, sizeof(search_title_input));
		cin.get();

		for (std::vector<media*>::iterator it = db.begin(); it != db.end(); ++it) {
			if (strcmp(((*it)->getTitle()), search_title_input) == 0) { // check if the titles are the same
				print(*it);
			}
		}
	}
	else if (strcmp(search_option_input, "YEAR") == 0) { // if the user wants to search by year
		cout << "\nEnter the year of the media you are looking for." << endl;

		int search_year_input;

		// ensures year is integer
		while (true) {
			clearInput();
			cin >> search_year_input;

			if (cin.fail() == 0) {
				break;
			}
			else {
				cout << "The year must be an integer!" << endl;
			}
		}

		for (std::vector<media*>::iterator it = db.begin(); it != db.end(); ++it) {
			if ((*it)->getYear() == search_year_input) { // check if the years are the same
				print(*it);
			}
		}
	}
}

// handles delete sequence
void del() {
	cout << "\nHow would you like to query the database and delete?" << endl;
	cout << "Options:\n>[TITLE] by title\n>[YEAR] by year" << endl;
			
	char delete_option_input[5];
	clearInput();
	cin >> delete_option_input;

	if (strcmp(delete_option_input, "TITLE") == 0) { // if the user wants to delete by title
		cout << "\nEnter the title of the media you want to delete." << endl;
				
		char search_title_input[25];
		clearInput();
		cin.get(search_title_input, sizeof(search_title_input));
		cin.get();

		for (std::vector<media*>::iterator it = db.begin(); it != db.end(); ++it) {
			if (strcmp(((*it)->getTitle()), search_title_input) == 0) { // check if the titles are the same
				print(*it);

				if ((*it)->getTypeID() == 1) { // 1 is the ID for video games
					video_game* vg = static_cast<video_game*>(*it);
					delete vg;
				}
				else if ((*it)->getTypeID() == 2) { // 2 is the ID for music
					music* m = static_cast<music*>(*it);
					delete m;
				}
				else if ((*it)->getTypeID() == 3) { // 3 is the ID for movies
					movie* m = static_cast<movie*>(*it);
					delete m;
				}
				
				db.erase(it);
			}
		}
	
	}
	else if (strcmp(delete_option_input, "YEAR") == 0) { // if the user wants to delete by year
		cout << "\nEnter the year of the media you are want to delete." << endl;

		int search_year_input;

		while (true) {
			clearInput();
			cin >> search_year_input;

			if (cin.fail() == 0) {
				break;
			}
			else {
				cout << "The year must be an integer!" << endl;
			}
		}

		for (std::vector<media*>::iterator it = db.begin(); it != db.end(); ++it) {
			if ((*it)->getYear() == search_year_input) { // check if years are the same
				print(*it);

				if ((*it)->getTypeID() == 1) {
					video_game* vg = static_cast<video_game*>(*it);
					delete vg;
				}
				else if ((*it)->getTypeID() == 2) {
					music* m = static_cast<music*>(*it);
					delete m;
				}
				else if ((*it)->getTypeID() == 3) {
					movie* m = static_cast<movie*>(*it);
					delete m;
				}
				
				db.erase(it);
			}
		}
	}
}

// prints the media according to the type
void print(media* m) {
	cout << "\n------ DATABASE ENTRY ------" << endl;
	
	if (m->getTypeID() == 1) { // if video game
		video_game* vg = static_cast<video_game*>(m);

		cout << "Media Type: VIDEO GAME" << endl;
		cout << "Title: " << vg->getTitle() << endl;
		cout << "Year: " << vg->getYear() << endl;
		cout << "Publisher: " << vg->getPublisher() << endl;
		cout << "Rating: " << vg->getRating() << endl;
	}
	else if (m->getTypeID() == 2) { // if music
		music* m1 = static_cast<music*>(m);

		cout << "Media Type: MUSIC" << endl;
		cout << "Title: " << m1->getTitle() << endl;
		cout << "Year: " << m1->getYear() << endl;
		cout << "Publisher: " << m1->getPublisher() << endl;
		cout << "Artist: " << m1->getArtist() << endl;
		cout << "Duration: " << m1->getDuration() << endl;
	}
	else if (m->getTypeID() == 3) { // if movie
		movie* m2 = static_cast<movie*>(m);

		cout << "Media Type: MOVIE" << endl;
		cout << "Title: " << m2->getTitle() << endl;
		cout << "Year: " << m2->getYear() << endl;
		cout << "Director: " << m2->getDirector() << endl;
		cout << "Rating: " << m2->getRating() << endl;
		cout << "Duration: " << m2->getDuration() << endl;
	}

	cout << "-----------------------------" << endl;
}
