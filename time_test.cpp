#include <iostream>
#include <fstream>
#include <istream>
#include <ctime>
#include <string>

using namespace std;

int main() {

int days_since;
int logged_day_int;
string logged_day;

time_t t = time(0);
tm* now = localtime(&t);
int current_day = now->tm_mday;

fstream log;
log.open("log");
getline(log,logged_day);
logged_day_int = stoi(logged_day);
log.close();
cin.ignore();

days_since = current_day - logged_day_int;
cout << "Last time you ran was " << days_since << " days ago." << endl;

string ran;
cout << "\nDid you go for run today??" << endl;
cin >> ran;

if (ran=="Y") {
	fstream log;
	log.open("log");
	log << current_day;
	log.close();
}

}
