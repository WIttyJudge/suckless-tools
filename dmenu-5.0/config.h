/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

/* DMENU-CENTER PATCH */

/* -b  option; if 0, dmenu appears at bottom     */
static int topbar = 1;

/* -c option; centers dmenu on screen */
static int centered = 8;

/* minimum width when centered */
static int min_width = 500;

/* DMENU-BORDER PATCH */

/* Size of the window border */
static const unsigned int border_width = 2;

/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"monospace:size=13"
};

/* -p  option; prompt to the left of input field */
static const char *prompt      = NULL;      

static const char *colors[SchemeLast][2] = {
	/*     fg         bg       */
	[SchemeNorm] = { "#bbbbbb", "#222222" },
	[SchemeSel] = { "#eeeeee", "#005577" },
	[SchemeOut] = { "#000000", "#00ffff" },
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";
