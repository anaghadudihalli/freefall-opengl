# freefall-opengl
The concept of free fall demonstrated using OpenGL.


## Compiling and Execution

### Windows
This project was done in Visual Studio 2010. To run it :
 + Run the freefall-opengl.sln file.
 
### Linux
You will need to make few changes in order to run it in Linux.
To begin with:
+ *_sleep()* is a Windows function. To make it work in Linux replace *_sleep(100)* function on lines 248 and 263 with *sleep(1)* or any appropriate delay.
+ Include *unistd.h* header file
+ If it gives an 'should return int' error in main, return an int changing the return type of the main accordingly.

+ Install freeglut.

##### Ubuntu
    c++ freefall.cpp -lGL -lGLU -lglut
##### Arch Linux
    c++ -lglut -lGLU -lGL freefall.cpp


## License
![WTFPL](https://github.com/anaghadudihalli/freefall-opengl/blob/master/license.png)

This project is released under the [WTFPL](http://www.wtfpl.net/txt/copying/) (Do **W**hat **T**he **F**uck You Want To **P**ublic **L**icense)

