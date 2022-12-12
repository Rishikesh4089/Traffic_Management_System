#include"bits/stdc++.h"
#include <fstream>
#include <chrono> //for delay
#include <stdlib.h>
#include<thread>
#include <ctime>
#include "coord.cpp"
#include<string.h>
#define pass 1234


                // ***** Smart Traffic Management Solution *****

                //keep the record of vehicles                      == recOfVeh()
                //keep the record of challan done                  == recOfChall()
                //Search the record of vehicles                    == vehSearch()
                //Display information of traffic in control booths == trafContBooth()
                //Helpline Information and nearby hospitals        == helpInfo()



using namespace std;
int i, choice, dd=0, mm=0, yy=0, hr=0, mint=0, sound=0; 

//Class for display features
class onlyDisplay
{
	public:
		void authentication();
		void load();
		void menu();
        void esc();

};

//Class for all the functions in database
class features
{
    public:
        void recOfVeh();
        void trafContBooth();
        void recOfChall();
        void vehSearch();
        void helpInfo();
};

//Class for vehicle information
class vehData
{
	private:
    	unsigned long long int owner_no;
		int seater, RTO_no;
		char veh_type[10], owner_name[50], des_pat[10], address[100], issued_date[20], veh_no[15];
	public:
		vehData(){strcpy(veh_no, "ABXXXXXXXX");}
		void read_data();
		int store_data();
		void view_data();
		void show_data();
		void header();
		void regSearch(char *);
		void deleteData(char *);
		void nameSearch(char *);
        void addChal();
        void chalReg();
        void chalName();
        void booth1();
        void booth2();
        void booth3();
};

//function for delay
void delay()
{
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds

    sleep_for(nanoseconds(1000000));
    sleep_until(system_clock::now() + seconds(1));
}


//to escape database
void onlyDisplay::esc()
{
    system("clear");
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                         Thank You for using our service, have a good day!                                         **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    exit(0);
}

//menu
void onlyDisplay::menu()
{
    features f;
    system("clear");
    time_t tt;
    struct tm * ti;
    time (&tt);
    ti = localtime(&tt);
    coord(53,9);
    cout<<asctime(ti);
    delay();

    system("clear");
    int choice;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                           WELCOME TO                                                              **"<<endl;
    cout<<"**                                                 SMART TRAFFIC MANAGEMENT SYSTEM                                                   **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                    Press Your Option :-                                                                                           **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                     1.Record of Vehicles                                                                          **"<<endl;
    cout<<"**                                     2.Record of Challan                                                                           **"<<endl;
    cout<<"**                                     3.Search the Record of Vehicles                                                               **"<<endl;
    cout<<"**                                     4.Traffic Control Booths                                                                      **"<<endl;
    cout<<"**                                     5.Help !                                                                                      **"<<endl;
    cout<<"**                                     0.Exit                                                                                        **"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"                      Enter your choice - ", cin>>choice;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    

    if(choice >=0 && choice < 6)
    {
        switch (choice)
        {
            case 0:
                esc();
                break;

            case 1:
                system("clear");
                f.recOfVeh();
                break;

            case 2:
                system("clear");
                f.recOfChall();
                break;

            case 3:
                system("clear");
                f.vehSearch();
                break;

            case 4:
                system("clear");
                f.trafContBooth();
                break;

            case 5:
                system("clear");
                f.helpInfo();
                break;
        }
    } else{
        cout<<"Enter Valid option !!"<<endl;
        delay();
        system("clear");
        menu();
    }
}

//Authentication
void onlyDisplay::authentication()
{
    int pkey, i;
    coord(14, 0);
	for(i=0; i<25; i++)
	{ 
        cout << "*";
    } 
	cout<<endl;
    coord(20, 1);
	cout << "Authentication";	
    coord(14, 2);
	for(i=0; i<25; i++)
	{
        cout << "*";
    }
	coord(16,3);
	cout << "** Enter the PIN : ";
	static int x=3;
	cin >> pkey;
	if(pkey == pass) {
        load();
        menu();
	}
    else 
    {
	    coord(17, 4);
		cout << "Sorry, you are not authorised..."<<endl;
		coord(17, 4);
		cout << "Attempts left " << --x<<endl;; 
		if(x==0)exit(0);
		authentication();
	}
}

