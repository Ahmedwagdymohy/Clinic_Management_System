#include "std_types.h"
#include "clinc.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ID_COUNT 100
#define MAX_MEMBERS_COUNT 100
uint32_t IDs[MAX_ID_COUNT];
uint32_t ID_COUNT= 0;
int given_ID =0 ;
//extern pat patients[MAX_MEMBERS_COUNT];
#define NUM_SLOTS 5
char slots[NUM_SLOTS][20] ={"2:00pm - 2:30pm",
                            "2:30pm - 3:00pm",
                            "3:00pm - 3:30pm",
                            "4:00pm - 4:30pm",
                            "4:30pm - 5:00pm"};


slot reservations[5];





void check_pass(){
    uint32_t default_password = 1234;
    sint32_t password = 0;
    uint32_t counter = 0 ;
    printf("please enter the password to access :  ");
    do{
    scanf("%i" , &password);
    if(password == default_password ){
        system("cls");
        sleep(1);
        printf("-------------------------------valid access -------------------------- \n");
        break;

        //sleep(3);
    }else{
        printf("Invalid Password ! please check it and try again : ");
        counter++;


    }
    }while(counter <= 3);
    if(counter >=3){printf("U entered the password many times !\n");
    sleep(1);
    printf(" WAIT five seconds to try again......... \n");
    sleep(7);
    check_pass();}

}

pat add_new_pat(){
    pat new_pat;
     printf("Enter the patient name: ");

    // Consume any newline character left in the input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    fgets(new_pat.name, sizeof(new_pat.name), stdin);

    // Remove the newline character from the name
    if (new_pat.name[strlen(new_pat.name) - 1] == '\n') {
        new_pat.name[strlen(new_pat.name) - 1] = '\0';
    }

    printf("Enter the patient age: ");
    scanf("%d", &new_pat.age);

    // Clear the newline character left in the input buffer after scanf
    while (getchar() != '\n');

    printf("Enter the patient gender (M/F): ");
    scanf(" %c", &new_pat.gender);

    uint32_t temp_given_ID = 0;
    temp_given_ID = give_ID();
    printf("your ID ON SYS is  : %i\n" , temp_given_ID);

    //ID array to store all the ID and we use Searching algorithm to check if there a repeated ID
    IDs[ID_COUNT] = temp_given_ID;
    new_pat.ID = temp_given_ID;
    ID_COUNT++;

    /*for test deletttte*/ //for(int i = 0 ; i<ID_COUNT ; i++){printf("%i" , IDs[i]);}
    //system("cls");

    return new_pat;


}

int give_ID(){
    given_ID++;
    return given_ID;
}




uint32_t admin_entry(){
            while(1){
            uint16_t choice;
            printf("-----WELCOME ADMIN-----\n");
            printf("1. Add new patient record\n");
            printf("2. Edit patient record \n");
            printf("3. Reserve a slot with the doctor\n");
            printf("4. Cancel reservation.\n");
            printf("5. Exit\n");
            printf("Enter your choice (1, 2, or 5 to exit): ");
            scanf("%d", &choice);
            switch(choice){
                case 1:
                    //add new patient here
                    add_new_pat();

                    break;

                case 2:
                    //edit patient record
                    break;
                case 3:
                    //reverse a slot
                    break;
                case 4:
                    //cancel a reservation
                    break;
                case 5:
                    //exits the program
                    system("cls");
                    break;
}}

}







void view_pat_record( pat patientss[]){
    int temp_ID = 0;
    system("cls");
    printf("Please enter the User ID: ");
    scanf("%i", &temp_ID);

    int userIndex = -1; // Initialize to -1 to indicate user not found

    for (int i = 0; i < MAX_MEMBERS_COUNT; i++) {
        if (temp_ID == IDs[i]) {
            userIndex = i; // Store the index where the user was found
            break;
        }
    }

    if (userIndex != -1) {
        printf("The User found!! \n");
        printf("The User name is: %s\n", patientss[userIndex].name);
        printf("The User gender is: %s\n", patientss[userIndex].gender);
        printf("The User age is: %i\n", patientss[userIndex].age);
    } else {
        printf("Error: Can't find a user with this ID!\n");
    }
    }















void edit_pat(pat patientss[]){
    int TEMP_ID = 0;
    system("cls");
    printf("Enter the ID u want to MOdify :  ");
    scanf("%i" , &TEMP_ID);
    int userIndex = -1; // Initialize to -1 to indicate user not found

    for (int i = 0; i < MAX_MEMBERS_COUNT; i++) {
        if (TEMP_ID == IDs[i]) {
            userIndex = i; // Store the index where the user was found
            break;
        }
    }       if(userIndex != -1){
            printf("Enter the patient name: ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            fgets(patientss[userIndex].name, sizeof(patientss[userIndex].name), stdin);

            // Remove the newline character from the name
            if (patientss[userIndex].name[strlen(patientss[userIndex].name) - 1] == '\n') {
            patientss[userIndex].name[strlen(patientss[userIndex].name) - 1] = '\0';
            }

            printf("Enter the patient age: ");
            scanf("%d", &patientss[userIndex].age);

            // Clear the newline character left in the input buffer after scanf
            while (getchar() != '\n');

            printf("Enter the patient gender (M/F): ");
            scanf(" %c", &patientss[userIndex].gender);
    }

        else{
        printf("Error can't find a user with this ID ! \n");
      }




}




void displayAvailableSlots() {
    printf("Available Slots:\n");
    for (int i = 0; i < NUM_SLOTS; i++) {
        if (!reservations[i].available) {
            printf("%d. %s\n", i + 1, slots[i]);
        }
    }
}








void book_slot(){
    system("cls");
    int patientID;
    int slotChoice;

    displayAvailableSlots();

    printf("Enter patient ID: ");
    scanf("%d", &patientID);

    printf("Enter desired slot number: ");
    scanf("%d", &slotChoice);

    // Check if the chosen slot is valid and available
    if (slotChoice >= 1 && slotChoice <= NUM_SLOTS && !(reservations[slotChoice - 1].available)) {
        // Reserve the slot
        reservations[slotChoice - 1].ID = patientID;
        reservations[slotChoice - 1].available = true;
        printf("Slot reserved successfully.\n");
    } else {
        printf("Invalid slot choice or slot is already reserved.\n");
    }







}




 void cancel_reservation(){
    int patientID;
    printf("Enter patient ID to cancel reservation: ");
    scanf("%d", &patientID);

    for (int i = 0; i < NUM_SLOTS; i++) {
        if (reservations[i].available && reservations[i].ID == patientID) {
            reservations[i].available = false;
            printf("Reservation for patient ID %d has been canceled.\n", patientID);
            return;
        }
    }

    printf("No reservation found for patient ID %d.\n", patientID);







 }





void view_all_reservations(){

    printf("Available Slots:\n");
    for (int i = 0; i < NUM_SLOTS; i++) {

        printf("%d. %s", i + 1, slots[i]); printf(" =>with ID: (%i) \n" , reservations[i].ID);

    }






}




