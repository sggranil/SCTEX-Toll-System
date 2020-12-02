#include<stdio.h>
#include<conio.h>
#include<time.h>

struct sctex
    {
	int val, chooseMenu, chooseOpt, choosePay, orCode;
    } sctex;

    // Exits and Class
    char exits[11][130] = {"None","Dinalupihan","Floridablanca","Porac","Clark South","Mabalacat","Clark North","Dolores","Concepcion","San Miguel/Luisita","Tarlac"};

    // Kilometer Post and Fee
    int km[11] = {0,6,8,12,16,21,26,29,30,32,36};
    int feeFir = 56, feeSec = 136, feeThi = 207;

    // For Transactions Purposes and Calculations
    int account, amount, balance, load; // Account Number and Amount of Money inside FIle Pointer
    float tax = 0.12, total, taxDec, totalFir, totalSec, totalThi; // Invoice Calculation

void transact(); // Transactions
void transactETC(); // Payment via Easy-Tap
void transactPTP(); // Payment via Cash-via-Toll Exits
void loads();
void mapsFare(); // SCTEX Map and Fare Table


int main()
{

	time_t t;
	time(&t);

     clrscr();

       printf("    Metro Pacific Tollways Corporation\n      Subic-Clark-Tarlac Expressway\n\t%s\n", ctime(&t));
       printf("    1. Top Up Easy-Tap Account\n");
       printf("    2. Issue End-of-Expressway Toll Fee\n");
       printf("    3. SCTEX Map with Fare Table\n");
       printf("    4. Exit\n");
       printf("\t\t===> ");
       scanf("%d", &sctex.chooseMenu);

       switch(sctex.chooseMenu)
	{
	    case 1:
            clrscr();
            loads();
            case 2:
        clrscr();
            transact();  // Directs to Issue End-of-Expressway Toll Fee
            break;
	    case 3:
            clrscr();
            mapsFare();  // Directs to the SCTEX Maps and Toll Fee Board
            break;
	    case 4:
            printf("\n\tHave a safe trip!\n\t   2019 @MPTC\n");
            getch();
            exit(0);
	    default:
            main();
            break;
	}
    return 0;
}

void loads() // Loading Easy-Tap Account
{
	    // File opening
	    FILE *fpt;
	    // Account Verification
	    printf("\n\tEnter Account Number: ");
	    scanf("%d", &account);

	    switch(account)
		{
		    	case 201811:
			fpt = fopen("C:/Users/DeLL/Desktop/Simon.txt","w");
			printf("\tEnter Amount: ");
			scanf("%d", &load);
				// Verify
			printf("\n\tTop Up: P%d\n\tPress Any Key to Confirm", load);
			getch();
				// Confirm
			printf("\n\tThank You!");
			fprintf(fpt,"%d",load);
			fclose(fpt);
			getch();
			main();
			break;
			    default:
			printf("\n\tAccount not Verified!\n");
			clrscr();
			getch();
			main();
			break;
		}
	}

