//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	        /*Command*/	 	/*Update Interval*/	/*Update Signal*/
	{"", "sb-microphone", 0,      20},
	{"", "sb-memory",	    2,      14},
	{"", "sb-cpu",        2,      18},
	{"", "sb-disk",       20,     16},
	{"", "sb-temp",       10,      8},
	{"", "sb-updates",    3600,    5},
	{"", "sb-weather",    0,       2},

	{"", "sb-keyboard",   0,      13},
	{"", "sb-internet",   5,       4},
	{"", "sb-volume",     0,      10},
  {"", "sb-clock",      60,      1},
};

//Sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char *delim = "|";
