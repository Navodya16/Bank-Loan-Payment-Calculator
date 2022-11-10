#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <iomanip>

using namespace std;

/*
Function 			: displayLoans(float v[], float h[], float e[], float s[], float p1[], float p2[], int s1, int s2, int age, int mIncome, int *arr)
Description 		: this function will check appropriate loans for the customer nad display them
Input parameters 	: float v[] - vehicle loan array
					  float h[] - housing loan array
					  float e[] - education loan array
					  float s[] - senior citizen loan array
					  float p1[] - personal loan 1 array
					  float p2[] - personal loan 2 array
					  int s1 - size of vehicle,housing,education,p1,pr arrays
					  int s2 - size of seniorcitizen array
					  int age - age of the customer
					  float mIncome - monthly income of the customer
					  int *arr - pass the choice[6] array from the main function to store relevent loans for customer(1-if applicable, 0-if not applicable)		   
Return 				: print loan details if applicable and modify the choice[6] array from the main function
*/
void displayLoans(float v[], float h[], float e[], float s[], float p1[], float p2[], int s1, int s2, int age, int mIncome, int *arr)
{
	if(age>=v[0] && age<=v[1])
	{
		if(mIncome>=v[2])
		{
			arr[0]=1;
			cout<<"loan name = vehicle\n";
			cout<<"maximum loan amount = "<<v[3]<<endl;
			cout<<"maximum repay period = "<<v[4]<<endl;
			cout<<"annual interest rate = "<<v[5]<<endl;
			cout<<endl;
		}
	}
	
	if(age>=h[0] && age<=h[1])
	{
		if(mIncome>=h[2])
		{
			arr[1]=1;
			cout<<"loan name = housing\n";
			cout<<"maximum loan amount = "<<h[3]<<endl;
			cout<<"maximum repay period = "<<h[4]<<endl;
			cout<<"annual interest rate = "<<h[5]<<endl;
			cout<<endl;
		}
	}
	
	if(age>=e[0] && age<=e[1])
	{
		if(mIncome>=e[2])
		{
			arr[2]=1;
			cout<<"loan name = education\n";
			cout<<"maximum loan amount = "<<e[3]<<endl;
			cout<<"maximum repay period = "<<e[4]<<endl;
			cout<<"annual interest rate = "<<e[5]<<endl;
			cout<<endl;
		}
	}
	
	if(age>=s[0])
	{
		if(mIncome>=s[1])
		{
			arr[3]=1;
			cout<<"loan name = senior citizen\n";
			cout<<"maximum loan amount = "<<s[2]<<endl;
			cout<<"maximum repay period = "<<s[3]<<endl;
			cout<<"annual interest rate = "<<s[4]<<endl;
			cout<<endl;
		}
	}
	
	if(age>=p1[0] && age<=p1[1])
	{
		if(mIncome>=p1[2])
		{
			arr[4]=1;
			cout<<"loan name = personal - type 1\n";
			cout<<"maximum loan amount = "<<p1[3]<<endl;
			cout<<"maximum repay period = "<<p1[4]<<endl;
			cout<<"annual interest rate = "<<p1[5]<<endl;
			cout<<endl;
		}
	}
	
	if(age>=p2[0] && age<=p2[1])
	{
		if(mIncome>=p2[2])
		{
			arr[5]=1;
			cout<<"loan name = personal - type 2\n";
			cout<<"maximum loan amount = "<<p2[3]<<endl;
			cout<<"maximum repay period = "<<p2[4]<<endl;
			cout<<"annual interest rate = "<<p2[5]<<endl;
			cout<<endl;
		}
	}
}

