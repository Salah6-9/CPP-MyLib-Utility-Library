#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <limits>
#include "MyLib.h"

using namespace std;
namespace MyBank
{
    // Data structures
    struct stClient {
        string NbrAcount, PinCode, FullName, NbrPhone;
        double AccountBalance;
        bool MarkForDelete = false;
    };

    struct stUser {
        string UserName;
        string Pasword;
        int Permission = 0;
        bool MarkForDelete = 0;
    };

    enum enMenuOptions {
        AddClient = 1,
        ShowClientsList,
        FindClient,
        UpdateClientInfo,
        RemoveClient,
        TransactionOptions,
        ManageUsers,
        Logout
    };

    enum enTransactionOptions {
        Deposit = 1,
        Withdraw,
        TotalBalances,
        BackToMainMenu
    };

    enum SystemPermissions {
        eAll = -1,
        eClientListe  = 1 << 0,
        eAddNewClient = 1 << 1,
        eDeleteClient = 1 << 2,
        eUpdateClient = 1 << 3,
        eFindClient   = 1 << 4,
        eTransaction  = 1 << 5,
        eManageUsers  = 1 << 6
    };

    // Function declarations (core reusable API)
    bool isAccountRegistered(const vector<stClient> &Clients, const string &Value);
    string ReadClientAccountNumber();
    stClient FillClientStruct(const vector<stClient> &vClients);
    string ConvertClientToLine(stClient stClien, string delm = " ");
    stClient ConvertLinetoRecord(string line, string delm = " ");
    void PrintClientRecord(stClient stClient);
    void addLineInFile(fstream &MyFile, const string &line);
    void AddClientInFile(string FileName = "Clients.txt");
    vector<stClient> LoadClientsDataFromFile(string FileName);
    void ShowClientDetails(string filename);
    bool SearchClientInVector(const string &NbrAcc, const vector<stClient> &vClients, stClient &FoundClient, int &position);
    bool SearchClientInFile(string FileName, string ClientID, stClient &FoundClient, int &position);
    void PrintFoundClients(string FileName, string ClientID);
    void ShowFindClientScreen(string FileName);
    void UpdateFile(const string &FileName, const vector<stClient> &Clients);
    void RemoveClientFromFile(string FileName, string ClientAccountID);
    void ShowDeleteClientScreen(string FileName);
    stClient ChangeClientData(const stClient &Client);
    void UpdateClientInFile(string FileName, string ClientAccountID);
    void ShowUpdateClientScreen(string FileName);
    enTransactionOptions GetTransactionChoice();
    enMenuOptions GetMenuChoice();
    void DepositToAccount(string FileName, vector<stClient> &vClient, bool isFound, double Value, int position);
    void WithdrawFromAccount(string FileName, vector<stClient> &vClient, bool isFound, double Amount, int position);
    void ShowDepositScreen(string FileName);
    void ShowWithdrawScreen(string FileName);
    void ShowTotalBalance(string FileName);
    void RunTheChoiceOfTransaction(enTransactionOptions choise, stUser User);
    void TransactionsMenuScreen(stUser User);
    void RunTheChoice(enMenuOptions choise, stUser User);
    char GetUserConfirmation();
    bool HasPermission(stUser User, SystemPermissions PermissionsToCheck);
    void GoBackToTransactionMenu(stUser User);
    void ShowAddNewClientsScreen(string FileName);
}