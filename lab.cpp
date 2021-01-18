#include<iostream>
#include<booking.h>
#include<checkin.h>
#include<checkout.h>
#include<summary.h>


using namespace std;

int main()
{
	char ch;
	do 
	{
	cout<<"\t\t#################################################"<<endl;
	    cout<<"	\t		Hotel Management System"      <<endl;
        cout<<"	\t			Main Menu"				<<endl<<endl;
       	cout<<"\t\t#################################################"<<endl;
        cout<<"	\t		1.Booking"<<endl;
        cout<<"	\t		2.Check_In"<<endl;
        cout<<"	\t		3.Check_out"<<endl;
        cout<<"	\t		4.Guest Summary"<<endl;
        cout<<"	\t		5.Exit"<<endl<<endl;
      	int num;
        cout<<"Enter number from (1 to 5) !"<<endl;
        cin>>num;
        	
        //conditions applying of number
        if (num==1)
        {
        	booking ();
		}
		else if(num==2)
		{
			check_in();
		}
		else if(num==3)
		{
			check_out();
			
		}
			else if(num==4)
		{
			summary_report();
		}
		else if(num==5)
		{
			return 0;
		}
		cout<<"Do you want to return to main menu ? if yes press y :";
		cin>>ch;
	}while(ch=='y' ||ch=='Y');
	return 0;
}
