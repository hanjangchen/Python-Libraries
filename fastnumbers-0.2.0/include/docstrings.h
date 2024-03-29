#ifndef DOCSTRINGS
#define DOCSTRINGS

/*
 * Docstrings for the fastnumbers functions.
 *
 * Author: Seth M. Morton, August 2, 2014
 */


static char module_docstring[] = "Quickly convert strings to numbers.\n";


static char safe_real_docstring[] = 
"safe_real(x, raise_on_invalid=False, default=None)\n"
"Quickly convert input to an `int` or `float` depending on value.\n"
"\n"
"Convert input to an `int` if the input is `int`-like, or to a `float`\n"
"otherwise. If the input cannot be converted to an `int` or `float`, then\n"
"the input will be returned unchanged if `raise_on_invalid` is *False*\n"
"(the default) or a `ValueError` will be raised if `raise_on_invalid`\n"
"is *True*. The return value is guaranteed to be of\n"
"type `str`, `int`, or `float` (or `long` on Python2).\n"
"\n"
"Parameters\n"
"----------\n"
"input : {str, float, int, long}\n"
"    The input you wish to convert to a real number.\n"
"raise_on_invalid : bool, optional\n"
"    If *True*, a `ValueError` will be raised if string input cannot be\n"
"    converted to a `float` or `int`.  If *False*, the string will be\n"
"    returned as-is.  The default is *False*.\n"
"default : optional\n"
"    If not *None*, this value will be returned instead of the input\n"
"    when the input cannot be converted. Has no effect if\n"
"    *raise_on_invalid* is *True*\n"
"\n"
"Returns\n"
"-------\n"
"out : {str, float, int, long}\n"
"    If the input could be converted to an `int`, the return type will be\n"
"    `int` (or `long` on Python2 if the integer is large enough).\n"
"    If the input could be converted to a `float` but not an `int`, the\n"
"    return type will be `float`.  Otherwise, the input `str` will be\n"
"    returned as-is (if `raise_on_invalid` is *False*) or whatever value\n"
"    is assigned to *default* if *default* is not *None*.\n"
"\n"
"Raises\n"
"------\n"
"TypeError\n"
"    If the input is not one of `str`, `float`, or `int`\n"
"    (or `long` on Python2).\n"
"ValueError\n"
"    If `raise_on_invalid` is *True*, this will be raised if the input\n"
"    string cannot be converted to a `float` or `int`.\n"
"\n"
"See Also\n"
"--------\n"
"fast_real, isreal\n"
"\n"
"Examples\n"
"--------\n"
"\n"
"    >>> from fastnumbers import safe_real\n"
"    >>> safe_real('56')\n"
"    56\n"
"    >>> safe_real('56.0')\n"
"    56\n"
"    >>> safe_real('56.07')\n"
"    56.07\n"
"    >>> safe_real('56.07 lb')\n"
"    '56.07 lb'\n"
"    >>> safe_real('56.07 lb', raise_on_invalid=True) #doctest: +IGNORE_EXCEPTION_DETAIL\n"
"    Traceback (most recent call last):\n"
"      ...\n"
"    ValueError: invalid literal for float(): 56.07 lb\n"
"    >>> safe_real(56.07)\n"
"    56.07\n"
"    >>> safe_real(56.0)\n"
"    56.0\n"
"    >>> safe_real(56)\n"
"    56\n"
"    >>> safe_real('invalid', default=50)\n"
"    50\n"
"\n"
"Notes\n"
"-----\n"
"It is roughly equivalent to (but much faster than)\n"
"\n"
"    >>> def py_safe_real(input, raise_on_invalid=False, default=None):\n"
"    ...     try:\n"
"    ...         a = float(input)\n"
"    ...     except ValueError:\n"
"    ...         if raise_on_invalid:\n"
"    ...             raise\n"
"    ...         elif default is not None:\n"
"    ...             return default\n"
"    ...         else:\n"
"    ...             return input\n"
"    ...     else:\n"
"    ...         return int(a) if a.is_integer() else a\n"
"    ... \n"
"\n"
"It is able to be faster than the pure-Python equivalent by skipping\n"
"detailed type checking (and avoiding the exception stack); because\n"
"most type checking is skipped, classes that define the `__float__`\n"
"or `__int__` methods won't be converted properly.\n"
"\n";


