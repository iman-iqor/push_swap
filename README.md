# 🎩✨ **Push_swap Project** ✨🎩

**Push_swap** is a sorting challenge where you sort **Stack A** using two stacks and limited operations, minimizing moves.

---

### **Operations**:
- **sa, sb**: Swap top two elements.
- **ss**: Swap both stacks.
- **pa, pb**: Move top element between stacks.
- **ra, rb**: Rotate top element to the bottom.
- **rr**: Rotate both stacks.
- **rra, rrb**: Reverse rotate top element to the front.
- **rrr**: Reverse rotate both stacks.

---

### **Example**:
**Input**: `./push_swap 2 1 3 6 5 8`

**Output**:
```bash
sa
pb
pb
pb
sa
pa
pa
pa

Run:

    Compile: make
    Run: ./push_swap 2 1 3 6 5 8

Validate:
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK: Success!
KO: Error.

Performance:

    100 numbers: <700 operations
    500 numbers: <5500 operations

Submission:

    Makefile: NAME, all, clean, fclean, re.
    No global variables.
********************************************************************************************************************************************************************************************************************************************************
