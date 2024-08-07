#include<iostream>
#include<string>
#include<conio.h>
#include<windows.h>
#include<ctime>
#include<vector>
#include<fstream>
#define TAX 8
using namespace std;

class Billing;
class nonFreqVisitor;
class frequentVisitor;
class room;
class reservation;
//forward declaration
class guest;
class hotel {
protected:
	string name;
	string address;
	string phoneNo;
public:
	hotel() {}
	hotel(string name, string address, string phoneNo) {
		this->address = address;
		this->name = name;
		this->phoneNo = phoneNo;
	}
	string get_address() {
		return address;
	}
	string get_phonNo() {
		return phoneNo;
	}
	string get_hotelName() {
		return name;
	}
	~hotel(){
		
	}

};
class room {
protected:
	static string roomKind;//room size
//	const int taxRate = 8;//tax which is the same for all room types
	float roomRate;
public:
	static int room_no;//generates room no everytime a room object is created
	static int roomCount1;//no of rooms in hotel of type single bed
	static int roomCount2;//no of rooms in hotel of type double bed
	static int roomCount3;//no of rooms in hotel of type triple bed
	static int roomCount4;//no of rooms in hotel of type master bed
	room() {}
	/*Let price of ...... 1 Twin single bad is 1000, 2 Twin single bed is 1500, 3 Twin single bed is 1900, 1 king bed is 2500 */
	bool checkRoomAvailaibility(string x) {//roomType already set when object constructed so only check if the entered parameter value is even available
		if ((x== "Single")||(x=="single") && (roomCount1 > 0)) {
			roomKind="Single";
			room_no++;//unique room number everytime
			roomCount1--;//one less single bed room now
			roomRate = 1000;
			return true;
		}
		else if ((x== "Double")||(x=="double") && (roomCount2 > 0)) {
			room_no++;//unique room number everytime
			roomCount2--;
			roomRate = 1500;
			roomKind="Double";
			return true;
		}
		else if ((x== "Triple")||(x=="triple") && (roomCount3 > 0)) {
			room_no++;//unique room number everytime
			roomCount3--;
			roomKind="Triple";
			roomRate = 1900;
			return true;
		}
		else if ((x== "Master")||(x=="master") && (roomCount4 > 0)) {
			room_no++;//unique room number everytime
			roomCount4--;
			roomKind="Master";
			roomRate = 2500;
			return true;
		}
		return false;
	}
	void set_roomRate(float x) {
		roomRate = x;
	}

	float get_roomRate() {
		return roomRate;
	}

	void set_roomType(string x) {
		roomKind = x;
	}

	string get_roomType() {
		return roomKind;
	}
	~room(){
	}
};int room::roomCount1 = 100;
int room::roomCount2 = 100;
int room::roomCount3 = 100;
int room::roomCount4 = 50;
int room::room_no = 1;
string room::roomKind = "Null";