static char safe_float_docstring[] = 
"safe_float(x, raise_on_invalid=False, default=None)\n"
"Quickly convert input to a `float`.\n"
"\n"
"Quickly convert input to a `float`. If the input cannot be converted\n"
"to a `float`, then the input will be returned unchanged if\n"
"`raise_on_invalid` is *False* (the default) or a `ValueError` will be\n"
"raised if `raise_on_invalid` is *True*. The return value is guaranteed\n"
"to be of type `str` or `float`.\n"
"\n"
"Parameters\n"
"----------\n"
"input : {str, float, int, long}\n"
"    The input you wish to convert to a `float`.\n"
"raise_on_invalid : bool, optional\n"
"    If *True*, a `ValueError` will be raised if string input cannot be\n"
"    converted to a `float`.  If *False*, the string will be\n"
"    returned as-is.  The default is *False*.\n"
"default : optional\n"
"    If not *None*, this value will be returned instead of the input\n"
"    when the input cannot be converted. Has no effect if\n"
"    *raise_on_invalid* is *True*\n"
"\n"
"Returns\n"
"-------\n"
"out : {str, float}\n"
"    If the input could be converted to a `float` the return type will\n"
"    be `float`. Otherwise, the input `str` will be returned as-is\n"
"    (if `raise_on_invalid` is *False*) or whatever value\n"
"    is assigned to *default* if *default* is not *None*.\n"
"\n"
"Raises\n"
"------\n"
"TypeError\n"
"    If the input is not one of `str`, `float`, or `int`\n"
"    (or `long` on Python2).\n"
"ValueError\n"
"    If `raise_on_invalid` is *True*, this will be raised if the input\n"
"    string cannot be converted to a `float`.\n"
"\n"
"See Also\n"
"--------\n"
"fast_float, isfloat\n"
"\n"
"Examples\n"
"--------\n"
"\n"
"    >>> from fastnumbers import safe_float\n"
"    >>> safe_float('56')\n"
"    56.0\n"
"    >>> safe_float('56.0')\n"
"    56.0\n"
"    >>> safe_float('56.07')\n"
"    56.07\n"
"    >>> safe_float('56.07 lb')\n"
"    '56.07 lb'\n"
"    >>> safe_float('56.07 lb', raise_on_invalid=True) #doctest: +IGNORE_EXCEPTION_DETAIL\n"
"    Traceback (most recent call last):\n"
"      ...\n"
"    ValueError: invalid literal for float(): 56.07 lb\n"
"    >>> safe_float(56.07)\n"
"    56.07\n"
"    >>> safe_float(56)\n"
"    56.0\n"
"    >>> safe_float('invalid', default=50)\n"
"    50\n"
"\n"
"Notes\n"
"-----\n"
"It is roughly equivalent to (but much faster than)\n"
"\n"
"    >>> def py_safe_float(input, raise_on_invalid=False, default=None):\n"
"    ...    try:\n"
"    ...        return float(input)\n"
"    ...    except ValueError:\n"
"    ...         if raise_on_invalid:\n"
"    ...             raise\n"
"    ...         elif default is not None:\n"
"    ...             return default\n"
"    ...         else:\n"
"    ...             return input\n"
"    ... \n"
"\n"
"It is able to be faster than the pure-Python equivalent by skipping\n"
"detailed type checking (and avoiding the exception stack); because\n"
"most type checking is skipped, classes that define the `__float__`\n"
"method won't be converted properly.\n"
"\n";


static char safe_int_docstring[] = 
"safe_int(x, raise_on_invalid=False, default=None)\n"
"Quickly convert input to an `int`.\n"
"\n"
"Quickly convert input to an `int`. If the input cannot be converted\n"
"to an `int`, then the input will be returned unchanged if\n"
"`raise_on_invalid` is *False* (the default) or a `ValueError` will be\n"
"raised if `raise_on_invalid` is *True*. The return value is guaranteed\n"
"to be of type `str` or `int` (or `long` on Python2).\n"
"\n"
"Parameters\n"
"----------\n"
"input : {str, float, int, long}\n"
"    The input you wish to convert to an `int`.\n"
"raise_on_invalid : bool, optional\n"
"    If *True*, a `ValueError` will be raised if string input cannot be\n"
"    converted to an `int`.  If *False*, the string will be\n"
"    returned as-is.  The default is *False*.\n"
"default : optional\n"
"    If not *None*, this value will be returned instead of the input\n"
"    when the input cannot be converted. Has no effect if\n"
"    *raise_on_invalid* is *True*\n"
"\n"
"Returns\n"
"-------\n"
"out : {str, int, long}\n"
"    If the input could be converted to an `int`, the return type will be\n"
"    `int` (or `long` on Python2 if the integer is large enough).\n"
"    Otherwise, the input `str` will be returned as-is\n"
"    (if `raise_on_invalid` is *False*) or whatever value\n"
"    is assigned to *default* if *default* is not *None*.\n"
"\n"
"Raises\n"
"------\n"
"TypeError\n"
"    If the input is not one of `str`, `float`, or `int`\n"
"    (or `long` on Python2).\n"
"ValueError\n"
"    If `raise_on_invalid` is *True*, this will be raised if the input\n"
"    string cannot be converted to an `int`.\n"
"\n"
"See Also\n"
"--------\n"
"fast_int, isint\n"
"\n"
"Examples\n"
"--------\n"
"\n"
"    >>> from fastnumbers import safe_int\n"
"    >>> safe_int('56')\n"
"    56\n"
"    >>> safe_int('56.0')\n"
"    '56.0'\n"
"    >>> safe_int('56.07 lb')\n"
"    '56.07 lb'\n"
"    >>> safe_int('56.07 lb', raise_on_invalid=True) #doctest: +IGNORE_EXCEPTION_DETAIL\n"
"    Traceback (most recent call last):\n"
"      ...\n"
"    ValueError: invalid literal for int() with base 10: '56.07 lb'\n"
"    >>> safe_int(56.07)\n"
"    56\n"
"    >>> safe_int(56)\n"
"    56\n"
"    >>> safe_int('invalid', default=50)\n"
"    50\n"
"\n"
"Notes\n"
"-----\n"
"It is roughly equivalent to (but much faster than)\n"
"\n"
"    >>> def py_safe_int(input, raise_on_invalid=False, default=None):\n"
"    ...    try:\n"
"    ...        return int(input)\n"
"    ...    except ValueError:\n"
"    ...         if raise_on_invalid:\n"
"    ...             raise\n"
"    ...         elif default is not None:\n"
"    ...             return default\n"
"    ...         else:\n"
"    ...             return input\n"
"    ... \n"
"\n"
"It is able to be faster than the pure-Python equivalent by skipping\n"
"detailed type checking (and avoiding the exception stack); because\n"
"most type checking is skipped, classes that define the `__int__`\n"
"method won't be converted properly.\n"
"\n";


