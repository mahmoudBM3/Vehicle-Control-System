

void start_engine(struct system_state *systemptr);
void set_traffic_light(struct system_state *systemptr);
void set_room_tempreture(struct system_state *systemptr);
void set_engine_tempreture(struct system_state *systemptr);
void adjust_system(struct system_state *systemptr);
void print_sensors_menu(struct system_state *systemptr);
void print_main_menu();
void initialize_system(struct system_state *systemptr);
void display_system(struct system_state *systemptr);
char inputchar(char lim1, char lim2);

