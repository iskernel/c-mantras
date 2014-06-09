c-mantras
========

Description
---------
c-mantras is a collection of C libraries I developed in my early college years. I will add more stuff to it whenever I get into a spartan mood and feel the need to implement algorithms in the rawest way possible.

Modules
---------
 - **base**  
  - **helpers** - various helpers used in other modules
      - *cm_generic* - various helper functions
      - *cm_numeric* - various numeric-related helper functions
      - *cm_text* - various text-related helper functions
  - *cm_operations* - complex error handling, useful for systems which have non-critical errors.
  - *cm_error_log* - error logging helper module
 - **collections** 
  - *cm_array* - generic array data structure and algorithms
  - *cm_arrayset* - generic arrayset data structure and algorithms
  - *cm_list* - generic double-linked list data structure and algorithms
  - *cm_searching* - generic searching algorithms (only for arrays)
  - *cm_sorting* - generic sorting algorithms (only quicksort, for arrays).
 - **cryptography** 
  - *cm_classical_ciphers* - caesar, disk and substitution ciphers algorithms
 - **media** 
  - *cm_g711* - A-law and mu-Law companding algorithms
  - *cm_colorspace* - RGB, HSI, HSV, HSL, YUV, YIK conversion algorithms.
 - **memory** 
  - *cm_nalloc* - generic memory allocation for 1D, 2D, 3D and 4D arrays.
 - **numeric** 
  - *cm_narray* - numeric array data structure and algorithms
  - *cm_narray* - numeric matrix data structure and  algorithms
 - **text** 
  - *cm_string* - string data structure and algorithms

Examples
---------
See the unit tests in the /test folder for each module.

License
---------
LGPL v3