static char safe_forceint_docstring[] = 
"safe_forceint(x, raise_on_invalid=False, default=None)\n"
"Quickly convert input to an `int` (by converting to `float` first).\n"
"\n"
"Quickly convert input to an `int`. If the input is a string of a `float`\n"
"(i.e. '56.07') then the `float` function will be used, and that `float`\n"
"is then converted to an `int`. If the input cannot be converted\n"
"to an `int`, then the input will be returned unchanged if\n"
"`raise_on_invalid` is *False* (the default) or a `ValueError` will be\n"
"raised if `raise_on_invalid` is *True*. The return value is guaranteed\n"
"to be of type `str` or `int` (or `long` on Python2).\n"
"\n"
"An input of 'inf' will return *sys.maxsize*, and '-inf' will return\n"
"*-sys.maxsize-1*. A 'nan' input will be treated like an invalid string.\n"
"\n"
"Parameters\n"
"----------\n"
"input : {str, float, int, long}\n"
"    The input you wish to convert to an `int`.\n"
"raise_on_invalid : bool, optional\n"
"    If *True*, a `ValueError` will be raised if string input cannot be\n"
"    converted to an `int`.  If *False*, the string will be\n"
"    returned as-is.  The default is *False*.\n"
"default : optional\n"
"    If not *None*, this value will be returned instead of the input\n"
"    when the input cannot be converted. Has no effect if\n"
"    *raise_on_invalid* is *True*\n"
"\n"
"Returns\n"
"-------\n"
"out : {str, int, long}\n"
"    If the input could be converted to an `int`, the return type will be\n"
"    `int` (or `long` on Python2 if the integer is large enough).\n"
"    Otherwise, the input `str` will be returned as-is\n"
"    (if `raise_on_invalid` is *False*) or whatever value\n"
"    is assigned to *default* if *default* is not *None*.\n"
"\n"
"Raises\n"
"------\n"
"TypeError\n"
"    If the input is not one of `str`, `float`, or `int`\n"
"    (or `long` on Python2).\n"
"ValueError\n"
"    If `raise_on_invalid` is *True*, this will be raised if the input\n"
"    string cannot be converted to an `int`.\n"
"\n"
"See Also\n"
"--------\n"
"fast_forceint, isintlike\n"
"\n"
"Examples\n"
"--------\n"
"\n"
"    >>> from fastnumbers import safe_forceint\n"
"    >>> safe_forceint('56')\n"
"    56\n"
"    >>> safe_forceint('56.0')\n"
"    56\n"
"    >>> safe_forceint('56.07')\n"
"    56\n"
"    >>> safe_forceint('56.07 lb')\n"
"    '56.07 lb'\n"
"    >>> safe_forceint('56.07 lb', raise_on_invalid=True) #doctest: +IGNORE_EXCEPTION_DETAIL\n"
"    Traceback (most recent call last):\n"
"      ...\n"
"    ValueError: invalid literal for float(): 56.07 lb\n"
"    >>> safe_forceint(56.07)\n"
"    56\n"
"    >>> safe_forceint(56)\n"
"    56\n"
"    >>> safe_forceint('invalid', default=50)\n"
"    50\n"
"\n"
"Notes\n"
"-----\n"
"It is roughly equivalent to (but much faster than)\n"
"\n"
"    >>> def py_safe_forceint(input, raise_on_invalid=False, default=None):\n"
"    ...     try:\n"
"    ...         return int(input)\n"
"    ...     except ValueError:\n"
"    ...         try:\n"
"    ...             return int(float(input))\n"
"    ...         except ValueError:\n"
"    ...             if raise_on_invalid:\n"
"    ...                 raise\n"
"    ...             elif default is not None:\n"
"    ...                 return default\n"
"    ...             else:\n"
"    ...                 return input\n"
"    ... \n"
"\n"
"It is able to be faster than the pure-Python equivalent by skipping\n"
"detailed type checking (and avoiding the exception stack); because\n"
"most type checking is skipped, classes that define the `__float__`\n"
"or `__int__` methods won't be converted properly.\n"
"\n";


