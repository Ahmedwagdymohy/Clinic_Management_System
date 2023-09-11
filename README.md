# About

 C code for clinic management system.
## Installation

use the following libraries to run the program.
```bash
#include "std_types.h"
#include "clinc.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
```

## Usage

```python
"Please choose a Mode : "
1. User
2. Admin
3. Exit
Enter your choice (1, 2, or 3 to exit):

```

## Functions

**In admin mode** 

The system asks for password, the default password is 1234. The system allows 3 trails for the password
entry, if the entered password was incorrect for 3 consecutive times, the system shall close. After login
in the admin mode, the system shall provide the following features:

**1. Add new patient record:** 

To add a new patient, the user shall admin shall enter these basic information: name, age, gender and
ID. The ID shall be unique for the user, if the entered ID is already exists, the system shall reject the
entry.

**2. Edit patient record**

By entering patient ID the system shall checks if the ID exists, the system shall allow the user to edit the
patient information. If not, the system shall display incorrect ID message.

**3. Reserve a slot with the doctor**

By default there are 5 available slots, 2pm to 2:30pm, 2:30pm to 3pm, 3pm to 3:30pm, 4pm to 4:30pm
and 4:30pm to 5pm. Upon opening of this window, the system shall display the available slots. The
admin shall enter the patient ID and the desired slot. The reserved slot shall not appear again in the next
patient reservation.

**4. Cancel reservation.**

The admin can cancel a reservation by entering the patient ID. This reservation shall be shown again in
the available slots window.


**In the user mode**

There is no password. The system allows the following features:

**1. View patient record.**

By entering the patient ID, the system shall show the basic information for the patient.

**2. View today’s reservations.**

In this view, the system shall print all reservations with the patient ID attached to each reservation slot.

## License

This material is developed by IMTSchool for educational use only
All copyrights are reserved
