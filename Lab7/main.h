#ifndef MAIN_H
#define MAIN_H

typedef struct restPlace
{
    int added;
    char name[100];
    char address[100];
    char activity[100];
    char time[100];
    char comment[1000];
} RestPlace;

typedef struct nodeRP
{
    RestPlace data;
    struct nodeRP *next;
    struct nodeRP *prev;
} NodeRP;

typedef struct restPlaces
{
    NodeRP *head;
    NodeRP *tail;
    int size;
} RestPlaces;

typedef struct monument
{
    int added;
    char name[100];
    char address[100];
    char description[1000];
    char comment[1000];
} Monument;

typedef struct nodeM
{
    Monument data;
    struct nodeM *next;
    struct nodeM *prev;
} NodeM;

typedef struct monuments
{
    NodeM *head;
    NodeM *tail;
    int size;
} Monuments;

typedef struct city
{
    int added;
    char name[100];
    RestPlaces restPlaces;
    Monuments monuments;
} City;

typedef struct nodeC
{
    City data;
    struct nodeC *next;
    struct nodeC *prev;
} NodeC;

typedef struct cities
{
    NodeC *head;
    NodeC *tail;
    int size;
} Cities;

RestPlaces RestPlacesCreate();
void RestPlacesAdd(RestPlaces *list, RestPlace data);
Monuments MonumentsCreate();
void MonumentsAdd(Monuments *list, Monument data);
Cities CitiesCreate();
void CitiesAdd(Cities *list, City data);
int ListCities(Cities cities, int check);
int CityPrint(Cities cities, char *name, int check, int hotel);
NodeC *FindCity(Cities cities, char *name);
int FindPlace(Cities cities, char *name);
void AddToBook(Cities *cities, char *name, char *comment);

#endif