//Loading screen
void onlyDisplay::load()
{
    system("clear");
    int r=0,c,q;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                                                                   Loading...                                                        *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;      
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    
    delay();
}

//Vehicle records
void features::recOfVeh()
{
    onlyDisplay od;
    vehData vd;
    int ROVChoice;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                                                            WELCOME TO                                                               *"<<endl;
    cout<<"*                                                  SMART TRAFFIC MANAGEMENT SYSTEM                                                    *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                                                      * Record of Vehicles *                                                         *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                     Press Your Option :-                                                                                            *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                                      1. Add a New Vehicle                                                                           *"<<endl;
    cout<<"*                                      2. Search a Vehicle Using registration number                                                  *"<<endl;
    cout<<"*                                      3. Search a Vehicle Using Name of the owner                                                    *"<<endl;
    cout<<"*                                      4. Delete a Vehicle record                                                                     *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                     Enter 0 For Home                                                                                                *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<"                      Enter your choice - ", cin>>ROVChoice;

    switch (ROVChoice)
    {
        case 0:
            system("clear");
            od.menu();
            break;
        case 1:
            vd.store_data();
            break;

        case 2:
            vd.chalReg();
            break;

        case 3:
            vd.chalName();
            break;
            
        case 4:
            vd.deleteData((char *)) ;
            break; 
    }
}
int vehData::store_data()
{
    features f;
    system("clear");
    fstream fio;
    string line;
    coord(20,0);
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<"*                                               Welcome to Registration of Vehicles                                                   *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*            Enter Registration number of the Vehicle in the first line                                                               *"<<endl;
    cout<<"*            Enter Name of the owner in the second line                                                                               *"<<endl;
    cout<<"*            Enter 0 to Exit                                                                                                          *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<" Enter here- "<<endl;
    

    fio.open("registration.txt", ios::app | ios::out | ios::in);

    // Execute a loop If file successfully Opened
    while (fio) {

        // Read a Line from standard input
        getline(cin, line);


        // Press 0 to exit
        if (line == "0")
            break;

        // Write line in file
        fio << line << endl;

    }
    cout<<"Data Entered successfully !!"<<endl;
    delay();

    system("clear");
    f.recOfVeh();
    return 0;
};

void vehData::regSearch(char *)
{
    onlyDisplay od;
    features f;
    system("clear");
    string path = "RecordOfVehicles.txt";
    ifstream file( path.c_str() );


    if( file.is_open() )
    {
        cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
        cout<<"*                                                                                                                                     *"<<endl;
        cout<<"*                                               Welcome to Registration of Vehicles                                                   *"<<endl;
        cout<<"*                                                                                                                                     *"<<endl;
        cout<<"*                             Write the Registration number of the vehicle you want to searching for                                  *"<<endl;
        string word ;
        cout<<"*                              ", cin >> word ;

        int countwords = 0 ;
        string candidate ;
        while( file >> candidate ) // for each candidate word read from the file
        {
            if( word == candidate ) ++countwords ;
        }
        if (countwords > 0)
        {
            cout << "The registration number " << word << "' has been found in our records."<<endl ;
            int choice;
            cout<<endl<<"Enter 1 to go to home screen and enter 2 for again entering the registration number ";
            cin>>choice;
            if(choice ==1) 
            { 
                od.menu();
            }
            else
            {
                f.recOfVeh();
            }
        }
        else
        {
            cout<<"Registration number does not foud !!";
            int choice;
            cout<<endl<<"Enter 1 to go to home screen and enter 2 for again entering the registration number ";
            cin>>choice;
            if(choice ==1) 
            { 
                od.menu();
            }
            else
            { 
                //regSearch();
            }
        }
    }

    else
    {
        cerr << "Error! 401!\n" ;
        delay();
        od.menu();
    }
}

