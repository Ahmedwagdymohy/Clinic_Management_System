#include "std_types.h"
#define NAME_MAX_SIZE 100
#include <stdbool.h>

typedef struct patient{
    char name[NAME_MAX_SIZE];
    uint32_t age;
    char gender[50];
    uint32_t ID;


}pat;


typedef struct booking{
    uint32_t ID;
    int slotIndex;
    bool available;



}slot;


/* --------------------------------------for admin functions -----------------------------*/
uint32_t mainMenu(); // done
void check_pass(); // done
pat add_new_pat(); // done
int give_ID();  // done
uint32_t admin_entry(); // done
void edit_pat();  // done
void book_slot();// make it display the slots too
 void cancel_reservation();
 void displayAvailableSlots();

/* --------------------------------------for user functions -----------------------------*/

void view_pat_record( pat patientss[]);
void view_all_reservations(); // display the slots with IDS that have reserved it





