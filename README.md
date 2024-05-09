# DataCore

DataCore is a simple, efficient, and scalable database management system implemented in C. It provides basic CRUD (Create, Retrieve, Update, Delete) operations, as well as functionalities to list and sort data.

## Features
- **CRUD Operations**: DataCore supports Create, Retrieve, Update, and Delete operations on database records.
- **List Data**: Retrieve a list of records from the database.
- **Sort Data**: Sort records based on specified criteria.
- **Efficient and Scalable**: Implemented in C for optimal performance and scalability.
- **Easy to Use**: Simple and intuitive interface for managing data.

## Usage
To use DataCore in your project, follow these steps:

1. **Clone the Repository**:
   ```
   git clone https://github.com/yourusername/datacore.git
   ``` 
2. **Go to the Root Repository**:
   ```  
    cd datacore
    make
   ``` 
3. **And then run it**:
   ``` 
   ./datacore
   ``` 

```c
#include "datacore.h"

int main() {
    // Initialize DataCore
    datacore_init();

    // Perform CRUD operations
    // Insert records
    datacore_Create(table, student1);
    datacore_Create(table, student2);

    // Retrieve records
    datacore_Retrieve(table, id);

    // Update records
    datacore_Update(table, id, new_data);

    // Delete records
    datacore_Delete(table, id);

    // List data
    datacore_List(table);

    // Sort data
    datacore_Sort(void (*criteria)(table));

    // Clean up
    datacore_Cleanup(table);

    return 0;
}