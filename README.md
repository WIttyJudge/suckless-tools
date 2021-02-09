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

## Dmenu

Patches: 
 - [border](https://tools.suckless.org/dmenu/patches/border/)
 - [caseinsensitive](https://tools.suckless.org/dmenu/patches/case-insensitive/)
 - [center](https://tools.suckless.org/dmenu/patches/center/)
 - [lineheight](https://tools.suckless.org/dmenu/patches/line-height/)
 - [numbers](https://tools.suckless.org/dmenu/patches/numbers/)
