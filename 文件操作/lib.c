/*  这是一个c库io接口的回顾：fopen fwrite fread fseek fclose
*      "r r+ w w+ a a+"
*/


#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<Windows.h>


//
//int main()
//{
//	
//#include <stdio.h>
//	FILE *stream, *stream2;
//	int numclosed;
//	/* Open for read (will fail if file "data" does not exist) */
//	if ((stream = fopen("data", "r")) == NULL)
//		printf("The file 'data' was not opened\n");
//	else
//		printf("The file 'data' was opened\n");
//	/* Open for write */
//	if ((stream2 = fopen("data2", "w+")) == NULL)
//		printf("The file 'data2' was not opened\n");
//	else
//		printf("The file 'data2' was opened\n");
//	/* Close stream */
//	if (fclose(stream2))
//		printf("The file 'data2' was not closed\n");
//	/* All other files are closed: */
//	numclosed = _fcloseall();
//	printf("Number of files closed by _fcloseall: %u\n", numclosed);
//	system("pause");
//	return 0;
//}







FILE *stream;
void main(void)
{
	long l;
	float fp;
	char s[81];
	char c;

	stream = fopen("fscanf.txt", "w+");
	if (stream == NULL)
		printf("The file fscanf.out was not opened\n");
	else
	{
		fprintf(stream, "%s %ld %f %c", "a-string",65000, 3.14159, 'x');

		/* Set pointer to beginning of file: */
		fseek(stream, 0, SEEK_SET);

		/* Read data back from file: */
		fscanf(stream, "%s %ld %f %c", s, &l, &fp, &c);

		/* Output data read: */
		printf("%s,%ld,%f,%c\n", s, l, fp, c);
		fclose(stream);
		system("pause");
	}
}




//
//FILE *stream;
//
//void main(void)
//{
//	int    i = 10;
//	double fp = 1.5;
//	char   s[] = "this is a string";
//	char   c = '\n';
//
//	stream = fopen("fprintf.txt", "w");
//	fprintf(stream, "%s%c", s, c);
//	fprintf(stream, "%d\n", i);
//	fprintf(stream, "%f\n", fp);
//	fclose(stream);
//}
//
//