class reservation {
protected:
	int stay;//no of days guest is staying at the property
	int choiceOfCar;
	float carRent;
	float mealCost;
	int checkIndate;
	int checkOutdate;
	int checkInmonth;
	int checkOutmonth;
	int noOfMeals;
public:
    static int reservationID;
	int choice, choice2, choice3;
	hotel h;
	room room;
	reservation() {
		carRent = 0;
		mealCost = 0;
	}
	~reservation(){
		
	}
	void displayRoomChoices() {
		cout << endl << "-----------------------------"<<""<<h.get_hotelName()<<" "<<h.get_address()<<"------------------------------" << endl;
		cout << endl << "             Unwind in luxury in our Makkah hotel accommodations" << endl;
		cout << endl << "-> Enjoy 426 hotel rooms in Karachi, with floor-to-ceiling windows featuring Saddar Market or city views" << endl;
		cout << endl << "-> Stay connected with high-speed internet access, well-placed lighting, outlets and an ergonomic chair" << endl;
		cout << endl << "-> Select rooms and suites with high ceilings, 37-inch flat-screen TVs, in-room safes and minibars" << endl;
		cout << endl << "1. Twin/Single Bed (PKR 1000 per night+ PKR 250 taxes and charges, non-refundable, breakfast PKR 750 (optional))" << endl << "2. Twin/Double Bed (PKR 1500 per night + PKR 375 taxes and charges, non-refundable, breakfast PKR 1125 (optional))" << endl << "3. Twin/Triple Bed (PKR 1900 per night + PKR 475 taxes and charges, non-refundable, breakfast PKR 1425 (optional))" << endl << "4. Twin/Single Bed (PKR 2400 per night + PKR 600 taxes and charges, non-refundable, breakfast PKR 1800 (optional))" << endl << "5. King Bed (PKR 2850 per night + PKR 715 taxes and charges, non-refundable, breakfast PKR 2135 (optional))" << endl;
	}
	void mealOptions() {
		cout << endl << "Would you like to book a meal with us? (1 for yes or 0 for no): ";
		cin >> choice;
		if (choice == 1) {
			cout << endl << "One time meal for PKR 5000. How many buffet meals would you like? ";
			cin >> noOfMeals;
			mealCost = 5000 * noOfMeals;
		}
	}
	float get_mealCost() {
		return mealCost;
	}
	float get_carRent() {
		return carRent;
	}
	void displayCarRent() {
		cout << endl << "1. Toyota Avalon Sedan 2x2 Vehicle for PKR 10,000/day " << endl << "2. Lexus Sports Plus 4x4 Vehicle for PKR 25,000/day" << endl << "Enter your choice: ";
		cin >> choiceOfCar;
		switch (choiceOfCar) {
		case 1:
			carRent = (stay * 10000);
			break;
		case 2:
			carRent = (25000 * stay);
			break;
		default:
			carRent = 0;
			break;
		}
	}
	int get_choiceOfCar() {
		return choiceOfCar;
	}
	void Stay(int d1, int d2, int m1, int m2) {
		checkIndate = d1;
		checkOutdate = d2;
		checkInmonth = m1;
		checkOutmonth = m2;
		reservationID++;
		if ((d2 > d1) && (m1 == m2)) {
			stay = d2 - d1;
		}
		else if ((d2 > d1) && (m2 > m1))
			stay = (d2 - d1) + ((m2 - m1) * 30);
		else if ((d2 < d1) && (m2 > m1) && ((m1 == 1) || (m1 == 3) || (m1 == 5) || (m1 == 7) || (m1 == 8) || (m1 == 10) || (m1 == 12)))
			stay = (31 - d1) + d2 + (m2 - m1 - 1) * 31;//for months that have 31 days
		else if ((d2 < d1) && (m2 > m1) && ((m1 == 4) || (m1 == 6) || (m1 == 9) || (m1 == 11)))
			stay = (30 - d1) + d2 + (m2 - m1) * 30;//for months that have 30 days
		else if ((d2 < d1) && (m2 > m1) && ((m1 == 2)))
			stay = (29 - d1) + d2 + (m2 - m1) * 29;
		else if ((d2 < d1) && (m1 == m2) && ((m1 == 1) || (m1 == 3) || (m1 == 5) || (m1 == 7) || (m1 == 8) || (m1 == 10) || (m1 == 12)))
			stay = 31 - d1;
		else if ((d2 < d1) && (m1 == m2) && ((m1 == 2) || (m1 == 4) || (m1 == 6) || (m1 == 9) || (m1 == 11)))
			stay = 30 - d1;
		else if ((d2 < d1) && (m2 == m1) && ((m1 == 2)))
			stay = 29 - d1;
		else if (d1 == d2)
			stay = (m2 - m1) * 30;
	}
	
