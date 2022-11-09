#include<stdio.h>
#include"Definitions.c"
#include"System Functions.h"
int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	struct system_state system1;
	initialize_system(&system1);
	while (1) {
		char choice = 'b';
		print_main_menu();
		choice = inputchar('a', 'c');
		switch (choice) {
		case 'a':
		case 'A':
			start_engine(&system1);
		case 'b':
		case 'B':
			continue;
		case 'c':
		case 'C':
			break;

		}
		break;
	}

}


