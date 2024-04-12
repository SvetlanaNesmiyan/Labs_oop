#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_SMARTPHONES = 200;

struct Smartphone 
{
    string name;
    float screenDiagonal;
    string processor;
    int ram;
};

Smartphone smartphones[MAX_SMARTPHONES];
int numSmartphones = 0;

void AddSmartphone() 
{
    if (numSmartphones < MAX_SMARTPHONES) 
    {
        Smartphone newSmartphone;
        cout << "Enter smartphone name: ";
        cin >> newSmartphone.name;
        cout << "Enter screen diagonal: ";
        cin >> newSmartphone.screenDiagonal;
        cout << "Enter processor: ";
        cin >> newSmartphone.processor;
        cout << "Enter RAM size: ";
        cin >> newSmartphone.ram;
        smartphones[numSmartphones++] = newSmartphone;
        cout << "Smartphone added successfully.\n";
    } 
    else
    {
        cout << "Maximum number of smartphones reached.\n";
    }
}

void DeleteSmartphone(string name) 
{
    for (int i = 0; i < numSmartphones; ++i) 
    {
        if (smartphones[i].name == name) 
        {
            for (int j = i; j < numSmartphones - 1; ++j) 
            {
                smartphones[j] = smartphones[j + 1];
            }
            --numSmartphones;
            cout << "Smartphone " << name << " deleted successfully.\n";
            return;
        }
    }
    cout << "Smartphone " << name << " not found.\n";
}

void ModifySmartphone(string name) 
{
    for (int i = 0; i < numSmartphones; ++i) 
    {
        if (smartphones[i].name == name) 
        {
            cout << "Enter new name: ";
            cin >> smartphones[i].name;
            cout << "Enter new screen diagonal: ";
            cin >> smartphones[i].screenDiagonal;
            cout << "Enter new processor: ";
            cin >> smartphones[i].processor;
            cout << "Enter new RAM size: ";
            cin >> smartphones[i].ram;
            cout << "Smartphone information modified successfully.\n";
            return;
        }
    }
    cout << "Smartphone " << name << " not found.\n";
}

void SortByProcessor() 
{
    for (int i = 0; i < numSmartphones - 1; ++i) 
    {
        for (int j = 0; j < numSmartphones - i - 1; ++j) 
        {
            if (smartphones[j].processor > smartphones[j + 1].processor) 
            {
                Smartphone temp = smartphones[j];
                smartphones[j] = smartphones[j + 1];
                smartphones[j + 1] = temp;
            }
        }
    }
}

void SaveSmartphonesToFile() 
{
    ofstream outFile("smartphones.bin", ios::binary | ios::out);
    if (!outFile) 
    {
        cout << "Unable to open file.\n";
        return;
    }
    outFile.write((char*)&numSmartphones, sizeof(numSmartphones));  
    outFile.write((char*)smartphones, numSmartphones * sizeof(Smartphone));  
    outFile.close();
    cout << "Smartphones saved to file successfully.\n";
}

void LoadSmartphonesFromFile() 
{
    ifstream inFile("smartphones.bin", ios::binary | ios::in);
    if (!inFile) 
    {
        cout << "Unable to open file or file does not exist.\n";
        return;
    }
    inFile.read((char*)&numSmartphones, sizeof(numSmartphones));
    inFile.read((char*)smartphones, numSmartphones * sizeof(Smartphone));
    inFile.close();
    
    cout << "Smartphones loaded from file successfully.\n";
}

void ShowSmartphones() 
{
    for (int i = 0; i < numSmartphones; ++i) 
    {
        cout << "\n";
        cout << "Smartphone name: " << smartphones[i].name << endl;
        cout << "Screen diagonal: " << smartphones[i].screenDiagonal << " inches" << endl;
        cout << "Processor: " << smartphones[i].processor << endl;
        cout << "RAM size: " << smartphones[i].ram << " GB" << endl;
    }
}

int main() 
{
    int choice;
    string smartphoneName;

    LoadSmartphonesFromFile();
do {
        cout << "\nMenu:\n";
        cout << "1. Show smartphones\n";
        cout << "2. Add smartphone\n";
        cout << "3. Delete smartphone\n";
        cout << "4. Modify smartphone information\n";
        cout << "5. Sort smartphones by ram\n";
        cout << "6. Save smartphones to file\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            ShowSmartphones();
            break;

        case 2:
            AddSmartphone();
            SaveSmartphonesToFile();
            break;

        case 3:
            cout << "Enter smartphone name to delete: ";
            cin >> smartphoneName;
            DeleteSmartphone(smartphoneName);
            SaveSmartphonesToFile();
            break;

        case 4:
            cout << "Enter smartphone name to modify: ";
            cin >> smartphoneName;
            ModifySmartphone(smartphoneName);
            SaveSmartphonesToFile();
            break;

        case 5:
            SortByProcessor();
            SaveSmartphonesToFile();
            break;

        case 6:
            SaveSmartphonesToFile();
            break;

        case 7:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