	int get_Stay() {
		return stay;
	}
	void get_dates() {
		cout << "" << checkIndate << " " << checkInmonth << " " << checkOutdate << " " << checkOutmonth;
	}
	int getIndate(){
		return checkIndate;
	}
	int getInMonth(){
		return checkInmonth;
	}
	int getOutdate(){
		return checkOutdate;
	}
	int getOutMonth(){
		return checkOutmonth;
	}
	int get_reservationID(){
		return reservationID;
	}
	int generate_reservationID(){
		fstream read;
		read.open("IDs.txt",ios::in);
		read.seekg(-7,ios::end);
		int temp;
		fflush(stdin);
		read>>temp;
		temp=temp+1;
		reservationID=temp;
		return temp;
	}
};int reservation::reservationID=1;
class guest {
protected:
	string firstName;
	string lastName;
	string email;
	string phoneNum;
	string request;
	int resID;
	//protected remain protected and public remain public;
public:
	reservation res;
	guest() {}
	~guest(){
		
	}
	void dataSet(string a, string b, string c, string d, string e,int x) {
		firstName = a;
		lastName = b;
		email = c;
		phoneNum = d;
		request = e;
		resID=x;
	}
	void setFirstName(string x) {
		firstName = x;
	}
	void setLastName(string x) {
		lastName = x;
	}
	void setEmail(string x) {
		email = x;
	}
	void setRequest(string x) {
		request = x;
	}
	string getFirstName() {
		return firstName;
	}
	string getLirstName() {
		return lastName;
	}
	string getEmail() {
		return email;
	}
	string getRequest() {
		return request;
	}
	int getResID(){
		return resID;
	}

};
class Billing : public guest{//object cant be created  //abstract class
protected:
	float bill;
	string dateOfIssue;
	string paymentMethod;
public:
	static float hotelTotal;
	Billing() {}
	virtual void billing() = 0;//pure virtual function
	float get_bill(){
		return bill;
	}
	void billingMethod (int x) {
		if (x == 0){
			paymentMethod = "Debit Card";
			bill=0;
		}
		else
			paymentMethod = "Cash";
			bill=0;
	}
	void displayBill(hotel hot) {
		time_t tt = time(NULL);
		struct tm*ti;
		time(&tt);
		ti = localtime(&tt);
		cout << endl << "Date of issue: " << asctime(ti);
		cout << endl << "" << hot.get_hotelName()<< " " << hot.get_address();
		cout << endl << "Property Contact: " << hot.get_phonNo();
		cout<<endl<<"Reservation ID: "<<res.get_reservationID();;
		cout << endl << "Thank you, " << getFirstName() << "! Your payment was successful and your booking is now confirmed.";
		hotelTotal = hotelTotal + bill;//for hotel revenue report///filing
		cout << endl << "Check-in: " << res.getIndate() << "/" <<res.getInMonth();// using dot opertaor of reservation class
		cout << endl << "Check-out: " << res.getOutdate()<< "/" << res.getOutMonth();
		cout<<endl<<"VAT (%):  "<<TAX;
		cout << endl << "Total Price for " << res.get_Stay() << " night (" ;
		// for(int i=0;i<x;++i)
		cout<<""<<res.room.get_roomType() <<" | ";
		cout<< ")";
		cout << endl << "Payment method: " << paymentMethod;
		cout << endl << "PKR " << bill << endl << "includes taxes and charges";

	}
};float Billing::hotelTotal = 0;
class frequentVisitor :public Billing {
public:
	frequentVisitor() {}
	~frequentVisitor(){
		
	}
	void billing() {
		// for(int i=0;i<x;++i){
		if (res.room.get_roomType() == "Single")
			bill = bill+(res.room.get_roomRate()*res.get_Stay())*1.08 *0.96+ res.get_carRent() + res.get_mealCost();
		else if (res.room.get_roomType() == "Double")
			bill = bill+(res.room.get_roomRate()*res.get_Stay())*1.08 *0.86+ res.get_carRent() + res.get_mealCost();
		else if (res.room.get_roomType() == "Triple")
			bill = bill+(res.room.get_roomRate()*res.get_Stay())*1.08 * 0.8+ res.get_carRent() + res.get_mealCost();
		if (res.room.get_roomType() == "Master")
			bill = bill+(res.room.get_roomRate()*res.get_Stay())*1.08 * 0.76+ res.get_carRent() + res.get_mealCost();
}
};
class nonFreqVisitor :public Billing {
public:
	nonFreqVisitor() {}
	void billing() {
		// for(int i=0;i<x;++i)
		bill = bill+(res.room.get_roomRate()*res.get_Stay())*1.08 + res.get_carRent() +res.get_mealCost();
	}
	~nonFreqVisitor(){
		
	}
};



