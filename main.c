#include <stdio.h>
#include <stdlib.h>
#include "std_types.h"
#include "clinc.h"
#include <unistd.h>
int numClients = 1;


pat patients[100];

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}



/*UPDATEs :   ADMIN : enters well with the password and exits
            USER :  enters well and exits too
            ================================================
            ADMIN functions:
                    EDIT // done
                    VIEW // done

*/


int main() {
    int exitFlag = 0;
    int inAdminMenu = 0; // Flag to indicate if in admin menu
    int inUserMenu = 0;  // Flag to indicate if in user menu

    while (!exitFlag) {
        if (!inAdminMenu && !inUserMenu) {
            // Main menu
            printf("----------------------------------------------- WELCOME to our-clinic system ----------------------------\n");
            printf("Please choose a Mode : \n");
            printf("1. User\n");
            printf("2. Admin\n");
            printf("3. Exit\n");
            printf("Enter your choice (1, 2, or 3 to exit): ");
        } else if (inAdminMenu) {
            // Admin menu
            printf("------WELCOME ADMIN-----\n");
            printf("1. Add new patient record\n");
            printf("2. Edit patient record \n");
            printf("3. Reserve a slot with the doctor\n");
            printf("4. Cancel reservation.\n");
            printf("5. Return to Main Menu\n");
            printf("Enter your choice (1, 2, 3, 4, or 5): ");
        } else if (inUserMenu) {
            // User menu
            printf("-------USER MENU-----\n");
            printf("1. View patient record. \n");
            printf("2. View today’s reservations \n");
            printf("3. Return to Main Menu\n");
            printf("Enter your choice (1, 2, or 3): ");
        }

        int entry = 0;
        /*fgets(entry, sizeof(entry), stdin);
        int choice = atoi(entry);*/

        scanf("%d", &entry);
        //clearInputBuffer(); // Clear the input buffer

        switch (entry) {
            case 1:
                if (!inAdminMenu && !inUserMenu) {
                    // Main menu option 1 (User)
                    system("cls");
                    sleep(1);
                    printf("You are in the user mode now!\n");
                    inUserMenu = 1;
                    // User mode goes here


                } else if (inAdminMenu) {
                    // Admin menu option 1 (Add new patient record)
                    system("cls");
                    //int temp_var = give_ID();
                    patients[numClients++] = add_new_pat();




                } else if (inUserMenu) {
                    // User menu option 1
                    // Code for User option 1
                    view_pat_record(patients);
                }
                break;

            case 2:
                if (!inAdminMenu && !inUserMenu) {
                    // Main menu option 2 (Admin) // done
                    system("cls");
                    sleep(1);
                    printf("You are in the admin mode now\n");
                    sleep(1);
                    // Checking the password of the admin
                    check_pass();
                    // Admin program goes here!
                    inAdminMenu = 1; // Enter admin menu
                    break;
                } else if (inAdminMenu) {
                    // Admin menu option 2 (Edit patient record) //done
                    edit_pat(patients);

                } else if (inUserMenu) {
                    // User menu option 2
                    // Code for User option 2
                    view_all_reservations();

                }
                break;

            case 3:
                if (!inAdminMenu && !inUserMenu) {
                    // Main menu option 3 (Exit)
                    system("cls");
                    printf("Exiting the program. Goodbye!\n");
                    exitFlag = 1;
                } else if (inAdminMenu) {
                    // Admin menu option 3 (Reserve a slot with the doctor) //done
                    book_slot();
                } else if (inUserMenu) {
                    system("cls");
                    sleep(1);
                    // User menu option 3 (Return to Main Menu)
                    inUserMenu = 0; // Return to main menu
                }
                break;

            case 4:
                if (inAdminMenu) {
                    // Admin menu option 4 (Cancel reservation) // done
                    cancel_reservation();
                }
                break;

            case 5:
                if (inAdminMenu) {
                    // Admin menu option 5 (Return to Main Menu)
                    system("cls");
                    sleep(1);
                    inAdminMenu = 0; // Return to main menu
                }
                break;

            default:
                printf("Invalid choice, please choose a valid option.\n");
                break;
        }
    }

    return 0;
}
