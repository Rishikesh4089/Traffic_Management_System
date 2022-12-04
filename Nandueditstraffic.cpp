#include<bits/stdc++.h>
#include <fstream>
#include <chrono> //for delay
#include <stdlib.h>
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
		void search_data(char *);
		void delete_data(char *);
		void update_data(char *);
        void addChal();
        void chalReg();
        void chalName();
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
    int choice{0};
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
    system("color 0A");
    int pkey, i;
    system("clr");
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
		system("color 0A");
        load();
        menu();
	}
    else 
    {
		system("color 4");
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

}

//Vehicle records
void features::recOfVeh()
{
    onlyDisplay od;
    vehData vd;
    int ROVChoice{0};
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
    }
}
int vehData::store_data()
{
    features f;
    system("clear");
    fstream fio;
    string line;
    coord(20,0);
    cout << "Welcome to Registration of Vehicles"<<endl;
    cout<<"Enter Registration number of the Vehicle in the first line "<<endl;
    cout<<"Enter Name of the owner in the second line "<<endl;
    cout<<endl<<"Enter './' to Exit ";
    fio.open("/home/lamecodes/CLionProjects/untitled/cmake-build-debug/RecordOfVehicles.txt", ios::app | ios::out | ios::in);

    // Execute a loop If file successfully Opened
    while (fio) {

        // Read a Line from standard input
        getline(cin, line);

        // Press -1 to exit
        if (line == "./")
            break;

        // Write line in file
        fio << line << endl;
    }
    cout<<"Data Entered successfully !!"<<endl;
    delay();

    system("clear");
    f.recOfVeh();

};

