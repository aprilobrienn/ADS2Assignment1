#define _CRT_SECURE_NO_WARNINGS 1 //this ensures commands like scanf can be used
#include <stdio.h>
#include <stdlib.h>


#define MAX_CARS 5 //max size of cars list is 5 as that is whats in the brief

// Define car structure
struct Car {
    char registration[8]; //allows up to 8 characters
    char make_model[50]; //ALLOWS UP TO 50 CHAR
    char colour[20]; //allows up to 20 characters
    int owners; //how many prev owners car has had
    bool reserved; //boolean to see if car has been reserved or not
    float rCost; //cost of reservation

    struct Car* next;
};

// Function prototypes
void addCar();  //adding car to front of the list
void sellCar(char); // delete a specific car
void reserveCar(); //to reserve
void viewAllCars(); //to see all
void viewACar(); //specific car

