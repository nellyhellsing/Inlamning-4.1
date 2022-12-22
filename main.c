#include "header.h"

/************************************************************************
* main: I funktionen main definieras tre statiskta objekt. Sedan lagras
*       adresserna till objekten i en array.
*       Innehållet i arrayen skrivs till en fil.
*************************************************************************/
void main()
{
    /* Definition av bil objekt */
        car car1,
        car2,
        car3;

    /* Initierar bil objekten */
    car_init(&car1, "Volvo", "V70", "Black", 1995, MANUAL);
    car_init(&car2, "BWM", "Z3", "Blue", 2001, AUTOMATIC);
    car_init(&car3, "Skoda", "Octavia RS", "White", 2003, MANUAL);

    
    car* cars[] = { &car1, &car2, &car3 };

    /* Ändrar färgen och växellådan */
    car_change_color(&car3, "Green");
    car_change_transmission(&car3);

    /* Innehåll skrivs till angiven fil */
    FILE* ostream = fopen("cars.txt", "w");
    for (int i = 0; i < 3; i++)
    {
        car_print(cars[i], ostream);
        fprintf(ostream, "--------------------------------------------------------------------------\n");
    }
    fclose(ostream);

    /* Läser upp fil */
    file_read("cars.txt");

    return;
}