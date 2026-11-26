# Software Requirements Specification (SRS)

* **Project:** Function Calculator
* **Author:** Polina Kuzovlieva
* **Version:** 1.0, November 2026  

A standalone C++ Windows console application that computes values of a piecewise mathematical function across an interval [a,b] with step h, supports keyboard and file input, validates parameters, and saves results to `results.txt`.

---
<br>

## 1. Purpose

### 1.1 Definitions of Variables and Parameters
| Symbol | Description |
| :--- | :--- |
| n | Integer upper bound parameter of the product and summation loops (7 <= n <= 140) |
| h | Positive step added to x at each iteration (h > 0) |
| a | Lower bound of the calculation interval for variable x (a <= b) |
| b | Upper bound of the calculation interval for variable x |
| x | Independent input variable evaluated across the interval [a, b] (argument of the function) |
| y | Calculated output value of the function |

### 1.2 System Overview 
The Mathematical Function Calculator is a standalone, single-user C++ console application developed for Windows. It automates the tabular calculation of a piecewise mathematical function (Variant № 13) across a user-defined interval $[a, b]$ with step $h$, validates all inputs, displays results on screen, and exports them to results.txt.

### Function (Variant № 13) 

<br>
<img width="637" height="226" alt="image" src="https://github.com/user-attachments/assets/b666e419-2303-4586-aaf7-8e7b0b350f5a" />
<br>

### 1.3 References 
* Books & Guidelines:
  1. Wiegers K., Beatty J., *Software Requirements*, 3rd Edition, Microsoft Press, 2013.
  2. Melnyk K.V., *Methodical Recommendation to Software Engineering Laboratory Practice*, Department of Software Engineering and Management Information Technologies, NTU "KhPI", Kharkiv, 2026.
* **System Diagrams ([charts/](../tree/main/charts)):**
  * Use Case Diagram
  * Use Case Scenarios (UC-01 – UC-10)
  * UML Activity Diagram
  * Console Wireframes
  * Flowchart Diagram

---
<br>

## 2. Overall Description

### 2.1 Product Perspective
The **Mathematical Function Calculator** is a standalone, self-contained Windows console application developed in C++. It operates independently as a single-user tool without relying on external servers, cloud services, or database management systems, interacting exclusively with the local operating system console and file system.

#### 2.1.1 System Interfaces
The application interacts directly with the host Windows operating system through standard input/output streams (`stdin`, `stdout`) and local file system handles (`std::ifstream`, `std::ofstream`) to read input datasets and generate calculation logs.

#### 2.1.2 User Interfaces
The software provides an interactive, text-based Command-Line Interface organized into modular screens: welcome screen (`Menu`), `MainMenu`, `CalculationsMenu`, `DataMenu`, `HelpMenu`, and `ExitMenu`. Screens use framed layouts, ANSI color highlighting (`green` headers, `cyan` hints and confirmations, `red` error alerts), confirmation dialogs before destructive actions, and consistent keyboard navigation (`'3'` to return to the Main Menu, `'q'` to return to the previous menu).

#### 2.1.3 Hardware Interfaces
The application requires a standard x86/x64 personal computer equipped with a standard keyboard for menu selection and parameter entry, and a display monitor capable of rendering a text console window.

#### 2.1.4 Software Interfaces
The system is developed in standard C++ (C++11 or higher) using Microsoft Visual Studio and standard libraries (`iostream`, `fstream`, `cmath`, `string`, `conio.h`). It uses the single-header `termcolor.hpp` library alongside the Windows Console API (`windows.h` with `ENABLE_VIRTUAL_TERMINAL_PROCESSING`) for color rendering, and standard `fstream` streams to read plain-text input files and write output to `results.txt`.

#### 2.1.5 Communication Interfaces
None. The application executes completely offline and does not implement network protocols, sockets, or external web APIs.

#### 2.1.6 Memory Constraints
The application maintains a lightweight memory footprint consuming less than 50 MB of RAM during execution. To prevent excessive memory allocation and console output overflow, the total number of calculation iterations is restricted to `(b - a) / h <= 100000` steps, and parameter `n` is bounded by `n <= 140`.

---

### 2.2 Design Constraints
The software is designed using a modular procedural architecture in C++ that separates user interface routing, input validation, mathematical evaluation of Variant № 13, and file persistence into discrete functions. The implementation is restricted to standard C++ console capabilities without third-party graphical user interface frameworks.

#### 2.2.1 Operations
The program follows an interactive single-user session lifecycle: it initializes virtual terminal processing, presents the welcome screen, and enters a continuous menu loop in `main()`. Calculated results are retained in session memory (`previous_results` and `has_data` state variables) so the user can view or export them later, until explicitly deleted via `clearData()` or until the session terminates through `ExitMenu()`.

