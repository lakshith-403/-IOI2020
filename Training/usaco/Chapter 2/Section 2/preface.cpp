/*
 ID: lakshit4
 LANG: C
 TASK: preface
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static char *encode[] = {
	"", "I", "II", "III", "IV",
	"V", "VI", "VII", "VIII", "IX",
};

char*
romandigit(int d, char *ivx)
{
	char *s, *p;
	static char str[10];

	for(s=encode[d%10], p=str; *s; s++, p++) {
		switch(*s){
		case 'I':
			*p = ivx[0];
			break;
		case 'V':
			*p = ivx[1];
			break;
		case 'X':
			*p = ivx[2];
			break;
		}
	}
	*p = '\0';
	return str;
}

char*
roman(int n)
{
	static char buf[20];

	strcpy(buf, "");
	strcat(buf, romandigit(n/1000, "M"));
	strcat(buf, romandigit(n/100,  "CDM"));
	strcat(buf, romandigit(n/10,   "XLC"));
	strcat(buf, romandigit(n,      "IVX"));
	return buf;
}

void
main(void)
{
	FILE *fin, *fout;
	int i, n;
	char *s;
	int count[256];

	fin = fopen("preface.in", "r");
	fout = fopen("preface.out", "w");
	assert(fin != NULL && fout != NULL);

	fscanf(fin, "%d", &n);

	for(s="IVXLCDM"; *s; s++)
		count[*s] = 0;

	for(i=1; i<=n; i++)
		for(s=roman(i); *s; s++)
			count[*s]++;

	for(s="IVXLCDM"; *s; s++)
		if(count[*s])
			fprintf(fout, "%c %d\n", *s, count[*s]);

	exit(0);
}