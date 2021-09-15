#pragma once
#include "Header.h"

ostream& operator<<(ostream& os, const Coffee& coffee)
{
	os << "Name: " << coffee.name << endl;
	os << "Price: " << coffee.price << endl;

	return os;
}

ostream& operator<<(ostream& os, const vector<Coffee>& coffee)
{
	for (auto i = 0; i < coffee.size(); i++)
	{
		cout << "#" << i + 1 << endl;
		cout << coffee[i] << endl;
	}

	return os;
}

ostream& operator<<(ostream& os, const Additive& additive)
{
	os << "Name: " << additive.name << endl;
	os << "Price: " << additive.price << endl;

	return os;
}

ostream& operator<<(ostream& os, const vector<Additive>& additive)
{
	for (auto i = 0; i < additive.size(); i++)
	{
		cout << "#" << i + 1 << endl;
		cout << additive[i] << endl;
	}

	return os;
}

ostream& operator<<(ostream& os, const Customer& customer)
{
	os << "Login: " << customer._login << endl;

	return os;
}

ostream& operator<<(ostream& os, const vector<Customer>& customer)
{
	for (auto i = 0; i < customer.size(); i++)
	{
		cout << "#" << i + 1 << endl;
		cout << customer[i] << endl;
	}

	return os;
}

void start(Coffee_shop& coffee_shop)
{
	int choose;

	Buffer buffer;

	switch (main_login_menu(coffee_shop))
	{
	case 0:
		return;
	case 1:
		while (true)
		{
			system("pause");
			system("cls");
			admin_main_menu();
			cin >> choose;
			system("cls");

			switch (choose)
			{
			case 1:
				cout << "Enter name: ";
				cin >> buffer.string_[0];

				cout << "Enter price: ";
				cin >> buffer.float_;

				try
				{
					coffee_shop.add_coffee(buffer.string_[0], buffer.float_);
				}
				catch (const std::exception& ex)
				{
					cout << ex.what() << endl;
				}

				break;
			case 2:
				coffee_shop.show_coffee();
				cout << "Enter # of coffee\n> ";
				cin >> buffer.int_;

				try
				{
					coffee_shop.remove_coffee(buffer.int_ - 1);
				}
				catch (const std::exception& ex)
				{
					cout << ex.what() << endl;
				}

				break;
			case 3:
				coffee_shop.show_coffee();
				cout << "Enter # of coffee\n> ";
				cin >> buffer.int_;
				system("cls");
				cout << "Enter new price\n> ";
				cin >> buffer.float_;

				try
				{
					coffee_shop.change_coffee_price(buffer.int_ - 1, buffer.float_);
				}
				catch (const std::exception& ex)
				{
					cout << ex.what() << endl;
				}

				break;
			case 4:
				coffee_shop.show_coffee();
				break;
			case 5:
				cout << "Enter name: ";
				cin >> buffer.string_[0];

				cout << "Enter price: ";
				cin >> buffer.float_;

				try
				{
					coffee_shop.add_additive(buffer.string_[0], buffer.float_);
				}
				catch (const std::exception& ex)
				{
					cout << ex.what() << endl;
				}

				break;
			case 6:
				coffee_shop.show_additives();
				cout << "Enter # of additive\n> ";
				cin >> buffer.int_;

				try
				{
					coffee_shop.remove_additive(buffer.int_ - 1);
				}
				catch (const std::exception& ex)
				{
					cout << ex.what() << endl;
				}

				break;
			case 7:
				coffee_shop.show_additives();
				cout << "Enter # of additive\n> ";
				cin >> buffer.int_;
				system("cls");
				cout << "Enter new price\n> ";
				cin >> buffer.float_;

				try
				{
					coffee_shop.change_additive_price(buffer.int_ - 1, buffer.float_);
				}
				catch (const std::exception& ex)
				{
					cout << ex.what() << endl;
				}

				break;
			case 8:
				coffee_shop.show_additives();
				break;
			case 9:
				cout << "Enter login: ";
				cin >> buffer.string_[0];

				cout << "Enter password: ";
				cin >> buffer.string_[1];

				try
				{
					coffee_shop.add_customer(*(new Customer(buffer.string_[0], buffer.string_[1])));
				}
				catch (const std::exception& ex)
				{
					cout << ex.what() << endl;
				}

				break;
			case 10:
				coffee_shop.show_customers();
				cout << "Enter # of customer\n> ";
				cin >> buffer.int_;

				try
				{
					coffee_shop.remove_customer(buffer.int_ - 1);
				}
				catch (const std::exception& ex)
				{
					cout << ex.what() << endl;
				}

				break;
			case 11:
				coffee_shop.show_customers();
				break;
			case 12:
				cout << "Enter login: ";
				cin >> buffer.string_[0];

				try
				{
					coffee_shop.get_admin()->change_login(buffer.string_[0]);
				}
				catch (const std::exception& ex)
				{
					cout << ex.what() << endl;
				}

				break;
			case 13:
				cout << "Enter password: ";
				cin >> buffer.string_[0];

				try
				{
					coffee_shop.get_admin()->change_password(buffer.string_[0]);
				}
				catch (const std::exception& ex)
				{
					cout << ex.what() << endl;
				}

				break;
			case 14:
				cout << "Enter login: ";
				cin >> buffer.string_[0];

				cout << "Enter password: ";
				cin >> buffer.string_[1];

				try
				{
					coffee_shop.get_admin()->change_data(buffer.string_[0], buffer.string_[1]);
				}
				catch (const std::exception& ex)
				{
					cout << ex.what() << endl;
				}

				break;
			case 15:
				cout << "Do you want to save changes?<y> or <n>: ";
				cin >> buffer.char_;

				if (buffer.char_ == 'y')
					coffee_shop.exit();

				return;
			}
		}
		break;
	case 2:
		while (true)
		{
			system("pause");
			system("cls");
			customer_main_menu();
			cin >> choose;
			system("cls");

			switch (choose)
			{
			case 1:
				make_order(coffee_shop);
				break;
			case 2:
				coffee_shop.exit();
				return;
			}
		}
		break;
	}
}

