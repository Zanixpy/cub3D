*This project has been created as part of the 42 curriculum by omawele, nbasheer.*

## Description
cub3D is a graphical design project that involves creating a "realistic" 3D representation of the inside of a maze from a first-person perspective. Inspired by the classic Wolfenstein 3D, this project utilizes a raycasting algorithm implemented in C to render the dynamic view. It serves as an exploration of practical mathematics, window management, event handling, and rendering utilizing the miniLibX library.

## Instructions

### Compilation
* **Compilation:** Run `make` at the root of the repository. This will compile the source files using `cc` with the mandatory `-Wall`, `-Wextra`, and `-Werror` flags.

### Execution
To run the program, provide a scene description file (with a `.cub` extension) as the first argument:
```bash
./cub3D map.cub
```

### Controls
* **W, A, S, D**: Move the point of view through the maze.
* **Left/Right Arrows**: Look left and right.
* **ESC** or **Window X button**: Close the window and quit the program cleanly.

## Resources

- [Raycasting tutorial by Lode](https://lodev.org/cgtutor/raycasting.html)

- [Make your own Raycaster Part 1 by 3DSage](https://www.youtube.com/watch?v=gYRrGTC7GtA&t=11s)

- [Ray casting in C by Daniel Hirsch](https://youtu.be/2IEUa2gYJHQ?si=NC_guqRyCDghi-6b)

* **AI Usage:** We used AI to understand the concept of raycasting generally.



