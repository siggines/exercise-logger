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

cout << "Last run was: " << days_since << " days ago." << endl;

string ran;
cout << "\nDid you run today? ";
cin >> ran;

if (
ran=="Y"||"y"||"yes"||"Yes"||"YES" 
) 
{
	fstream log;
	log.open("log");
	log << current_day;
	log.close();
}

cout << "\n\033[1;34mDaily reps\033[0m" << endl;

int chin, pull, press;
cout << "\nEnter chin-up reps: ";
cin >> chin;
cout << "\nEnter pull-up reps: ";
cin >> pull;

if(
chin+pull <=10
){cout<<"\n\033[1mTerrible\n"<<endl;}
else if(
chin+pull > 10 && chin+pull < 20
){cout<<"\nMediocre\n"<<endl;}
else if(
chin+pull > 20 && chin+pull < 30
){cout<<"\nGood\n"<<endl;}
else if(
chin+pull > 30
){cout<<"\nBrilliant\n"<<endl;}

cout << "Enter press-up reps: ";
cin >> press;

if(
press <=20
){cout<<"\nGet down and give me 100!\n";}
else if(
press >=100
){cout<<"\nWell done\n";}

}
