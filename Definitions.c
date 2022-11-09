#define critspeed 30 //critical speed at which the system self-adjusts
//bool datatype contains for logic variables either true or false
typedef enum {
	FALSE=0,TRUE=1
}bool;

//this datatype defines the state of a device either on or off
typedef enum {
	ON=1,OFF=0
}state;
/*The following struct contains the state of the car */
struct system_state {
	state engine;
	state AC;
	float speed;
	float room_temp;
	state engine_temp_controller;
	float engine_temp;
};
