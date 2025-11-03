# Medicine Management System Documentation

## Overview
This C program implements a medicine management system that handles medicine records stored in a binary file. The system provides functionality to search for medicines by date, export medicines to a text file based on price range, and delete medicines from the database.

## Data Structure

### Medicine Structure
```c
typedef struct medicine{
  char name[30];      // Medicine name (max 29 characters + null terminator)
  char date[7];       // Expiry date in format "MM.YYYY" (e.g., "12.2025")
  int code;           // Unique medicine code
  double price;       // Price in currency units
  int quantity;       // Available quantity
}Medicine;
```

## Function Documentation

### 1. search()
**Purpose**: Searches for medicines with expiry dates before a given date.

**Parameters**:
- `Medicine *pMedicines[]`: Array of pointers to medicine structures
- `int numberOfElements`: Number of medicines in the array
- `char date[7]`: Target date in "MM.YYYY" format

**Return Value**: 
- Returns a dynamically allocated array of medicines that expire before the given date
- Returns `NULL` if no medicines match the criteria

**Algorithm**:
1. Parses the input date to extract month and year
2. Counts how many medicines expire before the target date
3. Allocates memory for the result array
4. Populates the result array with matching medicines
5. Returns the array (caller is responsible for freeing memory)

**Example Usage**:
```c
Medicine *result = search(pMedicines, numberOfMedsInFile, "20.2020");
// Returns all medicines expiring before December 2020
```

### 2. enterTextFile()
**Purpose**: Exports medicines within a specified price range to a text file named "offer.txt".

**Parameters**:
- `Medicine *meds`: Array of medicine structures
- `int elements`: Number of medicines in the array
- `double minPrice`: Minimum price threshold (exclusive)
- `double maxPrice`: Maximum price threshold (exclusive)

**Return Value**: 
- Returns the number of medicines written to the file

**File Format**:
The function creates "offer.txt" with the following format for each medicine:
```
MedicineName
ExpiryDate
Code
Price.XXleva
Quantity

```

**Algorithm**:
1. Opens "offer.txt" in write mode
2. Iterates through all medicines
3. Checks if medicine price is within the specified range
4. Writes matching medicines to file with proper formatting
5. Closes the file and returns count

**Example Usage**:
```c
int count = enterTextFile(pMedicines, numberOfMedsInFile, 2.33, 10.33);
// Exports medicines priced between 2.33 and 10.33
```

### 3. delete()
**Purpose**: Removes a medicine from the array based on name and date matching.

**Parameters**:
- `Medicine *meds`: Array of medicine structures
- `int elements`: Number of medicines in the array
- `char name[]`: Name of medicine to delete
- `char date[]`: Expiry date of medicine to delete

**Return Value**: 
- Returns `1` if medicine was found and deleted
- Returns `0` if medicine was not found

**Algorithm**:
1. Searches for medicine with matching name and date
2. If found and it's the last element: reallocates array to smaller size
3. If found and not the last element: swaps with last element, then reallocates
4. Uses `realloc()` to reduce array size by one element

**Note**: The function modifies the original array and reduces its size by one element when a medicine is deleted.

**Example Usage**:
```c
int deleted = delete(pMedicines, numberOfMedsInFile, "Aspirin", "11.2025");
if(deleted == 0) {
    printf("Medicine not found");
}
```

### 4. main()
**Purpose**: Main program that demonstrates the medicine management system functionality.

**Program Flow**:
1. **File Operations**:
   - Opens "medicine.bin" in binary write mode
   - Calculates file size and number of medicines
   - Allocates memory for medicine array
   - Reads all medicines from binary file

2. **Function Demonstrations**:
   - Calls `search()` to find medicines expiring before "20.2020"
   - Calls `enterTextFile()` to export medicines priced between 2.33 and 10.33
   - Calls `delete()` to remove a medicine with name "name" and date "11.1111"

3. **Memory Management**:
   - Frees allocated memory for both main array and search results

## File Structure

### Input Files
- `medicine.bin`: Binary file containing medicine records

### Output Files
- `offer.txt`: Text file containing medicines within specified price range

## Memory Management

### Dynamic Memory Allocation
- `pMedicines`: Main array of medicines (allocated based on file size)
- `result`: Search results array (allocated in search function)

### Memory Deallocation
- Both arrays are properly freed in main function
- `realloc()` is used in delete function to reduce array size

## Error Handling

### Critical Errors
- File opening failures result in `exit(1)`
- Memory allocation failures result in `exit(1)`

### Graceful Handling
- Search function returns `NULL` when no matches found
- Delete function returns `0` when medicine not found

## Usage Examples

### Searching for Expired Medicines
```c
Medicine *expired = search(medicines, count, "12.2023");
// Returns all medicines expiring before December 2023
```

### Exporting Affordable Medicines
```c
int exported = enterTextFile(medicines, count, 5.0, 15.0);
// Exports medicines priced between 5.0 and 15.0
```

### Removing Specific Medicine
```c
int removed = delete(medicines, count, "Paracetamol", "06.2024");
// Removes Paracetamol expiring in June 2024
```

## Notes and Considerations

1. **Date Format**: All dates use "MM.YYYY" format (e.g., "12.2025")
2. **Price Format**: Prices are stored as doubles and formatted to 2 decimal places in output
3. **Memory Safety**: The program properly handles memory allocation and deallocation
4. **File Handling**: Binary file for input, text file for output
5. **Array Management**: The delete function modifies array size using realloc

## Potential Improvements

1. **Error Handling**: Add more robust error checking for file operations
2. **Input Validation**: Validate date and price formats
3. **Memory Safety**: Add bounds checking for array operations
4. **User Interface**: Add interactive menu for user operations
5. **Data Persistence**: Implement proper saving of modified data back to binary file 