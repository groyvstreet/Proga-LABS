#include <stdio.h>
#include "main.h"
#include <string.h>
#include <assert.h>

void TestRestPlacesCreate()
{
    RestPlaces rp;
    rp = RestPlacesCreate();
    assert(rp.head == NULL);
    assert(rp.tail == NULL);
    assert(rp.size == 0);
    rp.size = 10;
    rp = RestPlacesCreate();
    assert(rp.head == NULL);
    assert(rp.tail == NULL);
    assert(rp.size == 0);
}

void TestMonumentsCreate()
{
    Monuments m;
    m = MonumentsCreate();
    assert(m.head == NULL);
    assert(m.tail == NULL);
    assert(m.size == 0);
    m.size = 10;
    m = MonumentsCreate();
    assert(m.head == NULL);
    assert(m.tail == NULL);
    assert(m.size == 0);
}

void TestCitiesCreate()
{
    Cities c;
    c = CitiesCreate();
    assert(c.head == NULL);
    assert(c.tail == NULL);
    assert(c.size == 0);
    c.size = 10;
    c = CitiesCreate();
    assert(c.head == NULL);
    assert(c.tail == NULL);
    assert(c.size == 0);
}

void TestRestPlacesAdd()
{
    RestPlaces list;
    RestPlace rp;

    list = RestPlacesCreate();
    rp.added = 0;
    strcpy(rp.name, "name");
    strcpy(rp.address, "address");
    strcpy(rp.activity, "act");
    strcpy(rp.time, "time");
    strcpy(rp.comment, "comment");
    RestPlacesAdd(&list, rp);
    assert(list.head->data.added == 0);
    assert(strcmp(list.head->data.name, "name") == 0);
    assert(strcmp(list.head->data.address, "address") == 0);
    assert(strcmp(list.head->data.activity, "act") == 0);
    assert(strcmp(list.head->data.time, "time") == 0);
    assert(strcmp(list.head->data.comment, "comment") == 0);
    rp.added = 1;
    strcpy(rp.name, "name2");
    strcpy(rp.address, "address2");
    strcpy(rp.activity, "act2");
    strcpy(rp.time, "time2");
    strcpy(rp.comment, "comment2");
    RestPlacesAdd(&list, rp);
    assert(list.head->next->data.added == 1);
    assert(strcmp(list.head->next->data.name, "name2") == 0);
    assert(strcmp(list.head->next->data.address, "address2") == 0);
    assert(strcmp(list.head->next->data.activity, "act2") == 0);
    assert(strcmp(list.head->next->data.time, "time2") == 0);
    assert(strcmp(list.head->next->data.comment, "comment2") == 0);
}

void TestMonumentsAdd()
{
    Monuments list;
    Monument m;

    list = MonumentsCreate();
    m.added = 0;
    strcpy(m.name, "name");
    strcpy(m.address, "address");
    strcpy(m.description, "desc");
    strcpy(m.comment, "comment");
    MonumentsAdd(&list, m);
    assert(list.head->data.added == 0);
    assert(strcmp(list.head->data.name, "name") == 0);
    assert(strcmp(list.head->data.address, "address") == 0);
    assert(strcmp(list.head->data.description, "desc") == 0);
    assert(strcmp(list.head->data.comment, "comment") == 0);
    m.added = 1;
    strcpy(m.name, "name2");
    strcpy(m.address, "address2");
    strcpy(m.description, "desc2");
    strcpy(m.comment, "comment2");
    MonumentsAdd(&list, m);
    assert(list.head->next->data.added == 1);
    assert(strcmp(list.head->next->data.name, "name2") == 0);
    assert(strcmp(list.head->next->data.address, "address2") == 0);
    assert(strcmp(list.head->next->data.description, "desc2") == 0);
    assert(strcmp(list.head->next->data.comment, "comment2") == 0);
}

void TestCitiesAdd()
{
    Cities list;
    City c;

    list = CitiesCreate();
    c.added = 0;
    strcpy(c.name, "name");
    CitiesAdd(&list, c);
    assert(list.head->data.added == 0);
    assert(strcmp(list.head->data.name, "name") == 0);
    c.added = 1;
    strcpy(c.name, "name2");
    CitiesAdd(&list, c);
    assert(list.head->next->data.added == 1);
    assert(strcmp(list.head->next->data.name, "name2") == 0);
}

void TestFindCity()
{
    Cities list;
    City c;

    list = CitiesCreate();
    c.added = 0;
    strcpy(c.name, "name");
    CitiesAdd(&list, c);
    c.added = 1;
    strcpy(c.name, "name2");
    CitiesAdd(&list, c);
    assert(FindCity(list, "name") != NULL);
    assert(FindCity(list, "name2") != NULL);
    assert(FindCity(list, "name3") == NULL);
}

