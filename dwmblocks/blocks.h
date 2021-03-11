//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	        /*Command*/	 	/*Update Interval*/	/*Update Signal*/
	{"", "sb-microphone", 0,      20},
	{"", "sb-memory",	    2,      0},
	{"", "sb-cpu",        2,      18},
	{"", "sb-disk",       20,     16},
	{"", "sb-temp",       10,     0},
	{"", "sb-updates",    3600,   0},
	{"", "sb-weather",    1800,   0},

	{"", "sb-keyboard",   0,      1},
	{"", "sb-volume",     0,     10},
  {"", "sb-clock",      60,     0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = "|";
static unsigned int delimLen = 5;
