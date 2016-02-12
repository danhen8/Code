#include <Servo.h>

/********************************************************************************
*	This code is used to test the paralax Infrared Line Follower		*
*	along with 2 motor contorllers <insert name of motor contorller>	*
*	and 4 motors of the strider GTX.					*
*										*
*	The IRF identifies and returns 0's/1's; 0's				*
*	as white lines and 1's as black surfaces.				*
**********************************************************************************/

//*******************************************//
//    Declaration of Motor Controller PINs   //
//*******************************************//
#define MFR_A_PIN	11  // RIGHT MOTOR 
#define MFR_B_PIN	12 // LEFT MOTOR
#define MFR_PWM_PIN	13 	// PULSE WIDTH MODULATION PIN

//**************************************//
//      Declaration of the IRF PINs     //
//**************************************//
#define IRL_PIN_s0	22
#define IRL_PIN_s1	23
#define IRL_PIN_s2	24
#define IRL_PIN_s3	25
#define IRL_PIN_s4	26
#define IRL_PIN_s5	27
#define IRL_PIN_s6	28
#define IRL_PIN_s7	29
#define IRL_PIN_EN	30

int xFR = 147;
int xFL = 157;
int xBR = 130;
int xBL = 130;


/*
void Stop_Motors(void);
void IRL_Read(void);
void Forward_Motors(void);
*/

//***********************************************//
//    Stetting up peripherals to run code once   //
//***********************************************//
void setup()
{
	Serial.begin(9600); //Opens serial connection at 9600 baud rate
	
	//*****************************//
	//    Setting up Motor PINs    //
	//*****************************//
	pinMode(MFR_A_PIN,OUTPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(MFR_B_PIN,OUTPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(MFR_PWM_PIN,OUTPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	
	// Motor Front Left Side
	pinMode(MFL_A_PIN,OUTPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(MFL_B_PIN,OUTPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(MFL_PWM_PIN,OUTPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	 
	// Motor Back Right Side
	pinMode(MBR_A_PIN,OUTPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(MBR_B_PIN,OUTPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(MBR_PWM_PIN,OUTPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	
	// Motor Back Left Side
	pinMode(MBL_A_PIN,OUTPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(MBL_B_PIN,OUTPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(MBL_PWM_PIN,OUTPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output

	pinMode(IRL_PIN_s0, INPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(IRL_PIN_s1, INPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(IRL_PIN_s3, INPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(IRL_PIN_s4, INPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(IRL_PIN_s5, INPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(IRL_PIN_s6, INPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as output
	pinMode(IRL_PIN_s7, INPUT);		// Sets the pin mode of the I/O pin indicated by the #defined object as outpu
	pinMode(IRL_PIN_EN, OUTPUT);

}

int IRL_in;					// declaration of the buffer to store the output of all  s0- s7 pins of the KRF


void loop()
{
  IRL_Read();
  switch(IRL_in)
  {
    case 0b11111111: //off the line
    break;
    
    case 0b00000000: /// in a box
    break;
    
    case 0b11000011: case 0b11000111: case 0b11100011: //forward
    forward();
    break;
    
    case 0b00011111: case 0b00001111: case 0b00000111: case 0b00000011: //left 90 angle
    leftturn();
    break;
    
    case 0b11111000: case 0b11110000: case 0b11100000: case 0b11000000: //right 90 angle
    rightturn();
    break;
    
    case 0b00111111: case 0b10011111: case 0b11001111: case 0b10001111: case 0b10000111: case 0b10000011: //left curve
    leftcurve();
    break;
   
    case 0b11110011: case 0b11111001: case 0b11111100: case 0b11110001: case 0b11100001: case 0b11000001: //right curve
    rightcurve();
    break;
   
    
  }
    
}



void forward()
{
        Serial.println("Forward");
	digitalWrite(MFR_A_PIN, LOW);
	digitalWrite(MFR_B_PIN, HIGH);
	
	digitalWrite(MFL_A_PIN, LOW);
	digitalWrite(MFL_B_PIN, HIGH);
	
	analogWrite(MFR_PWM_PIN, xFR);
	analogWrite(MFL_PWM_PIN, xFL);
	
	analogWrite(MBR_PWM_PIN, xBR);
	analogWrite(MBL_PWM_PIN, xBL);
}

void rightcurve()
{
        Serial.println("rightcurve");
	digitalWrite(MFR_A_PIN, LOW);
	digitalWrite(MFR_B_PIN, HIGH);
	
	digitalWrite(MFL_A_PIN, LOW);
	digitalWrite(MFL_B_PIN, HIGH);
	
	analogWrite(MFR_PWM_PIN, 0);
	analogWrite(MFL_PWM_PIN, xFL);
	
	analogWrite(MBR_PWM_PIN, 0);
	analogWrite(MBL_PWM_PIN, xBL);
}

void rightturn()
{
        Serial.println("rightturnghtturn");
	digitalWrite(MFR_A_PIN, LOW);
	digitalWrite(MFR_B_PIN, HIGH);
	
	digitalWrite(MFL_A_PIN, LOW);
	digitalWrite(MFL_B_PIN, HIGH);
	
	analogWrite(MFR_PWM_PIN, 0);
	analogWrite(MFL_PWM_PIN, 255);
	
	analogWrite(MBR_PWM_PIN, 0);
	analogWrite(MBL_PWM_PIN, 255);
}

void leftcurve()
{
        Serial.println("leftcurve");
	digitalWrite(MFR_A_PIN, LOW);
	digitalWrite(MFR_B_PIN, HIGH);
	
	digitalWrite(MFL_A_PIN, LOW);
	digitalWrite(MFL_B_PIN, HIGH);
		
	analogWrite(MFR_PWM_PIN, xFR);
	analogWrite(MFL_PWM_PIN, 0);
	
	analogWrite(MBR_PWM_PIN, xBR);
	analogWrite(MBL_PWM_PIN, 0);
}

void leftturn()
{
        Serial.println("leftturn");
	digitalWrite(MFR_A_PIN, HIGH);
	digitalWrite(MFR_B_PIN, LOW);
	
	digitalWrite(MFL_A_PIN, HIGH);
	digitalWrite(MFL_B_PIN, LOW);
	
	analogWrite(MFR_PWM_PIN, 255);
	analogWrite(MFL_PWM_PIN, 0);
	
	analogWrite(MBR_PWM_PIN, 255);
	analogWrite(MBL_PWM_PIN, 0);
}

void IRL_Read()
{
	IRL_in = 0;
	
	for(int i = 0; i <= 7; i++)
	{
		IRL_in = (IRL_in << 1) + digitalRead(IRL_PIN_s7 - i);
	}
	Serial.println(IRL_in, BIN);
}

