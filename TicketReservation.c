#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PLANES 100

struct Plane{
    int flightNumber;
    int pNumber;
    int pCapacity;
    int pAvailable;
    int pPrice;
    char pDestination[20];
    char pOrigin[20];
};

/*struct User{
    char forename[20];
    char surename[20];
    int ticketNumber;
    int flight;
};*/

void addPlane(struct Plane planes[], int *planeCount);
void displayPlanes(struct Plane planes[], int planeCount, int option);
void pickFlight(struct Plane planes[], int planeCount);

int main(){
    struct Plane planes[MAX_PLANES];
    int planeCount=0;
    //test
    planes[0] = (struct Plane) {1, 101, 80, 80, 45, "New York", "Los Angeles"};
    planes[1] = (struct Plane) {2, 102, 150, 150, 60, "Chicago", "Miami"};
    planes[2] = (struct Plane) {3, 103, 200, 200, 75, "London", "Tokyo"};
    planes[3] = (struct Plane) {4, 104, 90, 90, 50, "Houston", "Chicago"};
    planes[4] = (struct Plane) {5, 105, 110, 110, 85, "Los Angeles", "New York"};
    planes[5] = (struct Plane) {6, 106, 170, 170, 40, "Tokyo", "Miami"};
    planes[6] = (struct Plane) {7, 107, 50, 50, 120, "Chicago", "London"};
    planes[7] = (struct Plane) {8, 108, 130, 130, 95, "Miami", "Houston"};
    planes[8] = (struct Plane) {9, 109, 200, 200, 55, "New York", "Tokyo"};
    planes[9] = (struct Plane) {10, 110, 70, 70, 30, "London", "Los Angeles"};
    planes[10] = (struct Plane) {11, 111, 160, 160, 110, "Chicago", "Miami"};
    planes[11] = (struct Plane) {12, 112, 120, 120, 125, "Houston", "New York"};
    planes[12] = (struct Plane) {13, 113, 50, 50, 90, "Miami", "London"};
    planes[13] = (struct Plane) {14, 114, 140, 140, 75, "Los Angeles", "Chicago"};
    planes[14] = (struct Plane) {15, 115, 180, 180, 135, "Tokyo", "Miami"};
    planes[15] = (struct Plane) {16, 116, 90, 90, 50, "New York", "Los Angeles"};
    planes[16] = (struct Plane) {17, 117, 200, 200, 145, "London", "Tokyo"};
    planes[17] = (struct Plane) {18, 118, 110, 110, 100, "Chicago", "Houston"};
    planes[18] = (struct Plane) {19, 119, 70, 70, 85, "Miami", "Los Angeles"};
    planes[19] = (struct Plane) {20, 120, 130, 130, 40, "New York", "Tokyo"};

    planeCount=20;
    //test

    int choice;
    while (1) {
        printf("1. Add Plane\n");
        printf("2. Display Planes\n");
        printf("3. Pick Flight\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPlane(planes, &planeCount);
                break;
            case 2:
                displayPlanes(planes, planeCount,0);
                break;
            case 3:
                pickFlight(planes, planeCount);
                return 0;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
                return 0;
        }
    }

}
void addPlane(struct Plane planes[], int *planeCount){
    if (*planeCount < MAX_PLANES) {
        printf("Enter flight number: ");
        scanf("%d", &planes[*planeCount].flightNumber);
        printf("Enter plane number: ");
        scanf("%d", &planes[*planeCount].pNumber);
        printf("Enter plane capacity: ");
        scanf("%d", &planes[*planeCount].pCapacity);
        planes[*planeCount].pAvailable = planes[*planeCount].pCapacity;
        printf("Enter plane price: ");
        scanf("%d", &planes[*planeCount].pPrice);
        printf("Enter plane destination: ");
        scanf("%19s", planes[*planeCount].pDestination);
        printf("Enter plane origin: ");
        scanf("%19s", planes[*planeCount].pOrigin);
        (*planeCount)++;
        printf("Plane added successfully!\n");
    } else {
        printf("Maximum number of planes reached!\n");
    }
}
void displayPlanes(struct Plane planes[], int planeCount, int option) {
    //All flights
    if(option==0) {
        for (int i = 0; i < planeCount; i++) {
            printf("Flight Number  |  Capacity  |  Available seats  |  Price  |  Destination  |  Origin\n"
                   "\t %d          %d    \t\t%d\t     %d       %s        %s\n", planes[i].flightNumber, planes[i].pCapacity,
                   planes[i].pAvailable, planes[i].pPrice, planes[i].pDestination, planes[i].pOrigin);
        }
    }
    //Flights by destination
    else if(option==1){
        char destination[20];
        fgets(destination, sizeof(destination), stdin);
// Remove the newline character from the end of the string
        destination[strcspn(destination, "\n")] = '\0';
        system("cls || clear");
        for (int i = 0; i < planeCount; i++) {
            if (strcmp(planes[i].pDestination, destination) == 0) {
                printf("Flight Number  |  Capacity  |  Available seats  |  Price  |  Destination  |  Origin\n"
                       "\t %d          %d    \t\t%d\t     %d       %s        %s\n", planes[i].flightNumber, planes[i].pCapacity,
                       planes[i].pAvailable, planes[i].pPrice, planes[i].pDestination, planes[i].pOrigin);
                printf("\n");
            }
        }
    }
    //Flights by origin
    else if(option==2){
        char origin[20];
        fgets(origin, sizeof(origin), stdin);

// Remove the newline character from the end of the string
        origin[strcspn(origin, "\n")] = '\0';
        system("cls || clear");
        for (int i = 0; i < planeCount; i++) {
            if (strcmp(planes[i].pOrigin, origin) == 0) {
                printf("Flight Number  |  Capacity  |  Available seats  |  Price  |  Destination  |  Origin\n"
                       "\t %d          %d    \t\t%d\t     %d       %s        %s\n", planes[i].flightNumber, planes[i].pCapacity,
                       planes[i].pAvailable, planes[i].pPrice, planes[i].pDestination, planes[i].pOrigin);
                printf("\n");
            }
        }
    }

}

