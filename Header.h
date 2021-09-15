#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Buffer
{
	Buffer() : int_(0), float_(0), char_(0), string_(2) {}
	int int_;
	float float_;
	char char_;
	vector<string> string_;
};

enum class ACTIVE
{
	OFF,
	ON
};

class Coffee_shop;
class Admin;
class Customer;

struct Coffee
{
	Coffee(float = 0, string = "None");

	float price;
	string name;
};

struct Additive
{
	Additive(float = 0, string = "None");

	float price;
	string name;
};

struct User
{
	User(string = "Default", string = "Default", ACTIVE = ACTIVE::OFF);
	User(const User&);

protected:
	string _login;
	string _password;
	ACTIVE _state;
};

class Coffee_shop
{
public:
	Coffee_shop();

	void log(Customer&, Coffee&, vector<Additive>&, float);

	void login();
	void exit();

	void add_coffee(string, float);
	void remove_coffee(int);
	void change_coffee_price(int, float);
	void show_coffee();

	void add_additive(string, float);
	void remove_additive(int);
	void change_additive_price(int, float);
	void show_additives();

	void add_customer(Customer&);
	void remove_customer(int);
	void show_customers();

	shared_ptr<Admin>& get_admin();

	friend void make_order(Coffee_shop&);
	friend int main_login_menu(Coffee_shop&);
	friend ostream& operator<<(ostream&, const Coffee&);
	friend ostream& operator<<(ostream&, const Additive&);
private:
	shared_ptr<Admin> _admin;
	vector<Customer> _customers;
	vector<Coffee> _coffee;
	vector<Additive> _additives;
};

class Customer : protected User
{
public:
	Customer(string = "Guest", string = "Guest", unsigned = 0, ACTIVE = ACTIVE::OFF);
	Customer(const Customer&);

	friend void Coffee_shop::exit();
	friend void Coffee_shop::log(Customer&, Coffee&, vector<Additive>&, float);
	friend void customer_login_menu(vector<Customer>&);
	friend void customer_create_menu(vector<Customer>&);
	friend void make_order(Coffee_shop&);

	friend ostream& operator<<(ostream&, const Customer&);

	friend void Coffee_shop::add_customer(Customer&);
private:
	unsigned _count_visits;
};

class Admin : protected User
{
public:
	Admin(string = "Default", string = "Default", ACTIVE = ACTIVE::OFF);
	Admin(const Admin&);

	void change_login(string);
	void change_password(string);
	void change_data(string, string);

	friend void Coffee_shop::exit();
	friend void Coffee_shop::log(Customer&, Coffee&, vector<Additive>&, float);
	friend void admin_login_menu(Admin&);
	friend shared_ptr<Admin>& Coffee_shop::get_admin();
};

ostream& operator<<(ostream&, const Coffee&);
ostream& operator<<(ostream&, const vector<Coffee>&);

ostream& operator<<(ostream&, const Additive&);
ostream& operator<<(ostream&, const vector<Additive>&);

ostream& operator<<(ostream&, const Customer&);
ostream& operator<<(ostream&, const vector<Customer>&);

void start(Coffee_shop&);

int main_login_menu(Coffee_shop&);
void admin_login_menu(Admin&);
void customer_pre_login_menu(vector<Customer>&);
void customer_login_menu(vector<Customer>&);
void customer_create_menu(vector<Customer>&);

void admin_main_menu();
void customer_main_menu();

void make_order(Coffee_shop&);

string& get_current_time();