<h1 align="center">
	A small header generator 🤖
</h1>

## What is it ?
This small program automatically generates nicely formatted headers of all the non-static functions written in the C files present inside the directories passed as arguments  

## How to use it ?
```
./prototypes dir1 dir2 ...
```

This will generate a ```prototypes.txt``` file which will contain all headers of the non-static functions written in the files of the directories (recursively).  
For example, if ```dir1``` contains a file named ```file1.c``` and a directory named ```subdir``` which contains ```file2.c```, then all prototypes
of the non-static functions inside file1.c and file2.c will be nicely written and organized in the ```prototypes.txt``` file. You can then copy/paste
it to another file or just keep it as it is and rename your file into a ```.h``` file.

> **Warning**:  
> • There might be a small bug if you wrote a comment right above a function, the comment might be written to the file as well. I will fix it whenever I have time

### Enjoy and have fun 🎉