static char fast_real_docstring[] = 
"fast_real(x, raise_on_invalid=False, default=None)\n"
"Quickly convert input to an `int` or `float` depending on value.\n"
"\n"
"Convert input to an `int` if the input is `int`-like, or to a `float`\n"
"otherwise. If the input cannot be converted to an `int` or `float`, then\n"
"the input will be returned unchanged if `raise_on_invalid` is *False*\n"
"(the default) or a `ValueError` will be raised if `raise_on_invalid`\n"
"is *True*. The return value is guaranteed to be of\n"
"type `str`, `int`, or `float` (or `long` on Python2).\n"
"\n"
"This function differs from `safe_real` in that no overflow/underflow\n"
"checks are performed, and the fast implementation of atof that is used\n"
"can cause a `float` to lose accuracy around the 12th decimal place\n"
"for large exponents.  For small numbers, neither of these issues will be a\n"
"problem and the enhancement in speed is significant over `safe_real`.\n"
"\n"
"Parameters\n"
"----------\n"
"input : {str, float, int, long}\n"
"    The input you wish to convert to a real number.\n"
"raise_on_invalid : bool, optional\n"
"    If *True*, a `ValueError` will be raised if string input cannot be\n"
"    converted to a `float` or `int`.  If *False*, the string will be\n"
"    returned as-is.  The default is *False*.\n"
"default : optional\n"
"    If not *None*, this value will be returned instead of the input\n"
"    when the input cannot be converted. Has no effect if\n"
"    *raise_on_invalid* is *True*\n"
"\n"
"Returns\n"
"-------\n"
"out : {str, float, int, long}\n"
"    If the input could be converted to an `int`, the return type will be\n"
"    `int` (or `long` on Python2 if the integer is large enough).\n"
"    If the input could be converted to a `float` but not an `int`, the\n"
"    return type will be `float`.  Otherwise, the input `str` will be\n"
"    returned as-is (if `raise_on_invalid` is *False*) or whatever value\n"
"    is assigned to *default* if *default* is not *None*.\n"
"\n"
"Raises\n"
"------\n"
"TypeError\n"
"    If the input is not one of `str`, `float`, or `int`\n"
"    (or `long` on Python2).\n"
"ValueError\n"
"    If `raise_on_invalid` is *True*, this will be raised if the input\n"
"    string cannot be converted to a `float` or `int`.\n"
"\n"
"See Also\n"
"--------\n"
"safe_real, isreal\n"
"\n"
"Examples\n"
"--------\n"
"\n"
"    >>> from fastnumbers import fast_real\n"
"    >>> fast_real('56')\n"
"    56\n"
"    >>> fast_real('56.0')\n"
"    56\n"
"    >>> fast_real('56.07')\n"
"    56.07\n"
"    >>> fast_real('56.07 lb')\n"
"    '56.07 lb'\n"
"    >>> fast_real('56.07 lb', raise_on_invalid=True) #doctest: +IGNORE_EXCEPTION_DETAIL\n"
"    Traceback (most recent call last):\n"
"      ...\n"
"    ValueError: could not convert string to float: '56.07 lb'\n"
"    >>> fast_real(56.07)\n"
"    56.07\n"
"    >>> fast_real(56.0)\n"
"    56.0\n"
"    >>> fast_real(56)\n"
"    56\n"
"    >>> fast_real('invalid', default=50)\n"
"    50\n"
"\n"
"Notes\n"
"-----\n"
"It is roughly equivalent to (but much faster than)\n"
"\n"
"    >>> def py_fast_real(input, raise_on_invalid=False, default=None):\n"
"    ...     try:\n"
"    ...         a = float(input)\n"
"    ...     except ValueError:\n"
"    ...         if raise_on_invalid:\n"
"    ...             raise\n"
"    ...         elif default is not None:\n"
"    ...             return default\n"
"    ...         else:\n"
"    ...             return input\n"
"    ...     else:\n"
"    ...         return int(a) if a.is_integer() else a\n"
"    ... \n"
"\n"
"It is able to be faster than the pure-Python equivalent by skipping\n"
"detailed type checking (and avoiding the exception stack); because\n"
"most type checking is skipped, classes that define the `__float__`\n"
"or `__int__` methods won't be converted properly.\n"
"\n";


