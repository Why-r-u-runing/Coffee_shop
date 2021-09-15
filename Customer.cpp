#pragma once
#include "Header.h"

Customer::Customer(string login, string password, unsigned visits, ACTIVE state) : User(login, password, state), _count_visits(visits) {}

Customer::Customer(const Customer& customer) : User(customer._login, customer._password, customer._state), _count_visits(customer._count_visits) {}
