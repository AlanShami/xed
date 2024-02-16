# xed

#### A ***program*** that reads a file and output the content of it as a hex or a binary along with the addresses of the content in memory.


##### This program consist of the following files:

- [main.c](https://github.com/AlanShami/xed/blob/main/main.c)
- [method.h](https://github.com/AlanShami/xed/blob/main/method.h)
- [methods.c](https://github.com/AlanShami/xed/blob/main/methods.c)
- [Makefile](https://github.com/AlanShami/xed/blob/main/Makefile)

-----

#### To compile and run follow the below instructions:

1. Download or clone this repo locally.
2. Make sure you have **C compiler installed locally (gcc)**.
3. Within the repo directory run the following commands:
    - `make ` -> This will compile the whole program and produce (`xed` executable).  
   If `make` succeeds, it will give the below output:
   ~~~ 
      gcc -Wall -Wextra -std=c11 -c main.c
      gcc -Wall -Wextra -std=c11 -c methods.c
      gcc -Wall -Wextra -std=c11 -o xed main.o methods.o 
   ~~~
    - `./xed <filename>` --> this will read a file and output the `hexadecimal` of it. You can specify a `binary` format
      by passing `-b` to it as an argument.
* To delete all the executables and artifacts created by the `make` command, run: `make clean`. 

---
#### Example Output:

* An example output in hex format of the bashrc file:
~~~
./xed ~/.bashrc 
0000000: 2320 2e62 6173 6872 630a 0a23 2053 6f75 # .bashrc..# Sou
0000010: 7263 6520 676c 6f62 616c 2064 6566 696e rce global defin
0000020: 6974 696f 6e73 0a69 6620 5b20 2d66 202f itions.if [ -f /
0000030: 6574 632f 6261 7368 7263 205d 3b20 7468 etc/bashrc ]; th
0000040: 656e 0a09 2e20 2f65 7463 2f62 6173 6872 en... /etc/bashr
0000050: 630a 6669 0a0a 2320 556e 636f 6d6d 656e c.fi..# Uncommen
0000060: 7420 7468 6520 666f 6c6c 6f77 696e 6720 t the following 
0000070: 6c69 6e65 2069 6620 796f 7520 646f 6e27 line if you don'
0000080: 7420 6c69 6b65 2073 7973 7465 6d63 746c t like systemctl
0000090: 2773 2061 7574 6f2d 7061 6769 6e67 2066 's auto-paging f
00000a0: 6561 7475 7265 3a0a 2320 6578 706f 7274 eature:.# export
00000b0: 2053 5953 5445 4d44 5f50 4147 4552 3d0a  SYSTEMD_PAGER=.
00000c0: 0a23 2055 7365 7220 7370 6563 6966 6963 .# User specific
00000d0: 2061 6c69 6173 6573 2061 6e64 2066 756e  aliases and fun
00000e0: 6374 696f 6e73 0a                       ctions.
~~~

Then in binary format:
~~~
./xed -b ~/.bashrc 
0000000: 00100011#00100000 00101110.01100010b01100001a01110011s01101000h01110010r01100011c00001010.00001010.00100011#00100000 01010011S01101111o01110101u 
0000010: 01110010r01100011c01100101e00100000 01100111g01101100l01101111o01100010b01100001a01101100l00100000 01100100d01100101e01100110f01101001i01101110n 
0000020: 01101001i01110100t01101001i01101111o01101110n01110011s00001010.01101001i01100110f00100000 01011011[00100000 00101101-01100110f00100000 00101111/ 
0000030: 01100101e01110100t01100011c00101111/01100010b01100001a01110011s01101000h01110010r01100011c00100000 01011101]00111011;00100000 01110100t01101000h 
0000040: 01100101e01101110n00001010.00001001.00101110.00100000 00101111/01100101e01110100t01100011c00101111/01100010b01100001a01110011s01101000h01110010r 
0000050: 01100011c00001010.01100110f01101001i00001010.00001010.00100011#00100000 01010101U01101110n01100011c01101111o01101101m01101101m01100101e01101110n 
0000060: 01110100t00100000 01110100t01101000h01100101e00100000 01100110f01101111o01101100l01101100l01101111o01110111w01101001i01101110n01100111g00100000  
0000070: 01101100l01101001i01101110n01100101e00100000 01101001i01100110f00100000 01111001y01101111o01110101u00100000 01100100d01101111o01101110n00100111' 
0000080: 01110100t00100000 01101100l01101001i01101011k01100101e00100000 01110011s01111001y01110011s01110100t01100101e01101101m01100011c01110100t01101100l 
0000090: 00100111'01110011s00100000 01100001a01110101u01110100t01101111o00101101-01110000p01100001a01100111g01101001i01101110n01100111g00100000 01100110f 
00000a0: 01100101e01100001a01110100t01110101u01110010r01100101e00111010:00001010.00100011#00100000 01100101e01111000x01110000p01101111o01110010r01110100t 
00000b0: 00100000 01010011S01011001Y01010011S01010100T01000101E01001101M01000100D01011111_01010000P01000001A01000111G01000101E01010010R00111101=00001010. 
00000c0: 00001010.00100011#00100000 01010101U01110011s01100101e01110010r00100000 01110011s01110000p01100101e01100011c01101001i01100110f01101001i01100011c 
00000d0: 00100000 01100001a01101100l01101001i01100001a01110011s01100101e01110011s00100000 01100001a01101110n01100100d00100000 01100110f01110101u01101110n 
00000e0: 01100011c01110100t01101001i01101111o01101110n01110011s00001010.
~~~


**Notice that the address starts at 0**

---

#### Design Description:

*C language* was chosen for sufficiency and better manage memory and addressing. Different headers (standard C
libraries) were used to make development easier and for time saving.

- <ctype.h> : Provides a set of functions to test and map characters.
- <string.h> : Provides a collection of functions for manipulating C strings and arrays of characters.
- "method.h" : A header file developed for readability and to ease maintenance of the program, following best practices.

Different methods were developed to ease manage and maintain the code that are included in "methods.h" header file.

- `printBinary` method: Reads bytes from the specified file and prints their binary representation.
- `printHex` method: Reads bytes from the specified file and prints their hexadecimal representation.
- `printByteAsChar` method: This utility function is used by both printHex and printBinary to print the ASCII character
  representation of a byte if it is printable; otherwise, it prints a dot (.). This is used to display the file's
  content in a human-readable form alongside its hexadecimal or binary representation.

---

#### Known Deficiencies or Bugs:

The `xed` program may face efficiency issues with large files due to its fixed-size buffer approach and lacks robust
error handling and Unicode support. Its simplistic command-line parsing and fixed method for representing non-printable
characters could limit usability and accuracy in diverse file analysis scenarios.

####
*NOTE*: No deep or heavy testing were made, this project is STILL under development and NOT all type of files were tested. The program was tested on Linux and macOS environments.

Feel Free to create a PR or any suggestions (;
