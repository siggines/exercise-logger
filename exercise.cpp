#include <iostream>
#include <fstream>
#include <istream>
#include <ctime>
#include <string>
#include <limits>

std::fstream& go_to_line(std::fstream& file, unsigned int line_num){
	file.seekg(std::ios::beg);
	for(int i = 0; i < line_num-1; ++i){
		file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	}
	return file;
}

using namespace std;

int main() {

int days_since;
int logged_day_int;
int logged_month_int;
string logged_day;
string logged_month;

time_t t = time(0);
tm* now = localtime(&t);
int current_day = now->tm_mday;
int current_month = now->tm_mon;

fstream log;
log.open("log");
go_to_line(log,1);
getline(log,logged_day);
logged_day_int = stoi(logged_day);
log.close();
log.open("log");
go_to_line(log,2);
getline(log,logged_month);
logged_month_int = stoi(logged_month);
log.close();

if( current_month > logged_month_int ){
	days_since = current_day + ( 30 - logged_day_int );
        fstream distance;
        distance.open("distance");
        distance << 0;
        distance.close();
}
else{
	days_since = current_day - logged_day_int;
}

cout << "Last run was: " << days_since << " days ago." << endl;

string ran = "";
cout << "\nDid you run today? ";
cin >> ran;

if (ran=="Y"||ran=="y"||ran=="yes"||ran=="Yes"||ran=="YES"||ran=="yeah"){
	fstream log;
	log.open("log");
	go_to_line(log,1);
	log << current_day;
	log.close();
	log.open("log",ios::app);
	log << current_month;
	log.close();

    	string l;
    	int k,l_int,n;

    	cout << "Number of Kilometers ran: ";
    	cin >> k;

    	fstream distance;
    	distance.open("distance");
    	getline(distance,l);
    	l_int = stoi(l);
    	n = l_int + k;
    	distance.close();

    	distance.open("distance",ios::trunc);
    	distance << n;
    	distance.close();
	cin.ignore();

    	cout << "\nTotal distance ran this month: " << n << "km" << endl;
}
else if(days_since > 3){cout<<"Go run."; cin.ignore();}
else{cin.ignore();}

cout << "\n\033[1;34mDaily reps\033[0m" << endl;

int chin, pull, press;
cout << "\nEnter chin-up reps: ";
cin >> chin;
cout << "\nEnter pull-up reps: ";
cin >> pull;

if(chin+pull <=10){cout<<"\n\033[1mTerrible\n";}
else if(chin+pull > 10 && chin+pull < 20){cout<<"\n\033[1mMediocre\n";}
else if(chin+pull > 20 && chin+pull < 30){cout<<"\n\033[1mGood\n";}
else if(chin+pull > 30){cout<<"\n\033[1mBrilliant";}

cout << "\n\033[0mEnter press-up reps: ";
cin >> press;

if(press <=20){cout<<"\n\033[1mGet down and give me 100!\n";}
else if(press >=100){cout<<"\n\033[1mWell done\n";}

}
