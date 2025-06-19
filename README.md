### 🔍 Short String Optimization (SSO)

**Short String Optimization (SSO)** is a performance technique used in modern C++ implementations of `std::string`. It allows short strings (typically 15 characters or fewer) to be stored **directly inside the `std::string` object itself**, avoiding costly heap allocations.

#### ✅ Why it matters:

* **Faster performance**: No heap allocation means faster construction, copying, and destruction.
* **Reduced memory fragmentation**: Everything stays on the stack for short strings.
* **Used by default**: Supported in most modern C++ standard libraries (libstdc++, libc++, MSVC STL).

#### 🧪 How it works:

Instead of dynamically allocating memory for every string, the `std::string` object reserves a small internal buffer. If the string fits, it's stored in that buffer — otherwise, normal heap allocation is used.

#### 🔧 Example:

```cpp
std::string s = "hello"; // Likely uses SSO (stack)
std::string s = "this string is way too long for SSO"; // Uses heap
```

### How to Build and Run
#### Prerequisites
- A C++ compiler (GCC, Clang, or MSVC)
- CMake (version 3.10 or higher)
- git (to clone the repository)

#### Steps
Clone the repository:

```bash
git clone `Short_String_Optimization`
cd `Short_String_Optimization`
```

Configure the project using CMake:
This will create a build directory and generate the build files for your system.

```bash
cmake -B build
```
Build the executables:
This will compile main.cpp twice with the different optimization flags and run the post-build commands to generate the assembly files.

```bash
cmake --build build
```

Run the analysis:
The final executables need to be run from the build directory. You must provide the path to the assembly file and the optimization level string as arguments.


# Run the Executable

```bash
./build/Release/Short_String_Optimization.exe
```



### Expected Output

When you run the program, you will see output similar to this:

```
String object address: 00000048F659F8D0
Data (c_str) address:  00000048F659F8D0
SSO is enabled.
SSO strings took: 5 ms
Long strings took: 39 ms
Since long string is 10 times bigger than short string, we can expect it to take 10 times longer.
```

