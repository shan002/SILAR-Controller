uint8_t heart[8] = {0x0, 0xa, 0x1f, 0x1f, 0xe, 0x4, 0x0};

//Definitions
//----------------------
#define num_of_pos 4    // number of bikar postions
#define num_of_menu_opt 3
#define num_of_settings_opt 4
#define VCC 44
#define VCCx 42
#define puls_x 40
#define dir_x 38
#define ENx 36
#define VCCy 34
#define puls_y 32
#define dir_y 30
#define ENy 28

#define limit_b 52
#define limit_d 50
#define limit_u 48
#define limit_n 46



#define KEY keypad.getKey()
//----------------------


//Header Files
//-------------------------------
#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>

//-------------------------------


//Library Variables:
//----------------------------------------------------------------------------------------
//For Keypad:
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {45, 43, 41, 39}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {53, 51, 49, 47}; //connect to the column pinouts of the keypad
//----------------------------------------------------------------------------------------


//Global Variables
//----------------------
int total_xdis, total_ydis, pos_dis, count[2], y_ref, index=1, pre_index=1;
char total_settings[num_of_menu_opt+num_of_settings_opt][30];   // Array of strings. Contains all settings like speed, dip time, order of positions, number of repetition etc as strings specified by the user in "menu" function and "settings" function. For example first byte of this array can hold the returned char from the menu function, 2nd byte cn hold order of the positions, 3rd byte can hold can number of number of repetitions ...........         
char inp_ara[30];
bool b_state, d_state, u_state, n_state;
unsigned long time1, time2, timet = 27769492;
//----------------------


//Function Prototypes
//----------------------
void callibrate(void);                // Counts the number of steps along the total x_axis --------------- done
void go_init(void);                  // Returns to the most left(initial) position --------------- done
void x_axis(int n);                  // Goes along the x_axis 'n' number of steps. RIGHT for postive valeus and LEFT for negative --------------- done
void y_axis(int n);                  // Goes along the y_axis 'n' number of steps. DOWN for postive valeus and UP for negative --------------- done
void y_top(int len);                    // Goes to the top of the y_axis; // NOT done
void y_bottom(int dip_len);          // Goes to the bottome of the y_axis dip_len deep. dip_len is in steps. I will modify it for mm; // NOT done
void go_pos(char *order, int times); // Goes in the postion specified in the 'order' array and repeats this 'times' number of times --------------- done
char show_menu(void);                // Shows the menu and returns the selected operation as character --------------- INCOMPLETE
void settings(void);                 // Shows all the settings like speed, dip time and stores user input in 'total_settings' array --------------- INCOMPLETE
void Run(void);                      // Runs the silar machine based on the information on 'total_settings' array. Calls different functions like "go_pos" to run the operations --------------- NOT done
void dis_inp(int row, int col1, int col2);
void homepage(void);
void show_limit(void);
//----------------------

//Library Function Prototypes
//---------------------------------------------------------------------------
//For Keypad:
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
//For LCD:
LiquidCrystal_I2C lcd(0x27, 20, 4);
//---------------------------------------------------------------------------



void loop(){
//Serial.print(total_xdis);
//Serial.print('\t');
//Serial.println(total_ydis);
//while(1);

  homepage();
  while(KEY != 'A');
  settings();
  go_pos(total_settings[0], total_settings[1]);
  go_init();
  Serial.println(time2-time1);
}


void show_limit(void)
{
  Serial.print(digitalRead(limit_b));
  Serial.print("\t");
  Serial.print(digitalRead(limit_d));
  Serial.print("\t");
  Serial.print(digitalRead(limit_u));
  Serial.print("\t");
  Serial.println(digitalRead(limit_n));
}

