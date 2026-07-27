#include "MyBank.h"
const string FileName = "Clients.txt";
const string UsersFileName = "Users.txt";
// ------------------------------------------------------------------
// Core helper implementations extracted from Project03.cpp
// ------------------------------------------------------------------
namespace MyBank
{
    void GoToMainMenue(stUser User);
    void PrintMainMenu(stUser User);
    void LoginScreen(stUser User);
    void ShowAccessDeniedMessage(stUser User);
    void ManageUsersMenuScreen(stUser User);
    int GetManageUsersOption();
    void RunUserManageChoice(int option, stUser User);

    bool isAccountRegistered(const vector<stClient> &Clients, const string &Value) {
        for (const stClient &c : Clients) {
            if (c.NbrAcount == Value) {
                return true;
            }
        }
        return false;
    }

    string ReadClientAccountNumber() {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }

    stClient FillClientStruct(const vector<stClient> &vClients) {
        stClient stClient;
        do {
            stClient.NbrAcount = MyLib::ReadString("\nEnter Account Number?  : ");
        } while (isAccountRegistered(vClients, stClient.NbrAcount));
        stClient.PinCode = MyLib::ReadString("\nEnter Pin Code?        : ");
        stClient.FullName = MyLib::ReadString("\nEnter Full Name?       : ");
        stClient.NbrPhone = MyLib::ReadString("\nEnter Phone number     : ");
        stClient.AccountBalance = MyLib::ReadPositiveNumber("\nEnter Account Balance? : ");
        return stClient;
    }

    string ConvertClientToLine(stClient stClien, string delm) {
        string line = "";
        line += stClien.NbrAcount + delm;
        line += stClien.PinCode + delm;
        line += stClien.FullName + delm;
        line += stClien.NbrPhone + delm;
        line += to_string(stClien.AccountBalance);
        return line;
    }

    stClient ConvertLinetoRecord(string line, string delm) {
        vector<string> splitedValue = MyLib::SplitEachWordInString(line, delm);
        stClient stClien;
        if (splitedValue.size() < 5) {
            cout << "\n[Warning] Corrupted record skipped: " << line << endl;
            stClien.MarkForDelete = true;
            return stClien;
        }
        stClien.NbrAcount = splitedValue[0];
        stClien.PinCode = splitedValue[1];
        stClien.FullName = splitedValue[2];
        stClien.NbrPhone = splitedValue[3];
        stClien.AccountBalance = stod(splitedValue[4]);
        return stClien;
    }

    void PrintClientRecord(stClient stClient) {
        cout << "\n this is the  Client Details : \n";
        cout << "\n Account Number : " << stClient.NbrAcount;
        cout << "\n Pin Code       : " << stClient.PinCode;
        cout << "\n Full Name      :" << stClient.FullName;
        cout << "\n Phone          :" << stClient.NbrPhone;
        cout << "\n Account Balance:" << stClient.AccountBalance;
    }

    void addLineInFile(fstream &MyFile, const string &line) {
        MyFile << line << "\n";
    }

    void AddClientInFile(string FileName) {
        fstream MyFile;
        char AddMore = 'y';
        MyFile.open(FileName, ios::out | ios::app);
        if (!MyFile.is_open()) {
            cout << "\nError opening file!";
            return;
        }
        vector<stClient> vClients = LoadClientsDataFromFile(FileName);
        do {
            stClient stClient = FillClientStruct(vClients);
            if (GetUserConfirmation() == 'Y') {
                vClients.push_back(stClient);
                string line = ConvertClientToLine(stClient, "#//#");
                addLineInFile(MyFile, line);
                cout << "\nthe Client has been added to File";
            }
            cout << "\nDo you want to add more Clients? | Y or N: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> AddMore;
        } while (toupper(AddMore) == 'Y');
        MyFile.close();
    }

    vector<stClient> LoadClientsDataFromFile(string FileName) {
        vector<stClient> Clients;
        fstream MyFile;
        MyFile.open(FileName, ios::in);
        if (MyFile.is_open()) {
            string Line;
            while (getline(MyFile, Line)) {
                if (MyLib::TrimSpaces(Line).empty())
                    continue;
                stClient c = ConvertLinetoRecord(Line, "#//#");
                if (!c.MarkForDelete)
                    Clients.push_back(c);
            }
        }
        MyFile.close();
        return Clients;
    }

