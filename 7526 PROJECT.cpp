#include<iostream>
#include<sstream>
#include<fstream>
#include<ctime>
#include<string>
using namespace std;
int itemCount;
int salesCount=0;
int CustomerCount;
class ITEM {
	bool saleEXIST_T;
	double Item_SKU;
	int Price, Quantity;
	string description;
	string CreationDate;
public:
	ITEM() {
		saleEXIST_T = 0;
		Item_SKU = 0;
		Price = 0;
		Quantity = 0;
		description = "";
		CreationDate = "";
	}
	ITEM(double sku, int s, int p, int q, string desp, string date)
	{
		Item_SKU = sku, Price = p, Quantity = q;
		description = desp;
		CreationDate = date;
		saleEXIST_T = s;
	}
	void SET_date() {
		time_t now = time(nullptr);
		CreationDate = ctime(&now);
	}
	void set_SKU(double a) {
		Item_SKU = a;
	}
	void set_P(int a) {
		Price = a;
	}
	void set_Q(int a) {
		Quantity = a;
	}
	void set_desp(string a) {
		description = a;
	}

	void set_date(string a)
	{
		CreationDate = a;
	}
	void set_sales(bool a)
	{
		saleEXIST_T = a;
	}
	bool get_sales()
	{
		return saleEXIST_T;
	}
	double get_SKU()
	{
		return Item_SKU;
	}
	int get_P()
	{
		return Price;
	}
	int get_Q()
	{
		return Quantity;
	}
	string get_desp() {
		return description;
	}
	string get_date()
	{
		return CreationDate;
	}
	friend ostream& operator<<(ostream& os, const ITEM& item);
	friend istream& operator>>(istream& in, ITEM& item);
};
ostream& operator<<(ostream& os, const ITEM& item) {

	os << item.Item_SKU << "\t\t\t$" << item.Price << "\t\t    " << item.Quantity << "\t\t" << item.description << "\t      " << item.CreationDate << endl;
	return os;
}
istream& operator>>(istream& in, ITEM& item) {
	cout << "ENTER ITEM_SKU==\n";
	in >> item.Item_SKU;
	item.set_sales(0);
	cout << "ENTER PRICE==\n";
	in >> item.Price;
	cout << "ENTER QUANTITY==\n";
	in >> item.Quantity;
	cout << "ENTER DESCRIPTION\n";
	in >> ws;
	getline(in, item.description);
	// Read the creation date field until a newline character is encountered
	item.SET_date();
	return in;
}
class CUSTOMER {
	bool SALESEXIST_C;
	string CNIC, name, address, phone, EMAIL, type;
	int amount;
	string CreationDate;

public:
	CUSTOMER() {
		SALESEXIST_C = 0;
		CNIC = "";
		name = "";
		address = "";
		phone = "";
		EMAIL = "";
		type = "";
		CreationDate = "";
		amount = 0;
	}

	CUSTOMER(bool a, string cnic, string n, string email, string addr, string ph, string ty, string date, int b) {
		SALESEXIST_C = a;
		CNIC = cnic;
		name = n;
		address = addr;
		phone = ph;
		EMAIL = email;
		type = ty;
		amount = b;
		CreationDate = date;
	}
	bool GET_SALES()
	{
		return SALESEXIST_C;
	}
	string get_CNIC() {
		return CNIC;
	}

	string get_name() {
		return name;
	}
	int get_amount()
	{
		return amount;
	}

	string get_address() {
		return address;
	}

	string get_phone() {
		return phone;
	}

	string get_type() {
		return type;
	}
	string get_mail()
	{
		return EMAIL;
	}
	//////////////
	// 
	void set_amount(int a)
	{
		amount = a;
	}
	void set_SALES(bool a)
	{
		SALESEXIST_C = a;
	}
	void set_CNIC(string a) {
		CNIC = a;
	}

	void set_name(string b) {
		name = b;
	}

	void set_address(string c) {
		address = c;
	}

	void set_phone(string d) {
		phone = d;
	}

	void set_type(string e) {
		type = e;
	}
	void set_mail(string f)
	{
		EMAIL = f;
	}
	//////////////
	string get_date() {
		return CreationDate;
	}
	void set_date(string date)
	{
		CreationDate = date;
	}

	void SET_date() {
		time_t now = time(nullptr);
		CreationDate = ctime(&now);
	}

	friend ostream& operator<<(ostream& os, const CUSTOMER& C);

