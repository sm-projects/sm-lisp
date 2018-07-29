# Modern C Notes

### Compiler Optimizations

### Warnings

### Modern types
- For modern programs, you should #include <stdint.h> then use standard types. 
- In addition to standard fixed-width like uint16_t and int32_t, we also have fast and least types defined in the stdint.h specification. 
    - Fast types are:
    ```
     int_fast_8, 
     int_fast16_t, int_fast32_t, int_fast64_t — signed integers
     uint_fast8_t, uint_fast16_t, uint_fast32_t, uint_fast64_t — unsigned integers
    ```
- One Exception to never-char
  The only acceptable use of char in 2016 is if a pre-existing API requires char 
  (e.g. strncat, printf’ing “%s”, …) or if you’re initializing a read-only string 
  (e.g. const char *hello = "hello";) because the C type of string literals ("hello")
  is char [].

- No need for usage of ‘’’unsigned’’’ types anymore. The <stdint.h> types are more explicit,
  more exact in meaning, convey intentions better, and are more compact for typographic 
  usage and readability.

ALSO: In C11 we have native unicode support, and the type of UTF-8 string literals is still char [] even for multibyte sequences like const char *abcgrr = u8"abc😬";.
### References
1. Modern C
2. [Matt sh blog](https://matt.sh/howto-c)

