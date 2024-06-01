#include <cstdio>
#include <cstdlib>

size_t prompt(void);
double *prompt(size_t const numel);
void cubic(size_t const numel, double *ary);
void disp(size_t const numel, double const *ary, char const *msg);
double *clear(double *ary);

int main ()
{
	size_t const numel = prompt();
	double *ary = prompt(numel);
	disp(numel, ary, "initial array:");
	cubic(numel, ary);
	disp(numel, ary, "modified array (raised to a power of three):");
	ary = clear(ary);
	return 0;
}

size_t prompt (void)
{
	size_t numel = 0;
	printf("input the number of elements of the array:");
	scanf("%zu", &numel);
	return numel;
}

double *prompt (size_t const numel)
{
	size_t const size = numel * sizeof(double);
	double *ary = (double*) malloc(size);
	double *it = ary;
	for (size_t i = 0; i != numel; ++i) {
		printf("input element number %zu:", i);
		scanf("%lf", it);
		++it;
	}
	return ary;
}

void cubic (size_t const numel, double *ary)
{
	for (size_t i = 0; i != numel; ++i) {
		double const elem = ary[i];
		ary[i] = elem * elem * elem;
	}
}

void disp (size_t const numel, double const *ary, char const *msg)
{
	printf("%s\n", msg);
	for (size_t i = 0; i != numel; ++i) {
		printf("%lf\n", ary[i]);
	}
}

double *clear (double *ary)
{
	free(ary);
	ary = NULL;
	return ary;
}

/*

Functions						June 01, 2024

source: Array.cpp
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