void transact() // Transactions
{
    // Header
    printf("\n   Subic-Clark-Tarlac Expressway\n    Tipo Interchange Toll Plaza\n\t(Gate 4) Southbound");
    printf("\n===================================\n\n");

    // Options
    printf("       Select Mode of Payment\n");
    printf("\t1. Easy-Tap\n");
    printf("\t2. Point-2-Point\n");
    printf("\t\t===> ");
    scanf("%d", &sctex.choosePay);

	switch(sctex.choosePay)
	{
	    case 1:
		transactETC();
		break;
	    case 2:
		transactPTP();
		break;
	    default:
		transact();
		break;
	}
}

    void transactETC() // Payment via Easy-Tap
    {
        clrscr();
	    // File opening
	    	FILE *fpt;
	    	fpt = fopen("C:/Users/DeLL/Desktop/Simon.txt","w");

	    // Menu
	    	printf("\n           Powered by Easy-Tap\n");
	    	printf("\tEnter Account Number: ");
	    	scanf("%d", &account); // Account Number on Switch Case
	    	printf("\tOrigin Code: ");
	    s	canf("%d", &sctex.orCode); // See Option 2 on Menu for the Code

	    // Calculations
		total = feeFir*sctex.orCode;
		taxDec = total*tax;
		balance = load-total;


	if (account = 201811)
	    {
		if (balance < 56)
		    {
			printf("\n\tInsufficient Fund!\n\n");
			getch();
			clrscr();
			main();
		    } else {
		    // Invoice
			printf("\n       ==========Transactions=========\n");
			printf("\tOrigin: %s | Class 1\n", exits[sctex.orCode]);
			printf("\tSubtotal: P%.2f\n", total-tax*total);
			printf("\t12%% VAT: P%.2f\n", taxDec);
			printf("\tTotal: P%.2f\n", total);
			printf("\tBalance: %d\n\n", balance);
		    // Re-verifying
			fprintf(fpt,"%d",balance);
			fclose(fpt);
		    // Closing
			printf("\n    Welcome to Subic Bay! Have a safe trip!\n\t        2019 @MPTC\n\n");
			getch();
			main();
		    }
		} else {
		    printf("\n\tAccount not Verified!\n");
		    getch();
		    clrscr();
		    transact();
	     }
	}

    void transactPTP() // Payment via Cash-via-Toll Exits
    {
	clrscr();
		int code, id, cash;
		printf("\n\tOrigin Code: "); // Point of Origin
		scanf("%d", &code);
		printf("\tClass: "); // Class Code
		scanf("%d", &id);

		// Calculations
		  totalFir = feeFir*code;
		  totalSec = feeSec*code;
		  totalThi = feeThi*code;
		  taxDec = total*tax;

		switch(id)
		    {
			case 1: // Class 1
			    printf("\n\tOrigin: %s | Class %d\n", exits[code], id);
			    printf("\tSubtotal: P%.2f\n", totalFir-tax*totalFir);
			    printf("\t12%% VAT: P%.2f\n", tax*totalFir);
			    printf("\tTotal: P%.2f\n", totalFir);
			    printf("\tCash: ");
			    scanf("%d", &cash);

		    if (cash < totalFir) // Expression
			{
			    printf("\n\tInvalid Input!\n");
			    getch();
			    clrscr();
			    transactPTP();
		    } else {
			printf("\tChange: P%.2f\n", cash-totalFir);
			printf("\n\tWelcome to Subic Bay! Keep safe!\n\n");
		    }

			    getch();
			    main();
			    break;
			case 2: // Class 2
			    printf("\n\tOrigin: %s | Class %d\n", exits[code], id);
			    printf("\tSubtotal: P%.2f\n", totalSec-tax*totalSec);
			    printf("\t12%% VAT: P%.2f\n", tax*totalSec);
			    printf("\tTotal: P%.2f\n", totalSec);
			    printf("\tCash: ");
			    scanf("%d", &cash);

		    if (cash < totalSec) // Expression
			{
			    printf("\n\tInvalid Input!\n");
			    getch();
			    clrscr();
			    transactPTP();
		    } else {
			printf("\tChange: P%.2f\n", cash-totalSec);
			printf("\n\tWelcome to Subic Bay! Keep safe!\n\n");
		    }

			    getch();
			    main();
			    break;
			case 3: // Class 3
			    printf("\n\tOrigin: %s | Class %d\n", exits[code], id);
			    printf("\tSubtotal: P%.2f\n", totalThi-tax*totalThi);
			    printf("\t12%% VAT: P%.2f\n", tax*totalThi);
			    printf("\tTotal: P%.2f\n", totalThi);
			    printf("\tCash: ");
			    scanf("%d", &cash);

		    if (cash < totalThi) // Expression
			{
			    printf("\n\tInvalid Input!\n");
			    getch();
			    clrscr();
			    transactPTP();
		    } else {
			printf("\tChange: P%.2f\n", cash-totalThi);
			printf("\n\tWelcome to Subic Bay! Keep safe!\n\n");
		    }

			    getch();
			    main();
			    break;
			default:
			    printf("\n\tInvalid Input!");
			    transactPTP();
			    break;
		    }
		}


void mapsFare() // SCTEX Map and Fare Table
{
    printf("\n     SCTEX Exits (Southbound) Fare as of November 2019\n\n");

    printf("KM No.\tClass 1 | Class 2 | Class 3\tCode\tExit\n\n");
    for (sctex.val=1;sctex.val<11;sctex.val++)
	    {
		printf("KM %d\t%d\t  %d\t    %d \t%d\t%s\n", km[sctex.val], feeFir*sctex.val, feeSec*sctex.val, feeThi*sctex.val, ++sctex.orCode, exits[sctex.val] );
	    }
    printf("\n\t\tPress Any Key to Continue\n");
    getch();
    main();
}