void recOfVeh_2()
{
    onlyDisplay od;
    system("clear");
    string path = "/home/lamecodes/CLionProjects/untitled/cmake-build-debug/RecordOfVehicles.txt";
    ifstream file( path.c_str() );


    if( file.is_open() )
    {
        cout << "                    Welcome to Registration of Vehicles\n" ;

        cout <<endl<< "Write the Registration number of the vehicle you want to searching for\n" ;
        string word ;
        cin >> word ;

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
                recOfVeh_2();
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
                recOfVeh_2();
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

void recOfVeh_3()
{
    onlyDisplay od;
    system("clear");

    string path = "/home/lamecodes/CLionProjects/untitled/cmake-build-debug/RecordOfVehicles.txt";
    ifstream file( path.c_str() );

    if( file.is_open() )
    {
        cout << "                    Welcome to Registration of Vehicles\n" ;

        cout <<endl<< "Write the Name of the Owner of the vehicle you want to searching for\n" ;
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

            int choice;
            cout<<endl<<"Enter 1 to go to home screen and enter 2 for again entering the Name of the Owner";
            cin>>choice;
            if (choice ==1)
                od.menu();
            else
                recOfVeh_2();

        }
        else{
            cout<<"Name of the Owner does not foud !!";
            int choice;
            cout<<endl<<"Enter 1 to go to home screen and enter 2 for again entering the Name of the Owner ";
            cin>>choice;
            if (choice ==1)
                od.menu();
            else
                recOfVeh_2();
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
    int ROCChoice{0};
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
    cout << "Welcome to Challan Management System\n"<<endl;

    cout<<"Enter Registration number of the Vehicle in the first line "<<endl;
    cout<<"Enter Name of the owner in the second line "<<endl;
    cout<<endl<<"Enter './' to Exit ";
    fio.open("/home/lamecodes/CLionProjects/untitled/cmake-build-debug/RecordOfChallan.txt", ios::app | ios::out | ios::in);

    // Execute a loop If file successfully Opened
    while (fio) {

        // Read a Line from standard input
        getline(cin, line);

        // Press -1 to exit
        if (line == "./")
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
    string path = "/home/lamecodes/CLionProjects/untitled/cmake-build-debug/RecordOfChallan.txt";
    ifstream file( path.c_str() );

    if( file.is_open() )
    {
        cout << "               Welcome to Challan Management System\n"<<endl;

        cout <<endl<< "Write the registration number of the vehicle you want to searching for\n" ;
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
            cout<<endl<<"Enter 1 to go to home screen and enter 2 for again entering the registration number.";
            cin>>choice;
            if (choice ==1)
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
    string path = "/home/lamecodes/CLionProjects/untitled/cmake-build-debug/RecordOfChallan.txt";
    ifstream file( path.c_str() );

    if( file.is_open() )
    {
        cout << "               Welcome to Challan Management System\n"<<endl;

        cout <<endl<< "Write the Name of the Owner of the vehicle you want to searching for\n" ;
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

            int choice;
            cout<<endl<<"Enter 1 to go to home screen and enter 2 for again entering the Name of the Owner";
            cin>>choice;
            if (choice ==1)
                od.menu();
            else
                chalName();
        }
        else{
            cout<<"Name of the Owner does not foud !!";
            int choice;
            cout<<endl<<"Enter 1 to go to home screen and enter 2 for again entering the Name of the Owner ";
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

    string path = "/home/lamecodes/CLionProjects/untitled/cmake-build-debug/RecordOfVehicles.txt";
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
            cout<<endl<<"Enter 1 to go to home screen and enter 2 for again entering the registration number ";
            cin>>choice;
            if (choice ==1)
                od.menu();
            else
                vehSearch();
        }
        else{
            cout<<"Registration number does not foud !!";
            int choice;
            cout<<endl<<"Enter 1 to go to home screen and enter 2 for again entering the registration number ";
            cin>>choice;
            if (choice ==1)
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
    int TCBChoice{0};
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                                                            WELCOME TO                                                               *"<<endl;
    cout<<"*                                                  SMART TRAFFIC MANAGEMENT SYSTEM                                                    *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                                                     * Traffic Control Booths *                                                      *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                     Press Your Option :-                                                                                            *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                                      1. Jalandhar Traffic Control Booth                                                             *"<<endl;
    cout<<"*                                      2. Amritsar Traffic Control Booth                                                              *"<<endl;
    cout<<"*                                      3. Chandigarh Traffic Control Booth                                                            *"<<endl;
    cout<<"*                                                                                                                                     *"<<endl;
    cout<<"*                     Enter 0 For Home                                                                                                *"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<"*                     Enter your choice - ", cin>>TCBChoice;

    switch (TCBChoice)
    {
        case 0:
            system("clear");
            od.menu();
            break;

        case 1:
            //trafContBooth_1();
            break;

        case 2:
           // trafContBooth_2();
            break;

        case 3:
            //trafContBooth_3();
            break;
    }
}
void trafContBooth_1()
{
    system("clear");
    for (int i = 0; i < 100; ++i) {
        cout<<"                     Jalandhar City Traffic Control Booth                 "<<endl;
        cout<<"Vehicles Going out of the City                   Vehicles coming into the City"<<endl;
        cout<<endl<<"      "<<i+1<<"                                             "<<i+5<<endl;
        delay();

        system("clear");

    }

}

void trafContBooth_2()
{
    system("clear");

    for (int i = 0; i < 100; ++i) {

        cout<<"                      Amritsar City Traffic Control Booth                 "<<endl;
        cout<<"Vehicles Going out of the City                   Vehicles coming into the City"<<endl;
        cout<<endl<<"      "<<i+5<<"                                             "<<i*7<<endl;
        delay();

        system("clear");

    }


}

void trafContBooth_3()
{
    system("clear");
    for (int i = 0; i < 100; ++i) 
    {
        cout<<"                      Chandigarh City Traffic Control Booth                 "<<endl;
        cout<<"Vehicles Going out of the City                   Vehicles coming into the City"<<endl;
        cout<<endl<<"      "<<i*16<<"                                             "<<i*22<<endl;
        delay();
        system("clear");
    }
}

//Helpline Information and nearby hospitals
void features::helpInfo()
{
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

int main()
{
    onlyDisplay od;
    od.authentication();
}
