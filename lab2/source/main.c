#include<stdio.h>
#include<stdlib.h>

typedef struct _clientData {

	int acctNum;
	char lastName[15];
	char firstName[10];
	float balance;

}client;

void main() {

	FILE* pRead, *pWrite;
	FILE* cfPtr;

	int cnt = 0;
	client clientA = { 0,"","",0.0 };

	pRead = fopen("C://credit.txt", "r");
	if (pRead == NULL) {
		printf("Error_pRead\n\n");
		return 0;
	}

	pWrite = fopen("C://credit_bin.txt", "wb");	//write binary
	if (pWrite == NULL) {
		printf("Error_pWrite\n\n");
		fclose(pRead);
		return 0;
	}

	while (!feof(pRead)) {



		fscanf_s(pRead, "%d", &clientA.acctNum);
		fscanf_s(pRead, "%s", clientA.lastName, 15);
		fscanf_s(pRead, "%s", clientA.firstName, 20);
		fscanf_s(pRead, "%f", &clientA.balance);



		/*
		fscanf(pRead, "%d%s%s%1f",
			&clientA.acctNum,
			clientA.lastName,
			clientA.firstName,
			&clientA.balance );
			*/


		fwrite(&clientA, sizeof(struct _clientData), 1, pWrite);

		printf("%d\t%s\t%s\t%.2f\n",
			clientA.acctNum,
			clientA.lastName,
			clientA.firstName,
			clientA.balance);
	}

	fclose(pRead);
	fclose(pWrite);

	printf("已讀取文字檔的ASCII Data，並轉存成Binary Data File\n\n");

	system("pause");

	printf("讀取文字檔Binary Data File，並格式化輸出如下:\n");

	if ((cfPtr = fopen("C://credit_bin.txt", "rb")) == NULL)
		printf("File could not be opened.\n");
	else {
		printf("%-6s%-16s%-11s%10s\n",
			"Acct",
			"Last Name",
			"First Name",
			"Balance");

		cnt = fread(&clientA, sizeof(struct _clientData), 1, cfPtr);

		while (cnt > 0) {
			printf("%-6d%-16s%-11s%10.2f\n",
				clientA.acctNum,
				clientA.lastName,
				clientA.firstName,
				clientA.balance);

			cnt = fread(&clientA, sizeof(struct _clientData), 1, cfPtr);

		}

		fclose(cfPtr);

	}





	system("pause");
	

}

