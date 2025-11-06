# System-Level Programming Assessment

This project consists of 4 tasks that assess skills in C, Assembly, Python, and shared libraries.

---

## Question 1: ELF File Disassembly
File: `disasm.c`  
This program accepts the path to an ELF executable as input. It uses the objdump command to extract the .text section and saves the disassembled output into a .txt file.

### How to run:
```bash
gcc disasm.c -o disasm
./disasm path_to_executable
```

---

## Question 2: ATM Simulation in Assembly 
File: `atm.asm`  
An x86 Assembly program that mimics basic ATM operations: Deposit, Withdraw, Check Balance, and Exit. It begins with a balance of 1000 and updates it based on user interactions. Each operation is implemented as a separate module.

### How to run:
```bash
nasm -f elf32 atm.asm -o atm.o
ld -m elf_i386 atm.o -o atm
./atm
```

---

## Question 3: IoT Sensor Monitor (C + Python)  
Files: `sim.c`, `setup.py`, `plot.py`  
This project simulates periodic readings from IoT sensors: temperature, humidity, and battery level. The C file (sim.c) is compiled into a Python extension. The Python script (plot.py) fetches data every 2 seconds for 30 seconds and visualizes it in real-time using matplotlib.

### How to run:
```bash
# Build and install the C extension
python3 setup.py build
python3 setup.py install --user

# Install matplotlib if it's not already installed
python3 -m pip install --user matplotlib

# Run the graphing program
python3 plot.py
```

---

## Question 4: Encrypted Diary Manager
Files: `crypto.c`, `diary.c`  
A command-line diary application that encrypts and decrypts diary entries with a simple symmetric key (key = 4) using a shared library. Encrypted entries are stored in memory, and a correct password is required to view them.

### How to run:
```bash
# Compile the shared library
gcc -fPIC -shared -o libcrypto.so crypto.c

# Compile the main diary program
gcc -o diary diary.c -L. -lcrypto

# Export the library path and run
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
./diary
```

---

Note: All programs are built and tested on Linux.

