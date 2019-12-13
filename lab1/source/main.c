#include<stdio.h>
#include<stdlib.h>


int main() {

	typedef struct _student {

		char name[10];
		int chi;
		int math;
		int eng;
		int sum;
		float avg;

	}student;

	student data[5];
	FILE* stream1;
	FILE* stream2;

	int i;

	stream1 = fopen("C://GradeData.txt", "r");
	stream2 = fopen("C://GradeOP.txt", "w");

	if (stream1 == NULL || stream2 == NULL)
		printf("File Not Found!!!\n");
	else {

		fprintf(stream2, "\tName\tChinese\tMath\tEnglish\tSum\tAverage\n");

		for (i = 0; i < 5; i++) {

			fscanf_s(stream1, "%s", &data[i].name, 10);
			fscanf_s(stream1, "%d", &data[i].chi);
			fscanf_s(stream1, "%d", &data[i].math);
			fscanf_s(stream1, "%d", &data[i].eng);

			data[i].sum = data[i].chi + data[i].math + data[i].eng;
			data[i].avg = data[i].sum / 3.0;

			fprintf(stream2, "\t%s\t%d\t%d\t%d\t%d\t%.2f\n",
				data[i].name,
				data[i].chi,
				data[i].math,
				data[i].eng,
				data[i].sum,
				data[i].avg);

		}
		//fcloseall;
		fclose(stream1);
		fclose(stream2);




	}

	system("pause");
	return 0;

}