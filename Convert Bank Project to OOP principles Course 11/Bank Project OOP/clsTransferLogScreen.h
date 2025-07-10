#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h"
#include"clsBankClient.h"
class clsTransferLogScreen : protected clsScreen
{
    static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
    {
        cout << setw(8) << left << "" << "| " << left << setw(23) << TransferLogRecord.DateTime;
        cout << "| " << left << setw(8) << TransferLogRecord.SourceAccount;
        cout << "| " << left << setw(8) << TransferLogRecord.DestinationAccount;
        cout << "| " << left << setw(8) << TransferLogRecord.Amount;
        cout << "| " << left << setw(10) << TransferLogRecord.SourceBalance;
        cout << "| " << left << setw(10) << TransferLogRecord.DestinationBalance;
        cout << "| " << left << setw(8) << TransferLogRecord.UserName;
    }

public:

	static void ShowTransferLogScreen()
	{
		vector<clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogList();

		string Title = "\t Transfer Log List Screen";
		string SubTitle = "\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if(vTransferLogRecord.size()==0)
            cout << "\t\t\t\t\n No Transfer Operations Available in the System! ";
        else
        {
            for (clsBankClient::stTransferLogRecord& TransferLogRecord : vTransferLogRecord)
            {
                _PrintTransferLogRecordLine(TransferLogRecord);
                cout << endl;
            }
        }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

	}
};

