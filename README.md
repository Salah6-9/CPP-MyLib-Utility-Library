
# MyLib
> 🎯 **About this Project:** 
> This utility library is built, refactored, and maintained entirely by me as part of my practical application while following the **Programming Advices** roadmap (by Dr. Mohammed Abu-Hadhoud).

A personal C++ utility library, split into focused modules so it's easier to grow, reuse across projects, and actually find things in.

This started as one giant `MyLib.h` file — 1845 lines, 168 functions, all crammed into a single namespace. It worked, but it was getting hard to navigate, and functions kept clashing names with each other. So we broke it apart. This README is the story of that, and a guide for using and growing it going forward.

---

## Why we split it up

A few real pain points pushed this:

- Functions kept colliding on names as the file grew.
- Finding anything meant scrolling through hundreds of lines.
- `using namespace std;` sitting in the header meant it leaked into every file that included the library.
- Everything was inline in the header — no real separation between "here's what this function does" and "here's how it does it."

None of these are fatal on their own, but together they were slowing things down more than the split itself now does.

---

## The layout

We went with a hybrid approach: bigger modules (20+ functions) get their own folder, smaller ones stay as flat files. No reason to over-organize something with 5 functions in it.

```
MyLibrary/
├─ MyLib.h                 ← the umbrella header — this is what old code includes
├─ MyLib.cpp
├─ Makefile                ← builds the whole thing with one command
├─ libMyLib.a              ← the compiled static library (shows up after you run `make`)
└─ modules/
   ├─ MyDate/    MyDate.h, MyDate.cpp      → dates, calendars, day math (39 functions)
   ├─ MyString/  MyString.h, MyString.cpp  → string/char handling (32 functions)
   ├─ MyMatrix/  MyMatrix.h, MyMatrix.cpp   → 2D matrix operations (27 functions)
   ├─ MyMath.h, MyMath.cpp                  → math & numbers (21 functions)
   ├─ MyArray.h, MyArray.cpp                → 1D array operations (22 functions)
   ├─ MyKey.h, MyKey.cpp                    → random key/word generation (4 functions)
   ├─ MyIO.h, MyIO.cpp                      → input helpers (8 functions)
   ├─ MyVector.h, MyVector.cpp              → vector helpers (5 functions)
   ├─ MyFile.h, MyFile.cpp                  → file I/O (7 functions)
   └─ MySystem.h, MySystem.cpp              → screen/system helpers (4 functions)
   ├─ MyBank.h, MyBank.cpp                → bank management utilities (reusable functions)
```

### The umbrella header

`MyLib.h` doesn't hold any real code anymore — it just pulls everything together so old code keeps working exactly as before:

```cpp
#pragma once
#include "modules/MyIO.h"
#include "modules/MyArray.h"
#include "modules/MyMatrix/MyMatrix.h"
#include "modules/MyMath.h"
#include "modules/MyString/MyString.h"
#include "modules/MyKey.h"
#include "modules/MyDate/MyDate.h"
#include "modules/MyVector.h"
#include "modules/MyFile.h"
#include "modules/MySystem.h"

namespace MyLib {
    using namespace MyIO;
    using namespace MyArray;
    using namespace MyMatrix;
    using namespace MyMath;
    using namespace MyString;
    using namespace MyKey;
    using namespace MyDate;
    using namespace MyVector;
    using namespace MyFile;
    using namespace MySystem;
}
```

So if some old project calls `MyLib::AddDaysToDate(...)`, it still just works. Nothing broke.

---

## How to build it

Just run:

```bash
cd MyLibrary
make
```

That's it. It compiles everything and produces `libMyLib.a`. Run `make clean` if you want to wipe the build and start fresh.

<details>
<summary>If you ever need to build it by hand (no Makefile)</summary>

```bash
cd MyLibrary
g++ -c MyLib.cpp modules/MyIO.cpp modules/MyString/MyString.cpp modules/MyFile.cpp \
    modules/MySystem.cpp modules/MyArray.cpp modules/MyKey.cpp modules/MyMath.cpp \
    modules/MyDate/MyDate.cpp modules/MyMatrix/MyMatrix.cpp modules/MyVector.cpp -I.

ar rcs libMyLib.a *.o modules/*.o modules/*/*.o
rm -f *.o modules/*.o modules/*/*.o
```
</details>

---

## How to use it in a project

**Want the whole library?**

```cpp
#include "MyLib.h"

int main() {
    string name = MyIO::ReadString("Enter name: ");
    sDate today = MyDate::GetRealTime();
}
```

**Only need one part of it?** Just include that module directly instead:

```cpp
#include "modules/MyMath.h"

int main() {
    if (MyMath::checkprime(17) == MyMath::prime) { /* ... */ }
}
```

Either way, the compile command stays exactly the same:

```bash
g++ YourProject.cpp -I/path/to/MyLibrary -L/path/to/MyLibrary -lMyLib -o YourProject.out
```

The linker is smart enough to only pull in the functions you actually call, so there's no downside to including the whole thing versus just one module — it's really just about keeping your code readable.

### Shortcut: skip typing the path every time