    void ShowClientDetails(string filename) {
        vector<stClient> Clients = LoadClientsDataFromFile(filename);
        int size = Clients.size();
        cout << setw(49) << "Client List " << size << " Client(s). \n";
        cout << "_____________________________________________________________________________________________ " << endl;
        cout << "| Account Number  | Pin Code |          Client Name          |    Phone    |    Balance      |" << endl;
        cout << "_____________________________________________________________________________________________|" << endl;
        for (int i = 0; i < size; ++i) {
            cout << "|" << setw(17) << left << Clients[i].NbrAcount;
            cout << "|" << setw(10) << left << Clients[i].PinCode;
            cout << "|" << setw(31) << left << Clients[i].FullName;
            cout << "|" << setw(13) << left << Clients[i].NbrPhone;
            cout << "|" << setw(17) << left << Clients[i].AccountBalance << "|" << endl;
        }
        cout << "_____________________________________________________________________________________________|" << endl;
    }

    bool SearchClientInVector(const string &NbrAcc, const vector<stClient> &vClients, stClient &FoundClient, int &position) {
        string SearchValueUpper = MyLib::AllLettersToUpper(MyLib::TrimSpaces(NbrAcc));
        for (size_t i = 0; i < vClients.size(); ++i) {
            const stClient &c = vClients[i];
            if (MyLib::AllLettersToUpper(MyLib::TrimSpaces(c.NbrAcount)) == SearchValueUpper) {
                FoundClient = c;
                position = static_cast<int>(i);
                return true;
            }
        }
        return false;
    }
   
    bool SearchClientInFile(string FileName, string ClientID, stClient &FoundClient, int &position) {
        vector<stClient> vClients = LoadClientsDataFromFile(FileName);
        return SearchClientInVector(ClientID, vClients, FoundClient, position);
    }

    void PrintFoundClients(string FileName, string ClientID) {
        stClient FoundClient;
        int position = -1;
        bool isFound = SearchClientInFile(FileName, ClientID, FoundClient, position);
        if (isFound) {
            PrintClientRecord(FoundClient);
        } else {
            while (!isFound) {
                cout << "\nNo clients found.";
                ClientID = MyLib::ReadString("\nEnter Account Number  to Search : ");
                isFound = SearchClientInFile(FileName, ClientID, FoundClient, position);
            }
            PrintClientRecord(FoundClient);
        }
    }

    void ShowFindClientScreen(string FileName) {
        cout << "\n-----------------------------------\n";
        cout << "\tFind Client Screen";
        cout << "\n-----------------------------------\n";
        string ClientID = MyLib::ReadString("\nEnter Account Number  to Search : ");
        PrintFoundClients(FileName, ClientID);
    }

    void UpdateFile(const string &FileName, const vector<stClient> &Clients) {
        vector<string> vFileContent;
        for (const stClient &c : Clients) {
            vFileContent.push_back(ConvertClientToLine(c, "#//#"));
        }
        MyLib::SaveVectorToFile(FileName, vFileContent);
    }

    void RemoveClientFromFile(string FileName, string ClientAccountID) {
        vector<stClient> Clients = LoadClientsDataFromFile(FileName);
        stClient FoundClient;
        int position = -1;
        bool isFound = SearchClientInVector(ClientAccountID, Clients, FoundClient, position);
        if (!isFound) {
            while (!isFound) {
                cout << "\nNo clients found.";
                ClientAccountID = MyLib::ReadString("\nEnter Account Number  to Search : ");
                isFound = SearchClientInVector(ClientAccountID, Clients, FoundClient, position);
            }
        }
        cout << "\n the following client will be removed from the file : ";
        PrintClientRecord(FoundClient);
        if (GetUserConfirmation() == 'Y') {
            Clients.erase(Clients.begin() + position);
            UpdateFile(FileName, Clients);
            cout << "\nClient removed successfully.";
        }
    }

    void ShowDeleteClientScreen(string FileName) {
        cout << "\n-----------------------------------\n";
        cout << "\tDelete Client Screen";
        cout << "\n-----------------------------------\n";
        string ClientAccountID = MyLib::ReadString("\nEnter Account Number  to Remove : ");
        RemoveClientFromFile(FileName, ClientAccountID);
    }