	friend istream& operator>>(istream& in, CUSTOMER& C);
};
istream& operator>>(istream& in, CUSTOMER& C) {
	cout << "ENTER CNIC== ";
	C.set_SALES(0);
	getline(in, C.CNIC);
	cout << "ENTER NAME== ";
	getline(in, C.name);
	cout << "ENTER EMAIL== ";
	getline(in, C.EMAIL);
	cout << "ENTER ADDRESS== ";
	getline(in, C.address);
	cout << "ENTER TYPE OF CUSTOMER\tS=silver G=gold P=platinum === ";
	getline(in, C.type);
	cout << "ENTER PHONE NO== ";
	getline(in, C.phone);
	cout << "TOTAL AMOUNT PAYABLE== ";
	in >> C.amount;
	C.SET_date();
	return in;
}
ostream& operator<<(ostream& os, const CUSTOMER& C) {
	os << C.name <<"  " << C.CNIC << "       " << C.EMAIL << "         " << C.address << "       " << C.phone << "        " << C.type << "   " << C.CreationDate << " " <<C.amount<< "\n";
	return os;
}
class SALES {
	string CNIC, CreationDate;
	double Item_SKU;
	int Quantity, Price,ID;
	public:
		SALES() {
		Item_SKU = 0;
		CNIC = "";
		Quantity = 0;
		Price = 0;
		ID = 0;
		CreationDate = "";
	}
		SALES(double item, string cnic, int q, int p, string date,int a) {
		Item_SKU = item;
		CNIC = cnic;
		Quantity = q;
		Price = p;
		CreationDate = date;
		ID = a;
	}
		int get_ID() {
			return ID;
		}
		void set_ID(int a) {
			ID = a;
		}
		double get_item() {
		return Item_SKU;
	}
		string get_CNIC() {
		return CNIC;
	}
		int get_quantity() {
		return Quantity;
	}
		int get_price() {
		return Price;
	}
		string get_date() {
		return CreationDate;
	}
		void set_item(double item) {
		Item_SKU = item;
	}
		void set_CNIC(string cnic) {
		CNIC = cnic;
	}
		void set_quantity(int q) {
		Quantity = q;
	}
		void set_price(int p) {
		Price = p;
	}
		void set_date(string date) {
		CreationDate = date;
	}
		void SET_date() {
		time_t now = time(nullptr);
		CreationDate = ctime(&now);
	}

		friend ostream& operator<<(ostream& os, SALES& sales) 
		{
			cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
			os << "ID: " << sales.get_ID() << "\n"
				<< "Item SKU: " << sales.get_item() << "\n"
				<< "CNIC: " << sales.get_CNIC() << "\n"
				<< "Quantity: " << sales.get_quantity() << "\n"
				<< "Price: " << sales.get_price() << "\n"
				<< "Creation Date: " << sales.get_date() << "\n";
			cout << "\n----------------------------------------------------------------------------------------------------------------------\n";

			return os;
		}
};
class RECEIPT {
	int ID;
	string cnic,name;
	int TOTAL=0;
public:
	
};
class POS {
	ITEM* item;
	CUSTOMER* customer;
	SALES* s;
public:
	POS()
	{
		s = nullptr;
		item = nullptr;
		customer = nullptr;
	}
	void CALCULATE_SALES()
	{
		readCustomersforsales("C.txt");
		string cnic;
		int ID;
		int a = count_LINES("sales.txt");
		ReadS("sales.txt");
		cin.ignore();
		cout << "Enter ID:";
		cin >> ID;

		int total = 0;
		bool foundSales = false;
		for (int i = 0; i < a; i++)
		{
			if (ID== s[i].get_ID())
			{
				cnic= s[i].get_CNIC();
				total += s[i].get_price() * s[i].get_quantity();
				foundSales = true;
			}
		}
		string name;
		string type;
		int INDEX;
		for (int i = 0; i < CustomerCount; i++)
		{
			if (cnic== customer[i].get_CNIC())
			{
				type=customer[i].get_type();
				name=customer[i].get_name();
				INDEX = i;
				
			}
			
		}
		
		if (type == "R")
		{
			if (total > 40000)
			{
				return;
			}
			else {
				total = total;
				customer[INDEX].set_amount(customer[INDEX].get_amount() + total);
			}
		}
		else if (type == "S")
		{
			if (total > 100000)
			{
				return;
			}
			else {
				total = total - (total * 0.03);
				total = total;
				customer[INDEX].set_amount(customer[INDEX].get_amount() + total);
			}
			
		}
		else if (type == "P")
		{
			if (total > 250000)
			{
				return;
			}
			else {
				total = total - (total * 0.05);
				total = total;
				customer[INDEX].set_amount(customer[INDEX].get_amount() + total);
			}
		}
		else {
			cout << "THERE IS SOME ERROR IN CUSTOMER TYPE\n";
			return;
		}
		writeC("C.txt", CustomerCount);
		if (foundSales)
		{
			cout << "NAME:  " << name << "\nCNIC: " << cnic << "\nTOTAL: " << total;
		}
		else
		{
			cout << "No sales found for customer with ID" << ID << endl;
		}

		delete[] s;
	}


