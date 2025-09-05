# OpalBolt's THE50 Keymap

**Features**
* 4-layer design: QWERTY (base), NU (numbers/nav), DK (Danish chars), FN (function keys)
* Right Shift: Hold for Danish layer access, Tap for Media Play/Pause
* Escape/Grave on single key (QK_GESC)
* LED feedback for Caps Lock state
* Danish character support (æøå/ÆØÅ) with US-INT keyboard layout compatibility
* Access to all number row, navigation, and function keys

**Layer Access**
* Hold spacebar (right side) → NU layer
* From NU layer, hold minus key → FN layer  
* Hold right shift → DK layer (Danish characters)

---

## Layer 0: QWERTY (Base Layer)
```
 ,-----------------------------------------------------------. ,--------------.
 |Esc | Q  | W  | E  | R  | T  | Y  | U  | I  | O  | P  |Bspc| | 7  | 8  | 9  |
 |-----------------------------------------------------------| |--------------|
 | Tab  | A  | S  | D  | F  | G  | H  | J  | K  | L  | Enter | | 4  | 5  | 6  |
 |-----------------------------------------------------------| |--------------|
 |Shift | Z  | X  | C  | V  | B  | N  | M  | ,  | .  |DK/Ply | | 1  | 2  | 3  |
 |-----------------------------------------------------------| |--------------|
 | Ctrl |Gui | Alt  |  NU+Spc  |     Spc    | -   | =  | /   | | 0  | .  |Entr|
 `-----------------------------------------------------------' `--------------'
```

## Layer 1: NU (Numbers/Navigation)
```
 ,-----------------------------------------------------------. ,--------------.
 | `  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 0  |Bspc| |Home|PgUp|Caps|
 |-----------------------------------------------------------| |--------------|
 |    |    |    |    |    |    |Left|Down| Up |Rght|   Del   | |End |PgDn|NumL|
 |-----------------------------------------------------------| |--------------|
 | Shift  |    |    |    |    |    | [  | ]  | ;  | '  |     | |    |    |    |
 |-----------------------------------------------------------| |--------------|
 | Ctrl|Gui |  Alt |            |            |  FN |    | \  | |    |    |BOOT|
 `-----------------------------------------------------------' `--------------'
```

## Layer 2: DK (Danish Characters) - Hold Right Shift
```
 ,-----------------------------------------------------------. ,--------------.
 |    |    |    |    |    |    |    |    |    | å  |    |    | |    |    |    |
 |-----------------------------------------------------------| |--------------|
 |      |    |    |    |    |    |    |    | æ  | ø  |       | |    |    |    |
 |-----------------------------------------------------------| |--------------|
 |        |    |    |    |    |    |    |    |    |    |     | |    |    |    |
 |-----------------------------------------------------------| |--------------|
 |     |    |      |            |            |     |    |    | |    |    |    |
 `-----------------------------------------------------------' `--------------'
```

## Layer 3: FN (Function Keys)
```
 ,-----------------------------------------------------------. ,--------------.
 |    | F1 | F2 | F3 | F4 | F5 | F6 |    |    |    |Ins |Del | |Home|PgUp|    |
 |-----------------------------------------------------------| |--------------|
 |      | F7 | F8 | F9 |F10 |F11 |F12 |    |    |    |       | |End |PgDn|    |
 |-----------------------------------------------------------| |--------------|
 | Shift  |    |    |    |    |    |    |    |    |    |     | |    |    |    |
 |-----------------------------------------------------------| |--------------|
 |EEPRST|    |      |            |           |     |    |    | |    |    |    |
 `-----------------------------------------------------------' `--------------'
```

---

## Key Reference
* `DK/Ply` = Right Shift: Hold for Danish layer, Tap for Media Play/Pause  
* `NU` = Hold for numbers/navigation layer
* `FN` = Hold for function keys layer
* `BOOT` = Put keyboard in bootloader mode for flashing
* `EEPRST` = Clear EEPROM settings

## Common Key Combinations
* **Numbers**: Hold NU + top row (1-0)
* **Symbols**: Hold NU + various keys (`, \, [, ], ;, ', /)
* **Navigation**: Hold NU + H/J/K/L (←↓↑→)
* **Function Keys**: Hold NU, then FN + Q-T (F1-F6) or A-G (F7-F12)
* **Delete**: Hold NU + Backspace
* **Insert**: Hold NU + FN + P
* **Danish Characters**: Hold right shift + K/L/O (æ/ø/å)
* **Uppercase Danish**: Hold right shift + left shift + K/L/O (Æ/Ø/Å)

---

## Configuration Files

### rules.mk
This file enables the QMK features needed for the keymap:

```makefile
SEND_STRING_ENABLE = yes
```

- **SEND_STRING_ENABLE**: Enables the `SEND_STRING()` macro functionality used for Danish character support. This allows the keyboard to send Alt-Gr key combinations that work with US-International keyboard layout.

### config.h  
This file contains configuration settings for timing compatibility:

```c
#pragma once

// Add delays to help with SEND_STRING timing and compatibility
#define TAP_CODE_DELAY 10
```

**Configuration Notes:**
- **TAP_CODE_DELAY**: Adds a small delay between key presses in `SEND_STRING()` macros to improve compatibility with different systems and applications (like Kitty terminal).

**Danish Character Implementation:**
The Danish characters (æøå) are implemented using `SEND_STRING()` with Alt-Gr combinations that work with US-International keyboard layout:
- `æ/Æ`: Alt-Gr + W (with optional Shift)
- `ø/Ø`: Alt-Gr + X (with optional Shift)  
- `å/Å`: Alt-Gr + L (with optional Shift)

This approach ensures compatibility with your existing US-INT layout and works reliably in terminals like Kitty.
