/************************************************************************
* car.h: Enumeration och funktionsdeklarationer till funktioner för bil.
*************************************************************************/
#ifndef CAR_H_
#define CAR_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> 
#include <stdbool.h>

/*Enumerationer*/
enum car_transmission {NONE, MANUAL,AUTOMATIC};

/* Strukt för bil */
typedef struct
{
	char* brand;
	char* model;
	char* color;
	uint16_t year_of_launch;
	enum car_transmission transmission;

}car;

/* Funktions deklarationer */

void car_init(car* self,
	char* brand,
	char* model,
	char* color,
	unsigned int year,
	enum car_transmission transmission);

void car_clear(car* self);

car* car_new(char* brand,
	char* model,
	char* color,
	unsigned int year,
	enum car_transmission transmission);

void car_delete(car** self);

void car_print(car* self,
	FILE* ostream);

void car_change_color(car* self,
	char* color);

void car_change_transmission(car* self);

int file_read(const char* filepath);

#endif /* CAR_H_ */
