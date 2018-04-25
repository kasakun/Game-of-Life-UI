# Game-of-Life-UI
Adv. Programming Techniques

## TO DO
### Library input `Yijun Zhang`
Urgent! generate a 'Welcome' pattern when first open the game.
How to deal with *life, *.lif, etc.



### UI `Xibei Zhang`
Known Bugs: The stats is not cleared when restart and shifting modes.

### About mutli-threading
Since the overhead is mostly on opengl buffer binding. And based on GLFW documentation, we cannot
bind buffer when we are not in a main thread. Thus, we are not going to move on this part.

### Draw Mode
Since we are not moving on multi-threading. I will help with the draw mode and keep finding some thing
interesting.

What do need to do?
1. choose a pattern 
2. get mouse position
3. parse parameter to game().

## Others
String Mode? randomly choose stable or oscili type to construct words.