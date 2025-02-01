# A simple 2D game built using the MiniLibX graphical library. 👾

Project Developed as part of the 42 School curriculum. The game consists of navigating a player through a map to collect all items and reach the exit.
The project focuses on fundamental concepts like parsing, pathfinding, and event handling in C.

Features:
- Map Parsing & Validation: Ensures the map contains only allowed characters and validates the structure (rectangular shape, correct placement of player, collectibles, and exit).
 
- Pathfinding Logic: Uses a flood fill algorithm to guarantee that all collectibles and the exit are reachable.

- User Controls: Move the player using keyboard inputs (in this case WASD or arrow keys).

- Error Handling: Detects invalid maps and handles edge cases, such as missing exits or unreachable collectibles.

- Memory Management: Fully functional, with no memory leaks.

**How to Run:**

Clone the repository:

<pre> bash
$ git clone https://github.com/bussMatheus/so_long.git 
$ cd so_long </pre>

Clone The Minilibx (Linux) and compile with Make:
<pre> bash
$ git clone https://github.com/42Paris/minilibx-linux.git minilibx-linux
$ make </pre>

Run the game with a map file:

<pre> bash
$ ./so_long Maps/map1.ber </pre>


**Controls**: 

W / ↑: Move Up

A / ←: Move Left

S / ↓: Move Down

D / →: Move Right

ESC: Exit the game
