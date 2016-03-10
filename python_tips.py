#### Basic introduction ####

Application:	Web Application, system admin, program wrapper.

Interpreter:	Python is a interpretive language. Several kinds of interpreters. 
				CPython: use >>>
				IPython: use In []:
				Pypy: speed focus
				Jython: run on JAVA, interprets oython to java objective code
				IronPython: rons on .Net

I/O:			print("", "") autometically insert a space when encounters a comma
				input() reads in user input
				



#### Detailed tips ####


To modify list elements in place: use list comprehensions:
eg. image_index[0:] = [image[0].split() for image in image_index[0:]]

Pandas data frame: each row has an index, access row need iloc[] func if we pass an integer, or use loc[''] is we pass a label. 

Determine whether an element is in list:

3 in [1, 2, 3] :: return true