int main_login_menu(Coffee_shop& coffee_shop)
{
	cout << "1. Admin\n2. Customer\n> ";
	int choose;
	cin >> choose;

	switch (choose)
	{
	case 1:
		try
		{
			admin_login_menu(*(coffee_shop._admin));
			return 1;
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl;
		}
		break;
	case 2:
		try
		{
			customer_pre_login_menu(coffee_shop._customers);
			return 2;
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl;
		}
		break;
	default:
		break;
	}
	return 0;
}

void admin_login_menu(Admin& admin)
{
	system("cls");
	cout << "Login: ";
	string tmp_login;
	cin >> tmp_login;

	cout << "Password: ";
	string tmp_password;
	cin >> tmp_password;

	if (admin._login == tmp_login && admin._password == tmp_password)
	{
		cout << "Success!" << endl;
		admin._state = ACTIVE::ON;
	}
	else
		throw exception("Incorrect login or password!");
}

void customer_pre_login_menu(vector<Customer>& customers)
{
	system("cls");
	cout << "1. Log in\n2. Register\n> ";
	int choose;
	cin >> choose;

	switch (choose)
	{
	case 1:
		customer_login_menu(customers);
		break;
	case 2:
		customer_create_menu(customers);
		break;
	default:
		break;
	}
}

void customer_login_menu(vector<Customer>& customers)
{
	system("cls");
	cout << "Login: ";
	string tmp_login;
	cin >> tmp_login;

	cout << "Password: ";
	string tmp_password;
	cin >> tmp_password;

	for (auto& customer : customers)
	{
		if (customer._login == tmp_login && customer._password == tmp_password)
		{
			cout << "Success!" << endl;
			customer._state = ACTIVE::ON;
			return;
		}
	}
	throw exception("Incorrect login or password!");
}

void customer_create_menu(vector<Customer>& customers)
{
	system("cls");
	cout << "Enter login\n> ";
	string tmp_login;
	cin >> tmp_login;

	for (auto& customer : customers)
	{
		if (customer._login == tmp_login)
			throw exception("Login is busy!");
	}

	cout << "Enter password\n> ";
	string tmp_password;
	cin >> tmp_password;

	customers.push_back(Customer(tmp_login, tmp_password, 0, ACTIVE::ON));
	cout << "Success!" << endl;
}

void admin_main_menu()
{
	cout << "1. Add new coffee\n2. Remove coffee\n3. Change coffee price\n4. Show coffee" << endl << endl;
	cout << "5. Add additive\n6. Remove additive\n7. Change additive price\n8. Show additive" << endl << endl;
	cout << "9. Add customer\n10. Remove customer\n11. Show customers" << endl << endl;
	cout << "12. Change login\n13. Change password\n14. Change both\n15. Exit\n> ";
}

void customer_main_menu()
{
	cout << "1. Make order\n2. Exit\n> ";
}

void make_order(Coffee_shop& coffee_shop)
{
	system("cls");
	coffee_shop.show_coffee();
	cout << "Choose #\n> ";
	int tmp_index;
	cin >> tmp_index;

	if (tmp_index <= 0 || tmp_index > coffee_shop._coffee.size())
		throw exception("Out of range!");
	Coffee coffee(coffee_shop._coffee[tmp_index - 1]);

	system("cls");
	coffee_shop.show_additives();
	cout << "Choose <0> if you don`t want any additives" << endl;
	cout << "Choose #\n> ";
	cin >> tmp_index;

	vector<Additive> additives;

	if (tmp_index)
	{
		if (tmp_index <= 0 || tmp_index > coffee_shop._additives.size())
			throw exception("Out of range!");
		additives.push_back(Additive(coffee_shop._additives[tmp_index - 1]));

		system("cls");
		cout << "Do you want extra additive?<y> or <n>:	";
		char tmp_char;
		cin >> tmp_char;

		switch (tmp_char)
		{
		case 'y':
			system("cls");
			coffee_shop.show_additives();
			cout << "Choose extra #\n> ";
			cin >> tmp_index;

			if (tmp_index <= 0 || tmp_index > coffee_shop._additives.size())
				throw exception("Out of range!");
			additives.push_back(Additive(coffee_shop._additives[tmp_index - 1]));
			break;
		default:
			additives.push_back(Additive(0, "None"));
			break;
		}
	}
	else
	{
		additives.push_back(Additive(0, "None"));
		additives.push_back(Additive(0, "None"));
	}

	system("cls");

	for (auto& customer : coffee_shop._customers)
	{
		if (customer._state == ACTIVE::ON)
		{
			float price = round((coffee.price + additives[0].price + additives[1].price) * 100) / 100;
			float discount = round(((customer._count_visits >= 5 ? customer._count_visits >= 10 ? customer._count_visits >= 15 ? 25 : 15 : 5 : 0) * (price / 100)) * 100) / 100;
			float total_price = round((price - discount) * 100) / 100;

			cout << "Price: " << price << "$" << endl;
			cout << "Discount: " << discount << "$" << endl;
			cout << "Total price: " << total_price << "$" << endl;
			cout << "Press any button to pay" << endl;
			customer._count_visits++;
			coffee_shop.log(customer, coffee, additives, total_price);
		}
	}
}

string& get_current_time()
{
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
	string* s = new string(buffer);

	return *s;
}