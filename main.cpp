#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>

using namespace std;

const int MAX_NUMBER = 20;

struct Property
{
    int number_property;
    string type;
    int area;
    string owner;
    int price;
};

Property arr[MAX_NUMBER];
int property_index = 0;

void saveToFile()
{
    ofstream outFile("filename", ios::binary | ios::out);
    if (!outFile)
    {
        cout << "Unable to open file.\n";
        return;
    }
    outFile.write((char*)&property_index, sizeof(property_index));
    outFile.write((char*)arr, property_index * sizeof(Property));
    outFile.close();
    cout << "Groups saved to file successfully.\n";
}

void loadRecordFromFile()
{
    ifstream inFile("filename", ios::binary | ios::in);
    if (!inFile)
    {
        cout << "Unable to open file or file does not exist.\n";
        return;
    }
    inFile.read((char*)&property_index, sizeof(property_index));
    inFile.read((char*)arr, property_index * sizeof(Property));
    inFile.close();

    cout << "Groups loaded from file successfully.\n";
}

void showRecord()
{
    for (int i = 0; i < property_index; ++i)
    {
        cout << endl;
        cout << "Property number: " << arr[i].number_property << endl;
        cout << "Property type: " << arr[i].type << endl;
        cout << "Property area: " << arr[i].area << endl;
        cout << "Property owner's name: " << arr[i].owner << endl;
        cout << "Price of property: " << arr[i].price << endl;

    }
}

void addNew()
{
    if (property_index < MAX_NUMBER)
    {
        Property newProperty;
        cout << "Enter number of property: ";
        cin >> newProperty.number_property;
        cout << "Enter property type: ";
        cin >> newProperty.type;
        cout << "Enter property area: ";
        cin >> newProperty.area;
        cout << "Enter owner's name: ";
        cin >> newProperty.owner;
        cout << "Enter property price: ";
        cin >> newProperty.price;
        arr[property_index++] = newProperty;
        cout << "Group added successfully. \n";
    }
    else
    {
        cout << "Maximum number of property reached. \n";
    }
}

void del(int number_property)
{
    cout << "Select the record number to be deleted";
    cin >> number_property;
    for (int i = number_property - 1; i < property_index; i++)
        arr[i] = arr[i + 1];
    property_index--;

    cout << "Group with number " << number_property << " deleted successfully.\n";
    return;
}

void modifyRecord(int number_property)
{
    for (int i = 0; i < property_index; ++i)
    {
        if (arr[i].number_property == number_property)
        {
            cout << "Enter new property type: ";
            cin >> arr[i].type;
            cout << "Enter new owner's name: ";
            cin >> arr[i].owner;
            cout << "Enter new price of property: ";
            cin >> arr[i].price;
            cout << "Group information modified successfully.\n";
            return;
        }
    }
}

void sortByOwner()
{
    for (int i = 0; i < property_index - 1; ++i)
    {
        for (int j = 0; j < property_index - i - 1; ++j)
        {
            if (arr[j].owner < arr[j + 1].owner)
            {
                Property temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int number_property;
    int choice;

    loadRecordFromFile();

    do
    {
        cout << "\nMenu:\n";
        cout << "1-Show a record\n";
        cout << "2-Save a record\n";
        cout << "3-Add a new record\n";
        cout << "4-Delete a record\n";
        cout << "5-Modify a record\n";
        cout << "6-Sort by price a record\n";
        cout << "7-Exit\n";
        cout << "\n";
        cout << "Enter your choise  ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            showRecord();
            break;
        case 2:
            saveToFile();
            break;
        case 3:
            addNew();
            break;
        case 4:
            cout << "Enter record number to delete: ";
            cin >> number_property;
            del(number_property);
            break;
        case 5:
            cout << "Enter record number to modify: ";
            cin >> number_property;
            modifyRecord(number_property);
            break;
        case 6:
            sortByOwner();
            break;
        case 7:
            return 0;
        default:
            cout << "Invalid choise. Please try again.\n";
            break;
        }
    } while (choice != 7);
    return 0;
}