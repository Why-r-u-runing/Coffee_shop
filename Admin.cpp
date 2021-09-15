#pragma once
#include "Header.h"

Admin::Admin(string login, string password, ACTIVE state) : User(login, password, state) {}

Admin::Admin(const Admin& admin) : User(admin._login, admin._password, admin._state) {}

void Admin::change_login(string login)
{
	login = login;
}

void Admin::change_password(string password)
{
	password = password;
}

void Admin::change_data(string login, string password)
{
	change_login(login);
	change_password(password);
}