#### 2.2.2 Site Adaptation Requirements
No complex installation procedure or site-specific environment configuration is required. The compiled executable runs directly in any Windows 10 or Windows 11 terminal supporting ANSI escape sequences, provided the user has read and write permissions in the working directory.

---

### 2.3 Product Functions
The application provides the following core capabilities:
* **Mathematical Evaluation:** Computes the piecewise function of Variant № 13 for user-defined integer parameter `n` (`7 <= n  0`), and interval `[a, b]` (`a  `8 0.5 -2 2`

**Console Execution Example:**
> Input n - parameter (7 <= n  Input h - step (h > 0): 0.5  
> Input a - lower bound of the interval: -2  
> Input b - upper bound of the interval (a   
> x = -2      y = 13  
> x = -1.5    y = 11.125  
> x = -1      y = 7  

**Saved Output File (`results.txt`):**
> x = -2.000000 | y = 13.000000  
> x = -1.500000 | y = 11.125000  
> x = -1.000000 | y = 7.000000  

---

### 2.4 User Characteristics
The intended users of the application are university students and software engineering instructors studying or evaluating numerical computation algorithms. Users are expected to have basic familiarity with navigating a Windows command-line menu and specifying local file paths; no programming knowledge is required to operate the compiled program.

---

### 2.5 Constraints, Assumptions, and Dependencies
* **Constraints:** The software must run offline as a Windows console application; parameter `n` must be an integer within `7 <= n <= 140`; interval bounds must satisfy `a  0`; and grid size must not exceed `100000` iterations.
* **Assumptions:** Input files provided by the user are plain-text encoded and contain four numeric values in the exact sequence `n h a b` without text headers. It is assumed that the host terminal supports ANSI color escape codes.
* **Dependencies:** Compilation depends on the presence of the `termcolor.hpp` header file in the project directory and standard Windows C++ runtime libraries.

---
<br>

## 3. Functional Requirements

## 3.1 Business Requirements (BR)

### BR-01 — Automated Piecewise Function Calculation

- **Type:** Business Requirement
- **Priority:** High
- **Source:** Teacher (Laboratory Assignment, Variant № 13)
- **Rationale:** Manual calculation of nested products and sums across multiple interval steps is time-consuming and prone to arithmetic errors.
- **Description:** The system shall automate the tabular calculation of the Variant № 13 piecewise mathematical function over a user-defined interval [a, b] with step h, displaying results in the console and exporting them to `results.txt`.
- **Preconditions:** A Windows environment capable of executing a compiled C++ console application is available.
- **Inputs:** Mathematical domain parameters (n, h, a, b) provided by the user via keyboard or file.
- **Expected Result:** Accurate (x, y) pairs are computed across [a, b], rendered on screen, and saved to `results.txt` upon confirmation.
- **Acceptance Criteria:**
  1. Calculated values match analytical solutions within `double` floating-point precision.
  2. Valid calculation grids (≤ 100000 steps) complete successfully.
- **Dependencies:** None
- **Status:** Implemented

---

## 3.2 User Requirements (UR)

### UR-01 — Interactive Console Navigation

- **Type:** User Requirement
- **Priority:** High
- **Source:** Student (Developer) / Teacher (`UC-06`, `UC-10`)
- **Rationale:** Users need a predictable, self-explanatory console menu structure.
- **Description:** The user shall be able to navigate structured console menus (`Menu`, `MainMenu`), view built-in instructions and formulas (`HelpMenu`), return to the Main Menu from submenus using `3`, and exit safely with confirmation (`ExitMenu`).
- **Preconditions:** The application is running in a Windows console window.
- **Inputs:** Menu selection and navigation commands (`1`–`4`, `q`).
- **Expected Result:** Smooth navigation across all screens and safe termination after confirmation.
- **Acceptance Criteria:**
  1. Submenus provide navigation back to `MainMenu`.
  2. The Help screen displays usage information and formulas.
  3. Exiting requires confirmation.
- **Dependencies:** `BR-01`
- **Status:** Implemented

---

### UR-02 — Dual Parameter Input and Validation

- **Type:** User Requirement
- **Priority:** High
- **Source:** Student (Developer) / Teacher (`UC-01` – `UC-03`)
- **Rationale:** Users need both keyboard entry and file loading protected against invalid inputs.
- **Description:** The user shall be able to run calculations by entering parameters n, h, a, b either via keyboard or from an external file, with immediate error feedback and step-back support (`q`).
- **Preconditions:** The user selected Run Calculations.
- **Inputs:** Keyboard entries or a file containing four numeric values.
- **Expected Result:** Valid parameters are processed into calculation results while invalid inputs display error messages.
- **Acceptance Criteria:**
  1. File and keyboard input modes are available.
  2. Invalid values are rejected.
  3. Pressing `q` returns to the previous menu.
- **Dependencies:** `BR-01`, `UR-01`
- **Status:** Implemented

---

### UR-03 — Stored Data Management

- **Type:** User Requirement
- **Priority:** Medium
- **Source:** Student (Developer) / Teacher
- **Rationale:** Users need to review, save, and clear stored calculation results.
- **Description:** The user shall be able to view calculated results via `DataMenu`, export them to `results.txt`, and clear stored session data after confirmation.
- **Preconditions:** The application session is active.
- **Inputs:** View, save, or clear commands.
- **Expected Result:** Results are displayed, saved, or deleted appropriately.
- **Acceptance Criteria:**
  1. Results are displayed in `x = ... | y = ...` format.
  2. Results can be saved to `results.txt`.
  3. Clearing data requires confirmation.
- **Dependencies:** `BR-01`, `UR-02`
- **Status:** Implemented

---

## 3.3 Functional Requirements (FR)

### FR-01 — Welcome Screen Entry

- **Type:** Functional Requirement
- **Priority:** Low
- **Source:** Student (Developer) (UR-01)
- **Rationale:** Initializes the session view and reminds the user to read the Help section before starting.
- **Description:** Upon startup, `Menu()` shall clear the console, display the welcome banner, and require pressing `1` to proceed to `MainMenu()`.
- **Preconditions:** The executable is launched in a Windows console.
- **Inputs:** Single character from keyboard (`std::cin`).
- **Expected Result:** Control transitions to `MainMenu()` on `1`; any other character displays an error and reloads `Menu()`.
- **Acceptance Criteria:**
  1. Console clears and renders "Welcome to the formula calculating program" and "*Read 'Help' before starting the program*".
  2. Entering `1` opens `MainMenu()`.
  3. Entering any other character displays "Invalid input. Please try again." and re-renders `Menu()`.
- **Dependencies:** `main()` initialization loop.
- **Status:** Implemented

---

### FR-02 — Main Menu Routing

- **Type:** Functional Requirement
- **Priority:** High
- **Source:** Student (Developer) (UR-01)
- **Rationale:** Provides a centralized hub to access all system modules.
- **Description:** `MainMenu()` shall display four options:
  - Run calculations
  - Management of data
  - Help
  - Exit the program

  and route execution based on the user's choice.
- **Preconditions:** User completed FR-01 or returned from a submenu.
- **Inputs:** Menu option character.
- **Expected Result:** Execution routes to the corresponding screen.
- **Acceptance Criteria:**
  1. Option `1` opens `CalculationsMenu()`.
  2. Option `2` opens `DataMenu()`.
  3. Option `3` opens `HelpMenu()`.
  4. Option `4` opens `ExitMenu()`.
  5. Invalid choices display an error and re-prompt.
- **Dependencies:** `Menu()`, `CalculationsMenu()`, `DataMenu()`, `HelpMenu()`, `ExitMenu()`.
- **Status:** Implemented

---

### FR-03 — Input Mode Selection

- **Type:** Functional Requirement
- **Priority:** Medium
- **Source:** Student (Developer)
- **Rationale:** Separates file-based and keyboard-based workflows.
- **Description:** `CalculationsMenu()` shall provide:
  - Input from a file
  - Input from a keyboard
  - Return to Main Menu
- **Preconditions:** User selected Run Calculations.
- **Inputs:** Single menu option.
- **Expected Result:** Correct calculation mode is launched.
- **Acceptance Criteria:**
  1. Option `1` invokes file calculations.
  2. Option `2` invokes keyboard calculations.
  3. Option `3` returns to Main Menu.
  4. Invalid choices display an error message.
- **Dependencies:** `runFileCalculations()`, `runCalculations()`.
- **Status:** Implemented

---

### FR-04 — File Input and Calculation

- **Type:** Functional Requirement
- **Priority:** High
- **Source:** Teacher / Student
- **Rationale:** Enables loading parameters from external files.
- **Description:** The system shall load parameters from a text file, validate them, execute calculations, display results, and provide the option to save the output.
- **Preconditions:** User selected file input.
- **Inputs:**
  - File name
  - File contents (`n h a b`)
- **Expected Result:** Valid values are processed and calculations are completed.
- **Acceptance Criteria:**
  1. Missing files produce an error.
  2. Invalid values are rejected.
  3. Valid values are calculated correctly.
  4. Results are displayed on screen.
  5. User is offered saving.
- **Dependencies:** `askToSaveFile()`.
- **Status:** Implemented

---

### FR-05 — Keyboard Input and Calculation

- **Type:** Functional Requirement
- **Priority:** High
- **Source:** Teacher / Student
- **Rationale:** Allows interactive calculations.
- **Description:** The system shall accept parameters from the keyboard, validate them, calculate results, display them, and offer saving.
- **Preconditions:** User selected keyboard input.
- **Inputs:** `n`, `h`, `a`, `b`
- **Expected Result:** Results are displayed and available for storage.
- **Acceptance Criteria:**
  1. Invalid values are rejected.
  2. Valid values produce calculated results.
  3. Overflow is detected.
  4. Save prompt appears.
- **Dependencies:** `askToSaveFile()`.
- **Status:** Implemented

---

### FR-06 — Save Results to File

- **Type:** Functional Requirement
- **Priority:** High
- **Source:** Teacher / Student
- **Rationale:** Preserves results between sessions.
- **Description:** The system shall save calculation results to `results.txt`.
- **Preconditions:** Result data exists.
- **Inputs:** Save confirmation.
- **Expected Result:** Results are written to disk.
- **Acceptance Criteria:**
  1. Existing data is saved successfully.
  2. File write failures are reported.
  3. User may cancel saving.
- **Dependencies:** Calculations completed.
- **Status:** Implemented

---

### FR-07 — View Stored Data

- **Type:** Functional Requirement
- **Priority:** Medium
- **Source:** Student (Developer)
- **Rationale:** Allows reviewing previously calculated values.
- **Description:** Stored results shall be displayed from session memory.
- **Preconditions:** Data menu opened.
- **Inputs:** User menu choice.
- **Expected Result:** Existing results are shown.
- **Acceptance Criteria:**
  1. Empty datasets display a notification.
  2. Stored results are displayed correctly.
  3. Save option is available.
- **Dependencies:** `DataMenu()`.
- **Status:** Implemented

---

### FR-08 — Clear Stored Data

- **Type:** Functional Requirement
- **Priority:** Medium
- **Source:** Student (Developer)
- **Rationale:** Allows removal of stored calculations.
- **Description:** The system shall clear stored session results after confirmation.
- **Preconditions:** Stored data exists.
- **Inputs:** Confirmation choice.
- **Expected Result:** Data is deleted or retained.
- **Acceptance Criteria:**
  1. Confirmation removes stored data.
  2. Cancellation keeps stored data.
  3. Invalid input re-prompts.
- **Dependencies:** `DataMenu()`.
- **Status:** Implemented

---

### FR-09 — Built-in Help Screen

- **Type:** Functional Requirement
- **Priority:** Low
- **Source:** Student (Developer)
- **Rationale:** Provides self-contained instructions.
- **Description:** The system shall display program purpose, usage instructions and formulas.
- **Preconditions:** User selected Help.
- **Inputs:** Menu choice.
- **Expected Result:** Help content is displayed.
- **Acceptance Criteria:**
  1. Data input instructions are shown.
  2. Data management instructions are shown.
  3. Mathematical formulas are shown.
- **Dependencies:** `MainMenu()`.
- **Status:** Implemented

---

### FR-10 — Safe Program Exit

- **Type:** Functional Requirement
- **Priority:** Medium
- **Source:** Student (Developer)
- **Rationale:** Prevents accidental closure.
- **Description:** The application shall require exit confirmation.
- **Preconditions:** User selected Exit.
- **Inputs:** Confirmation choice.
- **Expected Result:** Program exits or returns to Main Menu.
- **Acceptance Criteria:**
  1. Confirming exits the application.
  2. Cancelling returns to Main Menu.
  3. Invalid input re-prompts.
- **Dependencies:** `main()`.
- **Status:** Implemented

---
<br>

## 4. Non-Functional Requirements 

## 4.1 Business / Domain Rules (BRULE)

### BRULE-01 — Parameter n Domain Bounds

* **Type:** Business / Domain Rule
* **Priority:** High
* **Source:** Teacher (Methodical Recommendation, Variant № 13 Formula) / Student (Developer)
* **Rationale:** In the x < 0 branch, the product index runs from i = 4 to n - 3, requiring n - 3 ≥ 4, therefore n ≥ 7. The upper bound n ≤ 140 prevents numeric overflow in `double` precision.
* **Description:** The system shall enforce that parameter n is a whole integer satisfying 7 ≤ n ≤ 140 in both `runCalculations()` and `runFileCalculations()`.
* **Preconditions:** The user is entering or loading parameter n.
* **Inputs:** Numeric value for n.
* **Expected Result:** Values within 7 ≤ n ≤ 140 are accepted; values < 7, > 140, or fractional numbers are rejected with a red error message.
* **Acceptance Criteria:**
  1. Entering n = 6 or n = 141 displays `"Error: 'n' parameter must be >= 7"` / `"<= 140"` and re-prompts.
  2. Entering n = 8.5 is rejected via `peek()` check as a non-integer.
  3. Entering n = 7 and n = 140 succeeds.
* **Dependencies:** `FR-04`, `FR-05`
* **Status:** Implemented

---

### BRULE-02 — Calculation Interval and Step Constraints

* **Type:** Business / Domain Rule
* **Priority:** High
* **Source:** Teacher (Methodical Recommendation, Numerical Computation Rules)
* **Rationale:** Iterative calculation from a to b with x += h requires a ≤ b and h > 0 to prevent empty intervals or infinite loops.
* **Description:** The system shall enforce that lower bound a ≤ b, step h > 0, and total iteration steps satisfy (b - a) / h ≤ 100000.
* **Preconditions:** The user is inputting h, a, b via keyboard or file.
* **Inputs:** Floating-point values h, a, b.
* **Expected Result:** Valid intervals are processed; invalid bounds or excessive step counts trigger an error and re-prompt.
* **Acceptance Criteria:**
  1. Entering h ≤ 0 displays `"Error: 'h' step must be > 0"`.
  2. Entering a > b displays `"Error: 'a' cannot be greater than 'b'!"`.
  3. Entering (b - a) / h > 100000 displays `"Error: The interval is too large for step h"` and prevents an infinite loop.
* **Dependencies:** `FR-04`, `FR-05`
* **Status:** Implemented

---

### BRULE-03 — Single-Point Evaluation Warning

* **Type:** Business / Domain Rule
* **Priority:** Low
* **Source:** Student (Developer)
* **Rationale:** Explains to the user why only one result row is produced when the step exceeds the interval length.
* **Description:** When h > (b - a) and (b - a) > 0, the system shall display a cyan warning message and evaluate the function only at x = a.
* **Preconditions:** Validated inputs satisfy a < b and h > (b - a).
* **Inputs:** Validated h, a, b.
* **Expected Result:** Warning notice is displayed and a single (a, y(a)) pair is computed.
* **Acceptance Criteria:**
  1. Given a = 1, b = 3, h = 5, the program outputs `"Warning: Step 'h' is larger than the interval. Only one point (x = a) will be calculated."` and evaluates only x = 1.
* **Dependencies:** `BRULE-02`, `FR-04`, `FR-05`
* **Status:** Implemented

---

### BRULE-04 — Denominator Non-Zero Safety

* **Type:** Business / Domain Rule
* **Priority:** Medium
* **Source:** Teacher (Methodical Recommendation, Variant № 13 Formula)
* **Rationale:** Prevents division-by-zero exceptions in the expression `(2 - x) / (i + 4)` when x ≥ 0.
* **Description:** The inner summation loop for x ≥ 0 shall iterate index i from 1 to n + 3, ensuring i + 4 ≥ 5 ≠ 0 for all steps.
* **Preconditions:** Evaluation enters the x ≥ 0 branch.
* **Inputs:** Loop index i ∈ [1, n + 3].
* **Expected Result:** Division by zero never occurs during runtime.
* **Acceptance Criteria:**
  1. For any valid n ∈ [7, 140] and x ≥ 0, denominator i + 4 remains strictly ≥ 5.
* **Dependencies:** `FR-04`, `FR-05`
* **Status:** Implemented

---

## 4.2 Quality Attributes (QA)

### QA-01 — Calculation and Export Performance

* **Type:** Quality Attribute (Performance)
* **Priority:** Medium
* **Source:** Student (Developer) / Teacher
* **Rationale:** Guarantees responsive execution during interactive console sessions and automated testing.
* **Description:** For any valid grid up to 100000 steps and n ≤ 140, the program shall complete all loop calculations and export results to `results.txt` in under 3.0 seconds.
* **Preconditions:** Executed on a standard Windows PC.
* **Inputs:** Valid parameters within `BRULE-01` and `BRULE-02`.
* **Expected Result:** Total computation and file write latency remains within the defined limit.
* **Acceptance Criteria:**
  1. Calculating 10000 steps at n = 50 and saving `results.txt` completes within the defined performance target.
* **Dependencies:** `FR-04`, `FR-05`, `FR-06`
* **Status:** Implemented

---

### QA-02 — Input Validation and Fault Tolerance

* **Type:** Quality Attribute (Reliability)
* **Priority:** High
* **Source:** Teacher (Methodical Recommendation, Testing of Code) / Student (Developer)
* **Rationale:** Ensures the console application never crashes or hangs when given malformed input or missing files.
* **Description:** The program shall handle non-numeric keyboard entries, missing or corrupted files, invalid menu options, and numeric overflows gracefully with recoverable colored error alerts.
* **Preconditions:** Application is awaiting user input or reading an input file.
* **Inputs:** Invalid characters, non-existent file names, or overflow-inducing values.
* **Expected Result:** Error flags are cleared, a descriptive message is printed, and control returns to a valid prompt.
* **Acceptance Criteria:**
  1. Entering letters for numeric prompts clears `std::cin` and re-prompts without hanging.
  2. Entering a missing file path displays `"Error: Could not open file! File might not exist."` and reloads `runFileCalculations()`.
* **Dependencies:** `SR-02`, `FR-01`–`FR-10`
* **Status:** Implemented

---

### QA-03 — Modularity and Unit Testability

* **Type:** Quality Attribute (Maintainability / Testability)
* **Priority:** Medium
* **Source:** Teacher (Methodical Recommendation, Coding of Domain & Testing of Code)
* **Rationale:** Separating menu navigation, input validation, calculation loops, and file I/O supports clean code maintenance and unit testing.
* **Description:** The source code shall decompose distinct workflows into separate functions (`Menu`, `MainMenu`, `CalculationsMenu`, `runFileCalculations`, `runCalculations`, `askToSaveFile`, `DataMenu`, `clearData`, `HelpMenu`, `ExitMenu`).
* **Preconditions:** Source code compiled in Visual Studio.
* **Inputs:** C++ source structure.
* **Expected Result:** Each screen and operation is encapsulated in its own cohesive function.
* **Acceptance Criteria:**
  1. Control flow in `main()` coordinates submenus via explicit return codes (`1`–`4`, `q`).
* **Dependencies:** `CON-01`
* **Status:** Implemented

---

### QA-04 — Wireframe Usability and Visual Consistency

* **Type:** Quality Attribute (Usability)
* **Priority:** Low
* **Source:** Student (Developer) (Design Wireframes & Flowchart Diagram)
* **Rationale:** Consistent shortcut keys and color-coded feedback simplify console navigation.
* **Description:** All screens shall follow the designed `Wireframes` and `Flowchart Diagram`, providing `3` to return to `MainMenu()`, `q` to step back, confirmation dialogs before destructive actions, and ANSI color highlights (`green`, `cyan`, `red`).
* **Preconditions:** Console supports virtual terminal escape sequences.
* **Inputs:** User navigation commands.
* **Expected Result:** Framed screens render cleanly with clear visual distinction between headers, warnings, and errors.
* **Acceptance Criteria:**
  1. Headers render in `green`, warnings and confirmations in `cyan`, and validation errors in `red`.
  2. `clearData()` and `ExitMenu()` always display a `1. Yes` / `2. No` confirmation prompt.
* **Dependencies:** `EI-01`
* **Status:** Implemented

---

## 4.3 External Interfaces (EI)

### EI-01 — Console User Interface (Wireframes)

* **Type:** External Interface (User Interface)
* **Priority:** Medium
* **Source:** Student (Developer) (Design Wireframes)
* **Rationale:** Defines the layout and keyboard interaction protocol for the text-based screens.
* **Description:** The program shall interact with the user through a framed Command-Line Interface using `termcolor.hpp` color sequences and `std::cin` prompts matching the Figma wireframes.
* **Preconditions:** Windows console with `ENABLE_VIRTUAL_TERMINAL_PROCESSING` enabled.
* **Inputs:** Keyboard characters and strings.
* **Expected Result:** Framed menus and `(x, y)` output blocks render with aligned borders.
* **Acceptance Criteria:**
  1. All 10 wireframe screens render cleanly and accept expected navigation keys.
* **Dependencies:** `CON-01`, `QA-04`
* **Status:** Implemented

---

### EI-02 — Local File System Interface

* **Type:** External Interface (Software / File Interface)
* **Priority:** High
* **Source:** Teacher (Methodical Recommendation, Coding of Domain) / Student (Developer)
* **Rationale:** Required to support file-based parameter loading and mandatory/optional saving of results.
* **Description:** The program shall use standard C++ `fstream` (`std::ifstream` and `std::ofstream`) to read four whitespace-separated numbers (`n h a b`) from user-specified text files (`.txt`, `.csv`, plain text) and save formatted output tables to `results.txt`.
* **Preconditions:** Working directory has read/write file permissions.
* **Inputs:** Input file stream (`n h a b`) and `previous_results` buffer.
* **Expected Result:** Input parameters are parsed accurately, and `results.txt` is written in `x = ... | y = ...` format.
* **Acceptance Criteria:**
  1. Reading a file containing `8 0.5 -2 2` loads n = 8, h = 0.5, a = -2, b = 2.
  2. Confirming save writes `results.txt` readable by standard text editors.
* **Dependencies:** `FR-04`, `FR-06`
* **Status:** Implemented

---

### EI-03 — Hardware Interface

* **Type:** External Interface (Hardware Interface)
* **Priority:** Low
* **Source:** Student (Developer)
* **Rationale:** Defines the physical peripherals required to run the console executable.
* **Description:** The application shall run on a standard x86/x64 personal computer equipped with a keyboard for input and a display monitor for console output.
* **Preconditions:** Standard PC hardware running Windows.
* **Inputs:** Standard keyboard interrupts.
* **Expected Result:** Text input and output operate without specialized hardware.
* **Acceptance Criteria:**
  1. Executable runs on any standard Windows desktop or laptop.
* **Dependencies:** `CON-01`
* **Status:** Implemented

---

## 4.4 System Requirements (SR)

### SR-01 — Double Precision and Overflow Protection

* **Type:** System Requirement
* **Priority:** High
* **Source:** Student (Developer)
* **Rationale:** Nested sums and products grow rapidly for large n and x, risking floating-point `INF` or `NaN`.
* **Description:** The calculation engine shall compute all intermediate sums, products, and final values in `double` precision (`std::pow`) and check `std::isfinite()` at every product step.
* **Preconditions:** Evaluation loop is running for a point x ∈ [a, b].
* **Inputs:** Intermediate `product` and final `y` values.
* **Expected Result:** Numeric overflow terminates the current point's loop early, prints `"Error: Overflow (Value too large)"` in red, and logs `"y = Overflow"` in `previous_results`.
* **Acceptance Criteria:**
  1. At n = 140 and x = 100, `std::isfinite()` catches overflow and displays `"Error: Overflow (Value too large)"`.
* **Dependencies:** `FR-04`, `FR-05`
* **Status:** Implemented

---

### SR-02 — Input Stream State Validation

* **Type:** System Requirement
* **Priority:** High
* **Source:** Student (Developer)
* **Rationale:** Prevents `std::cin` and `std::ifstream` fail-bit lockups or partial reads (such as `12abc` or fractional n).
* **Description:** Keyboard (`std::cin`) and file (`std::ifstream`) input routines shall check `fail()` flags and lookahead characters (`peek()`) to reject non-numeric tokens, mixed alphanumeric strings, and decimal values for integer n.
* **Preconditions:** Program is reading user or file input.
* **Inputs:** Raw character stream.
* **Expected Result:** Invalid input is discarded (`cin.clear()`, `cin.ignore()`) and an error message is displayed.
* **Acceptance Criteria:**
  1. Entering `"abc"` or `"10xyz"` triggers a red validation error without crashing.
  2. Entering `"7.5"` for integer n is rejected via `peek() == '.'` check.
* **Dependencies:** `FR-04`, `FR-05`, `QA-02`
* **Status:** Implemented

---

## 4.5 Constraints (CON)

### CON-01 — Visual Studio C++ Windows Console Stack

* **Type:** Technical Constraint
* **Priority:** Medium
* **Source:** Teacher (Methodical Recommendation, Coding of Domain)
* **Rationale:** Aligns implementation with the C++ course environment in Microsoft Visual Studio.
* **Description:** The program shall be implemented in standard C++ (C++11 or higher) as a Visual Studio Windows Console Application using standard libraries (`iostream`, `fstream`, `cmath`, `string`, `conio.h`), `termcolor.hpp`, and the Windows Console API (`windows.h` with `ENABLE_VIRTUAL_TERMINAL_PROCESSING`).
* **Preconditions:** Windows 10/11 OS and MSVC or `g++` compiler.
* **Inputs:** Source files (`main.cpp`, `termcolor.hpp`).
* **Expected Result:** Clean compilation into a native Windows `.exe` binary.
* **Acceptance Criteria:**
  1. The project builds with zero errors in Visual Studio on Windows.
* **Dependencies:** None
* **Status:** Implemented

---

### CON-02 — Offline Single-User Execution

* **Type:** Operational Constraint
* **Priority:** Low
* **Source:** Teacher / Student (Developer)
* **Rationale:** Guarantees standalone portability without external servers or third-party GUI dependencies.
* **Description:** The application shall run completely offline as a standalone console process without databases, network sockets, or external GUI frameworks.
* **Preconditions:** Compiled executable is stored locally.
* **Inputs:** Local keyboard and file system only.
* **Expected Result:** All features operate identically without network access.
* **Acceptance Criteria:**
  1. Program runs and saves `results.txt` with internet access disabled.
* **Dependencies:** `CON-01`
* **Status:** Implemented

---
<br>

## 5. Requirements Traceability Matrix

| ID | Assoc ID | Description | Design Artifact | Software Module | Test Case | Status |
|------|------|------|------|------|------|------|
| **BR-01** | — | Automate function calculation (Variant № 13) over [a, b] with step h | Formula Variant № 13 | Calculation loops (`main.cpp`) | `TC-01`, `TC-02` | Implemented |
| **UR-01** | `BR-01` | Navigate console menus, open Help, and exit safely | `Use Case 6`, `Use Case 10`, Flowchart | `Menu()`, `MainMenu()`, `HelpMenu()`, `ExitMenu()` | `TC-03` | Implemented |
| **UR-02** | `BR-01` | Enter parameters via keyboard or file and check input validity | `Use Case 1`–`Use Case 3`, Activity Diagram | `CalculationsMenu()`, `runFileCalculations()`, `runCalculations()` | `TC-04`–`TC-07` | Implemented |
| **UR-03** | `BR-01` | View previous results, save to `results.txt`, and clear data | `Use Case 4`, `Use Case 5`, `Use Case 7`–`Use Case 9` | `DataMenu()`, `askToSaveFile()`, `clearData()` | `TC-08`–`TC-10` | Implemented |
| **FR-01** | `UR-01` | Show welcome screen and press `1` to open Main Menu | Entry Wireframe | `Menu()` | `TC-03` | Implemented |
| **FR-02** | `UR-01` | Choose Run Calculations, Data Management, Help, or Exit | Wireframes, Flowchart | `MainMenu()`, `main()` | `TC-03` | Implemented |
| **FR-03** | `UR-02` | Select file input (`1`), keyboard input (`2`), or Main Menu (`3`) | `Use Case 1`, Wireframes | `CalculationsMenu()` | `TC-04` | Implemented |
| **FR-04** | `UR-02`, `BR-01` | Read n, h, a, b from file, validate input, and calculate y(x) | `Use Case 3`, Activity Diagram | `runFileCalculations()` | `TC-05`, `TC-06` | Implemented |
| **FR-05** | `UR-02`, `BR-01` | Read n, h, a, b from keyboard, validate input, and calculate y(x) | `Use Case 2`, Activity Diagram | `runCalculations()` | `TC-01`, `TC-02`, `TC-07` | Implemented |
| **FR-06** | `UR-03` | Ask user to save calculated results into `results.txt` | `Use Case 4`, `Use Case 5` | `askToSaveFile()` | `TC-08` | Implemented |
| **FR-07** | `UR-03` | Show previous calculation results on screen | `Use Case 7`, `Use Case 8` | `DataMenu()` (Option 1) | `TC-09` | Implemented |
| **FR-08** | `UR-03` | Clear previous calculation data after confirmation | `Use Case 9`, Wireframes | `clearData()` | `TC-10` | Implemented |
| **FR-09** | `UR-01` | Display program purpose, instructions, and Variant № 13 formulas | `Use Case 6`, Wireframes | `HelpMenu()` | `TC-03` | Implemented |
| **FR-10** | `UR-01` | Confirm exit (`Yes` / `No`) and close the program | `Use Case 10`, Wireframes | `ExitMenu()` | `TC-03` | Implemented |
| **BRULE-01** | `FR-04`, `FR-05` | Integer parameter n must satisfy 7 ≤ n ≤ 140 | Activity Diagram | Validation logic (`main.cpp`) | `TC-04` | Implemented |
| **BRULE-02** | `FR-04`, `FR-05` | Interval a ≤ b, step h > 0, and maximum 100000 iterations | Activity Diagram | Validation logic (`main.cpp`) | `TC-04`, `TC-07` | Implemented |
| **BRULE-03** | `BRULE-02` | Display warning and calculate only x = a when h > (b - a) | Activity Diagram | Step warning check (`main.cpp`) | `TC-07` | Implemented |
| **BRULE-04** | `FR-04`, `FR-05` | Denominator i + 4 is never equal to zero for i ≥ 1 | Formula Variant № 13 | Inner summation loop (x ≥ 0 branch) | `TC-02` | Implemented |
| **QA-01** | `BR-01` | Complete calculations and export results within performance targets | System Specification | Iterative loops and `std::ofstream` | `TC-11` | Implemented |
| **QA-02** | `SR-02` | Handle invalid input and missing files without crashing | Activity Diagram | Validation and error handling | `TC-04`, `TC-06` | Implemented |
| **QA-03** | `CON-01` | Separate code into modular functions for easier maintenance and testing | Software Architecture | Functions in `main.cpp` | `TC-01`–`TC-10` | Implemented |
| **QA-04** | `EI-01` | Consistent navigation shortcuts and color-coded feedback | Wireframes, Flowchart | `termcolor.hpp` and menu routing | `TC-03` | Implemented |
| **EI-01** | `UR-01` | Framed console interface matching Figma wireframes | Figma Wireframes | Console I/O (`std::cout`, `std::cin`) | `TC-03` | Implemented |
| **EI-02** | `FR-04`, `FR-06` | Read input files and write `results.txt` | `Use Case 3`, `Use Case 5` | `std::ifstream`, `std::ofstream` | `TC-05`, `TC-08` | Implemented |
| **EI-03** | `CON-01` | Standard Windows PC keyboard and display monitor | Environment Specification | Windows Console I/O | `TC-03` | Implemented |
| **SR-01** | `FR-04`, `FR-05` | Use `double` precision and `std::isfinite()` overflow detection | Activity Diagram | Calculation loops (`main.cpp`) | `TC-12` | Implemented |
| **SR-02** | `FR-04`, `FR-05` | Validate input using `fail()`, `peek()`, and `ignore()` | Activity Diagram | Input parsing logic (`main.cpp`) | `TC-04`, `TC-06` | Implemented |
| **CON-01** | `BR-01` | Build using Visual Studio C++11+ for Windows Console | Technical Specification | `main.cpp`, `termcolor.hpp`, `windows.h` | Build Check | Implemented |
| **CON-02** | `CON-01` | Execute offline without internet, servers, or databases | Deployment Specification | Standalone local `.exe` | `TC-08` | Implemented |