Add this to your shell config once (`~/.zshrc` for zsh):

```bash
export MYLIB="/path/to/MyLibrary"
```

Then every command becomes:

```bash
g++ YourProject.cpp -I"$MYLIB" -L"$MYLIB" -lMyLib -o YourProject.out
```

If your folder path has spaces or special characters in it (like `&`), keep the quotes around `"$MYLIB"` — otherwise the shell will misread it.

Heads up: this variable only works in your terminal, not inside VS Code's build tasks — see the VS Code section below for that.

---

##### Adding a new function
Say you want to add `IsEven(int)` to `MyMath`.

1. **Declare it** in `modules/MyMath.h`:
   ```cpp
   bool IsEven(int num);
   ```
2. **Write it** in `modules/MyMath.cpp`:
   ```cpp
bool IsEven(int num) {
    return num % 2 == 0;
}
   ```
3. **Rebuild the library:**
   ```bash
   make
   ```
4. Done. Any project using `-lMyLib` picks it up automatically the next time it's compiled — no need to touch old projects.

---

## Modifying an existing function

Say you want to tweak the logic inside `MyMath::checkprime`.

1. **Just edit the body** in `modules/MyMath.cpp`. Leave the `.h` alone — unless you're changing the signature (different parameters or return type).
2. **If you do change the signature**, update the declaration in the `.h` too, and update every place that calls it.
3. **Rebuild:**
   ```bash
   make
   ```
4. **Recompile any project that uses it.** The change won't show up in old projects until you rebuild them too.

A heads-up: if you change a function's signature and forget to update a project that calls it, you'll get a clear compile error — not a mysterious crash. That's a good thing; it tells you exactly where to fix it.

---

## Adding a whole new module

Say you want a new `MyGeometry` module.

```bash
mkdir -p modules/MyGeometry
```

**`modules/MyGeometry/MyGeometry.h`:**
```cpp
#pragma once

namespace MyGeometry {
    double CircleArea(double radius);
}
```

**`modules/MyGeometry/MyGeometry.cpp`:**
```cpp
#include "MyGeometry.h"

namespace MyGeometry {
    double CircleArea(double radius) {
        return 3.14159 * radius * radius;
    }
}
```

Add it to the umbrella header:
```cpp
#include "modules/MyGeometry/MyGeometry.h"
// ...
namespace MyLib {
    // ...
    using namespace MyGeometry;
}
```

Then just run `make` — the Makefile automatically picks up any new `.cpp` file under `modules/`, so you don't need to edit it.

---

## Working in VS Code

If you want to skip typing build commands entirely, drop these three files into a `.vscode/` folder in your project:

**`c_cpp_properties.json`** — so VS Code stops underlining `#include "MyLib.h"` in red:
```json
{
  "configurations": [
    {
      "name": "Linux",
      "includePath": [
        "${workspaceFolder}/**",
        "/path/to/MyLibrary/**"
      ],
      "cStandard": "c17",
      "cppStandard": "c++17",
      "intelliSenseMode": "linux-gcc-x64"
    }
  ],
  "version": 4
}
```

**`tasks.json`** — so `Ctrl+Shift+B` builds your current file automatically:
```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "Build with MyLib",
      "type": "process",
      "command": "g++",
      "args": [
        "${file}",
        "-I", "/path/to/MyLibrary",
        "-L", "/path/to/MyLibrary",
        "-lMyLib",
        "-o", "${fileDirname}/${fileBasenameNoExtension}.out"
      ],
      "group": { "kind": "build", "isDefault": true },
      "problemMatcher": ["$gcc"]
    }
  ]
}
```

**`launch.json`** (optional) — for debugging with breakpoints via `F5`:
```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "Debug current file",
      "type": "cppdbg",
      "request": "launch",
      "program": "${fileDirname}/${fileBasenameNoExtension}.out",
      "cwd": "${fileDirname}",
      "preLaunchTask": "Build with MyLib",
      "MIMode": "gdb"
    }
  ]
}
```

For a new project, just copy the whole `.vscode/` folder over — it's ready to go immediately.

---

## Common problems

| What you see | Why | Fix |
|---|---|---|
| `undefined reference to 'MyX::func()'` | You compiled your file alone without linking the library | Add `-I... -L... -lMyLib` to your compile command, and make sure you ran `make` after any library changes |
| `No such file or directory` on `#include` | The `-I` path is wrong or missing | Double-check `-I` points to the `MyLibrary` folder |
| `zsh: no matches found` when doing `cd` into a path with spaces | The shell tried to expand a wildcard it couldn't match | Quote the fixed part of the path, keep the wildcard outside the quotes |
| Compile error after changing a function's signature | Some old project still calls it the old way | Update that call site to match the new signature |

---

## The short version

- The split is done, tested, and working — it builds cleanly and runs correctly.
- Day-to-day, using the library is just one steady command, whether you need one function or all of them.
- Adding or changing something always follows the same loop: **edit → `make` → recompile whatever project depends on it.**

This isn't meant to be perfect or final — it's meant to be easy to keep working in. If something here starts feeling clunky again down the road, that's a fine reason to revisit it.
