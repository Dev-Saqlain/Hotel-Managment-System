#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void del(string);
//check out function
check_out()
{
	Booking b;
	Check_in c;
	string date;
	long days;
	ofstream file("Checkout.txt",ios::app);
	ifstream file1("Check_in.txt",ios::in);
	string pin,line;
	//enter data for search
	cout<<"Enter your id : ";
	cin>>pin;
	//search file
	while(!file1.eof()){
	
	file1>>b.booking_id;
    file1>>b.guest_name;
	file1>>b.address;
	file1>>b.phone;
	file1>>b.from_date;
	file1>>c.payment_advance;
	if(b.booking_id==pin)	//search data
	{	
		if(file)		//data saving in checkout file
		{
			file<<b.booking_id<<"\t";
			file<<b.guest_name<<"\t";
			file<<b.address<<"\t";
			file<<b.phone<<"\t";
			file<<b.from_date<<"\t";
			file<<c.payment_advance<<"\n";
		}file.close();
		cout<<"Enter no. of days stayed : ";
		cin>>days;
		cout<<"Checkout date : ";
		getline(cin,date);
		cout<<"	Reciept	"<<endl;
		cout<<"Id	"<<pin<<endl;
		cout<<"Name	"<<b.guest_name<<endl;
		cout<<"Address	"<<b.address<<endl;
		cout<<"Phone no.	"<<b.phone<<endl;
		cout<<"Checkout date	"<<date<<endl;
		cout<<"Advance	"<<c.payment_advance<<endl;
		cout<<"Total bill	"<<(1000*days)<<endl;
		cout<<"Total payable	"<<(1000*days)-c.payment_advance<<endl;
		break;
	}
}
file1.close();
if(file1.eof() && b.booking_id!=pin)
{
	cout<<"No id found.";
}
del(pin);

}
void del(string x)
{
	Booking b;
	Check_in c;
	ifstream bill("Check_in.txt",ios::in);
	ofstream bill1("temp.txt",ios::app);
	while(!bill.eof())
	{
		bill>>b.booking_id;
		bill>>b.guest_name;
		bill>>b.address;
		bill>>b.phone;
		bill>>b.from_date;
		bill>>c.payment_advance;
		if(b.booking_id!=x)
		{
			if(bill1)
			{
				bill1<<b.booking_id<<"\t";
				bill1<<b.guest_name<<"\t";
				bill1<<b.address<<"\t";
				bill1<<b.phone<<"\t";
				bill1<<b.from_date<<"\t";
				bill1<<c.payment_advance<<"\n";
			}
		}
	}
	bill.close();
	bill1.close();
	remove("Check_in.txt");
	rename("temp.txt","Check_in.txt");
	
}
