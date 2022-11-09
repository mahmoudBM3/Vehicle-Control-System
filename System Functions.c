#include"Definitions.c"
#include<stdio.h>
#include<stdlib.h>

char inputchar(char lim1, char lim2) {
	/*this functions ensures that the character input is valid and within the range given
	 as input and only returns a valid value and asks the user to re-enter the value if its invalid*/
	char input;
	while (1) {
		scanf(" %c", &input);
		if (((input >= lim1) && (input <= lim2))
				|| ((input >= (lim1 - 32)) && (input <= (lim2 - 32))))
			return input;
		else {
			printf("\nPlease enter a valid Input between %c and %c :", lim1,
					lim2);
			continue;
		}

	}

}

void display_system(struct system_state *systemptr) {
	/* This function displays the current state of the system*/
	//printing Engine state
	if (systemptr->engine) //state :ON=1 OFF=0
		printf("\nEngine state: ON");
	else
		printf("\nEngine state: OFF");
//printing AC state
	if (systemptr->AC) //state :ON=1 OFF=0
		printf("\nAC: ON");
	else
		printf("\nAC: OFF");
//Printing speed
	printf("\nVehichle Speed:%f", systemptr->speed);
//printin Room temp
	printf("\nRoom Tempreture:%f", systemptr->room_temp);
//printing Engine controller state
	if (systemptr->engine_temp_controller) //state :ON=1 OFF=0
		printf("\nEngine Tempreture Controller state: ON");
	else
		printf("\nEngine Tempreture Controller state: OFF");
//Printing Engine Temp
	printf("\nEngine Tempreture :%f\n\n", systemptr->engine_temp);

}

void initialize_system(struct system_state *systemptr) {
	//this function initializes the system to the default state
	systemptr->engine = OFF;
	systemptr->AC = OFF;
	systemptr->speed = 0;
	systemptr->room_temp = 20;
	systemptr->engine_temp_controller = OFF;
	systemptr->engine_temp = 125;
}

void print_main_menu() {
	/*this function Prints the main system menu */
	printf("\na. Turn on the vehicle engine");
	printf("\nb. Turn off the vehicle engine");
	printf("\nc. Quit the system");
	printf("\nYour Input : ");

}

void print_sensors_menu(struct system_state *systemptr) {
	/*This function returns the sensors menu when the sensors are turned on*/
	display_system(systemptr);
	printf("\na. Turn off the engine");
	printf("\nb. Set the traffic light color");
	printf("\nc. Set the room temperature");
	printf("\nd. Set the engine temperature");
	printf("\nYour Input : ");

}

void adjust_system(struct system_state *systemptr) {
	/*this function Checks the speed of the vehichle and if its the critical speed defined then the
	 * the system adjusts the AC and Engine Temp controller accordingly
	 */
	if (critspeed == systemptr->speed) {
		systemptr->engine_temp_controller = ON;
		systemptr->AC = ON;
		systemptr->engine_temp = systemptr->engine_temp * (5.0 / 4) + 1;
		systemptr->room_temp = systemptr->room_temp * (5.0 / 4) + 1;
	}

}
void set_engine_tempreture(struct system_state *systemptr) {
	/*
	 * Function responsible for Setting engine tempreture sensor
	 */
	printf("\nEnter Engine Tempreture :");
	float input;
	scanf("%f", &input);
	if ((input > 150) || (input < 100)) {
		systemptr->engine_temp_controller = ON;
		systemptr->engine_temp = 125;
		return;
	} else {
		systemptr->engine_temp = input;
		systemptr->engine_temp_controller = OFF;
		return;
	}

}

void set_room_tempreture(struct system_state *systemptr) {
	/*
	 * Function responsible for Setting Room tempreture sensor
	 */
	printf("\nEnter Room Tempreture :");
	float input;
	scanf("%f", &input);
	if ((input > 30) || (input < 10)) {
		systemptr->AC = ON;
		systemptr->room_temp = 20;
		return;
	} else {
		systemptr->room_temp = input;
		systemptr->AC = OFF;
		return;
	}

}

void set_traffic_light(struct system_state *systemptr) {
	/*
	 * Function responsible for Setting Traffic light color
	 */
	printf("\nEnter Traffic Color :");
	char input;
	scanf(" %c", &input);
	switch (input) {
	case 'r':
	case 'R':
		systemptr->speed = 0;
		break;
	case 'o':
	case 'O':
		systemptr->speed = 30;
		break;
	case 'g':
	case 'G':
		systemptr->speed = 100;
		break;
	default :
		printf("\nInvalid Value\n");
		break;

	}
	return;
}

void start_engine(struct system_state *systemptr) {
	/*
	 * The function responsible for controlling the vehichle when the engine is turned on
	 */
	while (1) {
		print_sensors_menu(systemptr);
		char choice = inputchar('a', 'd');
		switch (choice) {
		case 'a':
		case 'A':
			return;
		case 'b':
		case 'B':
			set_traffic_light(systemptr);
			adjust_system(systemptr);
			break;
		case 'c':
		case 'C':
			set_room_tempreture(systemptr);
			break;
		case 'd':
		case 'D':
			set_engine_tempreture(systemptr);
			break;
		}

	}

}