static char fast_float_docstring[] = 
"fast_float(x, raise_on_invalid=False, default=None)\n"
"Quickly convert input to a `float`.\n"
"\n"
"Quickly convert input to a `float`. If the input cannot be converted\n"
"to a `float`, then the input will be returned unchanged if\n"
"`raise_on_invalid` is *False* (the default) or a `ValueError` will be\n"
"raised if `raise_on_invalid` is *True*. The return value is guaranteed\n"
"to be of type `str` or `float`.\n"
"\n"
"This function differs from `safe_float` in that no overflow/underflow\n"
"checks are performed, and the fast implementation of atof that is used\n"
"can cause a `float` to lose accuracy around the 12th decimal place\n"
"for large exponents.  For small numbers, neither of these issues will be a\n"
"problem and the enhancement in speed is significant over `safe_float`.\n"
"\n"
"Parameters\n"
"----------\n"
"input : {str, float, int, long}\n"
"    The input you wish to convert to a `float`.\n"
"raise_on_invalid : bool, optional\n"
"    If *True*, a `ValueError` will be raised if string input cannot be\n"
"    converted to a `float`.  If *False*, the string will be\n"
"    returned as-is.  The default is *False*.\n"
"default : optional\n"
"    If not *None*, this value will be returned instead of the input\n"
"    when the input cannot be converted. Has no effect if\n"
"    *raise_on_invalid* is *True*\n"
"\n"
"Returns\n"
"-------\n"
"out : {str, float}\n"
"    If the input could be converted to a `float` the return type will\n"
"    be `float`. Otherwise, the input `str` will be returned as-is\n"
"    (if `raise_on_invalid` is *False*) or whatever value\n"
"    is assigned to *default* if *default* is not *None*.\n"
"\n"
"Raises\n"
"------\n"
"TypeError\n"
"    If the input is not one of `str`, `float`, or `int`\n"
"    (or `long` on Python2).\n"
"ValueError\n"
"    If `raise_on_invalid` is *True*, this will be raised if the input\n"
"    string cannot be converted to a `float`.\n"
"\n"
"See Also\n"
"--------\n"
"safe_float, isfloat\n"
"\n"
"Examples\n"
"--------\n"
"\n"
"    >>> from fastnumbers import fast_float\n"
"    >>> fast_float('56')\n"
"    56.0\n"
"    >>> fast_float('56.0')\n"
"    56.0\n"
"    >>> fast_float('56.07')\n"
"    56.07\n"
"    >>> fast_float('56.07 lb')\n"
"    '56.07 lb'\n"
"    >>> fast_float('56.07 lb', raise_on_invalid=True) #doctest: +IGNORE_EXCEPTION_DETAIL\n"
"    Traceback (most recent call last):\n"
"      ...\n"
"    ValueError: could not convert string to float: '56.07 lb'\n"
"    >>> fast_float(56.07)\n"
"    56.07\n"
"    >>> fast_float(56)\n"
"    56.0\n"
"    >>> fast_float('invalid', default=50)\n"
"    50\n"
"\n"
"Notes\n"
"-----\n"
"It is roughly equivalent to (but much faster than)\n"
"\n"
"    >>> def py_fast_float(input, raise_on_invalid=False, default=None):\n"
"    ...    try:\n"
"    ...        return float(input)\n"
"    ...    except ValueError:\n"
"    ...         if raise_on_invalid:\n"
"    ...             raise\n"
"    ...         elif default is not None:\n"
"    ...             return default\n"
"    ...         else:\n"
"    ...             return input\n"
"    ... \n"
"\n"
"It is able to be faster than the pure-Python equivalent by skipping\n"
"detailed type checking (and avoiding the exception stack); because\n"
"most type checking is skipped, classes that define the `__float__`\n"
"method won't be converted properly.\n"
"\n";


static char fast_int_docstring[] = 
"fast_int(x, raise_on_invalid=False, default=None)\n"
"Quickly convert input to an `int`.\n"
"\n"
"Quickly convert input to an `int`. If the input cannot be converted\n"
"to an `int`, then the input will be returned unchanged if\n"
"`raise_on_invalid` is *False* (the default) or a `ValueError` will be\n"
"raised if `raise_on_invalid` is *True*. The return value is guaranteed\n"
"to be of type `str` or `int` (or `long` on Python2).\n"
"\n"
"This function differs from `safe_int` in that no overflow/underflow\n"
"checks are performed.  For small numbers, this issue will not be a\n"
"problem and the enhancement in speed is significant over `safe_int`.\n"
"\n"
"Parameters\n"
"----------\n"
"input : {str, float, int, long}\n"
"    The input you wish to convert to an `int`.\n"
"raise_on_invalid : bool, optional\n"
"    If *True*, a `ValueError` will be raised if string input cannot be\n"
"    converted to an `int`.  If *False*, the string will be\n"
"    returned as-is.  The default is *False*.\n"
"default : optional\n"
"    If not *None*, this value will be returned instead of the input\n"
"    when the input cannot be converted. Has no effect if\n"
"    *raise_on_invalid* is *True*\n"
"\n"
"Returns\n"
"-------\n"
"out : {str, int, long}\n"
"    If the input could be converted to an `int`, the return type will be\n"
"    `int` (or `long` on Python2 if the integer is large enough).\n"
"    Otherwise, the input `str` will be returned as-is\n"
"    (if `raise_on_invalid` is *False*) or whatever value\n"
"    is assigned to *default* if *default* is not *None*.\n"
"\n"
"Raises\n"
"------\n"
"TypeError\n"
"    If the input is not one of `str`, `float`, or `int`\n"
"    (or `long` on Python2).\n"
"ValueError\n"
"    If `raise_on_invalid` is *True*, this will be raised if the input\n"
"    string cannot be converted to an `int`.\n"
"\n"
"See Also\n"
"--------\n"
"safe_int, isint\n"
"\n"
"Examples\n"
"--------\n"
"\n"
"    >>> from fastnumbers import fast_int\n"
"    >>> fast_int('56')\n"
"    56\n"
"    >>> fast_int('56.0')\n"
"    '56.0'\n"
"    >>> fast_int('56.07 lb')\n"
"    '56.07 lb'\n"
"    >>> fast_int('56.07 lb', raise_on_invalid=True) #doctest: +IGNORE_EXCEPTION_DETAIL\n"
"    Traceback (most recent call last):\n"
"      ...\n"
"    ValueError: could not convert string to int: '56.07 lb'\n"
"    >>> fast_int(56.07)\n"
"    56\n"
"    >>> fast_int(56)\n"
"    56\n"
"    >>> fast_int('invalid', default=50)\n"
"    50\n"
"\n"
"Notes\n"
"-----\n"
"It is roughly equivalent to (but much faster than)\n"
"\n"
"    >>> def py_fast_int(input, raise_on_invalid=False, default=None):\n"
"    ...    try:\n"
"    ...        return int(input)\n"
"    ...    except ValueError:\n"
"    ...         if raise_on_invalid:\n"
"    ...             raise\n"
"    ...         elif default is not None:\n"
"    ...             return default\n"
"    ...         else:\n"
"    ...             return input\n"
"    ... \n"
"\n"
"It is able to be faster than the pure-Python equivalent by skipping\n"
"detailed type checking (and avoiding the exception stack); because\n"
"most type checking is skipped, classes that define the `__int__`\n"
"method won't be converted properly.\n"
"\n";