void pickFlight(struct Plane planes[], int planeCount){
    system("cls || clear");
    int fnumber,choice ;
    displayPlanes( planes, planeCount,0);
    while (1){
        printf("1.Choose flight\n2.Filter flights by destination\n3.Filter flight by origin\n4.Filter flights by price\nEnter your choice: ");
        scanf(" %d", &choice);
        switch(choice){
            case 1:
                system("cls || clear");
                bool wrongInput=false;
                displayPlanes(planes, planeCount,0);
                do {
                    printf("\nEnter flight number: ");
                    scanf(" %d", &fnumber);
                    for (int i = 0; i < planeCount; i++) {
                        if (fnumber == planes[i].flightNumber) {
                            system("cls || clear");
                            printf("Plane Number    Capacity    Available seats     Price   Destination    Origin\n"
                                   "\t%d\t%d\t%d\t%d\t%d\t%s\t%s\n", planes[i].flightNumber, planes[i].pNumber, planes[i].pCapacity,
                                   planes[i].pAvailable, planes[i].pPrice, planes[i].pDestination, planes[i].pOrigin);
                            printf("\nYour flight is reserved!\n");
                            return;
                        }else{
                            wrongInput=true;
                        }
                    }
                    displayPlanes(planes, planeCount,0);
                    printf("\nYou entered wrong number!");
                }while(wrongInput);
                break;
            case 2:
                displayPlanes(planes, planeCount,1);
                break;
            case 3:
                displayPlanes(planes, planeCount,2);
                break;
            case 4:
                int price;
                printf("Enter max price: ");
                scanf("%d", &price);
                system( "cls || clear");
                for (int i = 0; i < planeCount; i++) {
                    if (planes[i].pPrice <= price) {
                        printf("Flight Number  |  Capacity  |  Available seats  |  Price  |  Destination  |  Origin\n"
                               "\t %d          %d    \t\t%d\t     %d       %s        %s\n", planes[i].flightNumber, planes[i].pCapacity,
                               planes[i].pAvailable, planes[i].pPrice, planes[i].pDestination, planes[i].pOrigin);
                        printf("\n");
                    }
                }
                break;
            default:
                system("cls || clear");
                displayPlanes(planes, planeCount,0);
                printf("You entered wrong number!");
                return;
        }
    }
}