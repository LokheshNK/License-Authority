bool login(const string& username, const string& password)
{
    return (username == "admin" && password == "admin");
}
string findState(const string& numberPlate)
{
    string state = numberPlate.substr(0, 2);

    if (state == "AP") return "Andhra Pradesh";
    if (state == "AR") return "Arunachal Pradesh";
    if (state == "AS") return "Assam";
    if (state == "BR") return "Bihar";
    if (state == "CG") return "Chhattisgarh";
    if (state == "GA") return "Goa";
    if (state == "GJ") return "Gujarat";
    if (state == "HR") return "Haryana";
    if (state == "HP") return "Himachal Pradesh";
    if (state == "JH") return "Jharkhand";
    if (state == "KA") return "Karnataka";
    if (state == "KL") return "Kerala";
    if (state == "MP") return "Madhya Pradesh";
    if (state == "MH") return "Maharashtra";
    if (state == "MN") return "Manipur";
    if (state == "ML") return "Meghalaya";
    if (state == "MZ") return "Mizoram";
    if (state == "NL") return "Nagaland";
    if (state == "OD") return "Odisha";
    if (state == "PB") return "Punjab";
    if (state == "RJ") return "Rajasthan";
    if (state == "SK") return "Sikkim";
    if (state == "TN") return "Tamil Nadu";
    if (state == "TS") return "Telangana";
    if (state == "TR") return "Tripura";
    if (state == "UK") return "Uttarakhand";
    if (state == "UP") return "Uttar Pradesh";
    if (state == "WB") return "West Bengal";
    if (state == "AN") return "Andaman and Nicobar Islands";
    if (state == "CH") return "Chandigarh";
    if (state == "DN") return "Dadra and Nagar Haveli and Daman and Diu";
    if (state == "DD") return "Dadra and Nagar Haveli and Daman and Diu";
    if (state == "DL") return "Delhi";
    if (state == "JK") return "Jammu and Kashmir";
    if (state == "LA") return "Ladakh";
    if (state == "LD") return "Lakshadweep";
    if (state == "PY") return "Puducherry";

    return "State not found";
}

