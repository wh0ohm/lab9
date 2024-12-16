#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){	
	double loan, rate, amout;
	cout << "Enter initial loan: ";
	cin >>  loan ;
	cout << "Enter interest rate per year (%): ";
	cin >> rate ;
	cout << "Enter amount you can pay per year: ";
	cin >> amout ;

	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";

	int year = 1 ;
	double prevb, interest, total, payment, newb ;
	if(amout>loan){
		prevb = loan;
		interest = (rate/100)*prevb;
		total = prevb + interest ;
		payment = total ;
		newb = 0 ;
		cout << fixed << setprecision(2); 
		cout << setw(13) << left << year; 
		cout << setw(13) << left << prevb;
		cout << setw(13) << left << interest;
		cout << setw(13) << left << total;
		cout << setw(13) << left << payment;
		cout << setw(13) << left << newb;
		cout << "\n";
	}else{
		prevb = loan;
		interest = (rate/100)*prevb;
		total = prevb + interest ;
		payment = amout ;
		newb = total - payment ;
		cout << fixed << setprecision(2); 
		cout << setw(13) << left << year; 
		cout << setw(13) << left << prevb;
		cout << setw(13) << left << interest;
		cout << setw(13) << left << total;
		cout << setw(13) << left << payment;
		cout << setw(13) << left << newb;
		cout << "\n";
		while(newb != 0){
			year = year+1 ;
			prevb  = newb ;
			interest = (rate/100)*prevb;
			total = prevb + interest ;
			payment = amout ;
			newb = total - payment ;
			if(payment > total){
				payment = total ;
				newb = 0 ;
				cout << fixed << setprecision(2); 
				cout << setw(13) << left << year; 
				cout << setw(13) << left << prevb;
				cout << setw(13) << left << interest;
				cout << setw(13) << left << total;
				cout << setw(13) << left << payment;
				cout << setw(13) << left << newb;
				cout << "\n";
				break;
			}else if(payment <= total){
				cout << fixed << setprecision(2); 
				cout << setw(13) << left << year; 
				cout << setw(13) << left << prevb;
				cout << setw(13) << left << interest;
				cout << setw(13) << left << total;
				cout << setw(13) << left << payment;
				cout << setw(13) << left << newb;
				cout << "\n";
				continue;
			}
		}
	}
	return 0;
}