void vehData::nameSearch(char*)
{
    onlyDisplay od;
    system("clear");

    string path = "RecordOfVehicles.txt";
    ifstream file( path.c_str() );

    if( file.is_open() )
    {
        cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
        cout<<"*                                               Welcome to Registration of Vehicles                                                   *"<<endl;
        cout<<"*                                                                                                                                     *"<<endl;
        cout<<"*            Write the Name of the Owner of the vehicle you want to search for                                                        *"<<endl;
        cout<<"*            Enter 0 to Exit                                                                                                          *"<<endl;
        cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
        cout<<" Enter here- "<<endl;
        string word ;
        cin >> word ;

        int countwords = 0 ;
        string candidate ;
        while( file >> candidate ) // for each candidate word read from the file
        {
            if( word == candidate ) ++countwords ;
        }
        if (countwords > 0){
            cout << "The Name of the Owner " << word << "' has been found in our records."<<endl ;

            if(candidate=="0")
            {
                od.menu();
            }
            else();
            int choice;
            cout<<endl<<"Enter 1 to go to home screen and enter 2 for again entering the Name of the Owner";
            cin>>choice;
            if (choice ==1)
                od.menu();
            else
                //recOfVeh_2();

      //  }
       // else{
            cout<<"Name of the Owner does not foud !!";

      //      else
        //        recOfVeh_2();
        }
    }

    else
    {
        cerr << "Error! 401!\n" ;
        delay();
        od.menu();
    }
}

//To keep record of challan
void features::recOfChall()
{
    onlyDisplay od;
    vehData vd;
    int ROCChoice;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                                                            WELCOME TO                                                               *"<<endl;
    cout<<"*                                                  SMART TRAFFIC MANAGEMENT SYSTEM                                                    *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                                                      * Record of Challan *                                                          *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                     Press Your Option :-                                                                                            *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                                      1. Add a New Challan                                                                           *"<<endl;
    cout<<"*                                      2. Search a Challan Using registration number                                                  *"<<endl;
    cout<<"*                                      3. Search a Challan Using Name of the owner                                                    *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                     Enter 0 For Home                                                                                                *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<"                      Enter your choice - ", cin>>ROCChoice;

    switch (ROCChoice)
    {
        case 0:
            system("clear");
            od.menu();
            break;
        case 1:
            vd.addChal();
            break;
        case 2:
            vd.chalReg();
            break;
        case 3:
            vd.chalName();
            break;
        default:
            cout << "Please enter a valid case" << endl;
    }
}

void vehData::addChal()
{
    features f;
    system("clear");
    fstream fio;
    string line;
    coord(15,0);
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                                                Welcome to Challan Management System                                                 *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;         
    cout<<"* Enter Registration number of the Vehicle in the first line                                                                          *"<<endl;
    cout<<"* Enter Name of the owner in the second line                                                                                          *"<<endl;
    cout<<"* Enter '0' to Exit                                                                                                                   *"<<endl;
    fio.open("RecordOfChallan.txt", ios::app | ios::out | ios::in);

    // Execute a loop If file successfully Opened
    while (fio) {

        // Read a Line from standard input
        getline(cin, line);

        // Press -1 to exit
        if (line == "0")
            break;

        // Write line in file
        fio << line << endl;
    }
    cout<<"Data Entered successfully !!"<<endl;
    delay();

    system("clear");
    f.recOfChall();


}

void vehData::chalReg()
{
    onlyDisplay od;
    system("clear");
    string path = "RecordOfChallan.txt";
    ifstream file( path.c_str() );

    if( file.is_open() )
    {
        cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
        cout<<"*                                                                                                                                     *"<<endl;
        cout<<"*                                                Welcome to Challan Management System                                                 *"<<endl;
        cout<<"*                                                                                                                                     *"<<endl;         
        cout<<"Write the registration number of the vehicle you want to searching for" ;
        string word ;
        cin >> word ;

        int countwords = 0 ;
        string candidate ;
        while( file >> candidate ) // for each candidate word read from the file
        {
            if( word == candidate ) ++countwords ;
        }
        if (countwords > 0){
            cout << "The Registration number '" << word << "' has been found in our records."<<endl ;
            int choice;
            cout<<endl<<"Enter 0 to go to home screen and enter 2 for again entering the registration number.";
            cin>>choice;
            if (choice ==0)
                od.menu();
            else
                chalReg();
        }
        else{
            cout<<"Registration number does not foud !!";
            int choice;
            cout<<endl<<"Enter 1 to go to home screen and enter 2 for again entering the registration number.";
            cin>>choice;
            if (choice ==1)
                od.menu();
            else
                chalName();
        }
    }
    else
    {
        cerr << "Error! 402!\n" ;
        delay();
        od.menu();
    }
}

