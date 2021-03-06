#ifndef XBOX360CONTROLLER
#define XBOX360CONTROLLER


/// <summary>
/// Author: Jack Sinnott
/// Student Number: C00242525
/// Date: 16/09/2019
/// Estimated Time: 3 hrs
/// Actual Time: 6hrs 30 mins 
/// Known Bugs: 
/// </summary>

#include <SFML/Graphics.hpp>
#include <iostream>

/// <summary>
/// Data to store the current state of the controller
/// </summary>

struct GamePadState
{
	bool a;
	bool b;
	bool x;
	bool y;
	bool leftB;
	bool rightB;
	bool leftThumbStickClick;
	bool rightThumbStickClick;
	bool dPadUp;
	bool dPadDown;
	bool dPadLeft;
	bool dPadRight;
	bool start;
	bool back;
	bool xbox;
	float rTrigger;
	float lTrigger;
	sf::Vector2f rightThumbStick;
	sf::Vector2f leftThumbStick;
};


/// <summary>
/// Xbox controller class to query current state of controller
/// to mimic the controller states like XNA
/// </summary>

class Xbox360Controller
{
private:
	// deadzone for the dpad (joystick)
	const int DPAD_THRESHOLD = 50;
	sf::Joystick m_Joystick;

public:
	// newly added for multiple controller support not required in your
	// number of connected controllers
	static int s_noOfControllers;
	// index count for multiple controllers if connected
	int sf_Joystick_Index;
	// the current state of all the buttons
	GamePadState m_currentState;
	// The previous state to use to check for the moment a button is pressed
	GamePadState m_previousState;

	Xbox360Controller();
	~Xbox360Controller();
	void update();
	bool isConnect();
	bool connect();
	void buttonPresses();
	void axisCheck();
	void updatedCheck(bool* t_status, short t_button);
};

#endif // !XBOX360CONTROLLER


