1.sizeof:return the sizes of Byte，size：return the sizes of element，

2.operator []:no array bounds check, the program would crash while running,
  use at() in class vector would check the bounds while compiling.

3.mind the difference between int []a and int a[]

4.get out_of_range many many times

5.by adding "cout" in some critical points of unsure programs to debug.

6.be concentrated, mistake of a num or letter can cause sevious consumption of debugging time.

7.leetcode mistake:
    "variable length array bound evaluates to non-positive value 0": without consideration the condition that the
    size of array is 0.

    "Warning: operation on 'i' may be undefined, -Wsequence-point": func(i++)+func1(i),the operation order of two
    function is undefined, so.

    "CompileError: expected unqualified -id before string constant": missing colon after a class definition, missing
    {} or ()

    "Warning: Comparison between signed and unsigned integer expressions": note that every warning may cause fatal error, syntax warning but logic error.
        for (int i = 0; i < s.size() - 1; ++i) {}
    while s.size() equals to 0, this cause running error.
        for (int i = 0; (int)i < s.size() - 1; ++i) {}


