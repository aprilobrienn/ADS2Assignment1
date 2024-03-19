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

void main() {

    int menuOption; //to take value for menu choice

    do {
        printf("\nCar Showroom\n");
        printf("1. Add a car to the showroom\n");
        printf("2. Sell car\n");
        printf("3. Reserve/Unreserve a car\n");
        printf("4. View all cars in the showroom\n");
        printf("5. View a specific car\n");
        printf("6. ======\n"); //undecided function
        printf("7. Exit the system\n");
        printf("Please enter the number for which selection you would like to make: ");
        scanf("%d", &menuOption);

        while (menuOption <= 0 && menuOption >= 8)
        {
            printf("Invalid number. Please enter a number 1-7");
            scanf("%d", &menuOption);
        }
        if (menuOption == 1)
        {
            addCar();
        }
        else if (menuOption == 2)
        {
            sellCar();
        }
        else if (menuOption == 3)
        {
            reserveCar();
        }
        else if (menuOption == 4)
        {
            viewAllCars();
        }
        else if (menuOption == 5)
        {
            viewACar();
        }
        else if (menuOption == 6)
        {
            XXXXXXX; //undecided yet
        }
        else if (menuOption == 7)
        {
            printf("Exiting System");
        }

    } while (menuOption != 7); //when choice =7 then system ends
}

void addCar() {
    if (*head != NULL && getCarCount() >= MAX_CARS) {
        printf("ERROR! Showroom full\n");
        return;


        printf("Enter car registration: ");
        scanf("%s", newCar->registration);
    }


void sellCar() {

}

void reserveCar() {

}

void viewAllCars() {

}

void viewACar() {

}

int getCarCount(struct Car* head) { //this is so we can get car count
    int count = 0;
    struct Car* acar = head;
    while (acar != NULL) {
        count++;
        acar = acar->next;
    }
    return count;
}






