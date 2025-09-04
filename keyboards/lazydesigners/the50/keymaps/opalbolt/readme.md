# OpalBolt's THE50 Keymap

**Features**
* 3-layer design: QWERTY (base), NU (numbers/nav), FN (function keys)
* Left Shift acts as CapsLock when tapped, Right Shift acts as Media Play/Pause when tapped
* Escape/Grave on single key (QK_GESC)
* LED feedback for Caps Lock state
* Access to all number row, navigation, and function keys

**Layer Access**
* Hold spacebar (right side) → NU layer
* From NU layer, hold left spacebar → FN layer

---

## Layer 0: QWERTY (Base Layer)
```
 ,-----------------------------------------------------------. ,--------------.
 |Esc | Q  | W  | E  | R  | T  | Y  | U  | I  | O  | P  |Bspc| | 7  | 8  | 9  |
 |-----------------------------------------------------------| |--------------|
 | Tab  | A  | S  | D  | F  | G  | H  | J  | K  | L  | Enter | | 4  | 5  | 6  |
 |-----------------------------------------------------------| |--------------|
 |SftCap| Z  | X  | C  | V  | B  | N  | M  | ,  | .  |SftPly | | 1  | 2  | 3  |
 |-----------------------------------------------------------| |--------------|
 | Ctrl |Gui | Alt  |  Space  |    NU      | RAlt |RGui|RCtrl| | 0  | .  |Entr|
 `-----------------------------------------------------------' `--------------'
```

## Layer 1: NU (Numbers/Navigation)
```
 ,-----------------------------------------------------------. ,--------------.
 | `  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 0  |Del | |Home|PgUp|    |
 |-----------------------------------------------------------| |--------------|
 |    |    |    |    |    |Left|Down| Up |Rght| \  |       | | |End |PgDn|    |
 |-----------------------------------------------------------| |--------------|
 |        |    |    |    |    |    | [  | ]  | ;  | '  | /   | |    |    |    |
 |-----------------------------------------------------------| |--------------|
 |BOOT |    |      |   FN    |            |      |    |      | |    |    |    |
 `-----------------------------------------------------------' `--------------'
```

## Layer 2: FN (Function Keys)
```
 ,-----------------------------------------------------------. ,--------------.
 |    | F1 | F2 | F3 | F4 | F5 | F6 |    |    |    |Ins |Del | |Home|PgUp|    |
 |-----------------------------------------------------------| |--------------|
 |      | F7 | F8 | F9 |F10 |F11 |F12 |    |    |    |       | |End |PgDn|    |
 |-----------------------------------------------------------| |--------------|
 |        |    |    |    |    |    |    |    |    |    |     | |    |    |    |
 |-----------------------------------------------------------| |--------------|
 |EEPRST|    |      |         |            |      |    |     | |    |    |    |
 `-----------------------------------------------------------' `--------------'
```

---

## Key Reference
* `SftCap` = Shift when held, CapsLock when tapped
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

---
*Print this page for easy reference while learning your new layout!*
