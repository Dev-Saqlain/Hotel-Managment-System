#include<fstream>
using namespace std;
//Structure variables for booking
struct Booking 
{
   string booking_id;
   string guest_name;
   string address;
   string phone;
   string from_date;
   string to_date; 
   	
};

//booking function
void booking()
{
	//creating file to store data
	ofstream file("Booking.txt",ios::app);
	Booking b;
	char ch;
	//while loop saving data
	do
	{
		if(file)
		{
		cout<<"Enter the booking id!"<<endl;
		cin>>b.booking_id;
		cout<<"Enter guest name!"<<endl;
		cin>>b.guest_name;
		cout<<"Enter address of guest!"<<endl;
		cin>>b.address;
		cout<<"Enter phone number of the guest!"<<endl;
		cin>>b.phone;
		cout<<"Enter the booking date!"<<endl;
		cin>>b.from_date;
		cout<<"Enter the leaving date!"<<endl;
		cin>>b.to_date;
		cout<<endl;
		//storing data in the file
		file<<b.booking_id<<"\t"<<b.guest_name<<"\t"<<b.address<<"\t"<<b.phone<<"\t"<<b.from_date<<"\t"<<b.to_date<<endl;
		}
		//for terminating loop
		cout<<"Enter y if you want another booking!"<<endl;
		cin>>ch;	
	}while(ch=='y' || ch=='Y');
}