void addPersonalDetails()
{
    int type;
    string state,num,numberPlate;
    cout << "1. Add LLR Details" << endl;
    cout << "2. Add Licence Details" << endl;
    cout << "3. Add Aadhaar Details" << endl;
    cout<<"4. Owned Vechile details"<<endl;
    while (true)
        {
            try
            {
                cout << "Enter your choice: ";
                cin>>type;
                if (cin.fail())
                {
                    throw runtime_error("Invalid input. Date must be a number.");
                }
                break;
            }
            catch (const exception& e)
            {
                cerr << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

    if( type==1)
    {
        LLR llr;
        cin>>llr;
    }
    else if (type==2)
    {
        Licence lin;
        cin>>lin;
    }
    else if (type == 3)
    {
        Aadhaar Aad;
        cin>>Aad;
    }
    else if(type==4)
    {
        while(true)
        {
            cout<<"number plate : "<<endl;
            cin>>num;
            numberPlate = num;
            if (numberPlate.length() != 10)
            {
                cout<<"Error ...Reenter";
            }
            else if (!isalpha(numberPlate[0]) || !isalpha(numberPlate[1]))
            {
                cout<<"Error ...Reenter";
            }

            else if (!isdigit(numberPlate[2]) || !isdigit(numberPlate[3]))
            {
                cout<<"Error ...Reenter";
            }

            else if (!isalpha(numberPlate[4]) || !isalpha(numberPlate[5]))
            {
                cout<<"Error ...Reenter";
            }
            else if (!isdigit(numberPlate[6]) || !isdigit(numberPlate[7]) || !isdigit(numberPlate[8]) || !isdigit(numberPlate[9]))
            {
                cout<<"Error ...Reenter";
            }

            else
            {
                state=findState(numberPlate);
                cout << "State for number plate " << numberPlate << " is " << state << endl;
                break;
            }

        }


    }
    else
    {
        cout << "Error " << endl;
    }
}





void addFineDetails()
{
    Fine fin;
    cin>>fin;
    cout<<fin;
}




void accessRow()
{
    try
    {
        string searchKey;
        cout << "Enter LLR number, Licence number, or Aadhaar number to access the row: ";
        cin.ignore();
        getline(cin, searchKey);

        ifstream inFile("LICENCE.TXT");
        if (inFile.is_open())
        {
            string line;
            bool found = false;
            while (getline(inFile, line))
            {
                size_t pos = line.find(searchKey);
                if (pos != string::npos)
                {
                    cout << line << endl;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Row with search key '" << searchKey << "' not found." << endl;
            }
            inFile.close();
        }
        else
        {
            cout << "Error opening file for reading." << endl;
        }
    }
    catch (const exception& e)
    {
        cerr << e.what() << endl;
    }
}

void editDetails()
{
    try
    {
        string searchKey;
        cout << "Enter LLR number to edit the details: ";
        cin >> searchKey;

        ifstream inFile("LICENCE.TXT");
        ofstream tempFile("temp.txt"); // Temporary file to store modified data

        if (!inFile.is_open() || !tempFile.is_open())
        {
            cerr << "Error opening files for reading or writing." << endl;
            return;
        }

        string line;
        bool found = false;

        while (getline(inFile, line))
        {
            size_t pos = line.find(searchKey);
            if (pos != string::npos)
            {
                found = true;
                cout << "Existing details:\n" << line << endl;

                // Prompt user for the field to edit
                int fieldChoice;
                cout << "Select field to edit:\n"
                     "1. Name\n"
                     "2. Father's Name\n"
                     "3. Blood Group\n"
                     "4. LLR Number\n"
                     "5. Age\n"
                     "6. Licence Type\n"
                     "7. Date of Birth\n"
                     "8. Gender\n"
                     "9. Status\n"
                     "10. Mobile Number\n"
                     "11. Address\n"
                     "12. Issue Authority\n"
                     "13. Fine\n"
                     "14. Licence Number\n"
                     "15. Licence Issue date\n"
                     "16. licence expiry date\n"
                     "17. Aadhaar number\n";
                while (true)
                {
                    try
                    {
                        cout << "Enter choice: ";
                        cin >> fieldChoice;
                        if (cin.fail())
                        {
                            throw runtime_error("Invalid input. Date must be a number.");
                        }
                        break;
                    }
                    catch (const exception& e)
                    {
                        cerr << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                string newValue;
                cout << "Enter updated value: ";
                cin.ignore();
                getline(cin, newValue);

                // Find the position of the selected field
                size_t start = line.find('|');
                for (int i = 1; i < fieldChoice; ++i)
                {
                    start = line.find('|', start + 1);
                    if (start == string::npos)
                    {
                        cerr << "Invalid field choice." << endl;
                        return;
                    }
                }
                size_t end = line.find('|', start + 1);

                // Replace the field with the new value
                line.replace(start + 1, end - start - 1, newValue);
            }
            tempFile << line << '\n';
        }

        inFile.close();
        tempFile.close();

        if (!found)
        {
            cout << "Row with LLR number '" << searchKey << "' not found." << endl;
            return;
        }

        remove("LICENCE.TXT");
        rename("temp.txt", "LICENCE.TXT");

        cout << "Details updated successfully." << endl;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }
}



void displayFileContents()
{
    try
    {
        ifstream inFile("LICENCE.TXT");
        if(inFile.is_open())
        {
            cout << "********** FILE CONTENTS **********" << endl;
            string line;
            while (getline(inFile, line))
            {
                cout << line << endl;
            }
            inFile.close();
        }
        else
        {
            cout << "Error opening file for reading." << endl;
        }
    }
    catch (const exception& e)
    {
        cerr << e.what() << endl;
    }
}