void TestFindPlace()
{
    Cities list;
    City city;
    RestPlaces restPlaces;
    RestPlace restPlace;
    Monuments monuments;
    Monument monument;

    restPlaces = RestPlacesCreate();
    restPlace.added = 0;
    strcpy(restPlace.name, "City1_RP1");
    strcpy(restPlace.address, "address");
    strcpy(restPlace.activity, "act");
    strcpy(restPlace.time, "time");
    strcpy(restPlace.comment, "comment");
    RestPlacesAdd(&restPlaces, restPlace);
    restPlace.added = 0;
    strcpy(restPlace.name, "City1_RP2");
    strcpy(restPlace.address, "address");
    strcpy(restPlace.activity, "act");
    strcpy(restPlace.time, "time");
    strcpy(restPlace.comment, "comment");
    RestPlacesAdd(&restPlaces, restPlace);

    monuments = MonumentsCreate();
    monument.added = 0;
    strcpy(monument.name, "City1_M1");
    strcpy(monument.address, "address");
    strcpy(monument.description, "description");
    strcpy(monument.comment, "comment");
    MonumentsAdd(&monuments, monument);
    monument.added = 0;
    strcpy(monument.name, "City1_M2");
    strcpy(monument.address, "address");
    strcpy(monument.description, "description");
    strcpy(monument.comment, "comment");
    MonumentsAdd(&monuments, monument);

    list = CitiesCreate();
    city.added = 0;
    strcpy(city.name, "City1");
    city.restPlaces = restPlaces;
    city.monuments = monuments;
    CitiesAdd(&list, city);

    restPlaces = RestPlacesCreate();
    restPlace.added = 0;
    strcpy(restPlace.name, "City2_RP1");
    strcpy(restPlace.address, "address");
    strcpy(restPlace.activity, "act");
    strcpy(restPlace.time, "time");
    strcpy(restPlace.comment, "comment");
    RestPlacesAdd(&restPlaces, restPlace);
    restPlace.added = 0;
    strcpy(restPlace.name, "City2_RP2");
    strcpy(restPlace.address, "address");
    strcpy(restPlace.activity, "act");
    strcpy(restPlace.time, "time");
    strcpy(restPlace.comment, "comment");
    RestPlacesAdd(&restPlaces, restPlace);

    monuments = MonumentsCreate();
    monument.added = 0;
    strcpy(monument.name, "City2_M1");
    strcpy(monument.address, "address");
    strcpy(monument.description, "description");
    strcpy(monument.comment, "comment");
    MonumentsAdd(&monuments, monument);
    monument.added = 0;
    strcpy(monument.name, "City2_M2");
    strcpy(monument.address, "address");
    strcpy(monument.description, "description");
    strcpy(monument.comment, "comment");
    MonumentsAdd(&monuments, monument);

    city.added = 0;
    strcpy(city.name, "City2");
    city.restPlaces = restPlaces;
    city.monuments = monuments;
    CitiesAdd(&list, city);

    assert(FindPlace(list, "City1_M1") == 1);
    assert(FindPlace(list, "City2_RP1") == 1);
    assert(FindPlace(list, "City2_M1") == 1);
    assert(FindPlace(list, "City1_M3") == 0);
    assert(FindPlace(list, "City3_M1") == 0);
}

