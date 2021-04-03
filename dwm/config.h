/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 3;       /* snap pixel */

/* dwm-vanitygaps patch */
static const unsigned int gappih    = 8;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 8;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */

static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const unsigned int barpadh   = 7;        /* padding height to add to te status bar */
static const unsigned int barpadw   = 1;        /* padding width to add around text on the status bar */

static const char *fonts[]          = { "monospace:pixelsize=12",
	                                    "JoyPixels:size=10:antialias=true:autohint=true" };

static const char dmenufont[]       = "UbuntuMono Nerd Font:size=10";
static const char col_gray1[]       = "#2e3440";
static const char col_gray2[]       = "#2e3440";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#5e81ac";
static const char col_green[]       = "#a3be8c";
static const char col_red[]         = "#bf616a";
static const char col_yellow[]      = "#ebcb8b";
static const char col_orange[]      = "#d08770";

static const char *colors[][3]      = {
	/*				          	fg         bg        border   */
	[SchemeNorm]   = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]    = { col_gray4, col_cyan, col_cyan },
	[SchemeRed]    = { col_red, col_gray1, col_gray2 },
	[SchemeYellow] = { col_yellow, col_gray1, col_gray2 },
	[SchemeOrange] = { col_orange, col_gray1, col_gray2},
	[SchemeGreen]  = { col_green, col_gray1, col_gray2},
	[SchemeBlue]   = { col_cyan, col_gray1, col_gray2},
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9"};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/*  class      instance    title                  tags mask      iscentered     isfloating   monitor */
	{ "chromium",    NULL,       NULL,                 1 << 1,          0,              0,          -1 },
	{ "brave",       NULL,       NULL,                 1 << 1,          0,              0,          -1 },

	{ "telegram",    NULL,       NULL,                 1 << 3,          1,              1,          -1 },
	{ "discord",     NULL,       NULL,                 1 << 3,          0,              0,          -1 },
 
	{ "steam",       NULL,       NULL,                 1 << 4,          0,              0,          -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} }, \
	{ MODKEY|Mod1Mask,              KEY,      tagnextmon,     {.ui = 1 << TAG} }, \
	{ MODKEY|Mod1Mask|ShiftMask,    KEY,      tagprevmon,     {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define CMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	/* { MODKEY,                    XK_p,      spawn,          {.v = dmenucmd } }, */
	{ MODKEY,                       XK_b,      togglebar,      {0} },

  /* Chage size */
	{ MODKEY|ShiftMask,             XK_l,      rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_h,      rotatestack,    {.i = -1 } },

	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },

  /* Resize */
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.03} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.03} },

	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },

	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	/* { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} }, */
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },

	{ MODKEY|ControlMask,		        XK_comma,  cyclelayout,    {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, cyclelayout,    {.i = +1 } },
	{ MODKEY,                       XK_space,  setlayout,      {0} },

	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_f,      fullscreenmode, {0} },

	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY|Mod1Mask,              XK_space,  spawn,          CMD("rofi -modi drun -show drun -show-icons") },
	{ MODKEY|Mod1Mask,              XK_c,      spawn,          CMD("rofi -show emoji -modi emoji") },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_x,      quit,           {1} },
	{ MODKEY|ControlMask|ShiftMask, XK_x,      quit,           {0} }, 
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

