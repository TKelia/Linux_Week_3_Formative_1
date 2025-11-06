# System-Level Programming Assessment

This project contains 4 questions that test C, Assembly, Python, and shared libraries.

---

## Question 1: Disassemble ELF File  
File: `disasm.c`  
This program takes the path to an ELF executable file as input. It uses the `objdump` command to extract the `.text` section of the binary and saves the disassembled code into a `.txt` file.

### How to run:
```bash
gcc disasm.c -o disasm
./disasm path_to_executable
```

---

## Question 2: ATM in Assembly  
File: `atm.asm`  
This is an x86 Assembly program that simulates basic ATM functions: Deposit, Withdraw, Check Balance, and Exit. It starts with an initial balance of 1000 and updates it based on user input. Each function is modular.

### How to run:
```bash
nasm -f elf32 atm.asm -o atm.o
ld -m elf_i386 atm.o -o atm
./atm
```

---

## Question 3: IoT Sensor Monitor (C + Python)  
Files: `sim.c`, `setup.py`, `plot.py`  
This project simulates periodic IoT sensor readings: temperature, humidity, and battery level. The C file (`sim.c`) is compiled as a Python extension. The Python script (`plot.py`) uses that extension to fetch data every 2 seconds for 30 seconds and plots real-time graphs using `matplotlib`.

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

## Question 4: Diary Manager with Encryption  
Files: `crypto.c`, `diary.c`  
This is a command-line diary manager. It uses a shared library to encrypt and decrypt personal diary entries using a simple symmetric key (key = 4). The encrypted entries are stored in memory. To view them, the user must enter the correct password.

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