void TestAddToBook()
{
    Cities list;
    City city;
    RestPlaces restPlaces;
    RestPlace restPlace;
    Monuments monuments;
    Monument monument;

    restPlaces = RestPlacesCreate();
    restPlace.added = 0;
    strcpy(restPlace.name, "City1_RP1");
    strcpy(restPlace.address, "address");
    strcpy(restPlace.activity, "act");
    strcpy(restPlace.time, "time");
    strcpy(restPlace.comment, "comment");
    RestPlacesAdd(&restPlaces, restPlace);
    restPlace.added = 0;
    strcpy(restPlace.name, "City1_RP2");
    strcpy(restPlace.address, "address");
    strcpy(restPlace.activity, "act");
    strcpy(restPlace.time, "time");
    strcpy(restPlace.comment, "comment");
    RestPlacesAdd(&restPlaces, restPlace);

    monuments = MonumentsCreate();
    monument.added = 0;
    strcpy(monument.name, "City1_M1");
    strcpy(monument.address, "address");
    strcpy(monument.description, "description");
    strcpy(monument.comment, "comment");
    MonumentsAdd(&monuments, monument);
    monument.added = 0;
    strcpy(monument.name, "City1_M2");
    strcpy(monument.address, "address");
    strcpy(monument.description, "description");
    strcpy(monument.comment, "comment");
    MonumentsAdd(&monuments, monument);

    list = CitiesCreate();
    city.added = 0;
    strcpy(city.name, "City1");
    city.restPlaces = restPlaces;
    city.monuments = monuments;
    CitiesAdd(&list, city);

    restPlaces = RestPlacesCreate();
    restPlace.added = 0;
    strcpy(restPlace.name, "City2_RP1");
    strcpy(restPlace.address, "address");
    strcpy(restPlace.activity, "act");
    strcpy(restPlace.time, "time");
    strcpy(restPlace.comment, "comment");
    RestPlacesAdd(&restPlaces, restPlace);
    restPlace.added = 0;
    strcpy(restPlace.name, "City2_RP2");
    strcpy(restPlace.address, "address");
    strcpy(restPlace.activity, "act");
    strcpy(restPlace.time, "time");
    strcpy(restPlace.comment, "comment");
    RestPlacesAdd(&restPlaces, restPlace);

    monuments = MonumentsCreate();
    monument.added = 0;
    strcpy(monument.name, "City2_M1");
    strcpy(monument.address, "address");
    strcpy(monument.description, "description");
    strcpy(monument.comment, "comment");
    MonumentsAdd(&monuments, monument);
    monument.added = 0;
    strcpy(monument.name, "City2_M2");
    strcpy(monument.address, "address");
    strcpy(monument.description, "description");
    strcpy(monument.comment, "comment");
    MonumentsAdd(&monuments, monument);

    city.added = 0;
    strcpy(city.name, "City2");
    city.restPlaces = restPlaces;
    city.monuments = monuments;
    CitiesAdd(&list, city);

    AddToBook(&list, "City1_RP1", "comment1");
    AddToBook(&list, "City2_M2", "comment2");
    assert(list.head->data.added == 1);
    assert(list.head->data.restPlaces.head->data.added == 1);
    assert(strcmp(list.head->data.restPlaces.head->data.comment, "comment1") == 0);
    assert(list.head->next->data.added == 1);
    assert(list.head->next->data.monuments.head->next->data.added == 1);
    assert(strcmp(list.head->next->data.monuments.head->next->data.comment, "comment2") == 0);
}

void TestListCities()
{
    Cities list;
    City city;
    RestPlaces restPlaces;
    RestPlace restPlace;
    Monuments monuments;
    Monument monument;

    restPlaces = RestPlacesCreate();
    restPlace.added = 0;
    strcpy(restPlace.name, "City1_RP1");
    strcpy(restPlace.address, "address");
    strcpy(restPlace.activity, "act");
    strcpy(restPlace.time, "time");
    strcpy(restPlace.comment, "comment");
    RestPlacesAdd(&restPlaces, restPlace);
    restPlace.added = 0;
    strcpy(restPlace.name, "City1_RP2");
    strcpy(restPlace.address, "address");
    strcpy(restPlace.activity, "act");
    strcpy(restPlace.time, "time");
    strcpy(restPlace.comment, "comment");
    RestPlacesAdd(&restPlaces, restPlace);

    monuments = MonumentsCreate();
    monument.added = 0;
    strcpy(monument.name, "City1_M1");
    strcpy(monument.address, "address");
    strcpy(monument.description, "description");
    strcpy(monument.comment, "comment");
    MonumentsAdd(&monuments, monument);
    monument.added = 0;
    strcpy(monument.name, "City1_M2");
    strcpy(monument.address, "address");
    strcpy(monument.description, "description");
    strcpy(monument.comment, "comment");
    MonumentsAdd(&monuments, monument);

    list = CitiesCreate();
    city.added = 0;
    strcpy(city.name, "City1");
    city.restPlaces = restPlaces;
    city.monuments = monuments;
    CitiesAdd(&list, city);

    restPlaces = RestPlacesCreate();
    restPlace.added = 0;
    strcpy(restPlace.name, "City2_RP1");
    strcpy(restPlace.address, "address");
    strcpy(restPlace.activity, "act");
    strcpy(restPlace.time, "time");
    strcpy(restPlace.comment, "comment");
    RestPlacesAdd(&restPlaces, restPlace);
    restPlace.added = 0;
    strcpy(restPlace.name, "City2_RP2");
    strcpy(restPlace.address, "address");
    strcpy(restPlace.activity, "act");
    strcpy(restPlace.time, "time");
    strcpy(restPlace.comment, "comment");
    RestPlacesAdd(&restPlaces, restPlace);

    monuments = MonumentsCreate();
    monument.added = 0;
    strcpy(monument.name, "City2_M1");
    strcpy(monument.address, "address");
    strcpy(monument.description, "description");
    strcpy(monument.comment, "comment");
    MonumentsAdd(&monuments, monument);
    monument.added = 0;
    strcpy(monument.name, "City2_M2");
    strcpy(monument.address, "address");
    strcpy(monument.description, "description");
    strcpy(monument.comment, "comment");
    MonumentsAdd(&monuments, monument);

    city.added = 0;
    strcpy(city.name, "City2");
    city.restPlaces = restPlaces;
    city.monuments = monuments;
    CitiesAdd(&list, city);

    assert(ListCities(list, 0) == 0);
    assert(ListCities(list, 1) == 1);
    list.head->data.added = 1;
    assert(ListCities(list, 1) == 0);
}

