# Calculator program
<br>
Function Calculator is a C++ console application that calculates the values of a piecewise-defined mathematical function within a specified interval. The user provides the start value, end value, and calculation step, after which the program evaluates the function for each point in the range and displays the results.
<br>
<br>

## *Formula*
<br>

<img width="637" height="226" alt="image" src="https://github.com/user-attachments/assets/b666e419-2303-4586-aaf7-8e7b0b350f5a" />
<br>
<br>

## *Features*

### Program Capabilities
* User-defined parameter `n` (`7 <= n <= 140`), step `h` (`h > 0`), and interval `[a, b]` (`a <= b`)
* Input validation and arithmetic overflow protection
* Color-coded menu-driven interface with built-in Help
* Simple navigation between options

### Data Input Options
* Keyboard
* File

### Data Management Options
* View: see the calculated results directly on the screen
* Save: store results in an output file _results.txt_
* Delete: clear previous calculation data
<br>

## Input File Format
If you choose **Input from a file**, the file must contain 4 numbers separated by spaces or new lines in the exact order **`n h a b`**:
```text
8 0.5 -2 2
```

## Example

**Console output:**
```text
Input n - parameter (7 <= n <= 140): 8
Input h - step (h > 0): 0.5
Input a - lower bound of the interval: -2
Input b - upper bound of the interval (a <= b): -1

x= -2
y= 13

x= -1.5
y= 11.125

x= -1
y= 7
```

**Saved file (`results.txt`):**
```text
x = -2.000000  |  y = 13.000000
x = -1.500000  |  y = 11.125000
x = -1.000000  |  y = 7.000000
```
<br>

## *How to Run*
* **Platform:** Windows (requires `termcolor.hpp` in the project folder)

```bash
g++ main.cpp -o calculator.exe
calculator.exe
```

## *Autor*
Polina Kuzovlieva
