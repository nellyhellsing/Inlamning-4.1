#include "header.h"
/********************************************************************************
* car_init: Initierar ny bil.
*
*              self: Pekare till bilen som ska initieras.
*              band: Bilm�rke.
*              model: Bilmodell.
*              color: F�rg p� bilen.
*              year: �ret den tillverkades.
*              transmission: V�xell�da
********************************************************************************/
void car_init(car* self,
	char* brand,
	char* model,
	char* color,
	unsigned int year,
	enum car_transmission transmission)
{
	self->brand = brand;
	self->model = model;
	self->color = color;
	self->year_of_launch = year;
	self->transmission = transmission;

	return;
}
/********************************************************************************
* car_clear: Nollst�ller bil.
*          - self: Pekare till bilen som ska nollst�llas.
********************************************************************************/
void car_clear(car* self)
{
	self->brand = 0;
	self->model = 0;
	self->color = 0;
	self->year_of_launch = 0;
	self->transmission = NONE;

	return;
}
/********************************************************************************
* car_new: Returnerar en pekare till car-objekt, som initieras
*          via funktionen car_init.
********************************************************************************/
car* car_new(char* brand,
	           char* model,
	           char* color,
	           unsigned int year,
	           enum car_transmission transmission)
{
	car* self = malloc(sizeof(car));
	car_init(self, brand, model, color, year, transmission);

	return self;
}
/********************************************************************************
* car_delete: Raderar car-objekt genom att frig�ra minnet. Pekaren
*             till car-objekte s�ttas till null.
********************************************************************************/
void car_delete(car** self)
{
	car_clear(*self);
	free(*self);
	*self = NULL;
}
/********************************************************************************
* car_print: Skriver ut information om given bil.
*********************************************************************************/
void car_print(car* self, FILE* ostream)
{
	if (!ostream) ostream = stdout;

	fprintf(ostream, "Brand: %s\nModel: %s\nColor: %s\nYear of launch: %u\nTransmission: ",
		self->brand, self->model, self->color, self->year_of_launch);
	
	switch (self->transmission)
	{
	   case MANUAL:
		fprintf(ostream, "Manual\n");
		break;
	  case AUTOMATIC:
		fprintf(ostream, "Automatic\n");
		break;
	}
	return;
}
/**********************************************************************************
* car_change_color: �ndrar bilens f�rg till en ny f�rg.
***********************************************************************************/
void car_change_color(car* self,
	                  char* color)
{
	self->color = color;
	return;
}
/********************************************************************************
* car_change_transmission: �ndrar bilens v�xell�da fr�n manuell till automat
*                          eller viseversa.
********************************************************************************/
void car_change_transmission(car* self)
{

	if (self->transmission == MANUAL)
	{
		self->transmission = AUTOMATIC;
	}
	else
	{
		self->transmission = MANUAL;
	}
	return;
}