	void makesales()
	{
		int control = 0;
		salesCount++;
		s = new SALES[salesCount];
		string CreationDate;
		int id = 0;
		cout << "ENTER SALES ID\n";
		cin >> id;
		int c;
		int Cindex = 0, Iindex = 0;
		cout << "ENTER 1 TO AUTOMATICALLY SET DATE or ANYTHING ELSE TO MANUALLY ENTER DATE\n";
		cin >> c;
		if (c == 1) {
			time_t now = time(nullptr);
			CreationDate = ctime(&now);
		}
		else {
			cin.ignore();
			getline(cin, CreationDate);
		}
		cin.ignore();
		cout << "ENTER CNIC\n";
		int found = 0;
		string cnic;
		double sku = 0;
		int q = 0, p = 0;
		int remain_Q = 0;
		getline(cin, cnic);
		for (int i = 0; i < CustomerCount; i++)
		{
			if (customer[i].get_CNIC() == cnic)
			{
				Cindex = i;
				customer[i].set_SALES(1);
				found = 1;
				cout << "YOU ENTERED VALID CNIC\n";
				//additem(cnic,id,p,q,sku)
				break;
			}
		}
		if (found == 1) {
			do {
				cout << "ENTER ITEM SKU\n";
				cin >> sku;
				int itemFound = 0;
				for (int j = 0; j < itemCount; j++)
				{
					if (item[j].get_SKU() == sku)
					{
						item[j].set_sales(1);
						itemFound = 1;
						Iindex = j;
						cout << "YOU ENTERED VALID SKU\n";
						cout << item[j].get_desp() << " " << item[j].get_Q() << "\n";
						cout << "ENTER QUANTITY\n";
						cin >> q;
						if (q <= item[j].get_Q() && q >= 0)
						{
							cout << "YOU ENTERED VALID QUANTITY\n";
							p = item[j].get_P();
							remain_Q = item[j].get_Q() - q;
						}
						else {
							cout << "INVALID QUANTITY\n";
							break;
						}
						int choice_for_save;
						cout << "ENTER 1 TO SAVE SALE OR ANYTHING ELSE TO CANCEL SALE\n";
						cin >> choice_for_save;
						if (choice_for_save == 1)
						{
							s[salesCount - 1] = SALES{ sku,cnic,q,p,CreationDate,id };
							customer[Cindex].set_SALES(1);
							item[Iindex].set_Q(remain_Q);
							item[Iindex].set_sales(1);
							writeC("C.txt", CustomerCount);
							writeITEMS("items.txt", itemCount);
							writeS("sales.txt", salesCount, s);
							cout << "SALE MADE SUCCESSFULLY\n";

						}
						else
						{
							cout << "SALE CANCELLED\n";
						}
					}

				}
				if (!itemFound) {
					cout << "ITEM NOT FOUND\n";
				}
				int choice_to_END;
				cout << "ENTER 1 TO MAKE ANOTHER SALE OR ANYTHING ELSE TO END SALE\n";
				cin >> choice_to_END;
				if (choice_to_END == 1)
				{
					control = 0;
				}
				else {
					control = 1;
					break;
				}

			} while (control != 1);
		}
		else {
			cout << "INVALID CNIC\n";
		}
	}
	void dispS(int a)
	{
		for (int i = 0; i < a; i++)
		{
			cout << s[i];
		}
	}
	void writeS(string filename, int salesCount, SALES* s) {
		ofstream file(filename, ios::app);
		if (file.is_open()) {
			int i = 0;
			while (i != salesCount)
			{
				if (i == salesCount - 1)
				{
					file << s[i].get_date() << ", " << s[i].get_CNIC() << ", " << s[i].get_item() << " "
						<< s[i].get_ID() << " " << s[i].get_quantity() << " " << s[i].get_price() << "*" << endl;
					break;
				}
				i++;
			}
			file.close();
			cout << "Sales data written to file." << endl;
		}
		else {
			cout << "Unable to open file: " << filename << endl;
		}
		ReadS(filename);
	}
	int count_LINES(string filename)
	{
		int number_of_lines = 0;
		string line;
		ifstream myfile(filename);

		if (myfile.is_open()) {
			while (!myfile.eof()) {
				getline(myfile, line, '*');
				cout << line << endl;
				number_of_lines++;
			}
			myfile.close();
		}
		return number_of_lines - 1;
	}
	void ReadS(string filename)
	{
		int length;
		length = count_LINES(filename);
		s = new SALES[length];
		ifstream inFile(filename);
		if (!inFile) {
			cout << "Error: Can't open sales file" << filename << endl;
			return;
		}
		for (int i = 0; i < length; i++)
		{
			double item;
			int id;
			string cnic, date;
			int quantity, price;
			getline(inFile, date, ',');
			inFile.ignore();
			getline(inFile, cnic, ',');
			inFile >> item;
			inFile >> id;
			inFile >> quantity;
			inFile >> price;
			s[i] = SALES{ item,cnic,quantity,price,date,id };
			//cin.clear();
		}
		cout << "1 TO DISPLAY SALES\n";
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			dispS(length);
		}
		else
		{

		}
	}
	void ReadS_remove(string filename)
	{
		int length;
		length = count_LINES(filename);
		s = new SALES[length];
		ifstream inFile(filename);
		if (!inFile) {
			cout << "Error: Can't open sales file" << filename << endl;
			return;
		}
		for (int i = 0; i < length; i++)
		{
			double item;
			int id;
			string cnic, date;
			int quantity, price;
			getline(inFile, date, ',');
			inFile.ignore();
			getline(inFile, cnic, ',');
			inFile >> item;
			inFile >> id;
			inFile >> quantity;
			inFile >> price;
			s[i] = SALES{ item,cnic,quantity,price,date,id };
			//cin.clear();
		}
	}
	void writeS_R(string fileName, int a, SALES* s)
	{
		ofstream file(fileName, ios::out | ios::trunc); // truncate the file before writing
		for (int i = 0; i < a; i++) {
			file << s[i].get_date() << "," << s[i].get_CNIC() << ", " << s[i].get_item() << " " << s[i].get_ID() << " " << s[i].get_quantity() << " " << s[i].get_price() << "*" << endl;
		}
		file.close();
	}
	void removeS()
	{
		readITEMSforsales("items.txt");
		int a;
		int found = -1;
		a = count_LINES("sales.txt");
		cout << a;
		ReadS_remove("sales.txt");
		int sku, id;
		cout << "ENTER SKU OF ITEM TO BE REMOVED\n";
		cin >> sku;
		cout << "ENTER ID OF SALE TO BE REMOVED\n";
		cin >> id;
		for (int i = 0; i < itemCount; i++)
		{
			if (item[i].get_SKU() == sku)
			{
				item[i].set_sales(0);
			}
		}
		for (int i = 0; i < a; i++)
		{
			if (s[i].get_ID() == id && s[i].get_item() == sku)
			{
				found = i;
				break;
			}
		}
		if (found != -1)
		{
			SALES* new_S = new SALES[a - 1];
			int i = 0, j = 0;
			while (i < a)
			{
				if (i != found) {
					new_S[j] = s[i];
					j++;
				}
				i++;
			}
			delete[] s;
			s = new_S;
			a--;
			writeS_R("sales.txt", a, s);
		}
		else
		{
			cout << "SALE NOT FOUND\n";
		}
	}
	////////////////////////////////////////////////////////////////////////////////////////////////
	void dispITEMS(ITEM* item)
	{
		for (int i = 0; i < itemCount; i++)
		{
			cout << item[i]<< endl;
		}
	}
	void readITEMS(string filename) {
		ifstream inFile(filename);
		if (!inFile) {
			cout << "Error: Can't open items file" << filename << endl;
			return;
		}
		int numOfItems;
		inFile >> numOfItems;
		itemCount = numOfItems;
		item = new ITEM[numOfItems];//total no of items at the first line of file
		for (int i = 0; i < numOfItems; i++) {
			double sku;
			bool salesEXIST_T;
			int price, quantity;
			string desc, date;
			//reading data
			inFile >> sku >> salesEXIST_T >> price >> quantity;
			getline(inFile, desc, ','); //upto ,
			getline(inFile, date, '\n');//reading date
			item[i] = ITEM{ sku,salesEXIST_T, price, quantity, desc, date };
		}
		inFile.close();
		dispITEMS(item);
	}
	void readITEMSforsales(string filename) {
		ifstream inFile(filename);
		if (!inFile) {
			cout << "Error: Can't open items file" << filename << endl;
			return;
		}
		int numOfItems;
		inFile >> numOfItems;
		itemCount = numOfItems;
		item = new ITEM[numOfItems];//total no of items at the first line of file
		for (int i = 0; i < numOfItems; i++) {
			double sku;
			bool salesEXIST_T;
			int price, quantity;
			string desc, date;
			//reading data
			inFile >> sku >> salesEXIST_T >> price >> quantity;
			getline(inFile, desc, ','); //upto ,
			getline(inFile, date, '\n');//reading date
			item[i] = ITEM{ sku,salesEXIST_T, price, quantity, desc, date };
		}
		inFile.close();
	}
	void writeITEMS(string filename, int numItems)
	{
		ofstream outFile(filename, ios::out | ios::trunc);
		if (!outFile) {
			cout << "Error: Can't open items file " << filename << endl;
			return;
		}
		//updating numItems after an item is written successfully
		outFile << numItems << endl;
		//put data from array to file
		for (int i = 0; i < itemCount; i++) {
			outFile << item[i].get_SKU() << " " << item[i].get_sales() << " " << item[i].get_P() << " " << item[i].get_Q() << " " << item[i].get_desp() << "," << item[i].get_date() << endl;
		}
		outFile.close();
	}
	void addITEM()
	{
		int a = itemCount + 1;
		ITEM* items = new ITEM[a];
		//copy existing
		int i = 0;
		while (i != a - 1)
		{
			items[i] = item[i];
			i++;
		}
		cin >> items[a - 1];
		//delete item and then again initilize it to new array
		delete[] item;
		item = items;
		itemCount++;
		//display updated array

		writeITEMS("items.txt", itemCount);
		dispITEMS(item);
	}
	void removeITEM() {
		double sku;
		cout << "ENTER SKU TO FIND ITEM YOU WANT TO REMOVE\n";
		cin >> sku;
		int foundIndex = -1;
		for (int i = 0; i < itemCount; i++)
		{
			if (sku == item[i].get_SKU() && item[i].get_sales() == 0)
			{
				foundIndex = i;
				break;
			}
		}
		if (foundIndex != -1) {
			ITEM* newItems = new ITEM[itemCount - 1];
			int i = 0, j = 0;
			while (i < itemCount)
			{
				if (i != foundIndex) {
					newItems[j] = item[i];
					j++;
				}
				i++;
			}
			delete[] item;
			item = newItems;
			itemCount--;
			writeITEMS("items.txt", itemCount);
			dispITEMS(item); // pass the itemCount as a parameter to limit the display to the number of items remaining
		}
		else {
			cout << "SKU not found\n";
		}
	}
	void searchITEM()
	{
		dispITEMS(item);
		double sku = 0;
		int p = 0, q = 0;
		string desp, date;
		int choice_sku, choice_p, choice_q, choice_desp, choice_date;
		cout << "\nENTER 1 IF YOU WANT TO ENTER SKU OR ANYTHING ELSE TO LEAVE IT EMPTY\n";
		cin >> choice_sku;
		if (choice_sku == 1)
		{
			cin >> sku;
		}
		else {
			sku = 0;
		}
		cout << "\nENTER 1 IF YOU WANT TO ENTER PRICE OR ANYTHING ELSE TO LEAVE IT EMPTY\n";
		cin >> choice_p;
		if (choice_p == 1)
		{
			cin >> p;
		}
		else {
			p = 0;
		}
		cout << "\nENTER 1 IF YOU WANT TO ENTER QUANTITY OR ANYTHING ELSE TO LEAVE IT EMPTY\n";
		cin >> choice_q;
		if (choice_q == 1)
		{
			cin >> q;
		}
		else {
			q = 0;
		}
		cout << "\nENTER 1 IF YOU WANT TO ENTER DESCRIPTION OR ANYTHING ELSE TO LEAVE IT EMPTY\n";
		cin >> choice_desp;
		if (choice_desp == 1)
		{
			cin.ignore();
			getline(cin, desp);
		}
		else {
			desp = " ";
		}
		cout << "\nENTER 1 IF YOU WANT TO ENTER DATE(IN THE FORMAT SPECIFY ABOVE) OR ANYTHING ELSE TO LEAVE IT EMPTY\n";
		cin >> choice_date;
		if (choice_date == 1)
		{
			cin.ignore();
			getline(cin, date);
		}
		else {
			date = " ";
		}

		for (int i = 0; i < itemCount; i++)
		{
			if (sku == item[i].get_SKU() || p == item[i].get_P() || q == item[i].get_Q() || desp == item[i].get_desp() || date == item[i].get_date())
			{
				cout << "\nITEM FOUND SUCCESSFULLY\n";
				cout << item[i];
				break;
			}
		}

	}
	void updateITEM()
	{
		string a1, a2;
		double sku;
		cout << "ENTER SKU TO FIND ITEM\n";
		cin >> sku;
		for (int i = 0; i < itemCount; i++)
		{
			if (sku == item[i].get_SKU())
			{
				double a;
				int b, c;
				int choice1, choice2, choice3, choice4, choice5;
				cout << "press 1 if you want to change sku==\n";
				cin >> choice1;
				if (choice1 == 1) {
					cout << "\nENTER NEW ITEM SKU==  ";
					cin >> a;
					item[i].set_SKU(a);
					cout << "CONTENT CHANGE SUCCESSFULLY.....\n";
				}
				else {
					cout << "YOU CHOOSE NOT TO OVERWRITE PREVIOUS CONTENT\n";
				}
				cout << "press 1 if you want to change price==\n";
				cin >> choice2;
				if (choice2 == 1) {
					cout << "\nENTER NEW PRICE==  ";
					cin >> b;
					item[i].set_P(b);
					cout << "CONTENT CHANGE SUCCESSFULLY.....\n";
				}
				else {
					cout << "YOU CHOOSE NOT TO OVERWRITE PREVIOUS CONTENT\n";
				}
				cout << "press 1 if you want to change quantity==\n";
				cin >> choice3;
				if (choice3 == 1) {
					cout << "\nENTER NEW QUANTITY==  ";
					cin >> c;
					item[i].set_Q(c);
					cout << "CONTENT CHANGE SUCCESSFULLY.....\n";
				}
				else {
					cout << "YOU CHOOSE NOT TO OVERWRITE PREVIOUS CONTENT\n";
				}
				cout << "press 1 if you want to change description==\n";
				cin >> choice4;
				if (choice4 == 1) {
					cout << "\nENTER NEW DESCRIPTION==  ";
					cin.ignore(); // clear input stream
					getline(cin, a1);
					item[i].set_desp(a1);
					cout << "CONTENT CHANGE SUCCESSFULLY.....\n";
				}

				else {
					cout << "YOU CHOOSE NOT TO OVERWRITE PREVIOUS CONTENT\n";
				}
				cout << "press 1 if you want to change date==\n";
				cin >> choice5;
				if (choice5 == 1) {
					int choice_A;
					cout << "\nENTER 1 IF YOU WANT TO MANUALLY ENTER DATE AND ANYTHING ELSE IF YOU WANT TO USE CURRENT DATE \n";
					cin >> choice_A;
					if (choice_A == 1)
					{
						cin.ignore(); // clear input stream
						getline(cin, a2);
						item[i].set_date(a2);
						cout << "\nCONTENT CHANGE SUCCESSFULLY.....\n";
					}
					else {
						item[i].SET_date();
						cout << "CURRENT DATE SET\n";
					}
				}
				else {
					cout << "YOU CHOOSE NOT TO OVERWRITE PREVIOUS CONTENT\n";
				}

			}
		}
		writeITEMS("items.txt", itemCount);
		dispITEMS(item);

	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void dispC(CUSTOMER* customer)
	{
		cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
		for (int i = 0; i < CustomerCount; i++)
		{
			cout << customer[i];
		}
		cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
	}
	void readCustomersforsales(string filename)
	{
		ifstream inFile(filename);
		if (!inFile) {
			cout << "Cannot open file " << filename << endl;
			return;
		}

		int numCustomers;
		inFile >> numCustomers;
		CustomerCount = numCustomers;
		inFile.ignore(); // Skip the newline character after the integer

		// Allocate memory for the customer array
		customer = new CUSTOMER[numCustomers];

		// Read customer data from file into the array
		for (int i = 0; i < numCustomers; i++) {
			bool salesExist;
			string cnic, name, email, address, phone, type, creationDate;
			int amount;
		
			getline(inFile, name, ',');
			getline(inFile, cnic, ',');
			getline(inFile, email, ',');
			getline(inFile, address, ',');
			getline(inFile, phone, ',');
			getline(inFile, type, ',');
			getline(inFile, creationDate,',');
			inFile >> amount;
			inFile >> salesExist;
			

			customer[i] = CUSTOMER{ salesExist, cnic, name, email, address, phone, type, creationDate, amount };
		}
		
	}
	void readCustomers(string filename)
	{
		ifstream inFile(filename);
		if (!inFile) {
			cout << "Cannot open file " << filename << endl;
			return;
		}

		int numCustomers;
		inFile >> numCustomers;
		CustomerCount = numCustomers;
		inFile.ignore(); // Skip the newline character after the integer

		// Allocate memory for the customer array
		customer = new CUSTOMER[numCustomers];

		// Read customer data from file into the array
		for (int i = 0; i < numCustomers; i++) {
			bool salesExist;
			string cnic, name, email, address, phone, type, creationDate;
			int amount;
		
			
			getline(inFile, name, ',');
			getline(inFile, cnic, ',');
			getline(inFile, email, ',');
			getline(inFile, address, ',');
			getline(inFile, phone, ',');
			getline(inFile, type, ',');
			getline(inFile, creationDate,',');
			inFile >> amount;
			inFile >> salesExist;

			customer[i] = CUSTOMER{ salesExist, cnic, name, email, address, phone, type, creationDate, amount };
		}

		// Pass the customer array to a function for further processing/display
		dispC(customer);

	}
	void writeC(string filename, int numC)
	{
		ofstream outFile(filename, ios::out | ios::trunc);
		if (!outFile) {
			cout << "Error: Can't open items file " << filename << endl;
			return;
		}
		outFile << numC << endl;
		for (int i = 0; i < CustomerCount; i++) {
			outFile << customer[i].get_name() << "," << customer[i].get_CNIC() << "," << customer[i].get_mail() << "," << customer[i].get_address() << "," << customer[i].get_phone() << "," << customer[i].get_type() << "," << customer[i].get_date() << "," << customer[i].get_amount() << " " << customer[i].GET_SALES()<<endl;
		}

		outFile.close();
	}
	void add_C()
	{
		//create new array with one increment in size
		int a = CustomerCount + 1;
		CUSTOMER* customers = new CUSTOMER[a];
		//copy existing
		int i = 0;
		while (i != a - 1)
		{
			customers[i] = customer[i];
			i++;
		}
		cin.ignore();
		cin >> customers[a - 1];

		//delete item and then again initilize it to new array
		delete[] customer;
		customer = customers;
		CustomerCount++;
		//display updated array
		writeC("C.txt", CustomerCount);
		dispC(customer);
	}
	void removeC() {
		string cnic;;
		cout << "ENTER CNIC TO FIND CUSTOMER YOU WANT TO REMOVE\n";
		cin >> cnic;
		int foundIndex = -1;
		for (int i = 0; i < CustomerCount; i++)
		{
			if (cnic == customer[i].get_CNIC() && customer[i].GET_SALES() == 0)
			{
				foundIndex = i;
				break;
			}
		}
		if (foundIndex != -1) {
			CUSTOMER* newcustomers = new CUSTOMER[CustomerCount - 1];
			int i = 0, j = 0;
			while (i < CustomerCount)
			{
				if (i != foundIndex) {
					newcustomers[j] = customer[i];
					j++;
				}
				i++;
			}
			delete[] customer;
			customer = newcustomers;
			CustomerCount--;
			writeC("C.txt", CustomerCount);
			dispC(customer); // pass the itemCount as a parameter to limit the display to the number of items remaining
		}
		else {
			cout << "SKU not found\n";
		}
	}
	void searchC()
	{
		dispC(customer);
		string cnic, name, email, phone, type;
		int choice_cnic, choice_name, choice_type, choice_phone, choice_mail;
		cout << "\nENTER 1 IF YOU WANT TO ENTER CNIC OR ANYTHING ELSE TO LEAVE IT EMPTY\n";
		cin >> choice_cnic;
		if (choice_cnic == 1)
		{
			cin.ignore();
			getline(cin, cnic);
		}
		else {
			cnic = "";
		}
		cout << "\nENTER 1 IF YOU WANT TO ENTER NAME OR ANYTHING ELSE TO LEAVE IT EMPTY\n";
		cin >> choice_name;
		if (choice_name == 1)
		{
			cin.ignore();
			getline(cin, name);
		}
		else {
			name = "";
		}
		cout << "\nENTER 1 IF YOU WANT TO ENTER EMAIL ADDRESS OR ANYTHING ELSE TO LEAVE IT EMPTY\n";
		cin >> choice_mail;
		if (choice_mail == 1)
		{
			cin.ignore();
			getline(cin, email);
		}
		else {
			email = "";
		}
		cout << "\nENTER 1 IF YOU WANT TO ENTER PHONE OR ANYTHING ELSE TO LEAVE IT EMPTY\n";
		cin >> choice_phone;
		if (choice_phone == 1)
		{
			cin >> phone;
		}
		else {
			phone = "";
		}
		cout << "\nENTER 1 IF YOU WANT TO ENTER TYPE OR ANYTHING ELSE TO LEAVE IT EMPTY\n";
		cin >> choice_type;
		if (choice_type == 1)
		{
			cin >> type;
		}
		else {
			type = "";
		}

		for (int i = 0; i < CustomerCount; i++)
		{
			if (cnic == customer[i].get_CNIC() || name == customer[i].get_name() || email == customer[i].get_mail() || phone == customer[i].get_phone() || type == customer[i].get_type())
			{
				cout << "\nCUSTOMER FOUND SUCCESSFULLY\n";
				cout << customer[i];
			}
		}
	}
	void updateC()
	{
		string cnic;
		string Cnic, name, addr, ph, e, ty, d;
		int am;
		cout << "ENTER CNIC TO FIND ITEM\n";
		cin >> cnic;
		for (int i = 0; i < CustomerCount; i++)
		{
			if (cnic == customer[i].get_CNIC())
			{
				int choice1, choice2, choice3, choice4, choice5, choice6, choice7,choice8;
				cout << "press 1 if you want to change cnic==\n";
				cin >> choice1;
				if (choice1 == 1) {
					cout << "\nENTER NEW CNIC==  ";
					cin >> Cnic;
					customer[i].set_CNIC(Cnic);
					cout << "CONTENT CHANGE SUCCESSFULLY.....\n";
				}
				else {
					cout << "YOU CHOOSE NOT TO OVERWRITE PREVIOUS CONTENT\n";
				}
				cout << "press 1 if you want to change name==\n";
				cin >> choice2;
				if (choice2 == 1) {
					cout << "\nENTER NEW NAME==  ";
					cin.ignore();
					getline(cin, name);
					customer[i].set_name(name);
					cout << "CONTENT CHANGE SUCCESSFULLY.....\n";
				}
				else {
					cout << "YOU CHOOSE NOT TO OVERWRITE PREVIOUS CONTENT\n";
				}
				cout << "press 1 if you want to change address==\n";
				cin >> choice3;
				if (choice3 == 1) {
					cout << "\nENTER NEW ADDRESS==  ";
					cin.ignore();
					getline(cin, addr);
					customer[i].set_address(addr);
					cout << "CONTENT CHANGE SUCCESSFULLY.....\n";
				}
				else {
					cout << "YOU CHOOSE NOT TO OVERWRITE PREVIOUS CONTENT\n";
				}
				cout << "press 1 if you want to change phone==\n";
				cin >> choice4;
				if (choice4 == 1) {
					cout << "\nENTER NEW phone no==  ";
					cin.ignore();
					getline(cin, ph);
					customer[i].set_phone(ph);
					cout << "CONTENT CHANGE SUCCESSFULLY.....\n";
				}

				else {
					cout << "YOU CHOOSE NOT TO OVERWRITE PREVIOUS CONTENT\n";
				}
				cout << "press 1 if you want to change email==\n";
				cin >> choice5;
				if (choice5 == 1) {
					cout << "\nENTER NEW mail==  ";
					cin.ignore();
					getline(cin, e);
					customer[i].set_mail(e);
					cout << "CONTENT CHANGE SUCCESSFULLY.....\n";
				}

				else {
					cout << "YOU CHOOSE NOT TO OVERWRITE PREVIOUS CONTENT\n";
				}
				cout << "press 1 if you want to change type==\n";
				cin >> choice6;
				if (choice6 == 1) {
					cout << "\nENTER New type==  ";
					cin >> ty;
					customer[i].set_type(ty);
					cout << "CONTENT CHANGE SUCCESSFULLY.....\n";
				}

				else {
					cout << "YOU CHOOSE NOT TO OVERWRITE PREVIOUS CONTENT\n";
				}
				cout << "press 1 if you want to change date==\n";
				cin >> choice7;
				if (choice7 == 1) {
					int choice_A;
					cout << "\nENTER 1 IF YOU WANT TO MANUALLY ENTER DATE AND ANYTHING ELSE IF YOU WANT TO USE CURRENT DATE \n";
					cin >> choice_A;
					if (choice_A == 1)
					{
						cin.ignore();
						getline(cin, d);
						customer[i].set_date(d);
					}
					else {
						customer[i].SET_date();
						cout << "   CURRENT DATE SET   ...........\n";
					}
				}
				else {
					cout << "YOU CHOOSE NOT TO OVERWRITE PREVIOUS CONTENT\n";
				}
				cout << "press 1 if you want to change payable amount==\n";
				cin >> choice8;
				if (choice8 == 1) {
					cout << "\nENTER New amount==  ";
					cin >> am;
					customer[i].set_amount(am);
					cout << "CONTENT CHANGE SUCCESSFULLY.....\n";
				}

				else {
					cout << "YOU CHOOSE NOT TO OVERWRITE PREVIOUS CONTENT\n";
				}
			}
		}
		writeC("C.txt", CustomerCount);
		dispC(customer);

	}
};
int main()
{
	int Mcontrol = 0;
	do {
		int Mchoice;
		cout << "\n\t(((((MAIN MENU)))))\t\n";
		cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
		POS a;
		cout << "1:MANAGE ITEMS:\n";
		cout << "2:MANAGE CUSTOMERS:\n";
		cout << "3:MAKE NEW SALE:\n";
		cout << "4:MAKE PAYEMENT:\n";
		cout << "5:EXIT\n";
		cout << "----------------------------------------------------------------------------------------------------------------------\n";
		cin >> Mchoice;

		cout << endl;
		if (Mchoice == 1)
		{

			int Ichoice, Icontrol = 0;
			do {

				cout << "----------------------------------------------------------------------------------------------------------------------\n";
				cout << "\n\t(((((ITEMS MENU)))))\t\n";
				cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
				a.readITEMS("ITEMS.txt");
				cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
				cout << "\n1:ADD NEW ITEM:\n";
				cout << "2:UPDATE ITEM DETAILS:\n";
				cout << "3:REMOVE AN ITEM:\n";
				cout << "4:FIND AN ITEM:\n";
				cout << "5:EXIT TO MAIN MENU:\n";
				cout << "----------------------------------------------------------------------------------------------------------------------\n";
				cin >> Ichoice;

				if (Ichoice == 1)
				{
					a.addITEM();

				}
				else if (Ichoice == 2)
				{
					a.updateITEM();
				}
				else if (Ichoice == 3)
				{
					a.removeITEM();
				}
				else if (Ichoice == 4)
				{
					a.searchITEM();
				}
				else if (Ichoice == 5)
				{
					Icontrol = 1;
				}
				else {
					cout << "\nERROR::INCORRECT OPTION TRY AGAIN\n";
				}
			} while (Icontrol != 1);
		}
		else if (Mchoice == 2)
		{
			int Cchoice;
			int Ccontrol = 0;
			do {
				POS a;
				cout << "\n\t(((((CUSTOMER MENU)))))\t\n";
				cout << "----------------------------------------------------------------------------------------------------------------------\n";
				a.readCustomers("C.txt");
				cout << "\n1:ADD NEW CUSTOMER:\n";
				cout << "2:UPDATE CUSTOMER DETAILS:\n";
				cout << "3:FIND CUSTOMER:\n";
				cout << "4:REMOVE EXISTING CUSTOMER:\n";
				cout << "5:BACK TO MAIN:\n";
				cout << "----------------------------------------------------------------------------------------------------------------------\n";
				cin >> Cchoice;
				if (Cchoice == 1)
				{
					a.add_C();
				}
				else if (Cchoice == 2)
				{
					a.updateC();
				}
				else if (Cchoice == 3)
				{
					a.searchC();
				}
				else if (Cchoice == 4)
				{
					a.removeC();
				}
				else if (Cchoice == 5)
				{
					Ccontrol = 1;
				}
				else {
					cout << "\nERROR::INCORRECT OPTION TRY AGAIN\n";
				}
			} while (Ccontrol != 1);
		}

		else if (Mchoice == 3)
		{
			a.readCustomersforsales("C.txt");
			a.readITEMSforsales("items.txt");
			int c;
			cout << "ENTER 1 IF YOU WANT TO REMOVE ANY SALE OF ANY ITEM OR ANY THING ELSE TO IGNORE\n";
			cin >> c;
			if (c == 1)
			{
				a.removeS();
			}
			else {
				cout << "YOU CHOOSE NOT TO REMOVE ANY SALE\n";
			}
			
			a.makesales();
			
			Mcontrol = 0;
		}
		else if (Mchoice == 4)
		{
			POS r;
			r.CALCULATE_SALES();


		}
		
		else {
			Mcontrol = 1;
		}
	} while (Mcontrol != 1);
}
	