    stClient ChangeClientData(const stClient &Client) {
        stClient updatedClient = Client;
        cout << "\nDo you want update the name ? | Y or N: ";
        char choise = 'n';
        cin >> choise;
        if (toupper(choise) == 'Y')
            updatedClient.FullName = MyLib::ReadString("\nEnter New Full Name?       : ");
        cout << "\nDo you want update the Pin Code ? | Y or N: ";
        cin >> choise;
        if (toupper(choise) == 'Y')
            updatedClient.PinCode = MyLib::ReadString("\nEnter New Pin Code?        : ");
        cout << "\nDo you want update the Phone number ? | Y or N: ";
        cin >> choise;
        if (toupper(choise) == 'Y')
            updatedClient.NbrPhone = MyLib::ReadString("\nEnter New Phone number     : ");
        cout << "\nDo you want update the Account Balance ? | Y or N: ";
        cin >> choise;
        if (toupper(choise) == 'Y')
            updatedClient.AccountBalance = MyLib::ReadPositiveNumber("\nEnter New Account Balance? : ");
        return updatedClient;
    }

    void UpdateClientInFile(string FileName, string ClientAccountID) {
        vector<stClient> Clients = LoadClientsDataFromFile(FileName);
        stClient FoundClient;
        int position = -1;
        bool isFound = SearchClientInVector(ClientAccountID, Clients, FoundClient, position);
        if (!isFound) {
            while (!isFound) {
                cout << "\nNo clients found.";
                ClientAccountID = MyLib::ReadString("\nEnter Account Number  to Search : ");
                isFound = SearchClientInVector(ClientAccountID, Clients, FoundClient, position);
            }
        }
        cout << "\n the following client will be updated from the file : ";
        PrintClientRecord(FoundClient);
        if (GetUserConfirmation() == 'Y') {
            Clients[position] = ChangeClientData(Clients[position]);
            UpdateFile(FileName, Clients);
            cout << "\nClient updated successfully.";
        }
    }

    void ShowUpdateClientScreen(string FileName) {
        cout << "\n-----------------------------------\n";
        cout << "\tUpdate Client Info Screen";
        cout << "\n-----------------------------------\n";
        string ClientAccountID = MyLib::ReadString("\nEnter Account Number  to Update : ");
        UpdateClientInFile(FileName, ClientAccountID);
    }

    enTransactionOptions GetTransactionChoice() {
        int choice = MyLib::Read_num_in_range("Enter your choice (1-4): ", 1, 4);
        return static_cast<enTransactionOptions>(choice);
    }

    enMenuOptions GetMenuChoice() {
        int choice = MyLib::Read_num_in_range("Enter your choice (1-8): ", 1, 8);
        return static_cast<enMenuOptions>(choice);
    }

    void DepositToAccount(string FileName, vector<stClient> &vClient, bool isFound, double Value, int position) {
        if (isFound && GetUserConfirmation() == 'Y') {
            vClient[position].AccountBalance += Value;
            UpdateFile(FileName, vClient);
            cout << "\nTransaction completed successfully.";
            cout << "\nNew Balance for account " << vClient[position].NbrAcount << " is: " << vClient[position].AccountBalance;
        }
    }

    void WithdrawFromAccount(string FileName, vector<stClient> &vClient, bool isFound, double Amount, int position) {
        while (Amount > vClient[position].AccountBalance) {
            cout << "\nInsufficient balance. Please enter a valid amount to withdraw: ";
            Amount = MyLib::ReadPositiveDoubleNumber("\nEnter Amount to Withdraw : ");
        }
        DepositToAccount(FileName, vClient, isFound, -Amount, position);
    }

    void ShowDepositScreen(string FileName) {
        cout << "\n-----------------------------------\n";
        cout << "\tDeposit Screen";
        cout << "\n-----------------------------------\n";
        int position = -1;
        stClient stFoundClient;
        vector<stClient> vClient = LoadClientsDataFromFile(FileName);
        string NbrAcc = MyLib::ReadString("\nEnter Account Number  to Deposit : ");
        bool isFound = SearchClientInVector(NbrAcc, vClient, stFoundClient, position);
        while (!isFound) {
            cout << "\nClient not found.";
            NbrAcc = MyLib::ReadString("\nEnter Account Number  to Search : ");
            isFound = SearchClientInVector(NbrAcc, vClient, stFoundClient, position);
        }
        PrintClientRecord(vClient[position]);
        double Value = MyLib::ReadPositiveDoubleNumber("\nEnter Amount to Deposit : ");
        DepositToAccount(FileName, vClient, isFound, Value, position);
    }

