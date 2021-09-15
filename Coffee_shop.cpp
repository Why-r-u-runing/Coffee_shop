#pragma once
#include "Header.h"

Coffee_shop::Coffee_shop()
{
	login();
}

void Coffee_shop::log(Customer& customer, Coffee& coffee, vector<Additive>& additives, float total_price)
{
	ofstream fout;
	fout.exceptions(ofstream::badbit);
	fout.open("log.txt", ofstream::app);

	fout << "Time: " << get_current_time() << "; Customer: " << customer._login <<
		"; Coffee name: " << coffee.name <<	"; Additive #1: " << additives[0].name <<
		"; Additive #2: " << additives[1].name << "; Total price: " << total_price << "$;" << endl;

	fout.close();
}

void Coffee_shop::login()
{
	ifstream fin;
	fin.exceptions(ifstream::badbit);
	fin.open("admin.txt");

	string tmp_login;
	fin >> tmp_login;

	string tmp_password;
	fin >> tmp_password;

	_admin = make_shared<Admin>(tmp_login, tmp_password);

	fin.close();

	fin.open("customers.txt");

	tmp_login.clear();
	tmp_password.clear();

	unsigned tmp_visits;
	while (!fin.eof())
	{
		fin >> tmp_login;
		fin >> tmp_password;
		fin >> tmp_visits;
		_customers.push_back(Customer(tmp_login, tmp_password, tmp_visits));
		tmp_login.clear();
		tmp_password.clear();
	}
	_customers.pop_back();

	fin.close();

	fin.open("coffee.txt");

	tmp_login.clear();
	tmp_password.clear();

	float tmp_float;
	while (!fin.eof())
	{
		fin >> tmp_float;
		fin >> tmp_login;
		_coffee.push_back(Coffee(tmp_float, tmp_login));
		tmp_login.clear();
	}
	_coffee.pop_back();

	fin.close();

	fin.open("additive.txt");

	tmp_login.clear();
	tmp_password.clear();

	while (!fin.eof())
	{
		fin >> tmp_float;
		fin >> tmp_login;
		_additives.push_back(Additive(tmp_float, tmp_login));
		tmp_login.clear();
	}
	_additives.pop_back();

	fin.close();
}

void Coffee_shop::exit()
{
	ofstream fout;
	fout.exceptions(ofstream::badbit);
	fout.open("admin.txt");

	fout << _admin->_login << ' ' << _admin->_password;

	fout.close();

	fout.open("customers.txt");

	for (auto customer : _customers)
	{
		fout << customer._login << ' ' << customer._password << ' ' << customer._count_visits << endl;
	}

	fout.close();

	fout.open("coffee.txt");

	for (auto coffee : _coffee)
	{
		fout << coffee.price << ' ' << coffee.name << endl;
	}

	fout.close();

	fout.open("additive.txt");

	for (auto additive : _additives)
	{
		fout << additive.price << ' ' << additive.name << endl;
	}

	fout.close();
}

void Coffee_shop::add_coffee(string name, float price)
{
	for (auto element : _coffee)
	{
		if (element.name == name)
			throw exception("Coffee already exist!");
	}
	_coffee.push_back(Coffee(price, name));
}

void Coffee_shop::remove_coffee(int index)
{
	if (index < 0 || index >= _coffee.size())
		throw exception("Out of range!");

	_coffee.erase(_coffee.begin() + index);
}

void Coffee_shop::change_coffee_price(int index, float price)
{
	if (index < 0 || index >= _coffee.size())
		throw exception("Out of range!");

	_coffee[index].price = price;
}

void Coffee_shop::add_additive(string name, float price)
{
	for (auto element : _additives)
	{
		if (element.name == name)
			throw exception("Additive already exist!");
	}
	_additives.push_back(Additive(price, name));
}

void Coffee_shop::remove_additive(int index)
{
	if (index < 0 || index >= _additives.size())
		throw exception("Out of range!");

	_additives.erase(_additives.begin() + index);
}

void Coffee_shop::change_additive_price(int index, float price)
{
	if (index < 0 || index >= _additives.size())
		throw exception("Out of range!");

	_additives[index].price = price;
}

void Coffee_shop::add_customer(Customer& customer)
{
	for (auto element : _customers)
	{
		if (element._login == customer._login)
			throw exception("Customer already exist!");
	}
	_customers.push_back(Customer(customer._login, customer._password, customer._count_visits, ACTIVE::ON));
}

void Coffee_shop::remove_customer(int index)
{
	if (index < 0 || index >= _customers.size())
		throw exception("Out of range!");

	_customers.erase(_customers.begin() + index);
}

void Coffee_shop::show_coffee()
{
	cout << _coffee << endl;
}

void Coffee_shop::show_additives()
{
	cout << _additives << endl;
}

void Coffee_shop::show_customers()
{
	cout << _customers << endl;
}

shared_ptr<Admin>& Coffee_shop::get_admin()
{
	if (_admin->_state == ACTIVE::ON)
		return _admin;
	throw exception("You need to log in!");
}
