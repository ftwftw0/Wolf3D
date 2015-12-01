# Wolf3D
Environment : MacOS - Yosemite

This is a Wold3D-like game that uses my Raycasting engine.

Raycasting is an old technic often known for being the first one used to make first-person shooters.

Raycasting is the fact of sending a ray in a direction to detect an intersection/collision into this direction, and it's distance.
In fact, maps are simple grids rather than polygon meshes, that's why it's not real 3D, it's kind of a fake but you get the immersion of a 3D environment without many of the complexities of "real 3D" to slow you down.
With that in mind, imagine a grid (which is our map) made of 0 and 1, 0 represents a cell you can walk on and 1 is a wall, you are in a cell of that grid, and you send a ray for each column of pixel of your raycasting game.
So for a game of 400x300 pixels you're gonna send 400rays for each frame.
Each ray you throw is gonna (or not) find a wall and it's distance thanks to lord Pythagore.
With these distance, you can trace a centered line in each column of pixel, which size relies on the distance you hit the wall.

You just understood how to do a basic 3D game. That's like magic.

Technologies used :
- C
- MinilibX (an unofficial graphical library only containing a function to put a colored point into it's window)
- Pythagore

Here's a preview :



(Won't work on Linux, this version of MinilibX -the unofficial graphical library that i used- is only for MacOS)
