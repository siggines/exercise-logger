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

bool nm = false;
if( logged_day_int > current_day ){ days_since = current_day + ( 30 - logged_day_int ); nm=true; }
else{
days_since = current_day - logged_day_int;
}

cout << "Last run was: " << days_since << " days ago." << endl;

string ran;
cout << "\nDid you run today? ";
cin >> ran;

if (
ran=="Y"||"y"||"yes"||"Yes"||"YES" 
) 
{
    if(nm){ 
        cout << "nm is true";
        fstream distance;   
        distance.open("distance");
        distance << 0;
        distance.close();
    }
    
	fstream log;
	log.open("log");
	log << current_day;
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
    distance << n;
    distance.close();
    cin.ignore();

    distance.open("distance");
    distance << n;
    distance.close();
    
    cout << "\nTotal distance ran this month: " << n << "km" << endl;
}

cout << "\n\033[1;34mDaily reps\033[0m" << endl;

int chin, pull, press;
cout << "\nEnter chin-up reps: ";
cin >> chin;
cout << "\nEnter pull-up reps: ";
cin >> pull;

if(
chin+pull <=10
){cout<<"\n\033[1mTerrible\n";}
else if(
chin+pull > 10 && chin+pull < 20
){cout<<"\n\033[1mMediocre\n";}
else if(
chin+pull > 20 && chin+pull < 30
){cout<<"\n\033[1mGood\n";}
else if(
chin+pull > 30
){cout<<"\n\033[1mBrilliant";}

cout << "\n\033[0mEnter press-up reps: ";
cin >> press;

if(
press <=20
){cout<<"\n\033[1mGet down and give me 100!\n";}
else if(
press >=100
){cout<<"\n\033[1mWell done\n";}

}
