# perf-analysis
A small project to analyze the program performance.

## branch-predict
* The code is modified from [Why is processing a sorted array faster than processing an unsorted array?](https://stackoverflow.com/questions/11227809/why-is-processing-a-sorted-array-faster-than-processing-an-unsorted-array)
* Build
  * With sort 
    ```
    make SORT=y
    ```
  * Without sort
    ```
    make
    ```
* Summary
  * The performance of the version with sort is better than one without sort because of the branch prediction.
