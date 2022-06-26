# Suckless tools

Repository contains my personal settings for [suckless](suckless.org) tools.

Suckless tools is a quality software with a focus on simplicity, clarity, and frugality.

## Patching

There are all extensions (patches) in ``patches`` folder.

Go to the folder, for example:
```
cd dmenu-5.0
```

```
$ patch -p1 < patches/to/patch.diff
$ sudo make clean install
```

if you want to delete extension (unpatches).
```
patch -R < patches/patch.diff
```

## DWM

Patches:
 - [vanitygaps](https://dwm.suckless.org/patches/vanitygaps/) - Control inner, outer, horizontal and vertical gaps independently.
 - [attachasideandbelow](https://dwm.suckless.org/patches/attachasideandbelow/) - Combination between attachaside and attachbelow.
 - [stacker](https://dwm.suckless.org/patches/stacker/) - Keybindings to focus on, or push, any client in the slack.
 - [systray]()

 - [statuspadding](https://dwm.suckless.org/patches/statuspadding/) - Add horizontal and vertical padding in the statusbar.
 - [titlecolor](https://dwm.suckless.org/patches/titlecolor) - Add a new color schema used by window title.
 - [hide vacant tags](https://dwm.suckless.org/patches/hide_vacant_tags/) - prevent drawing tags with not clients on the bar.

 - [xresources](https://dwm.suckless.org/patches/xresources/) - Reads colors and additional settings from Xresources.

 - [dwmblocks(2)](https://gist.github.com/danbyl/54f7c1d57fc6507242a95b71c3d8fdea) - Add support for clickable dwmblocks via statuscmd.

## Dmenu

Patches:
 - [border](https://tools.suckless.org/dmenu/patches/border/)
 - [caseinsensitive](https://tools.suckless.org/dmenu/patches/case-insensitive/)
 - [center](https://tools.suckless.org/dmenu/patches/center/)
 - [lineheight](https://tools.suckless.org/dmenu/patches/line-height/)
 - [numbers](https://tools.suckless.org/dmenu/patches/numbers/)

## ST

Patches:
 - [alpha](https://st.suckless.org/patches/alpha/) - Adds opacity to the background (must have a compositor for this to work).
 - [font2](https://st.suckless.org/patches/font2/) - Adds the option to list multiple fonts.
 - [ligature](https://st.suckless.org/patches/ligatures/) - Adds ligature support (required harfbuzz).
 - [xresources](https://st.suckless.org/patches/xresources/) - Adds the ability to configure st via Xresources.
 - [workingdir](https://st.suckless.org/patches/workingdir/) - Adds option to open st at specific directory (ex: st -d ~/folder).
 - [scrollback](https://st.suckless.org/patches/scrollback/) - Adds scrollback with SHIFT+PageUp/PageDown.
 - [scrollback-mouse](https://st.suckless.org/patches/scrollback/) - Adds the ability to scroll with SHIFT+MouseWheel.
 - [scrollback-mouse-altscreen](https://st.suckless.org/patches/scrollback/) - Now you can scroll with just the MouseWhell (no SHIFT required).
 - [vertcenter](https://st.suckless.org/patches/vertcenter/) - Better vertical alignment.
 - [bold is not bright](https://st.suckless.org/patches/bold-is-not-bright/) - Bold text should be bold, not bright.
  

## Slock

Patches:
 - [Capscolor](https://tools.suckless.org/slock/patches/capscolor/) - Add color to indicate the state of Caps Lock.
 - [Xresources](https://tools.suckless.org/slock/patches/xresources/) - Reads colors and additional settings from Xresources.
