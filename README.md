# OverflowProject
This tool is being developed to assist with binary exploitation and to further learn C.

## Purpose
This tool is meant to make testing for buffer overflows easier by printing arbitrary
amounts of characters based on user input.

Later in development my intention is to add an option to allow for addresses to be
inserted at the end of the printed strings to facilitate control of the instruction
pointer.

## Usage
**The count argument is required for this program to run properly**

* -a / --alphabet= Sets a flag that iterates the printed character every n amount of characters with the default being 4. So for example, AAAABBBB
* -c / --count    Sets a variable that is basically the length of the built string
* -l / --letter   Sets a variable to an supplied character, the default if this
                argument is not supplied is 'A' as is tradition
* -h / --help     Simply prints this usage section

## Build Instructions
On Linux and Windows Systems simply use the following commands

	git clone https://github.com/NealsSec/OverflowProject.git
	cd Overflowproject
	mkdir build
	cd build
	cmake ..
	cmake --build .

		