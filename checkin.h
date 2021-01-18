#include<string.h>
#include<iostream>
#include<fstream>
using namespace std;
//structure variable for check in
struct Check_in
{
	long payment_advance;
	string guest_id;
};
//check-in record of the guest
void check_in()
{
	//creating file to store data
	ofstream file1("Check_in.txt",ios::app);
	ifstream book("Booking.txt",ios::in);
	int i=0;
	char ch;
	Check_in c;
	Booking b;
	do
	{
		//data saving
		cout<<"Enter guest id!"<<endl;
		cin>>c.guest_id;
		while(!book.eof())
		{
			book>>b.booking_id;
			book>>b.guest_name;
			book>>b.address;
			book>>b.phone;
			book>>b.from_date;
			book>>b.to_date;
			if(b.booking_id==c.guest_id)
			{
				file1<<c.guest_id<<"\t";
				file1<<b.guest_name<<"\t";
				file1<<b.address<<"\t";
				file1<<b.phone<<"\t";
				file1<<b.from_date<<"\t";
				cout<<"This id is already booked so plz pay advance."<<endl;
				cout<<"Enter the advance payment !"<<endl;
				cin>>c.payment_advance;
				file1<<c.payment_advance<<"\n";
				break;

			}
			book.close();
		}
		if(book.eof() && c.guest_id!=b.booking_id)
		{
		
		cout<<"Enter the arrival date!"<<endl;
		cin>>b.from_date;
		cout<<"Enter the guest name!"<<endl;
		cin>>b.guest_name;
		cout<<"Enter address of the guest!"<<endl;
		cin>>b.address;
		cout<<"Enter phone number of the guest!"<<endl;
		cin>>b.phone;
		cout<<"Enter the payment recieved!"<<endl;
		cin>>c.payment_advance;
		//storing data in the file
		file1<<b.booking_id<<"\t"<<b.guest_name<<"\t"<<b.address<<"\t"<<b.phone<<"\t"<<b.from_date<<"\t"<<c.payment_advance<<endl;
		}
		//for terminating loop
		cout<<"Enter y if you want another check_in!"<<endl;
		cin>>ch;
	}while (ch=='y' || ch=='Y');
}
