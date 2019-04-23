#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//declaration of functions
string welcome();
void print_seats(string flight[]);
void populate_seats();
bool validate_flight(string a);
bool validate_seat(string a, int b);
bool validate_book(string a);
void print_ticket(string passenger[], int &i);

//2D array for storing seat numbers and passenger details
string flights [5][52]; 
string passengers [4][250];
const int ECONOMY_CLASS = 1600;

int main(){   
    //initialising all variables that are needed in the program
    string seat, flight, book = "y";
    int int_flight, p = 0, j = 0;
    int seat_number, seat_price;
    populate_seats();
    
    //while loop that repeats the booking process while the user wants to continue booking.
    while (book == "y" || book == "Y"){   
        passengers[p][0] = (welcome());

        cout << "\nThe available travel times for flights are:" << endl;
        cout << "    Depart\tArrive" << endl;
        
        //Checks whether all the flights are fully booked,
        //If so, it ends the whole program.
        for (int i = 0; i < 5; i++){             
            if (flights[i][51] != "50"){
            cout << i + 1 << ".  " << flights[i][0] << endl;
            }
            else if (j < 4){
                j++;
            }
            else{
                cout << "\nAll flights are booked" << endl;
                return 0;
            }
        }

        //Flight selection.
        cout << "Choose the time by enetering the option number from the displayed list:" << endl;
        do{
            cin >> flight;
        }
        while(!validate_flight(flight));

        //Converts the flight selection string to an int. 
        //So that the index can be selected when printing out the seats and flight time.
        int_flight = stoi(flight) - 1;

        //Prompts user to select seat number and accesses flight time from flights array
        cout << "\nThe available seats for " << flights[int_flight][0].substr(0,5) << " are as follows:" << endl;        

        //Displays the seating layout for the chosen flight.
        print_seats(flights[int_flight]);

        cout << "Please key in a seat number to choose a seat (eg:A2)" << endl;

        //Seat selection.
        do{
            cin >> seat;                
        }
        while (!validate_seat(seat, int_flight));

        //Changes the booked seat number to **
        for (int i = 0; i < 51; i++){
            if (flights[int_flight][i] == seat){
                flights[int_flight][i] = "**";
                seat_number = i;                
                break;
            }
        }

        //checks whether the seat was booked in first or economy class
        //Sets the seat price for the passengers array 
        if (seat_number < 25){
            seat_price = ECONOMY_CLASS*1.2;
            passengers[p][4] = "First class";
        }
        else{
            seat_price = ECONOMY_CLASS;
            passengers[p][4] = "Economy class";
        }

        //Adds flight, seat and seat price information to passenger array
        passengers[p][1] = flight;
        passengers[p][2] = seat;
        passengers[p][3] = to_string(seat_price);

        //Keeps track of the number of seats booked on each flight
        flights[int_flight][51] = to_string(stoi(flights[int_flight][51]) + 1); 

        print_ticket(passengers[p], int_flight);       

        //Checks whether the user wants to book for another flight.
        cout << "\nWould you like to book another seat? Y/N: " ;
        do{ 
            cin >> book;
            cin.get();
        }while(!validate_book(book));        
        
        //Keeps track of how many passengers have been booked.
        //Allows the program to move to the next index in the passengers array.
        p++;
        cout << endl;
        }

        //Prints out the number of bookings for each flight
        for (int i = 0; i < 5; i++){
            cout << "Number of bookings made for " << flights[i][0].substr(0,5);
            cout << ": " << flights[i][51] << endl;
        }
    return 0;
}

//Welcome message and passenger name capture
string welcome(){   
    string passenger;

    cout << "Welcome to the COS1511 Flight Booking System\n" << endl;
    cout << "Enter Full Name" << endl;

    getline(cin,passenger);

    return passenger;
}

//Prints out seats with the correct layout
void print_seats(string flight[]){   
    int k = 0;
    cout << "First class(1920.00)" << endl;
    for (int j = 0; j < 9; j++){
        if (k == 24){
            cout << "Economy class(1600.00)" << endl;   
        }
        cout << "|";
        for (int i = 0; i < 3; i++){
            cout << flight[k+1] << "|";
            k++;
                
                if (k > 49){
                    cout << endl;
                    return;
            }
        }

        cout << "----";
        
        for (int i = 0; i < 3; i++){
            cout << "|" << flight[k+1];
            k++;
        }
        cout << "|" << endl;
    }
}

//Seat generation for all 5 flights
void populate_seats(){
    //Setting index 0 for all flights to the flights time
    flights[0][0] = "07:00\t09:30";
    flights[1][0] = "09:00\t11:30";
    flights[2][0] = "11:00\t13:30";
    flights[3][0] = "13:00\t15:30";
    flights[4][0] = "15:00\t17:30";
    
    for (int a = 0; a < 5; a++){   
        int b = 0;
        for (int i = 17; i < 26; i++){
            for ( int j = 1; j < 7; j++){   

                if (i == 25 && j > 2){
                    break;
                }
                //Converting i into an ascii character to form the letters
                string seat = char('0' + i) + to_string(j);
                flights[a][b+1] = seat;
                
                b++;
            }
            flights[a][b+1] = "0";
        }
    }
}

//Prints out the ticket for the passenger using setw for formatting
void print_ticket(string passenger[], int &i){
    int name = passenger[0].length();
    cout << "\n***************************" << endl;
    cout << "Travel Ticket for Flight " << i + 1 << endl;
    cout << "***************************" << endl;

    cout << left << setw(15) << "Name " << ":  " << passenger[0];
    cout << setw(13) << "" << "Travel Ticket Class " << ":  " <<  passenger[4] << endl;

    cout << setw(31 + name) << "" << setw(20) << "Seat No."  << ":  " << passenger[2] << endl;

    cout << setw(15) << "Departure" << ":  " << setw(13 + name) << "Johannesburg";
    cout << setw(20) << "Departure Time" << ":  " << flights[i][0].substr(0,5) << endl;

    cout << setw(15) << "Destination" << ":  " << setw(13 + name) << "Cape Town";
    cout << setw(20) << "Arrival Time" << ":  " << flights[i][0].substr(6,10) << endl;

    cout << "\n***************************" << endl;
    cout << "Amount: R" << passenger[3] << endl;
    cout << "Thank you for booking with COS 1511 Booking System." << endl;
    cout << "Your travel agent is Damian Jacobs" << endl; 
    cout << "***************************" << endl;
}

//Validates flight selection entry
bool validate_flight(string a){
    for (int i = 1; i < 6; i++){
        if (a == to_string(i)){
            return true;
        }
    }
    cout << "Incorrect option! Please choose from 1-5." << endl;
    return false;
}

//Validates seat selection entry
bool validate_seat(string a, int b){
    for (int i = 0; i < 51; i++){
        if (flights[b][i] == a){    
            return true;
        }
    }    
    cout << "Please select an available and valid seat number." << endl;
    return false ;
}

//validates whether the user would like to make another booking
bool validate_book(string a){
    while(a != "y" && a != "n" & a != "Y" && a != "N"){
        cout << "Enter a valid option: Y/N:";
        return false;
    }
    return true;
}