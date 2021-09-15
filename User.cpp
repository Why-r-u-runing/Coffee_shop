#pragma once
#include "Header.h"

User::User(string login, string password, ACTIVE state) : _login(login), _password(password), _state(state) {}

User::User(const User& user)
{
	_login = user._login;
	_password = user._password;
	_state = user._state;
}
