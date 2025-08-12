# C-WindowOS_Master_Template
Template for C++ Windows GUI template 

# Let's create a README.md file with the content from the previous message

readme_content = """# C-WindowOS Master Template

A **Unicode Win32 API GUI Application** template written in C++.  
This project demonstrates creating a basic Windows application with a custom window class, message loop, and basic GDI drawing.

## Features
- Unicode support (`wWinMain` entry point)
- Basic Win32 window creation
- Message loop handling
- Paint handling with `DrawText`
- Minimal dependencies (`user32`, `gdi32`)

## Getting Started

### Prerequisites
- **TDM-GCC** or **MinGW-w64** with g++
- Windows 10/11
- Basic knowledge of Win32 API programming

### Building
Open a terminal in the project folder and run:

```bash
g++ main.cpp -o HelloWorld.exe -mwindows -municode -luser32 -lgdi32
