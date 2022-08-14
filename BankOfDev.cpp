#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "windows.h"

using namespace std;

void header() {
	system("CLS");
	cout << "---------------------------------------------" << endl;
	cout << "              Bank Of DEV                    " << endl;
	cout << "---------------------------------------------" << endl;
}


bool checkLogin(int username, int password) {
	if (username == 1234 && password == 1234) {
		return true;
	}
	return false;
}

void depositeMoney(int &totalMoney) {
	header();
	cout << "\nDeposite Money" << endl;
	cout << "------------------" << endl;
	cout << "Enter your amount:"; int amount; cin >> amount;
	totalMoney += amount;
}
void distribution(int amount) {

	cout << "Cash Notes Values:" << endl;
	if (amount / 2000 >= 1) {
		cout << "2000 X " << (amount / 2000) << endl;
		amount %= 2000;
	}

	if (amount / 500 >= 1) {
		cout << "500 X " << (amount / 500) << endl;
		amount %= 500;
	}

	if (amount / 200 >= 1) {
		cout << "200 X " << (amount / 200) << endl;
		amount %= 200;
	}

	if (amount / 100 >= 1) {
		cout << "100 X " << (amount / 100) << endl;
		amount %= 100;
	}

	if (amount / 50 >= 1) {
		cout << "50 X " << (amount / 50) << endl;
		amount %= 50;
	}

	if (amount / 20 >= 1) {
		cout << "20 X " << (amount / 20) << endl;
		amount %= 20;
	}

	if (amount / 10 >= 1) {
		cout << "10 X " << (amount / 10) << endl;
		amount %= 10;
	}

	if (amount / 5 >= 1) {
		cout << "5 X " << (amount / 5) << endl;
		amount %= 5;
	}

	if (amount / 2 >= 1) {
		cout << "2 X " << (amount / 2) << endl;
		amount %= 2;
	}

	if (amount / 1 >= 1) {
		cout << "1 X " << (amount / 1) << endl;
		amount %= 1;
	}
}

void withdrawalMoney(int &totalMoney) {
	header();
	cout << "\nWithdrawal Money" << endl;
	cout << "------------------" << endl;
	cout << "Avaliable Amount: " << totalMoney << endl;
	cout << "Enter withdrawal amount: "; int amount; cin >> amount;
	if (totalMoney - 500 >= amount) {
		totalMoney -= amount;
		cout << "Remaining Balance: " << totalMoney << endl;
		distribution(amount);

	} else {
		cout << "Insufficient Balance" << endl;
		getch();
		withdrawalMoney(totalMoney);
	}
	getch();

}

void customerDetails(int totalMoney) {
	header();
	cout << "\nCustomer Details" << endl;
	cout << "------------------" << endl;
	cout << "Customer Id: 101" << endl;
	cout << "Name: Dev Nick" << endl;
	cout << "Account No.: 124421" << endl;
	cout << "Account Type: Saving" << endl;
	cout << "Total Money: " << totalMoney << endl;
	getch();
}

void logout() {
	system("CLS");
	cout << "\n\n\n\nLogout";
	for (int i = 0; i < 100; ++i)
	{
		Sleep(1);
		cout << "_";
	}
	cout << "BYE :)";
	Sleep(2);
	exit(0);
}


void dashboard(int totalMoney) {

	bool flag = true;
	while (flag) {


		header();
		cout << "---------------------------------------------" << endl;
		cout << "                 WELCOME                   " << endl;
		cout << "---------------------------------------------" << endl;
		cout << "\nMenu" << endl;
		cout << "------" << endl;
		cout << "Press 1 For Customer Details" << endl;
		cout << "Press 2 For Withdrawal Money" << endl;
		cout << "Press 3 For Deposite Money" << endl;
		cout << "Press 4 For Logout" << endl;
		cout << "\n_____________________________";
		cout << "\nEnter Your Choice:";
		int choice; cin >> choice;


		switch (choice) {
		case 1: customerDetails(totalMoney);
			break;
		case 2: withdrawalMoney(totalMoney);
			break;
		case 3: depositeMoney(totalMoney);
			break;
		case 4: logout();
			break;
		default:
			cout << "Please Enter Valid Choice" << endl;

		}

	}

}

void login() {
	cout << "LOGIN" << endl;
	cout << "-----" << endl;
	int username, password;
	cout << "Enter Username: "; cin >> username;
	cout << "Enter Password: "; cin >> password;
	if (checkLogin(username, password)) {
		dashboard(5000);
	} else {
		cout << "\nUsername and Password Are Wrong!!!!";
	}
}
int main()
{
	header();
	login();

	return 0;
}




