#define _CRT_SECURE_NO_WARNINGS 1 //this ensures commands like scanf can be used
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define MAX_CARS 5 //max size of cars list is 5 as that is whats in the brief

// Define car structure
struct Car {
    char registration[9]; //allows up to 8 characters (9th for null)
    char makeModel[51]; //ALLOWS UP TO 50 CHAR (51st for null)
    char colour[21]; //allows up to 20 characters (21syt for null)
    int owners; //how many prev owners car has had
    bool reserved; //boolean to see if car has been reserved or not
    float rCost; //cost of reservation

    struct Car* next;
};

struct Car* head = NULL;

// Function prototypes
void addCar();  //adding car to front of the list
void sellCar(char); // delete a specific car
void reserveCar(); //to reserve
void viewAllCars(); //to see all
void viewACar(); //specific car
void searchYear(); //search car by year it was made (own added function)
int getCarCount(); //count ho wmany cars in showroom

void main() {

    int menuOption; //to take value for menu choice

    do {
        printf("\nCar Showroom\n");
        printf("1. Add a car to the showroom\n");
        printf("2. Sell car\n");
        printf("3. Reserve/Unreserve a car\n");
        printf("4. View all cars in the showroom\n");
        printf("5. View a specific car\n");
        printf("6. Search by Year\n"); //function to see cars by year they were made
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
            searchYear(); //own function to search car by year made
        }
        else if (menuOption == 7)
        {
            printf("Exiting System");
        }

    } while (menuOption != 7); //when choice =7 then system ends


}

void addCar() {
    if (getCarCount() >= MAX_CARS) {
        printf("ERROR! Showroom full\n");
        return;
    }

    struct Car* newCar = (struct Car*)malloc(sizeof(struct Car));



        printf("Enter car registration: ");
        scanf("%s", newCar->registration);

        printf("Enter car make and model: ");
        scanf(" %s", newCar->makeModel);

        printf("Enter car colour: ");
        scanf(" %s", newCar->colour);

        printf("Enter number of previous owners (0-3): ");
        scanf("%d", &newCar->owners);

        
        if (newCar->owners < 0 || newCar->owners > 3) //cannot have more than 3 owners so this will check
        {
            printf("Invalid number of owners. Must be between 0 and 3.\n");
            free(newCar);
            return;
        }

        newCar->reserved = false; //will automatically be false as it is just added
        newCar->rCost = 0.0;
        newCar->next = head;
        head = newCar;

        printf("Car added to the showroom.\n");
    }
    


void sellCar() {

    if (head == NULL) {
        printf("No cars avaliable to sell\n");
        return;
    }

    char reg[9];
    printf("Enter car registration of the car to sell: ");
    scanf("%s", reg);

    struct Car* prev = NULL;
    struct Car* curr = head;

    while (curr != NULL) {
        if (strcmp(curr->registration, reg) == 0)  //check to see i fregistation matches reg
        {
            if (curr->reserved) {
                if (prev == NULL) {
                    head = curr->next;
                }
                else {
                    prev->next = curr->next;
                }
                free(curr);
                printf("Car %s sold.\n", reg);
                return;
            }
            else {
                printf("Car %s is not reserved and cannot be sold.\n", reg);
                return;
            }
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Car with registration %s not found.\n", reg);
}

}

void reserveCar() {
    if (head == NULL) {
        printf("No cars in the showroom to reserve/unreserve.\n");
        return;
    }

    char reg[9];
    printf("Registration of car you would like to reserve/unreserve: ");
    scanf("%s", reg);

    struct Car* curr = *head;
    while (curr != NULL) {
        if (strcmp(curr->registration, reg) == 0) {
            if (curr->reserved) {
                curr->reserved = false;
                curr->rCost = 0;
                printf("Car %s unreserved.\n", reg);
            }
            else {
                curr->reserved = true;
                printf("Enter reserve amount (500 - 1500): ");
                scanf("%f", &curr->rCost);
                if (curr->rCost < 500 || curr->rCost > 1500) {
                    printf("Error. Must be between 500 and 1500.\n");
                    curr->rCost = 0;
                    curr->reserved = false;
                }
                else {
                    printf("Car %s reserved.\n", reg);
                }
            }
            return;
        }
        curr = curr->next;
    }

    printf("Car with registration %s not found.\n", reg);
}

void searchYear() {

    if (head == NULL) {
        printf("Showroom empty.\n");
        return;
    }

    int year;
    printf("Enter the year of cars you would like to see : ");
    scanf("%d", &year);

    struct Car* curr = head;
    bool found = false;

    printf("\nCars from %d:\n", year);
    while (curr != NULL) {
        //to find year through car reg
        int registrationYear = 2000 + ((curr->registration[0] - '0') * 10) + (curr->registration[1] - '0');

        if (registrationYear == year) { //displays infor of car/cars with that year
            printf("\nRegistration: %s\n", curr->registration);
            printf("Make and Model: %s\n", curr->makeModel);
            printf("Colour: %s\n", curr->colour);
            printf("Number of Previous Owners: %d\n", curr->owners);
            printf("Reserved: %s\n", curr->reserved ? "Yes" : "No");
            printf("Reserve Amount: %.2f\n", curr->rCost);
            found = true;
        }

        curr = curr->next;
    }

    if (!found) {
        printf("No cars in showroom made in the year %d.\n", year);
    }
}

}

void viewAllCars() {
    if (head == NULL) {
        printf("Unable to display cars. Showroom is empty.\n");
        return;
    }
    struct Car* curr = head;
    while (curr != NULL) { //will keep looping till reaching the end of the list
        printf("\nRegistration: %s\n", curr->registration);
        printf("Make and Model: %s\n", curr->makeModel);
        printf("Colour: %s\n", curr->colour);
        printf("Previous Owners: %d\n", curr->owners);
        printf("Reserved: %s\n", curr->reserved ? "Yes" : "No");
        printf("Reserve Amount: %.2f\n", curr->rCost);
        

        curr = curr->next;
    }
}


}

void viewACar() {
    if (head == NULL) {
        printf("Showroom is empty.\n");
        return;
    }

    char reg[9];
    printf("Enter car registration: ");
    scanf("%s", reg);

    struct Car* curr = head;
    while (curr != NULL) { //will keep lopping till end of list
        if (strcmp(curr->registration, reg) == 0) { //check to see if matching reg is found
            printf("\nRegistration: %s\n", curr->registration);
            printf("Make and Model: %s\n", curr->makeModel);
            printf("Colour: %s\n", curr->colour);
            printf("Previous Owners: %d\n", curr->owners);
            printf("Reserved: %s\n", curr->reserved ? "Yes" : "No");
            printf("Reserve Amount: %.2f\n", curr->rCost);
            return;
        }
        curr = curr->next; //will move to next on list
    }

    printf("Car %s not found.\n", reg);
}

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