int main()
{
	//double m=10000000.00;
	cout<<fixed<<setprecision(2);
	//cout<<m<<endl;
	
	//store the details of every loan. 1st elemnt is minimum age, 2nd-max age,3rd-monthly income,4th-max loan amount,5th-max repay period,6th-interest rate
	//but float seniorCitizen[5] has only the minimum age ,other elemnts are same
	float vehicle[6]={18,55,45000,1000000.00,60,14}; 
	float housing[6]={25,55,100000,2500000.00,60,8};
	float education[6]={25,35,45000,1500000.00,84,6};
	float seniorCitizen[5]={60,35000,500000.00,60,4.5};
	float personal1[6]={30,55,100000,2000000.00,60,14.5};
	float personal2[6]={30,55,100000,3000000.00,84,16.2};
	string loanArray[6] = {"vehicle", "housing", "education", "seniorCitizen", "personalType1", "personalType2"};
	
	while(true)
	{
		string name; //name of the customer
		int Age; //age of the customer
		float income; //monthly income of the customer
		cout<<"please enter your name :";
		cin>>name;
		cout<<"please enter your age :";
		cin>>Age;
		cout<<"please enter your monthly income :";
		cin>>income;
	
		int choices[6]={0,0,0,0,0,0}; //this array will modify based on the customer's appropriatebility 
	
		cout<<endl<<endl;
		cout<<"customer's name : "<<name<<endl<<endl;
		displayLoans(vehicle, housing, education, seniorCitizen, personal1, personal2, 6, 5, Age, income, choices);//display the loan details
		cout<<endl;
		cout<<"corresponding numbers of loans that you can apply : "<<endl; //to get the user input from the customer
		for(int i=0;i<6;i++)
		{
			if(choices[i]==1) //only prints if the customer can apply to that loan
			{
				if(i==0)
					cout<<"\t1. vehicle\n";
				else if(i==1)
					cout<<"\t2. housing\n";
				else if(i==2)
					cout<<"\t3. education\n";
				else if(i==3)
					cout<<"\t4. seniorCitizen\n";
				else if(i==4)
					cout<<"\t5. personal type 1\n";
				else if(i==5)
					cout<<"\t6. personal type 2\n";	
			}
		}
	
		cout<<"please enter your choice of loan. enter the relevent number : ";
		int choice;
		cin>>choice;
		float a,b; //a and b are relevent maximum loan amount and maximum repay period of choice
		if(choice==1)
		{
			a=vehicle[3];
			b=vehicle[4];
		}
		else if(choice==2)
		{
			a=housing[3];
			b=housing[4];
		}
		else if(choice==3)
		{
			a=education[3];
			b=education[4];
		}
		else if(choice==4)
		{
			a=seniorCitizen[2];
			b=seniorCitizen[3];
		}
		else if(choice==5)
		{
			a=personal1[3];
			b=personal1[4];
		}
		else if(choice==6)
		{
			a=personal2[3];
			b=personal2[4];
		}
		float loan; //the amount customer wish to apply
		int repayPeriod; //repay period 
		while(true) //validate user inputs
		{
			cout<<"enter the amount of loan you wish to buy : ";
			cin>>loan;
			if(loan>a)
				cout<<"the maximum allowed amount is "<<a<<" , therefore enter a smaller amount.\n";
			else
				break;
		}
		while(true)
		{
			cout<<"enter the repay period in months: ";
			cin>>repayPeriod;
			if(repayPeriod>b)
				cout<<"the maximum allowed repay period is "<<b<<" , therefore enter a smaller value.\n";
			else
				break;
		}
	
		//calculate the monthly repay amount, total interest and total amount that customer pays
		float rate; //get interest from the arrays 
		if(choice==1)
			rate=vehicle[5];
		else if(choice==2)
			rate=housing[5];
		else if(choice==3)
			rate=education[5];
		else if(choice==4)
			rate=seniorCitizen[4];
		else if(choice==5)
			rate=personal1[5];
		else if(choice==6)
			rate=personal2[5];
	
		cout<<endl;
		float ir=(rate*0.01)/12; //periodic interest rate	
		float discountFactor= (pow(1+ir,repayPeriod)-1)/(ir*pow(1+ir,repayPeriod)); //caculate discount factor
		float tMonthPay = loan/discountFactor; //total monthly payment
		cout<<"total monthly repay amount = "<<tMonthPay<<endl;
		float tCusAmn = tMonthPay * repayPeriod; //total amount that customer should pay
		cout<<"total amount that customer have to pay = "<<tCusAmn<<endl;
		float tInterest = tCusAmn - loan; //total amount of interest that bank gets
		cout<<"total interest of the bank = "<<tInterest<<endl;
	
		//create a text file and print the data
		string cName = name+".txt"; //create the file name
		ofstream file; 
		file.open(cName.c_str(), ios::out | ios::app); //open file
		file<<"name\t\t:"<<name<<endl;
		file<<"selected loan\t:"<<loanArray[choice-1]<<endl;
		file<<"maximum allowed repay period (in months):"<<b<<endl;
		file<<"annual interest rate:"<<rate<<"%"<<endl;
		file<<"requested loan amount:"<<fixed<<setprecision(2)<<loan<<endl;
		file<<"requested repay period (in months):"<<repayPeriod<<endl<<endl;
		file<<"month\tremaining loan amount\tinterest\trepaid loan amount"<<endl;
	
		for(int i=0;i<repayPeriod;i++)
		{
			float mInterest = (loan*rate*0.01)/12;
			float mRepay = tMonthPay-mInterest;
			file<<i+1<<"\t"<<fixed<<setprecision(2)<<loan<<"\t\t"<<fixed<<setprecision(2)<<mInterest<<"\t\t"<<fixed<<setprecision(2)<<mRepay<<endl;
			loan=loan-mRepay;
		
		}
		file<<"total amount paid by the customer:"<<fixed<<setprecision(2)<<tCusAmn<<endl;
	
	    file.close(); //close the file
		
		char input; //ask from the user whether he wants to continue the programme
		cout<<"do you wish to check next customer's details. if yes, enter'y' or 'Y' else enter 'n' or 'N' : ";
		cin>>input;
		cout<<endl;
		if(input=='n' || input=='N')
			break;
	}
	
	return 0;
}
