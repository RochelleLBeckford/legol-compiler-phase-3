# Legol Compiler - Phase 3

## A simple C program that simulates building and stacking Legol Building Blocks.

-   [ ] I am a huge Lego fan so I decided that I want to create a simple compiler based on this. A basic Legol-building-block language and output instructions. A single Legol command will be read from the user and then processes it. Then it will print what it is doing. Lastly the program will end.
-   [ ] Phase 3 of this project now has an interactive command loop! It will keep building until you say "End".

## What phase 3 does?

-   [ ] This program will now:
    -   [ ] Keep running until you type "END"
    -   [ ] Understands two main commands:
        -   [ ] `BUILD` -> creates single blocks
        -   [ ] `STACK` -> stack blocks together
    -   [ ] Shows results immediately after each command
    -   [ ] Still remembers everything in the symbol table

## How to Use

-   [ ] Run the program
-   [ ] Type one of these commands:
    -   [ ] `BUILD` `<color>` `<size>` (Example: `BUILD pink large`)
    -   [ ] `STACK` `<color>` `<size>` (Example: `STACK mint medium`)
    -   [ ] `END` (to stop the program)
-   [ ] See immediate results and the growing symbol table
-   [ ] The program keeps asking for commands until you type "END"

## Example

```
-> Welcome to the Legol Mini Compiler!
You can uae these commands:
BUILD <color> <size> -> to build a single Legol Building block
STACK <color> <size> -> to stack one Legol Building block on another
END -> to quit the program

Please enter Legol command:
BUILD pink medium

WORD TYPES:
BUILD (token1 = 1) = command
pink (token2 = 2) = color
medium (token3 = 3) = size

RESULT: You built a pink Legol Building block of size medium!

SYMBOL TABLE:
Word Type Description
BUILD  | Command | Command to build a Legol Block
pink   | Color   | Color of the Legol Block
medium | Size    | Size of the Legol Block

Please enter a Legol command:
END

WORD TYPES:
END (token1 = 1) = command

RESULT: All done! Bye bye!
```

## What You'll Learn: Phase 3

-   [ ] This version shows:
    -   [ ] How to make interactive programs with loops
    -   [ ] Processing different command structures
    -   [ ] Maintaining state between commands
    -   [ ] Immediate feedback for user actions

## Enjoying it's Growth

-   [ ] This program is now feels like a real interactive tool due to:
    -   [ ] You can now build many Legol building blocks
    -   [ ] It understands different command formats
    -   [ ] It remember everything you've done
    -   [ ] You can control when it ends

-   [ ] Encompass:
    -   [ ] C Programming Language
-   [ ] C → This language is best to use when writing a compiler, it is fast, and close to how computers actually work.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