void vehData::chalName()
{
    onlyDisplay od;
    system("clear");
    string path = "RecordOfChallan.txt";
    ifstream file( path.c_str() );

    if( file.is_open() )
    {
        cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
        cout<<"*                                                                                                                                     *"<<endl;
        cout<<"*                                                Welcome to Challan Management System                                                 *"<<endl;
        cout<<"*                                                                                                                                     *"<<endl;         
        cout<<"Write the Name of the Owner of the vehicle you want to searching for\n" ;
        string word ;
        cin >> word ;

        int countwords = 0 ;
        string candidate ;
        while( file >> candidate ) // for each candidate word read from the file
        {
            if( word == candidate ) ++countwords ;
        }
        if (countwords > 0){
            cout << "The Name of the Owner '" << word << "' has been found in our records."<<endl ;
            int choice;
            cout<<endl<<"Enter 0 to go to home screen and enter 2 for again entering the Name of the Owner";
            cin>>choice;
            if (choice ==0)
                od.menu();
            else
                chalName();
        }
        else{
            cout<<"Name of the Owner does not foud !!";
            int choice;
            cout<<endl<<"Enter 0 to go to home screen and enter 2 for again entering the Name of the Owner ";
            cin>>choice;
            if (choice ==0)
                od.menu();
            else
                chalName();
        }
    }
    else
    {
        cerr << "Error! 402!\n" ;
        delay();
        od.menu();
    }
}

//To search details of a vehicle
void features::vehSearch()
{
    onlyDisplay od;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                                                            WELCOME TO                                                               *"<<endl;
    cout<<"*                                                  SMART TRAFFIC MANAGEMENT SYSTEM                                                    *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                                                 * Search the Record of Vehicles *                                                   *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                                               Enter The Vehicles Registration Number                                                *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                     Enter 0 For Home                                                                                                *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;

    string path = "RecordOfVehicles.txt";
    ifstream file( path.c_str() );
    system("clear");

    if( file.is_open() )
    {
        string word ;
        cin >> word ;
        int countwords = 0 ;
        string candidate ;
        while( file >> candidate ) // for each candidate word read from the file
        {
            if( word == candidate ) ++countwords ;
        }
        if (countwords > 0){
            cout << "The registration number " << word << "' has been found in our records."<<endl ;
            int choice;
            cout<<endl<<"Enter 0 to go to home screen and enter 1 for entering the registration number ";
            cin>>choice;
            if (choice ==0)
                od.menu();
            else
                vehSearch();
        }
        else{
            cout<<"Registration number not found !!";
            int choice;
            cout<<endl<<"Enter 0 to go to home screen and enter 1 for entering the registration number ";
            cin>>choice;
            if (choice ==0)
                od.menu();
            else
                vehSearch();
        }
    }
    else
    {
        cerr << "Error! 401!\n" ;
        delay();
        od.menu();

    }
}

// Traffic Control Booths
void features::trafContBooth()
{
    onlyDisplay od;
    vehData vd;
    int TCBChoice;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                                                            WELCOME TO                                                               *"<<endl;
    cout<<"*                                                  SMART TRAFFIC MANAGEMENT SYSTEM                                                    *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                                                     * Traffic Control Booths *                                                      *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                     Press Your Option :-                                                                                            *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                                      1. Mumbai Traffic Control Booth                                                                *"<<endl;
    cout<<"*                                      2. Pune Traffic Control Booth                                                                  *"<<endl;
    cout<<"*                                      3. Nashik Traffic Control Booth                                                                *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                     Enter 0 For Home                                                                                                *"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<"                      Enter your choice - ", cin>>TCBChoice;

    switch (TCBChoice)
    {
        case 0:
            system("clear");
            od.menu();
            break;

        case 1:
            vd.booth1();
            break;

        case 2:
            vd.booth2();
            break;

        case 3:
            vd.booth3();
            break;
    }
}
void vehData::booth1()
{
    system("clear");
    for (int i = 0; i < 100; ++i) {
        cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
        cout<<"*                                                   Mumbai City Traffic Control Booth                                                 *"<<endl;
        cout<<"*                                                                                                                                     *"<<endl;
        cout<<"*             Vehicles Going out of the City                                               Vehicles coming into the City              *"<<endl;
        cout<<endl<<"      "<<i+1<<"                                             "<<i+5<<endl;
        delay();

        system("clear");

    }

}

