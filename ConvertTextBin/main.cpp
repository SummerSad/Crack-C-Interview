#include <stdio.h>

void convertTextToBinary(FILE *text, FILE *bin)
{
	short M, N;
	fscanf(text, "%hi %hi", &M, &N);
	fwrite(&M, sizeof(short), 1, bin);
	fwrite(&N, sizeof(short), 1, bin);
	int temp;
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			fscanf(text, "%d", &temp);
			fwrite(&temp, sizeof(int), 1, bin);
		}
	}
}
void convertBinaryToText(FILE *bin, FILE *text)
{
	short M, N;
	fread(&M, sizeof(M), 1, bin);
	fread(&N, sizeof(N), 1, bin);
	fprintf(text, "%d %d\n", M, N);
	int temp;
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			fread(&temp, sizeof(int), 1, bin);
			fprintf(text, "%d ", temp);
		}
		fprintf(text, "\n");
	}
}

int main()
{
	FILE *f1 = fopen("text.txt", "r");
	if(f1 == NULL)
	{
		printf("No files\n");
		return 0;
	}
	FILE *f2 = fopen("bin.dat", "wb");
	convertTextToBinary(f1, f2);
	fclose(f1);
	fclose(f2);
	FILE *f3 = fopen("bin.dat", "rb");
	if(f3 == NULL)
	{
		printf("No files\n");
		return 0;
	}
	FILE *f4 = fopen("new.txt", "w");
	convertBinaryToText(f3, f4);
	fclose(f3);
	fclose(f4);
	return 0;
}
