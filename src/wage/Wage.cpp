#include <cstdio>
#include <cstdlib>

#define WORKED_YEARS_JUNIOR 5.0
#define WORKED_YEARS_SENIOR 10.0

#define WAGE_FRACTION_RAISE_JUNIOR 0.06
#define WAGE_FRACTION_RAISE_MIDDLE 0.08
#define WAGE_FRACTION_RAISE_SENIOR 0.10

// DEVNOTE: passing primitive parameters by reference to meet program design requirements
struct Employee {
	double workedYears;
	double currentWage;
	double percentageRaiseWage;
	Employee(double const& employee_worked_years,
		 double const& employee_current_wage);
	void *operator new(size_t size);
	void operator delete(void *vp);
	void setPercentageRaiseWage();
	void logWage() const;
	void updateWage();
};

struct Roster {
	int num_employees = 0;
	Employee **employees = NULL;
	double totalShippingCost = 0;
	Roster(int& num_employees, Employee **employees);
	void *operator new(size_t size);
	void operator delete(void *vp);
	void setPercentageRaiseWageEmployees();
	void logEmployeeWages() const;
	void updateWageEmployees();
	void promptInfoEmployees();
};

int prompt_num_employees(void);

int main ()
{
	int num_employees = prompt_num_employees();
	size_t const size = num_employees * sizeof(Employee*);
	Employee **employees = (Employee**) malloc(size);
	Roster *roster = new Roster(num_employees, employees);
	roster->promptInfoEmployees();
	roster->setPercentageRaiseWageEmployees();
	roster->updateWageEmployees();
	roster->logEmployeeWages();
	delete(roster);
	roster = NULL;
	return 0;
}

int prompt_num_employees(void)
{
	int num = 0;
	printf("input the number of employees:");
	scanf("%d", &num);
	return num;
}

static void prompt_employee_info (int const& tag,
				  double& worked_years,
				  double& current_wage)
{
	printf("input the worked-years of employee %d:", tag);
	scanf("%lf", &worked_years);
	printf("input the current wage of employee %d:", tag);
	scanf("%lf", &current_wage);
}

Employee::Employee(double const& employee_worked_years,
		   double const& employee_current_wage):
		   workedYears(employee_worked_years),
		   currentWage(employee_current_wage)
{
	return;
}

void *Employee::operator new (size_t size)
{
	return malloc(size);
}

void Employee::operator delete (void *vp)
{
	free(vp);
	vp = NULL;
}

void Employee::setPercentageRaiseWage()
{
	double const wy = this->workedYears;
	if (wy < WORKED_YEARS_JUNIOR) {
		this->percentageRaiseWage = WAGE_FRACTION_RAISE_JUNIOR;
	} else if ((wy >= WORKED_YEARS_JUNIOR) && (wy < WORKED_YEARS_SENIOR)) {
		this->percentageRaiseWage = WAGE_FRACTION_RAISE_MIDDLE;
	} else {
		this->percentageRaiseWage = WAGE_FRACTION_RAISE_SENIOR;
	}
}

void Employee::updateWage()
{
	this->currentWage += (this->currentWage * this->percentageRaiseWage);
}

void Employee::logWage() const
{
	printf("wage: $%.2f\n", this->currentWage);
}

Roster::Roster (int& num_employees, Employee **employees) : num_employees(num_employees)
{
	this->employees = employees;
}

void *Roster::operator new (size_t size)
{
	return malloc(size);
}

void Roster::operator delete (void *vp)
{
	Roster *p = (Roster*) vp;
	for (int i = 0; i != p->num_employees; ++i) {
		free(p->employees[i]);
		p->employees[i] = NULL;
	}
	free(p->employees);
	p->employees = NULL;
	free(p);
	p = NULL;
	vp = NULL;
}

void Roster::promptInfoEmployees ()
{
	for (int i = 0; i != this->num_employees; ++i) {
		int const tag = i;
		double worked_years = 0;
		double current_wage = 0;
		prompt_employee_info(tag, worked_years, current_wage);
		this->employees[i] = new Employee(worked_years, current_wage);
	}
}

void Roster::setPercentageRaiseWageEmployees()
{
	for (int i = 0; i != this->num_employees; ++i) {
		Employee *employee = this->employees[i];
		employee->setPercentageRaiseWage();
	}
}

void Roster::updateWageEmployees ()
{
	for (int i = 0; i != this->num_employees; ++i) {
		Employee *employee = this->employees[i];
		employee->updateWage();
	}
}

void Roster::logEmployeeWages () const
{
	for (int i = 0; i != this->num_employees; ++i) {
		Employee *employee = this->employees[i];
		employee->logWage();
	}
}

/*

Functions						June 01, 2024

source: Wage.cpp
author: @misael-diaz

Copyright (C) 2024 Misael Díaz-Maldonado

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

References:

[0] https://en.cppreference.com/w/cpp

*/
