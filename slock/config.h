/* user and group to drop privileges to */
static const char *user  = "wittyjudge";
static const char *group = "wittyjudge";

static const char *colorname[NUMCOLS] = {
	[INIT]   = "black",     /* after initialization */
	[INPUT]  = "#005577",   /* during input */
	[FAILED] = "#CC3333",   /* wrong password */
	[CAPS]   = "#EAFF00",     /* CapsLock on */
};

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
		{ "color0",       STRING,  &colorname[INIT] },
		{ "color4",       STRING,  &colorname[INPUT] },
		{ "color1",       STRING,  &colorname[FAILED] },
		{ "color3",       STRING,  &colorname[CAPS] },
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;