void vehData::booth2()
{
    system("clear");

    for (int i = 0; i < 100; ++i) {
        cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
        cout<<"*                                                      Pune City Traffic Control Booth                                                *"<<endl;
        cout<<"*                                                                                                                                     *"<<endl;
        cout<<"*             Vehicles Going out of the City                                               Vehicles coming into the City              *"<<endl;
        cout<<endl<<"      "<<i+5<<"                                             "<<i*7<<endl;
        delay();

        system("clear");

    }


}

void vehData::booth3()
{
    system("clear");
    for (int i = 0; i < 100; ++i) 
    {
        cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
        cout<<"*                                                                                                                                       *"<<endl;
        cout<<"*                                                      Nashik City Traffic Control Booth                                                *"<<endl;
        cout<<"*             Vehicles Going out of the City                                               Vehicles coming into the City                *"<<endl;
        cout<<endl<<"      "<<i*16<<"                                             "<<i*22<<endl;
        delay();
        system("clear");
    }
}

//Helpline Information and nearby hospitals
void features::helpInfo()
{
        cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;        
        cout<<"                                                             * Help line :                                                               "<<endl;
        cout<<"                                                                                                                                         "<<endl;
        cout<<"		S.No				               CITY		              	CONTACT DETAILS                                                         "<<endl;
        cout<<"_________________________________________________________________________________________________________________________________________"<<endl;
        cout<<"                                                                                                                                         "<<endl;
        cout<<"		Police Control Room		Anywhere in India	100                                                                                     "<<endl;
        cout<<"		Fire Control Room		Mumbai 		        101                                                                                     "<<endl;
        cout<<"		Ambulance Helpline		Mumbai 			102                                                                                         "<<endl;
        cout<<"		Centralised Accident &                                                                                                              "<<endl;
        cout<<"		Trauma Services (CATS)		Mumbai		        1099                                                                                "<<endl;
        cout<<"		Ambulance Helpline 		Mumbai		        1092                                                                                    "<<endl;
        cout<<"		Women's Helpline		Mumbai		        1091                                                                                    "<<endl;
        cout<<"		Women's Helpline		Anywhere in India	181                                                                                     "<<endl;
        cout<<"		Senior Citizen Helpline		Mumbai		        1091 , 1291                                                                         "<<endl;
        cout<<"		Anti-Obscene Calls Cell		Mumbai		        1091	                                                                            "<<endl;
        cout<<"		Anti Stalking Cell		Mumbai		        1091                                                                                    "<<endl;
        cout<<"		AIDS Helpline			Anywhere in India	1097                                                                                    "<<endl;
        cout<<"		Medical Helpline, State		Maharashtra                                                                                             "<<endl;
        cout<<"		Anti Poison			Mumbai		        1066                                                                                        "<<endl;
        cout<<"		Eye Donation			Mumbai			1919                                                                                        "<<endl;
        cout<<"		Fire Control Room		Mumbai 			101                                                                                         "<<endl;
        cout<<"		Indian Red Cross Society	Mumbai			011- 23711551                                                                           "<<endl;
        cout<<"		Directory Enquiry		Mumbai			197                                                                                         "<<endl;
        cout<<"		CGHS Helpline, Directorate                                                                                                          "<<endl;
        cout<<"		General of Health Services	Mumbai			155224                                                                                  "<<endl;
        cout<<"		Institute of Liver and Biliary                                                                                                      "<<endl;
        cout<<"		Sciences			Mumbai			155353                                                                                          "<<endl;
        cout<<"		Disaster Management of Govt.                                                                                                        "<<endl;
        cout<<"		of Mumbai  			Mumbai			1077                                                                                            "<<endl;
        cout<<"		Dy.Commissioner of Police                                                                                                           "<<endl;
        cout<<"		(Missing Children and Women)	Mumbai			1094                                                                                "<<endl;
        cout<<"		Traffic Police Helpline		Mumbai			1095                                                                                    "<<endl;
        cout<<"		Mumbai Police Helpline		Mumbai			1090                                                                                    "<<endl;
        cout<<"		Helpline of NDMC Control Room	Mumbai			1267                                                                                "<<endl;
        cout<<"		Ambulance Service		Mumbai			1066                                                                                        "<<endl;
        cout<<"		Helpline for Women		Mumbai 			1092                                                                                        "<<endl;
        cout<<"		ORBO C.N.Centre, AIIMS                                                                                                              "<<endl;
        cout<<"		(for donation of organs)	Mumbai 			1060                                                                                    "<<endl;
        cout<<"                                                                                                                                         "<<endl;
        cout<<"	                                                     	* BLOOD BANKS IN MUMBAI *                                                       "<<endl;
        cout<<"                                                                                                                                         "<<endl;		
        cout<<"		EMERGENCY HELPLINES.		CITY			CONTACT DETAILS                                                                         "<<endl;
        cout<<"_________________________________________________________________________________________________________________________________________"<<endl;
        cout<<"                                                                                                                                         "<<endl;		
        cout<<"		AIIMS				Mumbai 			022- 26593726, 26594438                                                                         "<<endl;
        cout<<"		Bombay Hospital			Mumbai			022- 66364887                                                                               "<<endl;
        cout<<"		White Cross Blood Bank		Mumbai  		022- 26831063, 26844140                                                                 "<<endl;
        cout<<"		Batra Hospital and Medical                                                                                                          "<<endl;
        cout<<"		Research Centre			Mumbai			022- 29958747, 29957487, 29956509                                                           "<<endl;
        cout<<"		Bhagvati Hospital		Mumbai			022- 64788237, 64788249                                                                     "<<endl;
        cout<<"		Apollo Blood Bank		Mumbai 			022- 26825707, 26925858, 26925801                                                           "<<endl;
        cout<<"		Lions Blood Bank		Mumbai 			022- 42258080, 42258494                                                                     "<<endl;
        cout<<"		Dharmashila Cancer Foundation                                                                                                       "<<endl;
        cout<<"		& Research Centre		Mumbai			022- 43066424-25, 22617771-75                                                               "<<endl;
        cout<<"		Sir JJ Hospital			Mumbai			022 - 25750000, 25751111                                                                    "<<endl;
        cout<<"		Indian Red Cross Society	Mumbai			022 - 23711551                                                                          "<<endl;
        cout<<"		Batra Hospital & Medical                                                                                                            "<<endl;
        cout<<"		Research Centre			Mumbai			022-26056148, 26056153, 26057154                                                            "<<endl;
        cout<<"		Jai Prakash Narayan Apex                                                                                                            "<<endl;
        cout<<"		Trauma Centre			Mumbai		 	022- 2673 1166, 2673 1179                                                                   "<<endl;
        cout<<"		Max Balaji Hospital		Mumbai 			022- 66242515, Extension- 2031                                                              "<<endl;
        cout<<"		Fortis Flt. Lt. Rajan Dhall                                                                                                         "<<endl;
        cout<<"		Hospital			Mumbai 			022- 42776222, Extension- 5850                                                                  "<<endl;
        cout<<"                                                                                                                                         "<<endl;	
        cout<<"                                                                                                                                         "<<endl;		
        cout<<"	                                                      	* 24 HOUR AMBULANCE IN MUMBAI                                                   "<<endl;
        cout<<"                                                                                                                                         "<<endl;	
        cout<<"		EMERGENCY HELPLINES.		CITY			CONTACT DETAILS                                                                         "<<endl;
        cout<<"_________________________________________________________________________________________________________________________________________"<<endl;
        cout<<"                                                                                                                                         "<<endl;	
        cout<<"		All India Institute of                                                                                                              "<<endl;
        cout<<"		Medical Sciences (AIIMS)	Mumbai			022- 26588776                                                                           "<<endl;
        cout<<"		Centralized Accident Trauma                                                                                                         "<<endl;
        cout<<"		Service (CATS)			Mumbai 			102, 1099                                                                                   "<<endl;
        cout<<"		Escort Hospital			Mumbai 			022- 26825000                                                                               "<<endl;
        cout<<"		Moolchand Hospital		Mumbai			022- 42000000                                                                               "<<endl;
        cout<<"		Batra Hospital			Mumbai 			022- 26083747                                                                               "<<endl;
        cout<<"		Rajiv Gandhi Cancer Institute	Mumbai 			022- 27051011 to 29                                                                 "<<endl;
        cout<<"		National Heart Institute	Mumbai 			022- 26441293                                                                           "<<endl;
        cout<<"		Sir Ganga Ram Hospital		Mumbai			022- 25750000, 25757575                                                                 "<<endl;
        cout<<"		Vidyasagar Institute of Mental                                                                                                      "<<endl;
        cout<<"		Health and NeuroSciences                                                                                                            "<<endl;
        cout<<"	    (VIMHANS)			    Mumbai			022- 26924302                                                                               "<<endl;
        cout<<"		All India Institute of Medical                                                                                                      "<<endl;
        cout<<"		Sciences (AIIMS)		Mumbai 			022- 26588776                                                                               "<<endl;
        cout<<"		AIDS Diagnostic Centre		Mumbai 			022- 64360750                                                                           "<<endl;
        cout<<"		Mumbai Psychiatry Centre	Mumbai			022- 2214727                                                                            "<<endl;
        cout<<"		MP Heart Centre	Byculla		Mumbai			022- 6413436                                                                            "<<endl;
        cout<<"		National Heart Institute	Mumbai 			022- 6414156                                                                            "<<endl;
        cout<<"		Anand Hospital			Mumbai			022- 2224126                                                                                "<<endl;
        cout<<"		Holy Angles Hospital		Mumbai			022- 6143411                                                                            "<<endl;
        cout<<"		GM Modi Hospital Sion		Mumbai			022- 6852112                                                                            "<<endl;
        cout<<"		PS Funeral & Ambulance Services                                                                                                     "<<endl;
        cout<<"		Private Limited			Mumbai 			09350016581, 08373903017                                                                    "<<endl;
        cout<<"		Max Emergency Ambulance		Mumbai 			022 - 40554055                                                                          "<<endl;
        cout<<"		Goodmans Rescue Ambulance                                                                                                           "<<endl;
        cout<<"		Service				Mumbai			022 - 29231665, 46566890                                                                        "<<endl;
        cout<<"                                                                                                                                         "<<endl;	
        cout<<"	                                                            	* MISCELLANEOUS                                                         "<<endl;
        cout<<"                                                                                                                                         "<<endl;	
        cout<<"		NON-EMERGENCY HELPLINES		CITY			CONTACT DETAILS                                                                         "<<endl;
        cout<<"_________________________________________________________________________________________________________________________________________"<<endl;
        cout<<"                                                                                                                                         "<<endl;
        cout<<"		Insurance Regulatory and Development                                                                                                "<<endl;
        cout<<"		Authority (IRDA)		  Anywhere in India	155255/ 1800 4254732                                                                    "<<endl;
        cout<<"		Reproductive Health, Family                                                                                                         "<<endl; 
        cout<<"		Planning and Infant Health	Mumbai			1800-11-6555                                                                            "<<endl;
        cout<<"                                                                                                                                         "<<endl;	
        cout<<"                                                                                                                                         "<<endl;	
        cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;        

        onlyDisplay od;
        int choice;
        cout << endl << "Enter 1 to go Home Page" << endl;
        cin>>choice;
        if (choice == 1)
        {
            system("clear");
            od.menu();
        } 
        else 
        {
            cout << endl << "Enter Valid option !!";
        }
}

/*DATE and TIME*/
void date_time() 
{
	time_t t = time(NULL);
  	struct tm tm = *localtime(&t);
  	dd = tm.tm_mday; mm = tm.tm_mon + 1; yy = tm.tm_year + 1900-2000;
  	hr = tm.tm_hour; mint = tm.tm_min;
}

int main()
{
    onlyDisplay od;
    od.authentication();
}