    void ShowWithdrawScreen(string FileName) {
        cout << "\n-----------------------------------\n";
        cout << "\tWithdraw Screen";
        cout << "\n-----------------------------------\n";
        int position = -1;
        stClient stFoundClient;
        vector<stClient> vClient = LoadClientsDataFromFile(FileName);
        string NbrAcc = MyLib::ReadString("\nEnter Account Number  to Withdraw : ");
        bool isFound = SearchClientInVector(NbrAcc, vClient, stFoundClient, position);
        while (!isFound) {
            cout << "\nClient not found.";
            NbrAcc = MyLib::ReadString("\nEnter Account Number  to Search : ");
            isFound = SearchClientInVector(NbrAcc, vClient, stFoundClient, position);
        }
        PrintClientRecord(vClient[position]);
        double Amount = MyLib::ReadPositiveDoubleNumber("\nEnter Amount to Withdraw : ");
        WithdrawFromAccount(FileName, vClient, isFound, Amount, position);
    }

    void ShowTotalBalance(string FileName) {
        vector<stClient> Clients = LoadClientsDataFromFile(FileName);
        int size = Clients.size();
        double sum = 0;
        cout << setw(49) << "Client List " << size << " Client(s). \n";
        cout << "_____________________________________________________________________________________________ " << endl;
        cout << "|     Account Number      |              Client Name               |         Balance         |" << endl;
        cout << "_____________________________________________________________________________________________|" << endl;
        for (int i = 0; i < size; ++i) {
            cout << "|" << setw(26) << left << Clients[i].NbrAcount;
            cout << "|" << setw(40) << left << Clients[i].FullName;
            cout << "|" << setw(25) << left << Clients[i].AccountBalance << "|" << endl;
            sum += Clients[i].AccountBalance;
        }
        cout << "_____________________________________________________________________________________________|" << endl;
        cout << "\nTotal Balances = " << sum << endl;
        cout << "_____________________________________________________________________________________________|" << endl;
    }

    void RunTheChoiceOfTransaction(enTransactionOptions choise, stUser User) {
        switch (choise) {
            case enTransactionOptions::Deposit:
                ShowDepositScreen(FileName);
                GoBackToTransactionMenu(User);
                break;
            case enTransactionOptions::Withdraw:
                ShowWithdrawScreen(FileName);
                GoBackToTransactionMenu(User);
                break;
            case enTransactionOptions::TotalBalances:
                ShowTotalBalance(FileName);
                GoBackToTransactionMenu(User);
                break;
            case enTransactionOptions::BackToMainMenu:
                GoToMainMenue(User);
                break;
            default:
                break;
        }
    }
    void GoToMainMenue(stUser User) {
        MyLib::PauseAndClearScreen();
        PrintMainMenu(User);
    }
    void TransactionsMenuScreen(stUser User) {
        system("clear");
        cout << "==================== Transactions Menu ====================\n";
        cout << "[1]. Deposit\n";
        cout << "[2]. Withdraw\n";
        cout << "[3]. Total Balances\n";
        cout << "[4]. Back to Main Menu\n";
        cout << "===========================================================\n";
        RunTheChoiceOfTransaction(GetTransactionChoice(), User);
    }

    char GetUserConfirmation() {
        cout << "\nAre you sure you want Confirm the Operation for This account ?  Y or N:    ";
        char userChoice;
        cin >> userChoice;
        if (toupper(userChoice) != 'Y') {
            cout << "\nOperation canceled.";
            return toupper(userChoice);
        }
        return toupper(userChoice);
    }

