// DEVNOTES:
//
// The problem statement should have defined the following asymmetric ranges:
//
// [0, WEIGHT_LIGHT),
// [WEIGHT_LIGHT, WEIGHT_BASIC),
// [WEIGHT_BASIC, WEIGHT_HEAVY), (THIS ONE IS MISSING FROM THE PROBLEM STATEMENT)
// [WEIGHT_HEAVY, INFINITY)
//
// This program accounts for the missing logic in its own way since it has been
// left to the programmer to decide and that is expressed in the code itself.
//
// There's also the issue of the charges by weight differences see notes below:
//
// The extra charge by weight difference must be defined with respect to the lower
// bound for each case so the problem statement is missing (again) program logic so
// we have added our own parameters to account for the missing data.
//

#include <cstdio>

#define WEIGHT_LIGHT 10.0
#define WEIGHT_BASIC 30.0
#define WEIGHT_HEAVY 50.0

#define SHIPPING_COST_LIGHT 28.0e3
#define SHIPPING_COST_BASIC 34.0e3
#define SHIPPING_COST_HEAVY 60.0e3

#define SHIPPING_COST_RELATIVE_TO_WEIGHT_LIGHT 1.6e3
#define SHIPPING_COST_RELATIVE_TO_WEIGHT_BASIC 1.9e3
#define SHIPPING_COST_RELATIVE_TO_WEIGHT_HEAVY 2.2e3

// DEVNOTE: passing parameter `weight` by value to constructor to meet design requirements
struct Item {
	double weight;
	double shippingCost;
	Item(double item_weight);
	void logShippingCost() const;
	void calcShippingCost();
};

double prompt(void);

int main ()
{
	double weight = prompt();
	Item item(weight);
	item.calcShippingCost();
	item.logShippingCost();
	return 0;
}

double prompt (void)
{
	double weight = 0;
	printf("input item weight:");
	scanf("%lf", &weight);
	return weight;
}

Item::Item(double item_weight): weight(item_weight)
{
	return;
}

void Item::calcShippingCost()
{
	double const weight = this->weight;
	if (weight < WEIGHT_LIGHT) {
		this->shippingCost = SHIPPING_COST_LIGHT;
	} else if ((weight >= WEIGHT_LIGHT) && (weight < WEIGHT_BASIC)) {
		double const weight_light = WEIGHT_LIGHT;
		double const weight_diff = (weight - weight_light);
		double const cost = SHIPPING_COST_BASIC;
		double const costByWeightDiff = SHIPPING_COST_RELATIVE_TO_WEIGHT_LIGHT;
		this->shippingCost = (cost + (weight_diff * costByWeightDiff));
	} else if ((weight >= WEIGHT_BASIC) && (weight < WEIGHT_HEAVY)) {
		double const weight_basic = WEIGHT_BASIC;
		double const weight_diff = (weight - weight_basic);
		double const cost = SHIPPING_COST_BASIC;// DEVNOTE: we really mean this
		double const costByWeightDiff = SHIPPING_COST_RELATIVE_TO_WEIGHT_BASIC;
		this->shippingCost = (cost + (weight_diff * costByWeightDiff));
	} else {
		double const weight_heavy = WEIGHT_HEAVY;
		double const weight_diff = (weight - weight_heavy);
		double const cost = SHIPPING_COST_HEAVY;
		double const costByWeightDiff = SHIPPING_COST_RELATIVE_TO_WEIGHT_HEAVY;
		this->shippingCost = (cost + (weight_diff * costByWeightDiff));
	}
}

void Item::logShippingCost() const
{
	printf("shipping-cost: $%.2f\n", this->shippingCost);
}

/*

Functions						June 01, 2024

source: Cart.cpp
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
