#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "header.h"
#include <string.h>

const char* imeDatoteke = "zaposlenici.bin";


int main(void) {

	FILE* fp = NULL;
	fp = fopen(imeDatoteke, "ab");
	if (fp == NULL) {
		printf("Datoteka %s ne postoji na disku.\n", imeDatoteke);
	}
	else {
		printf("Datoteka %s postoji na disku.\n", imeDatoteke);
		fclose(fp);
	}

	pocetnoUcitavanje(imeDatoteke);

	printf("\t\t\t _             _       \n");
	printf("\t\t\t| | ___   __ _(_)_ __  \n");
	printf("\t\t\t| |/ _ \\ / _` | | '_ \\ \n");
	printf("\t\t\t| | (_) | (_| | | | | |\n");
	printf("\t\t\t|_|\\___/ \\__, |_|_| |_|\n");
	printf("\t\t\t         |___/         \n");
	

	printf("\n\n\n\t\tUnesite opciju koju zelite odabrati: ");
	printf("\n\n\t1. Admin");
	printf("\n\n\t2. Korisnik\n");

	int sve=0;
	do { scanf("%d", &sve); } while (sve != 1 && sve != 2);

	if (sve == 1) {

		
		char m[20] = { '\0' };
		int fail = 0;

		printf("\n\n\n\tUnesite lozinku: ");
		do {
		
			scanf("%18s", m);

			if (strcmp("asdf1234", m) == 0) {

				int uvjet = 1;

				while (uvjet) {
					uvjet = izbornik(imeDatoteke);
				}
			}
			else if (strcmp("asdf1234", m) != 0) {
				printf("\nPogresan unos.\n\n\t Ponovno unesite lozinku:   ");
				fail++;
				if (fail == 4) {
					printf("\n\n\nPresli ste broj pokusaja, program se zatvara.\n\n");
				}
			}
			else if (fail == 4) {
				printf("\n\n\nPresli ste broj pokusaja, program se zatvara.\n\n");
				return 0;
			}
		} while (fail != 4);
	}

	else if (sve == 2) {
		int cap = 1;

		while (cap) {
			cap = izbornik2(imeDatoteke);
		}

	}
	
	return 0;
}