    bool HasPermission(stUser User, SystemPermissions PermissionsToCheck) {
        if (User.Permission == SystemPermissions::eAll)
            return true;
        return ((User.Permission & PermissionsToCheck) == PermissionsToCheck);
    }
void ShowAccessDeniedMessage(stUser User){
    cout << "\n-----------------------------------\n";
    cout << "\t Acces Denid,\n";
    cout << " You Dont Have Permission To Do This,\n";
    cout << " Please Contact Your Admin,\n";
    cout << "\n-----------------------------------\n";
    MyLib::PauseAndClearScreen();
    GoToMainMenue(User);  

}

bool IsUserAuthorized(stUser User, const string& UsersFileName, stUser& FoundUser) {
    // Placeholder implementation: always authorize and copy user
    FoundUser = User;
    return true;
}
int GetManageUsersOption() {
    // Default to 'Back to Main Menu' (option 6)
    return 6;
}

void RunUserManageChoice(int option, stUser User) {
    // Placeholder: simply return to main menu for any choice
    GoToMainMenue(User);
}

void ManageUsersMenuScreen(stUser User)
{
    system("clear");
    cout << "==================== Manage Users Menu ====================\n";
    cout << "[1]. List Users\n";
    cout << "[2]. Add New User\n";
    cout << "[3]. Delete Users\n";
    cout << "[4]. Update Users\n";
    cout << "[5]. Find Users\n";
    cout << "[6]. Back to Main Menu\n";
    cout << "===========================================================\n";
    RunUserManageChoice(GetManageUsersOption(),User);
}
void LoginScreen(stUser User)
{
    cout << "\n-----------------------------------\n";
    cout << "\tLogin Screen";
    cout << "\n-----------------------------------\n";
    bool Denid=false;
    stUser Found;
    do
    {
        User.UserName = MyIO::ReadString("Enter A User Name Please: ");
        User.Pasword = MyIO::ReadString("Enter A Password Please: ");

        Denid = !IsUserAuthorized(User,UsersFileName,Found);
        if (Denid)
            system("clear");
        else    
            User = Found ;   
        
    } while (Denid);
    PrintMainMenu(User);
}

void RunTheChoice(enMenuOptions choise,stUser User)
{
    system("clear");
    switch (choise)
    {
    case enMenuOptions::ShowClientsList:
    {
        if (HasPermission(User,SystemPermissions::eClientListe))
            ShowClientDetails(FileName);
        else 
            ShowAccessDeniedMessage(User);

        GoToMainMenue(User);
        break;
    }

    case enMenuOptions::AddClient:
    {
        if (HasPermission(User,SystemPermissions::eAddNewClient))
            ShowAddNewClientsScreen(FileName);
        else 
            ShowAccessDeniedMessage(User);

        GoToMainMenue(User);
        break;
    }

    case enMenuOptions::RemoveClient:
    {
        if (HasPermission(User,SystemPermissions::eDeleteClient))
            ShowDeleteClientScreen(FileName);
        else 
            ShowAccessDeniedMessage(User);

        GoToMainMenue(User);
        break;
    }

    case enMenuOptions::UpdateClientInfo:
    {
        if (HasPermission(User,SystemPermissions::eUpdateClient))
            ShowUpdateClientScreen(FileName);
        else 
            ShowAccessDeniedMessage(User);

        GoToMainMenue(User);
        break;
    }

    case enMenuOptions::FindClient:
    {
        if (HasPermission(User,SystemPermissions::eFindClient))
            ShowFindClientScreen(FileName);
        else 
            ShowAccessDeniedMessage(User);

        GoToMainMenue(User);
        break;
    }

    case enMenuOptions::TransactionOptions:
    {
        if (HasPermission(User,SystemPermissions::eTransaction))
            TransactionsMenuScreen(User);
        else 
            ShowAccessDeniedMessage(User);
        break;
    }
    case enMenuOptions::ManageUsers:
    {
        if (HasPermission(User,SystemPermissions::eManageUsers))
            ManageUsersMenuScreen(User);
        else 
            ShowAccessDeniedMessage(User);
        
        break;
    }
    case enMenuOptions::Logout:
    
        break;
    }
}
void PrintMainMenu(stUser User)
{

    system("clear");
    cout << "==================== Client Management System ====================\n";
    cout << "[1]. Add New Client\n";
    cout << "[2]. Show Clients List\n";
    cout << "[3]. Find Client\n";
    cout << "[4]. Update Client Info\n";
    cout << "[5]. Remove Client\n";
    cout << "[6]. Transactions\n";
    cout << "[7]. Manage Users\n";
    cout << "[8]. Logout\n";
    cout << "==================================================================\n";
    RunTheChoice(GetMenuChoice(),User);
}



    void GoBackToTransactionMenu(stUser User) {
        MyLib::PauseAndClearScreen();
        TransactionsMenuScreen(User);
    }

    void ShowAddNewClientsScreen(string FileName) {
        cout << "\n-----------------------------------\n";
        cout << "\tAdd New Clients Screen";
        cout << "\n-----------------------------------\n";
        AddClientInFile(FileName);
    }

    // Note: UI functions such as PrintMainMenu, RunTheChoice, etc., are omitted from this core library for brevity.
}