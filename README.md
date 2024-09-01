
# Extended CString

`xt` is a lightweight and flexible string manipulation library for C, designed to handle dynamic strings with a focus on ease of use and efficiency. It provides a set of functions to work with dynamically allocated strings (`xs`), allowing operations such as creating, appending, and converting strings to different cases.


## Overview


- **Dynamic Strings**: Manage strings without worrying about memory allocation.
- **String Operations**: Functions to create, append, and manipulate strings.
- **Case Conversion**: Convert strings to lowercase or uppercase.
- **Memory Management**: Easily free string memory when no longer needed.
- **Namespace Simulation**: Easy access to functions within a simulated namespace, reducing potential name collisions and providing a cleaner interface.
- Will add more operations/methods

## Usage/Examples

```c
typedef struct {
    void    (*change_case)(xs s, CaseMethod method);
    void    (*free)(xs s);
    void    (*push_str)(xs s, const char *str);
    xs      (*from)(const char *buf);
} xs_ops;
```

```c
xs buf = xt.from("sample");
xt.push(" new text");
xt.change_case(buf, CASE_UPPER)  // CASE_UPPER | CASE_LOWER
xt.free(buf);
...
```
## Running Tests

To run tests, run the following command

```bash
make test
```

