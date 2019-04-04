#include <iostream>
#include <vector>
#include <string>

using namespace std;

//declaration of functions
string welcome();
void print_seats(string flight[]);
void populate_seats();

//2D array for storing seat numbers and passenger details
string flights [5][52]; 
string passengers [4][250];

int main()
{   
    string seat, flight, book = "y";
    int int_flight, p = 0, j = 0;
    populate_seats();
    
    while (book == "y")
    {   
        passengers[p][0] = (welcome());

        cout << "\nThe available travel times for flights are:" << endl;
        cout << "    Depart\tArrive" << endl;
        for (int i = 0; i < 5; i++)
        {               
            if (flights[i][51] != "50")
            {
            cout << i+1 << ".  " << flights[i][0] << endl;
            }
            else if (j < 4)
            {
                j++;
            }
            else
            {
                cout << "\nAll flights are booked" << endl;
                return 0;
            }
        }
        cout << "Choose the time by enetering the option number from the displayed list:" << endl;

        cin >> flight;
        passengers[p][1] = flight;
    
        cout << "\nSelect your seat:" << endl;

        int_flight = stoi(flight);
        print_seats(flights[int_flight]);

        cin >> seat;

        for (int i = 0; i <  50; i++)
        {
            if (flights[int_flight][i] == seat)
            {
                flights[int_flight][i] = "**";
                break;
            }
        }

        passengers[p][2] = seat;

        cout << "Would you like to book another seat? y/n: " ;
        cin >> book;
        cin.get();
        p++;
        }
        
    return 0;
}

//Welcome message and passenger name capture
string welcome()
{   
    string passenger;

    cout << "Welcome to the COS1511 Flight Booking System\n" << endl;
    cout << "Enter Full Name" << endl;

    getline(cin,passenger);

    return passenger;
}

//Prints out seats with the correct layout
void print_seats(string flight[])
{   
    int k = 0;
    for (int j = 0; j < 9; j++)
    {   
        cout << "|";
        for (int i = 0; i < 3; i++)
        {
        cout << flight[k+1] << "|";
        k++;
            if (k > 49)
            {
                cout << endl;
                return;
            }
        }

        cout << "----";
        
        for (int i = 0; i < 3; i++)
        {
        cout << "|" << flight[k+1];
        k++;
        }
        cout << "|" << endl;
    }
}

//Seat generation for all 5 flights
void populate_seats()
{
    flights[0][0] = "07:00\t09:30";
    flights[1][0] = "09:00\t11:30";
    flights[2][0] = "11:00\t13:30";
    flights[3][0] = "13:00\t15:30";
    flights[4][0] = "15:00\t17:30";
    for (int a = 0; a < 5; a++)
    {   
        int b = 0;
        for (int i = 17; i < 26; i++)
        {
            for ( int j = 1; j < 7; j++)
            {   
                char achar = '0' + i;

                if (i == 25 && j > 2){
                    break;
                }
                else

                //Converting i into an ascii character to form the letters
                char achar = '0' + i;
                string seat = achar + to_string(j);
                flights[a][b+1] = seat;
                
                b++;
            }
            flights[a][b+1] = "0";
        }
    }
}

string authenticate(string a, string correct)
{
    return "hello";
}