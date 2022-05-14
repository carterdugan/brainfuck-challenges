# What is Brainfuck?

Brainfuck is an incredibly simple esoteric programming language
that serves no real purpose other than to challenge masochistic
programmers. Brainfuck works by manipulating bytes of memory
with 8 possible instructions:

* `>` Shift right to the next byte of memory
* `<` Shift left to the previous byte of memory
* `+` Increment the current byte of memory by 1
* `-` Decrement the current byte of memory by 1
* `.` Output the current byte of memory
* `,` Assign a byte of input to the current byte of memory
* `[` Jump to the instruction after the matching `]` when the
current byte is equal to 0
* `]` Jumpt to the instruction after the matching `[` when the
current byte is not equal to 0

The following resources are incredibly helpful in understanding
the history and nature of the brainfuck language:
* [The Brainfuck Wiki](https://en.wikipedia.org/wiki/Brainfuck#Commands)
* [Brainfuck in 100 Seconds](https://www.youtube.com/watch?v=hdHjjBS4cs8)

# What is this project?

The real purpose of this project is to improve my problem
solving skills and to build my portfolio. I also just think it
would be a lot of fun.

It is worth noting that I have minimal experience in writing
brainfuck code. The little research I have done on existing
brainfuck programs has shown the most people have fine-tuned
their projects to be efficient and clever. While I believe that
is a good thing to do, I think it would be beneficial to learn
these tricks as I go and I will not be improving the challenges
after I complete them in order to make the learning process
accesible to anyone else who might be idiotic enough to follow
in my footsteps in this stupid journey.

# Table of Contents

* The interpreter
* Hello World
* Adding two numbers
* The Square