static char fast_forceint_docstring[] = 
"fast_forceint(x, raise_on_invalid=False, default=None)\n"
"Quickly convert input to an `int` (by converting to `float` first).\n"
"\n"
"Quickly convert input to an `int`. If the input is a string of a `float`\n"
"(i.e. '56.07') then the `float` function will be used, and that `float`\n"
"is then converted to an `int`. If the input cannot be converted\n"
"to an `int`, then the input will be returned unchanged if\n"
"`raise_on_invalid` is *False* (the default) or a `ValueError` will be\n"
"raised if `raise_on_invalid` is *True*. The return value is guaranteed\n"
"to be of type `str` or `int` (or `long` on Python2).\n"
"\n"
"An input of 'inf' will return *sys.maxsize*, and '-inf' will return\n"
"*-sys.maxsize-1*. A 'nan' input will be treated like an invalid string.\n"
"\n"
"This function differs from `safe_forceint` in that no overflow/underflow\n"
"checks are performed, and the fast implementation of atof that is used\n"
"can cause a `float` to lose accuracy around the 12th decimal place\n"
"for large exponents.  For small numbers, neither of these issues will be a\n"
"problem and the enhancement in speed is significant over `safe_forceint`.\n"
"\n"
"Parameters\n"
"----------\n"
"input : {str, float, int, long}\n"
"    The input you wish to convert to an `int`.\n"
"raise_on_invalid : bool, optional\n"
"    If *True*, a `ValueError` will be raised if string input cannot be\n"
"    converted to an `int`.  If *False*, the string will be\n"
"    returned as-is.  The default is *False*.\n"
"default : optional\n"
"    If not *None*, this value will be returned instead of the input\n"
"    when the input cannot be converted. Has no effect if\n"
"    *raise_on_invalid* is *True*\n"
"\n"
"Returns\n"
"-------\n"
"out : {str, int, long}\n"
"    If the input could be converted to an `int`, the return type will be\n"
"    `int` (or `long` on Python2 if the integer is large enough).\n"
"    Otherwise, the input `str` will be returned as-is\n"
"    (if `raise_on_invalid` is *False*) or whatever value\n"
"    is assigned to *default* if *default* is not *None*.\n"
"\n"
"Raises\n"
"------\n"
"TypeError\n"
"    If the input is not one of `str`, `float`, or `int`\n"
"    (or `long` on Python2).\n"
"ValueError\n"
"    If `raise_on_invalid` is *True*, this will be raised if the input\n"
"    string cannot be converted to an `int`.\n"
"\n"
"See Also\n"
"--------\n"
"safe_forceint, isintlike\n"
"\n"
"Examples\n"
"--------\n"
"\n"
"    >>> from fastnumbers import fast_forceint\n"
"    >>> fast_forceint('56')\n"
"    56\n"
"    >>> fast_forceint('56.0')\n"
"    56\n"
"    >>> fast_forceint('56.07')\n"
"    56\n"
"    >>> fast_forceint('56.07 lb')\n"
"    '56.07 lb'\n"
"    >>> fast_forceint('56.07 lb', raise_on_invalid=True) #doctest: +IGNORE_EXCEPTION_DETAIL\n"
"    Traceback (most recent call last):\n"
"      ...\n"
"    ValueError: could not convert string to float: '56.07 lb'\n"
"    >>> fast_forceint(56.07)\n"
"    56\n"
"    >>> fast_forceint(56)\n"
"    56\n"
"    >>> fast_forceint('invalid', default=50)\n"
"    50\n"
"\n"
"Notes\n"
"-----\n"
"It is roughly equivalent to (but much faster than)\n"
"\n"
"    >>> def py_fast_forceint(input, raise_on_invalid=False, default=None):\n"
"    ...     try:\n"
"    ...         return int(input)\n"
"    ...     except ValueError:\n"
"    ...         try:\n"
"    ...             return int(float(input))\n"
"    ...         except ValueError:\n"
"    ...             if raise_on_invalid:\n"
"    ...                 raise\n"
"    ...             elif default is not None:\n"
"    ...                 return default\n"
"    ...             else:\n"
"    ...                 return input\n"
"    ... \n"
"\n"
"It is able to be faster than the pure-Python equivalent by skipping\n"
"detailed type checking (and avoiding the exception stack); because\n"
"most type checking is skipped, classes that define the `__float__`\n"
"or `__int__` methods won't be converted properly.\n"
"\n";