void TestCityPrint()
{
    Cities list;
    City city;
    RestPlaces restPlaces;
    RestPlace restPlace;
    Monuments monuments;
    Monument monument;

    restPlaces = RestPlacesCreate();
    restPlace.added = 0;
    strcpy(restPlace.name, "City1_RP1");
    strcpy(restPlace.address, "address");
    strcpy(restPlace.activity, "act");
    strcpy(restPlace.time, "time");
    strcpy(restPlace.comment, "comment");
    RestPlacesAdd(&restPlaces, restPlace);
    restPlace.added = 0;
    strcpy(restPlace.name, "City1_RP2");
    strcpy(restPlace.address, "address");
    strcpy(restPlace.activity, "act");
    strcpy(restPlace.time, "time");
    strcpy(restPlace.comment, "comment");
    RestPlacesAdd(&restPlaces, restPlace);

    monuments = MonumentsCreate();
    monument.added = 0;
    strcpy(monument.name, "City1_M1");
    strcpy(monument.address, "address");
    strcpy(monument.description, "description");
    strcpy(monument.comment, "comment");
    MonumentsAdd(&monuments, monument);
    monument.added = 0;
    strcpy(monument.name, "City1_M2");
    strcpy(monument.address, "address");
    strcpy(monument.description, "description");
    strcpy(monument.comment, "comment");
    MonumentsAdd(&monuments, monument);

    list = CitiesCreate();
    city.added = 0;
    strcpy(city.name, "City1");
    city.restPlaces = restPlaces;
    city.monuments = monuments;
    CitiesAdd(&list, city);

    restPlaces = RestPlacesCreate();
    restPlace.added = 1;
    strcpy(restPlace.name, "City2_RP1");
    strcpy(restPlace.address, "address");
    strcpy(restPlace.activity, "act");
    strcpy(restPlace.time, "time");
    strcpy(restPlace.comment, "comment");
    RestPlacesAdd(&restPlaces, restPlace);
    restPlace.added = 1;
    strcpy(restPlace.name, "City2_RP2");
    strcpy(restPlace.address, "address");
    strcpy(restPlace.activity, "act");
    strcpy(restPlace.time, "time");
    strcpy(restPlace.comment, "comment");
    RestPlacesAdd(&restPlaces, restPlace);

    monuments = MonumentsCreate();
    monument.added = 1;
    strcpy(monument.name, "City2_M1");
    strcpy(monument.address, "address");
    strcpy(monument.description, "description");
    strcpy(monument.comment, "comment");
    MonumentsAdd(&monuments, monument);
    monument.added = 1;
    strcpy(monument.name, "City2_M2");
    strcpy(monument.address, "address");
    strcpy(monument.description, "description");
    strcpy(monument.comment, "comment");
    MonumentsAdd(&monuments, monument);

    city.added = 1;
    strcpy(city.name, "City2");
    city.restPlaces = restPlaces;
    city.monuments = monuments;
    CitiesAdd(&list, city);

    assert(CityPrint(list, "City1", 0, 0) == 0);
    assert(CityPrint(list, "City1", 0, 1) == 1);
    strcpy(list.head->data.restPlaces.head->data.activity, "Hotel");
    assert(CityPrint(list, "City1", 0, 1) == 0);
    assert(CityPrint(list, "City2", 1, 0) == 0);
}

int main()
{
    TestRestPlacesCreate();
    TestMonumentsCreate();
    TestCitiesCreate();
    TestRestPlacesAdd();
    TestMonumentsAdd();
    TestCitiesAdd();
    TestFindCity();
    TestFindPlace();
    TestAddToBook();
    TestListCities();
    TestCityPrint();
    system("cls");
    printf("Tests passed!");
    return 0;
}
