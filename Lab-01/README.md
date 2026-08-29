# Pointer Arithmetic & Array Analysis — C++ Lab

> **Course:** Object-Oriented Programming / C++ Lab  
> **Student:** Mehr Ali  
> **Language:** C++  
> **Topic:** Pointers, Pointer Arithmetic, Arrays, Memory Access & Bounds  
> **Lab Tasks:** 01–04

---

## 📌 Overview

This repository contains my work for a four-part C++ laboratory focused on **pointer arithmetic, arrays, memory access, and array bounds**.

The laboratory explores how pointers can be used to traverse arrays, access individual elements, calculate memory addresses, perform calculations, and analyze program behavior at the memory level.

The four tasks progressively move from basic pointer-based array traversal to more advanced analysis of:

- Pointer arithmetic
- Array traversal
- Pointer dereferencing
- Memory addresses
- Array bounds
- One-past-the-end pointers
- Undefined behavior
- Raw pointer limitations
- Adversarial inputs
- Pointer-based function parameters
- Pointer range validation
- Manual pointer tracing

The central concept demonstrated throughout this laboratory is:

## 🎯 Learning Objectives

The main objective of this laboratory is to develop a practical understanding of how pointers interact with arrays and memory in C++.

By completing these four tasks, I learned how to:

-Understand the relationship between pointers and arrays.
-Use pointer arithmetic to access array elements.
Traverse arrays using pointer increments.
Access array elements using *(ptr + i).
Understand how pointer offsets correspond to array positions.
Use pointers to calculate totals, averages, and maximum values.
Work with character arrays.
Check characters using pointer-based access.
Display and understand memory addresses.
Understand array boundaries.
Identify valid and invalid pointer dereferences.
Understand one-past-the-end pointers.
Understand undefined behavior caused by out-of-bounds access.
Design adversarial inputs to test pointer-based programs.
Understand the limitations of raw pointers.
Understand why array size information is important when passing arrays to functions.
Manually trace pointer movement through an array.
Critically evaluate claims about pointer safety and efficiency.
Develop safer programming practices when working with raw pointers.

```cpp
*(ptr + i)