static char isreal_docstring[] = 
"isreal(x, str_only=False, allow_inf=False, allow_nan=False)\n"
"Quickly determine if a string is a real number.\n"
"\n"
"Quickly determine if a string is a real number. No value\n"
"error will be raised if it is not, even for objects like `list`.\n"
"This function returns *True* for any input that `safe_real` or\n"
"`fast_real` can convert. By default 'inf' and 'nan' will return\n"
"*False*.\n"
"\n"
"Parameters\n"
"----------\n"
"input :\n"
"    The input you wish to test if it is a real number.\n"
"str_only : bool, optional\n"
"    If *True*, then any non-`str` input will cause this function to return\n"
"    *False*. The default is *False*.\n"
"allow_inf : bool, optional\n"
"    If *True*, then the strings 'inf' and 'infinity' will also return *True*.\n"
"    This check is case-insensitive, and the string may be signed (i.e. '+/-').\n"
"    The default is *False*.\n"
"allow_nan : bool, optional\n"
"    If *True*, then the string 'nan' will also return *True*.\n"
"    This check is case-insensitive, and the string may be signed (i.e. '+/-').\n"
"    The default is *False*.\n"
"\n"
"Returns\n"
"-------\n"
"result : bool\n"
"    Whether or not the input is a real number.\n"
"\n"
"See Also\n"
"--------\n"
"safe_real, fast_real\n"
"\n"
"Examples\n"
"--------\n"
"\n"
"    >>> from fastnumbers import isreal\n"
"    >>> isreal('56')\n"
"    True\n"
"    >>> isreal('56.07')\n"
"    True\n"
"    >>> isreal('56.07 lb')\n"
"    False\n"
"    >>> isreal(56.07)\n"
"    True\n"
"    >>> isreal(56.07, str_only=True)\n"
"    False\n"
"    >>> isreal(56)\n"
"    True\n"
"\n"
"Notes\n"
"-----\n"
"It is roughly equivalent to (but much faster than)\n"
"\n"
"    >>> import re\n"
"    >>> def py_isreal(input, str_only=False):\n"
"    ...     try:\n"
"    ...         return bool(re.match(r'[-+]?\\d*\\.?\\d+(?:[eE][-+]?\\d+)?$', input))\n"
"    ...     except TypeError:\n"
"    ...         return False if str_only else type(input) in (int, float)\n"
"    ... \n"
"\n"
"It is able to be faster than the pure-Python equivalent by skipping\n"
"detailed type checking (and avoiding the exception stack); because\n"
"most type checking is skipped, classes that define the `__float__`\n"
"or `__int__` methods will likely return *False*.\n"
"\n";


static char isfloat_docstring[] = 
"isfloat(x, str_only=False, allow_inf=False, allow_nan=False)\n"
"Quickly determine if a string is a `float`.\n"
"\n"
"Quickly determine if a string is a `float`. No value\n"
"error will be raised if it is not, even for objects like `list`.\n"
"By default 'inf' and 'nan' will return *False*.\n"
"\n"
"It differs from `isreal` in that an `int` object will return `False`.\n"
"If `str_only` is *True*, it is no different from `isreal`.\n"
"\n"
"Parameters\n"
"----------\n"
"input :\n"
"    The input you wish to test if it is a `float`.\n"
"str_only : bool, optional\n"
"    If *True*, then any non-`str` input will cause this function to return\n"
"    *False*. The default is *False*.\n"
"allow_inf : bool, optional\n"
"    If *True*, then the strings 'inf' and 'infinity' will also return *True*.\n"
"    This check is case-insensitive, and the string may be signed (i.e. '+/-').\n"
"    The default is *False*.\n"
"allow_nan : bool, optional\n"
"    If *True*, then the string 'nan' will also return *True*.\n"
"    This check is case-insensitive, and the string may be signed (i.e. '+/-').\n"
"    The default is *False*.\n"
"\n"
"Returns\n"
"-------\n"
"result : bool\n"
"    Whether or not the input is a `float`.\n"
"\n"
"See Also\n"
"--------\n"
"safe_float, fast_float, isreal\n"
"\n"
"Examples\n"
"--------\n"
"\n"
"    >>> from fastnumbers import isfloat\n"
"    >>> isfloat('56')\n"
"    True\n"
"    >>> isfloat('56.07')\n"
"    True\n"
"    >>> isfloat('56.07 lb')\n"
"    False\n"
"    >>> isfloat(56.07)\n"
"    True\n"
"    >>> isfloat(56.07, str_only=True)\n"
"    False\n"
"    >>> isfloat(56)\n"
"    False\n"
"\n"
"Notes\n"
"-----\n"
"It is roughly equivalent to (but much faster than)\n"
"\n"
"    >>> import re\n"
"    >>> def py_isfloat(input, str_only=False):\n"
"    ...     try:\n"
"    ...         return bool(re.match(r'[-+]?\\d*\\.?\\d+(?:[eE][-+]?\\d+)?$', input))\n"
"    ...     except TypeError:\n"
"    ...         return False if str_only else type(input) == float\n"
"    ... \n"
"\n"
"It is able to be faster than the pure-Python equivalent by skipping\n"
"detailed type checking (and avoiding the exception stack); because\n"
"most type checking is skipped, classes that define the `__float__`\n"
"method will likely return *False*.\n"
"\n";


