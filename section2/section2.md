## Chapter2: Representing and Manipulating Information

### Software used for code:
- OS
    - Slackware Live Xfce (15+) 23/04/25 - 32bit version
- Compiler/debugger
    - gcc (GCC) 14.2.0
    - GNU gdb (GDB) 16.3

- Document creation
    - git version 2.46.3
    - Visual Studio Code version 1.99.3

### Related resources
- [My Miscellaneous notes](misc.md#miscellaneous-notes)
- [Video Lectures: 2015 Fall 15-213 Introduction to Computer Systems](https://scs.hosted.panopto.com/Panopto/Pages/Sessions/List.aspx#folderID=%22b96d90ae-9871-4fae-91e2-b1627b43e25e%22)
- [Video Lecture 02: Bits, Bytes, and Integers](https://scs.hosted.panopto.com/Panopto/Pages/Viewer.aspx?id=6ca8cdb4-6961-42d9-8fac-299e53759a17)
- [Video Lecture 03: Bits, Bytes, and Integers (cont.)](https://scs.hosted.panopto.com/Panopto/Pages/Viewer.aspx?id=526e6341-aa53-4107-8fa1-d13c0e92342e)
- [Video Lecture 04: Floating Point](https://scs.hosted.panopto.com/Panopto/Pages/Viewer.aspx?id=8dd08ed5-7688-4b34-937f-201b909f61c7)
- [Alt. bad audio Video Lecture 04: Floating Point](https://www.youtube.com/watch?v=Q-JcxMNgrkU&t=19s)
- [website | float.exposed](https://float.exposed/0x44bf9400)
- [Section2 Errata (Hardback Edition)](./errata.txt)
- [Hexadecimal to Decimal converter](https://www.rapidtables.com/convert/number/hex-to-decimal.html)
- [Learning to Bit Twiddle and Optimize](https://wiredream.com/learning-to-bit-twiddle/)
- [Dive into Systems | Bitwise Operators](https://diveintosystems.org/singlepage/#_bitwise_operators)

## Table of Contents
- [Chapter 2 Practice problems TOC](#chapter-2-practice-problems-toc)
- [Chapter 2 Web Asides TOC](#chapter-2-web-asides-toc)

### Chapter 2 Practice problems TOC

- [My code for practice problems](./practice-problems/code/)
- [Practice Problems 2.1 | Hexadecimal Notation](./practice-problems/problem2-1.md)
- [Practice Problems 2.2 | Hexadecimal Notation](./practice-problems/problem2-2.md)
- [Practice Problems 2.3 | Hexadecimal Notation](./practice-problems/problem2-3.md)
- [Practice Problems 2.4 | Hexadecimal Notation](./practice-problems/problem2-4.md)
- [Practice Problems 2.5 | Addressing and Byte Ordering](./practice-problems/problem2-5.md)
- [Practice Problems 2.6 | Addressing and Byte Ordering](./practice-problems/problem2-6.md)
- [Practice Problems 2.7 | Representing Strings](./practice-problems/problem2-7.md)
- [Practice Problems 2.8 | Introduction to Boolean Algebra](./practice-problems/problem2-8.md)
- [Practice Problems 2.9 | Introduction to Boolean Algebra](./practice-problems/problem2-9.md)
- [Practice Problems 2.10 | Bit-Level Operations in C | bitwise boolean](./practice-problems/problem2-10.md)
- [Practice Problems 2.11 | Bit-Level Operations in C](./practice-problems/problem2-11.md)
- [Practice Problems 2.12 | Bit-Level Operations in C | masking](./practice-problems/problem2-12.md)
- [Practice Problems 2.13 | Bit-Level Operations in C](./practice-problems/problem2-13.md)
- [Practice Problems 2.14 | Logical Operations in C](./practice-problems/problem2-14.md)
- [Practice Problems 2.15 | Logical Operations in C](./practice-problems/problem2-15.md)
- [Practice Problems 2.15 | Logical Operations in C](./practice-problems/problem2-15.md)
- [Practice Problems 2.16 | Shift Operations in C](./practice-problems/problem2-16.md)
- [Practice Problems 2.17| Two's Complement Encodings](./practice-problems/problem2-17-hardback.md)
- [Practice Problems 2.18| Two's Complement Encodings](./practice-problems/problem2-18-hardback.md)
- [Practice Problems 2.19 | Conversions between Signed versus Unsigned](./practice-problems/problem2-19-hardback.md)
- [Practice Problems 2.20 | Conversions between Signed versus Unsigned](./practice-problems/problem2-20.md)
- [Practice Problems 2.21 | Signed versus Unsigned in C](./practice-problems/problem2-21-hardback.md)
- [Practice Problems 2.22 | Expanding the Bit Representation of a Number](./practice-problems/problem2-22-hardback.md)
- [Practice Problems 2.23 | Expanding the Bit Representation of a Number](./practice-problems/problem2-23-hardback.md)
- [Practice Problems 2.24 | Truncating Numbers](./practice-problems/problem2-24.md)
- [Practice Problems 2.25 | Advice on Signed versus Unsigned](./practice-problems/problem2-25.md)
- [Practice Problems 2.26 | Advice on Signed versus Unsigned](./practice-problems/problem2-26.md)
- [Practice Problems 2.27 | Unsigned addition](./practice-problems/problem2-27.md)
- [Practice Problems 2.28 | Unsigned additive inverse (unsigned negation)](./practice-problems/problem2-28.md)
- [Practice Problems 2.29 | Two's Complement Addition](./practice-problems/problem2-29.md)
- [Practice Problems 2.30 | Two's Complement Addition](./practice-problems/problem2-30.md)
- [Practice Problems 2.33 | Two's Complement Negation (additive inverse)](./practice-problems/problem2-33.md)
- [Practice Problems 2.34 | Unsigned and Two's Complement Multiplication](./practice-problems/problem2-34.md)
- [Practice Problems 2.35 | Unsigned and Two's Complement Multiplication](./practice-problems/problem2-35.md)
- [Practice Problems 2.39 | Multiplication by Constants](./practice-problems/problem2-39.md)
- [Practice Problems 2.40 | Multiplication by Constants](./practice-problems/problem2-40.md)
- [Practice Problems 2.42 | Dividing by Powers of 2](./practice-problems/problem2-42.md)
- [Practice Problems 2.44 | Integer Arithmetic summary | "C puzzle" problems](./practice-problems/problem2-44.md)
- [Practice Problems 2.45 | Floating Point | Fractional Binary Numbers](./practice-problems/problem2-45.md)
- [Practice Problems 2.47 | Floating Point | Fractional Binary Numbers](./practice-problems/problem2-47.md)
- [Practice Problems 2.48 | Floating Point | Fractional Binary Numbers](./practice-problems/problem2-48.md)
- [Practice Problems 2.50 | Floating Point | Rounding](./practice-problems/problem2-50.md)
- [Practice Problems 2.52 | Floating Point | Rounding](./practice-problems/problem2-52.md)

### Chapter 2 Web Asides TOC
- [Chapter2: Web Asides | Bit-level representation of two's complement negation](./webasides/data_tneg.md)
- [Chapter2: Web Asides | Writing TMin in C](./webasides/data_tmin.md)