class Agent {
public:

	void answerQueries(string query) {
		if (query.find("taxes") != string::npos) {
			cout << "Yes the charges shown are inclusive of taxes" << endl;
		}
		else if (query.find("discount") != string::npos) {
			cout << "Sorry to inform you but there are no discount availabe but We do offer discounted price to our frequent customers!" << endl;
		}
		else if (query.find("credit card") != string::npos) {
			cout << "Yes We do accept payment through creditcards!" << endl;
		}
		else if (query.find("roomtype") != string::npos) {
			cout << "There are four different roomtypes available: " << endl;
			cout << "1.Single" << endl << "2.Double" << endl << "3.Triple" << endl << "4.Master" << endl;
		}
		else if ((query.find("major") != string::npos) || (query.find("event") != string::npos)) {
			cout << "Yes" << endl;
		}
		else if ((query.find("smoking") != string::npos)) {
			cout << "Smolkins is allowed, but only in the smoking area opposite to the front desk!" << endl;
		}
		else if ((query.find("transportation") != string::npos)) {
			cout << "Transportation is available, You can rent a car while booking for your room." << endl;
		}
		else if ((query.find("located") != string::npos) || (query.find("location") != string::npos)) {
			cout << "King Abdul Aziz Rd, Endowment, Ajyad Street, Mecca 24231, Saudi Arabia" << endl;
		}
		else if ((query.find("shoppingmall") != string::npos) || (query.find("resturant") != string::npos)) {
			cout << "There are malls down the street!" << endl;
		}
		else if ((query.find("check-in") != string::npos) || (query.find("check-out") != string::npos)) {
			cout << "Timings for check-in and check-out are i" << endl;
		}


	}

};
int main() {
	bool temp,IDcheck;
	string temp2, temp3, temp4, temp5, temp6, temp7, temp8;
	char temp9[100];
	int day1, day2, month1, month2, choice4, choice3, choice5, choice6,choice7,choice8;
	int choice2,temp10; // we are using this...
	float temp11,lastRevenue;
	nonFreqVisitor* Nonbill_ptr;
	frequentVisitor* freqbill_ptr;
	reservation res;
	hotel h("Fairmont Hotel", "Makkah", "0539873384");
	cout<<endl<<"-----"<<h.get_hotelName()<<" "<<h.get_address()<<"-----";
	here:
	try{
	cout <<endl<< endl << "1. Queries" << endl << "2. Make a reservation" << endl << "3. Cancel booking" << endl;
	cin >> choice4;
	if((choice4!=1)&&(choice4!=2)&&(choice4!=3))
	throw(choice4);
	else 
	goto here2;
	}
	catch(int choice4){
	cout<<endl<<"Invalid input.";
		goto here;
	}
	here2:
	guest g1;
	string query;
	switch (choice4) {
	case 1:
        int decision;
		Agent agent; 
		system("cls");

		cout << "Welcome to  "<<h.get_hotelName()<<" "<<h.get_address()<<"! Enter your query, you will be answered shortly! " << endl;
	do{
        
    		cin.ignore();
			getline(cin, query);
			agent.answerQueries(query);
            cout<<"Do you have any other query? 0/1"<<endl;
            cin>>decision;
    }while(decision!=0);
		break;
	case 2:
	{
		cout << endl << "Please enter your check-in date : ";
		cout << endl << "Enter day  : ";
		cin >> day1;
		cout << endl << "Enter month : ";
		cin >> month1;
		cout << endl << "Enter your check-out date : ";
		cout << endl << "Enter day  : ";
		cin >> day2;
		cout << endl << "Enter month : ";
		cin >> month2;
		system("cls");
		cout << endl << "     Loading...";
		Sleep(1000);
		system("cls");
		system("color C7");
		
		system("cls");
		
		res.displayRoomChoices();
		cout << "   ENTER YOUR DETAILS" << endl << "   Almost done! Just fill in the required fields";
		cout << endl << "First Name: ";
		cin >> temp3;
		cout << endl << "Last Name: ";
		cin >> temp4;
		cout << endl << "Email ID:  ";
		cin >> temp5;
		cout << endl << "Phone No. ";
		cin >> temp6;
		cout << endl << "Special Request: ";
		cin >> temp7;
		fflush(stdin);
		fstream input;
		system("cls");
	
		here3:
			try
			{
					cout<<endl<<"Select 0 if you have hotel premium card or 1 if you don't: ";
					cin>>choice8;
					if((choice8 !=0)&&(choice8 !=1))
					throw(choice8);
					else 
						goto here4;
			}
			catch(int)
			{
				cout<<"Invaild input";
				goto here3;
			}
			here4:
		
		switch(choice8){
			case 0:
				fstream input;
				input.open("Premium Guest IDs.txt",ios::in);
				char id[10];
				cout<<endl<<"Enter your premium card ID: ";
				cin.ignore();
				cin.getline(temp9,99);
				
				while(!input.eof())
				{
					input.getline(id,99);
					if(!strcmp(id,temp9))
					{
						IDcheck = 1;
					}
					else 
					continue;
			}
			if(IDcheck==0){
				cout<<"Not found";
				cout<<endl<<"Do you want to enter again (1/0) : ";
				cin>>choice8;
				if(choice8 == 1)
				{
					fstream input;
				input.open("Premium Guest IDs.txt",ios::in);
				char id[10];
				cout<<endl<<"Enter your premium card ID: ";
				cin.ignore();
				cin.getline(temp9,99);
				
				while(!input.eof())
				{
					input.getline(id,99);
					if(!strcmp(id,temp9))
					{
						IDcheck = 1;
					}
					else 
					continue;
				}
				if(IDcheck==0)
				cout<<"Not found";
				}
			}
			input.close();	
		}
		
		// cout << endl << "Would you like to use debit card or cash? (0 for debit card and 1 for cash: ";
		// cin >> choice5;
		if (IDcheck==1) {
			freqbill_ptr=new frequentVisitor;
			freqbill_ptr->res.Stay(day1, day2, month1, month2);
			cout << endl << "Room Type"<<" "<<" (Single/Double/Triple/Master):  ";
			cin >> temp8;
			fstream input;
			temp10=res.generate_reservationID();
			input.open("IDs.txt",ios::app);
			input<<temp10<<endl;
			temp =freqbill_ptr->res.room.checkRoomAvailaibility(temp8);
			freqbill_ptr->res.room.set_roomType(temp8);
			while (temp == false) {
				cout << endl << "Your choice of room is unavailable at the moment. You may check back later or choose another room type" << endl;
				cout << endl << "Do you want to continue searching or exit? (1 for continue or 0 for exit: ";
				cin >> choice2;
				if (choice2 == 1) {
					freqbill_ptr->res.displayRoomChoices();
					cin >> temp2;
					temp = freqbill_ptr->res.room.checkRoomAvailaibility(temp2);
				}
				else if (choice2 == 0) {
					cout << endl << "Dear " << temp3 << endl << "We are sorry to hear that yo were not able to stay at ABC Hotel Karachi";
					exit(0);
				}
				freqbill_ptr->res.room.set_roomType(temp2);
			}

				freqbill_ptr->dataSet(temp3, temp4, temp5, temp6, temp7,temp10);
				cout << endl << "Interested in renting a car? (1 for Yes or 0 for No): ";
				cin >> choice6;
				if (choice6 == 1) {//wants to rent car
					freqbill_ptr->res.displayCarRent();
				}
				freqbill_ptr->res.mealOptions();

				cout << endl << "Would you like to use debit card or cash? (0 for debit card and 1 for cash: ";
				cin >> choice5;
				freqbill_ptr->billingMethod(choice5);
				freqbill_ptr->billing();
				system("cls");
				temp11=freqbill_ptr->get_bill();
				fstream read;
					read.open("Revenue.txt", ios::in);
					fflush(stdin);
					read >> lastRevenue;
					read.close();
					fstream write;
					write.open("Revenue.txt");
					lastRevenue += temp11;
					write << lastRevenue; // last value of revenue.;
					write.close();
				ofstream out("Guest Data.txt", ios::app);
				out.write((char*)&freqbill_ptr, sizeof(freqbill_ptr));
				freqbill_ptr->displayBill(h);
				out.close();
				input.close();
					
		}
 		else {
 			
 			Nonbill_ptr=new nonFreqVisitor;
			Nonbill_ptr->res.Stay(day1, day2, month1, month2);
			cout << endl << "Room Type"<<" "<<" (Single/Double/Triple/Master):  ";
			cin >> temp8;
			fstream input;
			temp10=res.generate_reservationID();
			input.open("IDs.txt",ios::app);
			input<<temp10<<endl;
			temp =Nonbill_ptr->res.room.checkRoomAvailaibility(temp8);
			Nonbill_ptr->res.room.set_roomType(temp8);
			while (temp == false) {
				cout << endl << "Your choice of room is unavailable at the moment. You may check back later or choose another room type" << endl;
				cout << endl << "Do you want to continue searching or exit? (1 for continue or 0 for exit: ";
				cin >> choice2;
				if (choice2 == 1) {
					Nonbill_ptr->res.displayRoomChoices();
					cin >> temp2;
					temp = Nonbill_ptr->res.room.checkRoomAvailaibility(temp2);
				}
				else if (choice2 == 0) {
					cout << endl << "Dear " << temp3 << endl << "We are sorry to hear that yo were not able to stay at ABC Hotel Karachi";
					exit(0);
				}
				Nonbill_ptr->res.room.set_roomType(temp2);
			}

				Nonbill_ptr->dataSet(temp3, temp4, temp5, temp6, temp7,temp10);
				cout << endl << "Interested in renting a car? (1 for Yes or 0 for No): ";
				cin >> choice6;
				if (choice6 == 1) {//wants to rent car
					Nonbill_ptr->res.displayCarRent();
				}
				Nonbill_ptr->res.mealOptions();

				cout << endl << "Would you like to use debit card or cash? (0 for debit card and 1 for cash: ";
				cin >> choice5;
				Nonbill_ptr->billingMethod(choice5);
				Nonbill_ptr->billing();
				system("cls");
				temp11=Nonbill_ptr->get_bill();
				fstream read;
					read.open("Revenue.txt", ios::in);
					fflush(stdin);
					read >> lastRevenue;
					read.close();
					fstream write;
					write.open("Revenue.txt");
					lastRevenue += temp11;
					write << lastRevenue; // last value of revenue.;
					write.close();
				ofstream out("Guest Data.txt", ios::app);
				out.write((char*)&Nonbill_ptr, sizeof(Nonbill_ptr));
				Nonbill_ptr->displayBill(h);
				out.close();
				input.close();
 		}
 	
		break;
	}
			case 3: //cancellation
			{
			Billing  *temp;
			ifstream input;
			input.open("IDs.txt", ios::in);

			int id;
			cout << "Enter your Reservation ID : ";
			cin >> id;

			while (!input.eof())
			{
				input.read((char*)&temp, sizeof(temp));

				if (temp->res.get_reservationID() == id)
				{
					cout << "successfully deleted";
					continue;
				}
				else
				{
					ifstream output;
					output.open("temp.txt", ios::app);
					output.read((char*)&temp, sizeof(temp));
					output.close();
				}
			}
			remove("IDs.txt");
			ifstream input2;
			input2.open("temp.txt"); 
			while (!input.eof())
			{
				input.read((char*)&temp, sizeof(temp));

				ifstream output2;
				output2.open("GuestData.txt", ios::app);
				output2.read((char*)&temp, sizeof(temp));
			}

		break;
		}
		default:
			cout<<endl<<"Invalid input";
				}
	}