static char isint_docstring[] = 
"isint(x, str_only=False)\n"
"Quickly determine if a string is an `int`.\n"
"\n"
"Quickly determine if a string is an `int`. No value\n"
"error will be raised if it is not, even for objects like `list`.\n"
"This function returns *True* for any input that `safe_int` or\n"
"`fast_int` can convert.\n"
"\n"
"It differs from `isintlike` in that a `float` object will return `False`\n"
"and `int`-like strings (i.e. '45.0') will return `False`.\n"
"\n"
"Parameters\n"
"----------\n"
"input :\n"
"    The input you wish to test if it is an `int`.\n"
"str_only : bool, optional\n"
"    If *True*, then any non-`str` input will cause this function to return\n"
"    *False*. The default is *False*.\n"
"\n"
"Returns\n"
"-------\n"
"result : bool\n"
"    Whether or not the input is an `int`.\n"
"\n"
"See Also\n"
"--------\n"
"safe_int, fast_int, isintlike\n"
"\n"
"Examples\n"
"--------\n"
"\n"
"    >>> from fastnumbers import isint\n"
"    >>> isint('56')\n"
"    True\n"
"    >>> isint('56.07')\n"
"    False\n"
"    >>> isint('56.07 lb')\n"
"    False\n"
"    >>> isint(56.07)\n"
"    False\n"
"    >>> isint(56)\n"
"    True\n"
"    >>> isint(56, str_only=True)\n"
"    False\n"
"\n"
"Notes\n"
"-----\n"
"It is roughly equivalent to (but much faster than)\n"
"\n"
"    >>> import re\n"
"    >>> def py_isint(input, str_only=False):\n"
"    ...     try:\n"
"    ...         return bool(re.match(r'[-+]?\\d+$', input))\n"
"    ...     except TypeError:\n"
"    ...         return False if str_only else type(input) == int\n"
"    ... \n"
"\n"
"It is able to be faster than the pure-Python equivalent by skipping\n"
"detailed type checking (and avoiding the exception stack); because\n"
"most type checking is skipped, classes that define the `__int__`\n"
"method will likely return *False*.\n"
"\n";


static char isintlike_docstring[] = 
"isintlike(x, str_only=False)\n"
"Quickly determine if a string (or object) is an `int` or `int`-like.\n"
"\n"
"Quickly determine if a string (or object) is an `int` or `int`-like. \n"
"No value error will be raised if it is not, even for objects like `list`. \n"
"This function returns *True* for any input that `safe_forceint` or\n"
"`fast_forceint` can convert.\n"
"\n"
"Parameters\n"
"----------\n"
"input :\n"
"    The input you wish to test if it is an `int`.\n"
"\n"
"Returns\n"
"-------\n"
"result : bool\n"
"    Whether or not the input is an `int`.\n"
"str_only : bool, optional\n"
"    If *True*, then any non-`str` input will cause this function to return\n"
"    *False*. The default is *False*.\n"
"\n"
"See Also\n"
"--------\n"
"safe_forceint, fast_forceint\n"
"\n"
"Examples\n"
"--------\n"
"\n"
"    >>> from fastnumbers import isintlike\n"
"    >>> isintlike('56')\n"
"    True\n"
"    >>> isintlike('56.07')\n"
"    False\n"
"    >>> isintlike('56.0')\n"
"    True\n"
"    >>> isintlike('56.07 lb')\n"
"    False\n"
"    >>> isintlike(56.07)\n"
"    False\n"
"    >>> isintlike(56.0)\n"
"    True\n"
"    >>> isintlike(56.0, str_only=True)\n"
"    False\n"
"    >>> isintlike(56)\n"
"    True\n"
"\n"
"Notes\n"
"-----\n"
"It is roughly equivalent to (but much faster than)\n"
"\n"
"    >>> import re\n"
"    >>> def py_isintlike(input, str_only=False):\n"
"    ...     try:\n"
"    ...         if re.match(r'[-+]?\\d+$', input):\n"
"    ...             return True\n"
"    ...         elif re.match(r'[-+]?\\d*\\.?\\d+(?:[eE][-+]?\\d+)?$', input):\n"
"    ...             return float(input).is_integer()\n"
"    ...         else:\n"
"    ...             return False\n"
"    ...     except TypeError:\n"
"    ...         if str_only:\n"
"    ...             return False\n"
"    ...         elif type(input) == float:\n"
"    ...             return input.is_integer()\n"
"    ...         elif type(input) == int:\n"
"    ...             return True\n"
"    ...         else:\n"
"    ...             return False\n"
"    ... \n"
"\n"
"It is able to be faster than the pure-Python equivalent by skipping\n"
"detailed type checking (and avoiding the exception stack); because\n"
"most type checking is skipped, classes that define the `__float__`\n"
"or `__int__` methods will likely return *False*.\n"
"\n";


#endif /* DOCSTRINGS */