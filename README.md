# Sort A Unstable

A fast, in-place, non-auxiliary sorting algorithm that discards original sort order context.

`sort_a_unstable_ascending()` and `sort_a_unstable_descending()` are the unstable sorting functions that sort elements in either ascending or descending order while discarding original sort order context.

They accept the following 2 arguments in left-to-right order.

1. `input_count` is the count of elements in `input`.
2. `input` is the array of elements to sort.

It's in the same class as Heap Sort, Selection Sort, Shell Sort and Unstable Binary Insertion Sort.

It's the fastest unstable sorting algorithm that doesn't require substantial auxiliary space for sorted runs or unsorted subarrays.

It's close to Insertion Sort for small input sizes, then it scales to the fastest Shell Sort gap sequence for all input data types and unsorted distributions.

I welcome submissions of algorithms in the same class that challenge the aforementioned claim.

The following security explanation uses the context of ascending sort order.

The consistent decrements from `gap = (gap >> 5) + (gap >> 3)` ensure there are never pitfalls that cause critically-slow sorting instances with any combination of numbers.

Elements are always guaranteed to be sorted within bounds using conditional statements that guarantee the final pass is always a regular Insertion Sort with a `gap` value of `1`.

After each pass, `gap > 15` prevents any result of `gap` calculation from using a value of `0` or `1` based on the following calculation output table.

```
Gap   Result

0     0
1     0
2     0
3     0
4     0
5     0
6     0
7     0
8     1
9     1
10    1
11    1
12    1
13    1
14    1
15    1
16    3
17    3
18    3
```

It doesn't pre-calculate a consistent gap sequence that has an upper limit.

Instead, each sorting instance calculates a gap sequence dynamically with inconsistencies among different `input_count` values.

After sorting with each `gap` value greater than `1`, it falls through to a hard-coded, optimized variation of Insertion Sort.
